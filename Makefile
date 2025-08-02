# Nome do executável
EXEC = nrparser
LLVM_EXEC = executavel

# Diretórios
SRC_DIR = src
INC_DIR = include

# Arquivos
LEXFILE = $(SRC_DIR)/lexer.l
YACCFILE = $(SRC_DIR)/parser.y
INPUT = programVoce.nr
CODEGEN = $(SRC_DIR)/LLVMgen.c
UTILS = $(SRC_DIR)/nrUtils.c
RUNTIME = $(SRC_DIR)/pilhaRuntime.c

# Gerados
PARSER_C = $(SRC_DIR)/parser.tab.c
PARSER_H = $(SRC_DIR)/parser.tab.h
LEX_C = $(SRC_DIR)/lex.yy.c

# Flags do LLVM
LLVMFLAGS = `llvm-config --cflags --ldflags --libs core` -Wno-unused-command-line-argument

# Compilador
CC = clang
CFLAGS = -g -I$(INC_DIR)

# Alvo padrão
all: $(EXEC)

# Gera o parser com bison
$(PARSER_C) $(PARSER_H): $(YACCFILE)
	bison -d -v -o $(PARSER_C) $(YACCFILE)

# Gera o lexer com flex
$(LEX_C): $(LEXFILE) $(PARSER_H)
	flex -o $(LEX_C) $(LEXFILE)

# Compila tudo com suporte a LLVM
$(EXEC): $(LEX_C) $(PARSER_C) $(CODEGEN) $(UTILS)
	$(CC) $(CFLAGS) -o $@ $(LEX_C) $(PARSER_C) $(CODEGEN) $(UTILS) $(LLVMFLAGS)

# Executa o parser com o arquivo de entrada
run: $(EXEC) $(INPUT)
	./$(EXEC) < $(INPUT)

# Gera e executa o LLVM IR via clang
run-llvm: run
	clang nrLLVM.ll -o $(LLVM_EXEC) $(RUNTIME)

# Limpeza
clean:
	rm -f $(SRC_DIR)/lex.yy.c $(SRC_DIR)/parser.tab.c $(SRC_DIR)/parser.tab.h \
	      $(SRC_DIR)/parser.output $(EXEC) $(LLVM_EXEC) nrLLVM.ll
