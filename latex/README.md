# Gerador de PDF da Biblioteca

Sistema automatizado para gerar PDF da biblioteca de códigos de programação competitiva usando LaTeX.

Baseado no [notebook do stanfordacm](https://github.com/jaehyunp/stanfordacm).

## Pré-requisitos

### 1. LaTeX

```bash
sudo apt-get install texlive-full
sudo apt-get install latexmk
```

### 2. Python

Python 3.6+ (usa apenas bibliotecas padrão)

## Como Usar

### Passo 1: Gerar contents.txt

Execute o script para escanear a biblioteca e gerar o arquivo `contents.txt`:

```bash
python3 make_contents.py
```

Isso irá:
- Escanear todos os arquivos `.cpp` da pasta `../biblioteca/`
- Criar a pasta `code/` com cópias normalizadas dos arquivos
- Gerar o arquivo `contents.txt` com a estrutura da biblioteca

### Passo 2: Gerar PDF

Execute o script para compilar o PDF:

```bash
python3 generate_pdf.py
```

Isso irá:
- Ler `contents.txt` e gerar `contents.tex`
- Compilar `notebook.tex` usando `latexmk`
- Gerar `notebook.pdf` com toda a biblioteca formatada
- Limpar arquivos auxiliares do LaTeX

### Atalhos com Makefile

```bash
make                # Executa toda a pipeline
make contents       # Gera o contents do PDF
make pdf            # Gera o PDF completo
make clean          # Limpa todos os arquivos
make help           # Mostra ajuda
```
