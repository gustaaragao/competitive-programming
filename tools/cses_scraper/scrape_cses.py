#!/usr/bin/env python3
"""Baixa o ultimo submit ACCEPTED de cada problema resolvido no CSES.

Recebe uma lista de contas (login/senha). Contas com indice menor tem
prioridade maior: se duas contas resolveram o mesmo problema, o arquivo
final e o da conta de maior prioridade (mais no inicio da lista).

Organiza a saida por tema (categoria do CSES), dentro de biblioteca/classics/
por padrao: biblioteca/classics/<tema>/<problema>.<ext>

Entre os submits ACCEPTED de uma tarefa, C++ e sempre priorizado; outra
linguagem so e usada quando nao existe nenhum ACCEPTED em C++. Isso evita
que a mesma tarefa fique com dois arquivos (ex: problema.py e problema.cpp).

Uso:
    python3 scrape_cses.py --accounts accounts.json

accounts.json:
    [
      {"login": "conta_prioritaria", "password": "..."},
      {"login": "conta_secundaria", "password": "..."}
    ]
"""

import argparse
import json
import re
import sys
import time
import unicodedata
from pathlib import Path

import requests
from bs4 import BeautifulSoup

BASE_URL = "https://cses.fi"
LOGIN_URL = f"{BASE_URL}/login"
LIST_URL = f"{BASE_URL}/problemset/list/"
TASK_URL = f"{BASE_URL}/problemset/task/{{task_id}}"
RESULT_URL = f"{BASE_URL}/problemset/result/{{result_id}}/"

USER_AGENT = "cses-scraper/1.0 (uso pessoal - baixa meus proprios submits)"

LANGUAGE_EXTENSIONS = {
    "c++": "cpp",
    "c": "c",
    "python3": "py",
    "pypy3": "py",
    "python2": "py",
    "java": "java",
    "javascript": "js",
    "rust": "rs",
    "go": "go",
    "c#": "cs",
}


def slugify(text):
    text = unicodedata.normalize("NFKD", text).encode("ascii", "ignore").decode("ascii")
    text = text.lower().strip()
    text = re.sub(r"[^a-z0-9]+", "-", text)
    return text.strip("-") or "sem-nome"


def guess_extension(language):
    if not language:
        return "txt"
    key = language.lower()
    for name, ext in LANGUAGE_EXTENSIONS.items():
        if key.startswith(name):
            return ext
    return "txt"


def is_cpp(language):
    return guess_extension(language) == "cpp"


def clean_code(text):
    """Normaliza quebras de linha (CRLF/CR -> LF), remove espacos no fim de
    cada linha e linhas em branco sobrando no inicio/fim do arquivo."""
    text = text.replace("\r\n", "\n").replace("\r", "\n")
    lines = [line.rstrip() for line in text.split("\n")]
    while lines and lines[0] == "":
        lines.pop(0)
    while lines and lines[-1] == "":
        lines.pop()
    return "\n".join(lines) + "\n"


class CsesSession:
    def __init__(self, login, password, delay, verbose, debug_dir=None):
        self.login_name = login
        self.password = password
        self.delay = delay
        self.verbose = verbose
        self.debug_dir = debug_dir
        self.session = requests.Session()
        self.session.headers.update({"User-Agent": USER_AGENT})

    def log(self, msg):
        if self.verbose:
            print(f"  [{self.login_name}] {msg}", file=sys.stderr)

    def _get(self, url):
        time.sleep(self.delay)
        resp = self.session.get(url)
        resp.raise_for_status()
        return resp

    def _post(self, url, data):
        time.sleep(self.delay)
        resp = self.session.post(url, data=data)
        resp.raise_for_status()
        return resp

    def login(self):
        resp = self._get(LOGIN_URL)
        soup = BeautifulSoup(resp.text, "html.parser")
        token_input = soup.find("input", {"name": "csrf_token"})
        if token_input is None:
            self.log("nao encontrei csrf_token na pagina de login")
            return False
        csrf_token = token_input.get("value", "")

        resp = self._post(
            LOGIN_URL,
            data={"csrf_token": csrf_token, "nick": self.login_name, "pass": self.password},
        )
        return self._is_logged_in(resp.text)

    def _is_logged_in(self, html):
        soup = BeautifulSoup(html, "html.parser")
        account_link = soup.find("a", {"class": "account"})
        if account_link is None:
            return False
        href = account_link.get("href", "")
        return href != "/login" and "/login" not in href

    def get_solved_tasks(self):
        """Retorna lista de dicts {id, name, category} para tarefas 100% resolvidas."""
        resp = self._get(LIST_URL)
        soup = BeautifulSoup(resp.text, "html.parser")

        solved = []
        category = None
        for el in soup.select(".content h2, .content ul.task-list"):
            if el.name == "h2":
                category = el.get_text(strip=True)
                continue
            if el.name == "ul":
                for li in el.select("li.task"):
                    link = li.find("a")
                    if link is None:
                        continue
                    score_span = li.find("span", class_="task-score")
                    classes = score_span.get("class", []) if score_span else []
                    if "full" not in classes:
                        continue
                    match = re.search(r"/problemset/task/(\d+)", link.get("href", ""))
                    if not match:
                        continue
                    solved.append(
                        {
                            "id": match.group(1),
                            "name": link.get_text(strip=True),
                            "category": category or "outros",
                        }
                    )
        return solved

    def get_last_accepted_submission(self, task_id, max_checks=15):
        """Retorna dict {id, language, code} da melhor submissao ACCEPTED, ou None.

        A barra lateral da pagina da tarefa (div.nav.sidebar), na secao
        "Your submissions", lista os resultados do usuario logado como
        <a href="/problemset/result/<id>/">data <span class="task-score icon
        full|zero">...</a>, do mais recente para o mais antigo. O proprio
        span ja indica se aquele resultado foi ACCEPTED (classe "full"),
        entao nao e preciso abrir cada resultado so pra descobrir o veredito.

        Entre os ACCEPTED, C++ tem prioridade absoluta (mais recente C++
        ACCEPTED vence, mesmo que exista um ACCEPTED mais novo em outra
        linguagem). Se nao houver nenhum ACCEPTED em C++, cai para o
        ACCEPTED mais recente em qualquer outra linguagem.
        """
        resp = self._get(TASK_URL.format(task_id=task_id))
        soup = BeautifulSoup(resp.text, "html.parser")

        sidebar = soup.find("div", class_="nav sidebar") or soup.find(
            "div", class_=lambda c: c and "sidebar" in c.split()
        )
        # fallback: se nao achou a sidebar por classe, procura em toda a
        # pagina (mais tolerante a mudanca de layout)
        search_root = sidebar if sidebar is not None else soup

        entries = []
        for a in search_root.find_all("a", href=re.compile(r"/problemset/result/\d+")):
            match = re.search(r"/problemset/result/(\d+)", a["href"])
            if not match:
                continue
            span = a.find("span", class_="task-score")
            classes = span.get("class", []) if span else []
            entries.append({"id": match.group(1), "full": "full" in classes})

        accepted_entries = [e for e in entries if e["full"]][:max_checks]

        self.log(
            f"task {task_id}: sidebar {'achada' if sidebar is not None else 'NAO achada'}, "
            f"{len(entries)} resultado(s) listado(s), {len(accepted_entries)} ACCEPTED"
        )

        if not entries and self.debug_dir:
            self._dump_debug(f"task_{task_id}.html", resp.text)

        fallback = None
        for entry in accepted_entries:
            info = self._fetch_result(entry["id"])
            if info is None:
                self.log(f"  resultado {entry['id']}: nao consegui extrair codigo")
                continue
            self.log(f"  resultado {entry['id']}: lang={info['language']} ({len(info['code'])} chars)")
            if fallback is None:
                fallback = info
            if is_cpp(info["language"]):
                return info
        if fallback is not None:
            self.log(f"  sem ACCEPTED em C++, usando '{fallback['language']}' (resultado {fallback['id']})")
        return fallback

    def _dump_debug(self, filename, html):
        self.debug_dir.mkdir(parents=True, exist_ok=True)
        path = self.debug_dir / filename
        path.write_text(html or "", encoding="utf-8")
        self.log(f"  html de debug salvo em {path}")

    def _fetch_result(self, result_id):
        resp = self._get(RESULT_URL.format(result_id=result_id))
        if self.debug_dir:
            self._dump_debug(f"result_{result_id}.html", resp.text)
        soup = BeautifulSoup(resp.text, "html.parser")

        language = None
        for row in soup.find_all("tr"):
            cells = row.find_all(["th", "td"])
            if len(cells) >= 2 and "language" in cells[0].get_text(strip=True).lower():
                language = cells[1].get_text(strip=True)
                break

        pre_blocks = soup.find_all("pre")
        code = None
        if pre_blocks:
            code = max(pre_blocks, key=lambda p: len(p.get_text())).get_text()

        if code is None:
            return None

        return {"id": result_id, "language": language, "code": code}


def load_accounts(path):
    with open(path, "r", encoding="utf-8") as f:
        accounts = json.load(f)
    if not isinstance(accounts, list) or not accounts:
        raise ValueError("accounts.json deve ser uma lista nao vazia de {login, password}")
    for acc in accounts:
        if "login" not in acc or "password" not in acc:
            raise ValueError(f"conta invalida, faltando login/password: {acc}")
    return accounts


def write_solution(output_dir, category, task_name, code, extension):
    folder = output_dir / slugify(category)
    folder.mkdir(parents=True, exist_ok=True)
    slug = slugify(task_name)
    path = folder / f"{slug}.{extension}"

    # remove arquivos de outras linguagens do mesmo problema, pra nunca
    # sobrar problema.py e problema.cpp coexistindo
    for other in folder.glob(f"{slug}.*"):
        if other != path:
            other.unlink()

    path.write_text(clean_code(code), encoding="utf-8")
    return path


def process_account(account, output_dir, delay, verbose, debug_dir=None, only_task=None):
    login_name = account["login"]
    print(f"== Conta: {login_name} ==")
    client = CsesSession(login_name, account["password"], delay, verbose, debug_dir)

    if not client.login():
        print(f"  falha no login de '{login_name}', pulando conta", file=sys.stderr)
        return {"written": 0, "no_ac_found": 0, "errors": 0}

    solved = client.get_solved_tasks()
    print(f"  {len(solved)} problema(s) resolvido(s) encontrados")

    if only_task:
        solved = [t for t in solved if t["id"] == only_task]
        print(f"  filtrando para task {only_task}: {len(solved)} encontrada(s)")

    stats = {"written": 0, "no_ac_found": 0, "errors": 0}
    for task in solved:
        try:
            submission = client.get_last_accepted_submission(task["id"])
        except requests.RequestException as e:
            print(f"  [erro] {task['name']}: {e}", file=sys.stderr)
            stats["errors"] += 1
            continue

        if submission is None:
            print(f"  [aviso] nao achei submit ACCEPTED para '{task['name']}' (id {task['id']})")
            stats["no_ac_found"] += 1
            continue

        ext = guess_extension(submission["language"])
        path = write_solution(output_dir, task["category"], task["name"], submission["code"], ext)
        client.log(f"{task['name']} -> {path}")
        stats["written"] += 1

    print(
        f"  concluido: {stats['written']} escrito(s), "
        f"{stats['no_ac_found']} sem AC encontrado, {stats['errors']} erro(s)"
    )
    return stats


def main():
    parser = argparse.ArgumentParser(description="Baixa os ultimos submits ACCEPTED do CSES")
    parser.add_argument(
        "--accounts",
        type=Path,
        default=Path(__file__).parent / "accounts.json",
        help="JSON com lista de {login, password}, em ordem de prioridade (default: accounts.json)",
    )
    default_output = Path(__file__).resolve().parents[2] / "biblioteca" / "classics"
    parser.add_argument(
        "--output",
        type=Path,
        default=default_output,
        help=f"pasta de saida, organizada por tema (default: {default_output})",
    )
    parser.add_argument(
        "--delay",
        type=float,
        default=0.4,
        help="segundos de espera entre requests, para nao sobrecarregar o CSES (default: 0.4)",
    )
    parser.add_argument("-v", "--verbose", action="store_true", help="log detalhado por tarefa")
    parser.add_argument(
        "--debug",
        action="store_true",
        help="salva HTML das paginas problematicas em output/_debug para diagnostico",
    )
    parser.add_argument(
        "--only-task",
        help="processa so essa task id (para teste rapido)",
    )
    args = parser.parse_args()

    if not args.accounts.exists():
        print(f"arquivo de contas nao encontrado: {args.accounts}", file=sys.stderr)
        print(
            "crie um accounts.json (veja accounts.example.json) com a lista de logins/senhas,",
            "em ordem de prioridade (o primeiro sobrescreve os demais).",
            file=sys.stderr,
        )
        sys.exit(1)

    accounts = load_accounts(args.accounts)
    args.output.mkdir(parents=True, exist_ok=True)
    debug_dir = (args.output / "_debug") if args.debug else None

    # processa da menor para a maior prioridade: quem roda por ultimo
    # sobrescreve os arquivos, entao a primeira conta da lista "vence".
    for account in reversed(accounts):
        process_account(
            account, args.output, args.delay, args.verbose, debug_dir, args.only_task
        )

    print(f"\npronto. solucoes em: {args.output}")


if __name__ == "__main__":
    main()
