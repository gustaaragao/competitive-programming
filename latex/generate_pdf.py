#!/usr/bin/env python3
"""
Script para gerar PDF da biblioteca usando LaTeX
Baseado no script do stanfordacm
"""

import subprocess
import sys
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
        ("❌ Arquivo contents.txt não encontrado!")
        ("📝 Execute 'python3 make_contents.py' primeiro")
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
            tex += '\\raggedbottom\\lstinputlisting[style=%s]{%s/%s}\n' % (
                get_style(filename), CODE_DIR, filename)
            tex += '\\hrulefill\n'
        
        tex += '\n'
    
    return tex


def compile_latex():
    """Compila o PDF usando latexmk"""
    ("🔨 Compilando PDF com LaTeX...")
    ()
    
    try:
        # Verificar se latexmk está instalado
        result = subprocess.run(['which', 'latexmk'], 
                              capture_output=True, 
                              text=True)
        
        if result.returncode != 0:
            ("❌ latexmk não encontrado!")
            ("📦 Instale com:")
            ("   sudo apt-get install texlive-full")
            ("   sudo apt-get install latexmk")
            return False
        
        # Compilar PDF múltiplas vezes para gerar TOC corretamente
        # Primeira passagem: coleta informações das seções
        pdflatex_cmd = ["pdflatex", "-interaction=nonstopmode", "notebook.tex"]
        subprocess.run(pdflatex_cmd, 
                      capture_output=True, 
                      text=True,
                      encoding='utf-8',
                      errors='replace')
        
        # Segunda passagem: gera o TOC
        subprocess.run(pdflatex_cmd, 
                      capture_output=True, 
                      text=True,
                      encoding='utf-8',
                      errors='replace')
        
        # Verificar se o PDF foi gerado
        pdf_exists = Path('notebook.pdf').exists()
        
        if not pdf_exists:
            ("❌ Erro ao compilar LaTeX")
            return False
        
        return True
    
    except Exception as e:
        (f"❌ Erro ao compilar: {e}")
        return False


def main():
    """Função principal"""
    ("=" * 70)
    ("  📄 GERADOR DE PDF DA BIBLIOTECA")
    ("=" * 70)
    ()
    
    # Verificar se código está em diretório correto
    if not Path('code').exists():
        ("❌ Pasta code/ não encontrada!")
        ("📝 Execute 'python3 make_contents.py' primeiro")
        return
    
    # Verificar se notebook.tex existe
    if not Path('notebook.tex').exists():
        ("❌ Arquivo notebook.tex não encontrado!")
        ("📝 Certifique-se de que o template LaTeX existe")
        return
    
    # Ler seções
    ("📚 Lendo contents.txt...")
    sections = get_sections()
    (f"✅ {len(sections)} seções encontradas")
    ()
    
    # Gerar contents.tex
    ("📝 Gerando contents.tex...")
    tex = get_tex(sections)
    
    with open('contents.tex', 'w', encoding='utf-8') as f:
        f.write(tex)
    
    (f"✅ contents.tex gerado ({len(tex)} bytes)")
    ()
    
    # Compilar PDF
    if compile_latex():
        ()
        ("=" * 70)
        ("✅ PDF gerado com sucesso: notebook.pdf")
        ("=" * 70)
        ()
        
        # Limpar arquivos auxiliares
        ("🧹 Limpando arquivos auxiliares...")
        aux_extensions = ['.aux', '.fdb_latexmk', '.fls', '.log', '.out', '.toc']
        for ext in aux_extensions:
            aux_file = Path('notebook' + ext)
            if aux_file.exists():
                aux_file.unlink()
        ("✅ Limpeza concluída")
        ()
    else:
        ()
        ("❌ Falha ao gerar PDF")
        ("📝 Verifique se o LaTeX está instalado corretamente")
        ()


if __name__ == "__main__":
    main()
