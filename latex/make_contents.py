#!/usr/bin/env python3
"""
Script para escanear a biblioteca e gerar contents.txt
Baseado no script do stanfordacm
"""

import os
import shutil
from pathlib import Path


def create_code_folder(directory):
    """Cria pasta code/ e remove se já existir"""
    path = os.path.join(directory, 'code')
    if os.path.exists(path):
        shutil.rmtree(path)
    os.mkdir(path)


def normalize(s):
    """Remove acentos e caracteres especiais (versão sem dependências)"""
    import unicodedata
    
    # Normaliza usando NFD (decomposição) e remove marcas diacríticas
    normalized = unicodedata.normalize('NFD', s)
    # Remove acentos (categoria Mn = Mark, Nonspacing)
    result = ''.join(char for char in normalized if unicodedata.category(char) != 'Mn')
    
    return result


def format_name(filename):
    """Formata o nome do arquivo para exibição"""
    import re
    # Remove extensão (se houver)
    if '.' in filename:
        name = filename.rsplit('.', 1)[0]
    else:
        # Arquivo sem extensão (ex: Makefile, vimrc)
        name = filename
    
    # Remove numeração inicial (ex: "1. STL" -> "STL")
    name = re.sub(r'^\d+[\.\-_\s]*', '', name)
    
    # Substitui underscores e hífens por espaços
    name = name.replace('_', ' ').replace('-', ' ')
    return name


def write_info(f):
    """Escreve cabeçalho do arquivo contents.txt"""
    f.write('# Any line followed by a \'#\' character is ignored\n')
    f.write('# Section headings must be in square brackets\n')
    f.write('# Subsections within a section should follow the format:\n')
    f.write('# [filename within code directory][tab character \\t][subsection title]\n')
    f.write('\n')


def calculate_hash(file_path):
    """Calcula o hash do arquivo usando o script hash.sh"""
    import subprocess
    
    try:
        # Contar linhas do arquivo
        with open(file_path, 'r', encoding='utf-8') as f:
            num_lines = len(f.readlines())
        
        # Executar hash.sh
        hash_script = Path(file_path).parent.parent.parent / 'biblioteca' / 'utils' / 'hash.sh'
        if not hash_script.exists():
            return None
        
        result = subprocess.run(
            ['bash', str(hash_script), str(file_path), '1', str(num_lines)],
            capture_output=True,
            text=True,
            cwd=hash_script.parent
        )
        
        if result.returncode == 0:
            return result.stdout.strip()
    except Exception:
        pass
    
    return None


def write_folders_content(f, biblioteca_path):
    """Escaneia a biblioteca e escreve no contents.txt"""
    directory = Path(biblioteca_path).resolve()
    latex_dir = Path.cwd()
    
    create_code_folder(latex_dir)
    
    # Mapeamento de categorias
    category_names = {
        "binary-search-and-ternary-search": "Binary Search and Ternary Search",
        "bitmask": "Bitmask",
        "dp": "Dynamic Programming",
        "geometry": "Geometry",
        "graph": "Graph",
        "number-theory": "Math",
        "STL": "STL",
        "strings": "Strings",
        "structures": "Data Structures",
        "techniques": "Techniques",
        "utils": "Utils"
    }
    
    # Ignorar esses arquivos/pastas (gerais)
    ignore_files_general = ['cpp.json', 'makefile.json', 'build_library.py', 'README_BUILD.md', '.gitignore']
    
    # Ignorar nas pastas que não são utils
    ignore_files_non_utils = ignore_files_general + ['Makefile', 'vimrc', 'template.cpp']
    
    # Escanear diretórios
    for item in sorted(directory.iterdir()):
        if not item.is_dir() or item.name.startswith('.'):
            continue
        
        folder_name = item.name
        section_name = category_names.get(folder_name, folder_name.replace('-', ' ').title())
        
        # Listar arquivos no diretório
        # Para utils, incluir todos os arquivos (exceto ignorados gerais)
        # Para outras pastas, apenas .cpp (exceto template.cpp e outros ignorados)
        if folder_name == 'utils':
            code_files = sorted([f for f in item.iterdir() 
                               if f.is_file() and f.name not in ignore_files_general])
        elif folder_name == 'teoria':
            code_files = sorted([f for f in item.glob('*.tex')])
        else:
            code_files = sorted([f for f in item.glob('*.cpp') 
                               if f.name not in ignore_files_non_utils])
        
        if not code_files:
            continue
        
        f.write(f'[{section_name}]\n')
        
        for code_file in code_files:
            filename = code_file.name
            subsection_name = format_name(filename)
            
            # Calcular hash (apenas para arquivos de código)
            if not filename.endswith('.tex'):
                file_hash = calculate_hash(code_file)
                if file_hash:
                    subsection_name = f"{subsection_name} ({file_hash})"
            
            f.write(f'{filename}\t{subsection_name}\n')
            
            # Copiar arquivo para code/ com normalização
            dest_path = latex_dir / 'code' / filename
            with open(code_file, 'r', encoding='utf-8') as source:
                content = source.read()
            
            with open(dest_path, 'w', encoding='utf-8') as dest:
                if filename.endswith('.tex'):
                    dest.write(content)
                else:
                    dest.write(normalize(content))
        
        f.write('\n')


def main():
    """Função principal"""
    print("=" * 70)
    print("  📚 GERADOR DE CONTENTS.TXT")
    print("=" * 70)
    print()
    
    # Determinar caminho da biblioteca
    script_dir = Path(__file__).parent
    biblioteca_path = script_dir.parent / 'biblioteca'
    
    if not biblioteca_path.exists():
        print(f"❌ Erro: Biblioteca não encontrada em {biblioteca_path}")
        return
    
    print(f"📂 Biblioteca: {biblioteca_path}")
    print(f"📂 Diretório LaTeX: {script_dir}")
    print()
    
    # Gerar contents.txt
    contents_file = script_dir / 'contents.txt'
    
    with open(contents_file, 'w', encoding='utf-8') as f:
        write_info(f)
        write_folders_content(f, biblioteca_path)
    
    print(f"✅ Arquivo {contents_file} gerado com sucesso!")
    print(f"✅ Pasta code/ criada com {len(list((script_dir / 'code').glob('*.cpp')))} arquivos")
    print()
    print("📝 Próximo passo: execute 'python3 generate_pdf.py' para gerar o PDF")
    print()


if __name__ == "__main__":
    main()
