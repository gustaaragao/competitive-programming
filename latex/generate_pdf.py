#!/usr/bin/env python3
"""
Script para gerar PDF da biblioteca usando LaTeX
Baseado no script do stanfordacm
"""

import subprocess
import sys
import shutil
import os
from pathlib import Path

CODE_DIR = "code"

def get_sections():
    """Lê o arquivo contents.txt e retorna lista de seções"""
    sections = []
    section_name = None
    
    try:
        with open('contents.txt', 'r', encoding='utf-8') as f:
            for line in f:
                # Ignorar comentários
                if '#' in line:
                    line = line[:line.find('#')]
                line = line.strip()
                
                if len(line) == 0:
                    continue
                
                # Seção
                if line[0] == '[' and line[-1] == ']':
                    section_name = line[1:-1]
                    subsections = []
                    sections.append((section_name, subsections))
                # Subseção
                else:
                    tmp = line.split('\t', 1)
                    if len(tmp) == 1:
                        raise ValueError(f'Erro ao parsear subseção: {line}')
                    
                    filename = tmp[0]
                    subsection_name = tmp[1]
                    
                    if section_name is None:
                        raise ValueError('Subseção sem seção pai')
                    
                    subsections.append((filename, subsection_name))
    
    except FileNotFoundError:
        print("❌ Arquivo contents.txt não encontrado!")
        print("📝 Execute 'python3 make_contents.py' primeiro")
        sys.exit(1)
    
    return sections


def get_style(filename):
    """Determina o estilo de syntax highlighting baseado na extensão"""
    ext = filename.lower().split('.')[-1]
    if ext in ['c', 'cc', 'cpp', 'h', 'hpp']:
        return 'cpp'
    elif ext in ['java']:
        return 'java'
    elif ext in ['py']:
        return 'py'
    elif ext in ['sh', 'bash']:
        return 'bash'
    elif ext in ['md']:
        return 'md'
    else:
        return 'txt'


def texify(s):
    """Escapa caracteres especiais para LaTeX"""
    # Substituições básicas para LaTeX
    s = s.replace('\\', '\\textbackslash')
    s = s.replace('_', '\\_')
    s = s.replace('#', '\\#')
    s = s.replace('$', '\\$')
    s = s.replace('%', '\\%')
    s = s.replace('&', '\\&')
    s = s.replace('{', '\\{')
    s = s.replace('}', '\\}')
    return s


def get_tex(sections):
    """Gera o conteúdo LaTeX para contents.tex"""
    tex = ''
    
    for (section_name, subsections) in sections:
        tex += '\\section{%s}\n' % texify(section_name)
        
        for (filename, subsection_name) in subsections:
            tex += '\\subsection{%s}\n' % texify(subsection_name)
            if filename.endswith('.tex'):
                tex += '\\input{%s/%s}\n' % (CODE_DIR, filename)
            else:
                tex += '\\raggedbottom\\lstinputlisting[style=%s]{%s/%s}\n' % (
                    get_style(filename), CODE_DIR, filename)
            tex += '\\hrulefill\n'
        
        tex += '\n'
    
    return tex


def compile_latex():
    """Compila o PDF usando latexmk ou pdflatex."""
    print("🔨 Compilando PDF com LaTeX...")
    print()
    
    try:
        if shutil.which("latexmk"):
            compile_cmd = [
                "latexmk",
                "-pdf",
                "-interaction=nonstopmode",
                "-halt-on-error",
                "notebook.tex",
            ]
            runs = 1
        elif shutil.which("pdflatex"):
            compile_cmd = [
                "pdflatex",
                "-interaction=nonstopmode",
                "-halt-on-error",
                "notebook.tex",
            ]
            runs = 2
        else:
            print("❌ Nenhum compilador LaTeX encontrado!")
            print("📦 Instale com:")
            print("   sudo apt-get install texlive-full latexmk")
            return False

        pdf_path = Path("notebook.pdf")
        if pdf_path.exists():
            pdf_path.unlink()

        last_result = None
        for _ in range(runs):
            last_result = subprocess.run(
                compile_cmd,
                capture_output=True,
                text=True,
                encoding="utf-8",
                errors="replace",
            )
            if last_result.returncode != 0:
                break
        
        if last_result is None or last_result.returncode != 0 or not pdf_path.exists():
            print("❌ Erro ao compilar LaTeX")
            if last_result:
                output = (last_result.stdout or "") + (last_result.stderr or "")
                if output.strip():
                    print()
                    print(output[-4000:])
            return False
        
        return True
    
    except Exception as e:
        print(f"❌ Erro ao compilar: {e}")
        return False


def main():
    """Função principal"""
    os.chdir(Path(__file__).resolve().parent)

    print("=" * 70)
    print("  📄 GERADOR DE PDF DA BIBLIOTECA")
    print("=" * 70)
    print()
    
    # Verificar se código está em diretório correto
    if not Path('code').exists():
        print("❌ Pasta code/ não encontrada!")
        print("📝 Execute 'python3 make_contents.py' primeiro")
        return
    
    # Verificar se notebook.tex existe
    if not Path('notebook.tex').exists():
        print("❌ Arquivo notebook.tex não encontrado!")
        print("📝 Certifique-se de que o template LaTeX existe")
        return
    
    # Ler seções
    print("📚 Lendo contents.txt...")
    sections = get_sections()
    print(f"✅ {len(sections)} seções encontradas")
    print()
    
    # Gerar contents.tex
    print("📝 Gerando contents.tex...")
    tex = get_tex(sections)
    
    with open('contents.tex', 'w', encoding='utf-8') as f:
        f.write(tex)
    
    print(f"✅ contents.tex gerado ({len(tex)} bytes)")
    print()
    
    # Compilar PDF
    if compile_latex():
        print()
        print("=" * 70)
        print("✅ PDF gerado com sucesso: notebook.pdf")
        print("=" * 70)
        print()
        
        # Limpar arquivos auxiliares
        print("🧹 Limpando arquivos auxiliares...")
        aux_extensions = ['.aux', '.fdb_latexmk', '.fls', '.log', '.out', '.toc']
        for ext in aux_extensions:
            aux_file = Path('notebook' + ext)
            if aux_file.exists():
                aux_file.unlink()
        print("✅ Limpeza concluída")
        print()
    else:
        print()
        print("❌ Falha ao gerar PDF")
        print("📝 Verifique se o LaTeX está instalado corretamente")
        print()
        sys.exit(1)


if __name__ == "__main__":
    main()
