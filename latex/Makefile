# Makefile para gerar PDF da biblioteca de programação competitiva
# Baseado no notebook do stanfordacm

PYTHON = python3
LATEX_DIR = /home/gustavo/competitive-programming/latex
BIBLIOTECA_DIR = /home/gustavo/competitive-programming/biblioteca

.PHONY: all contents pdf clean view help

all: clean pdf

# Gera contents.txt escaneando a biblioteca
contents:
	@echo "📚 Gerando contents.txt..."
	@cd $(LATEX_DIR) && $(PYTHON) make_contents.py

# Gera o PDF completo
pdf: contents
	@echo "📄 Gerando PDF..."
	@cd $(LATEX_DIR) && $(PYTHON) generate_pdf.py
	@echo "✅ PDF gerado: $(LATEX_DIR)/notebook.pdf"

# Limpa tudo
clean:
	@echo "🧹 Limpando arquivos gerados..."
	@cd $(LATEX_DIR) && rm -rf code/
	@cd $(LATEX_DIR) && rm -f contents.txt contents.tex
	@cd $(LATEX_DIR) && rm -f *.aux *.fdb_latexmk *.fls *.log *.out *.toc *.synctex.gz
	@echo "✅ Tudo limpo"