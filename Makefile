# Nome do executável
EXEC = nrparser
LLVM_EXEC = llvm_exec

# Arquivos
LEXFILE = nr.l
YACCFILE = nr.y
INPUT = program.nr
CODEGEN = LLVMgen.c
UTILS = nrUtils.c

# Flags do LLVM
LLVMFLAGS = `llvm-config --cflags --ldflags --libs core` -Wno-unused-command-line-argument

# Alvo padrão
all: $(EXEC)

# Gera o parser com bison (ativando warnings e debug)
nr.tab.c nr.tab.h: $(YACCFILE)
	bison -d -v $(YACCFILE)

# Gera o lexer com flex
lex.yy.c: $(LEXFILE) nr.tab.h
	flex $(LEXFILE)

# Compila tudo com suporte a LLVM
$(EXEC): lex.yy.c nr.tab.c $(CODEGEN) $(UTILS)
	clang++ -g -o $(EXEC) nr.tab.c lex.yy.c $(CODEGEN) $(UTILS) $(LLVMFLAGS)

# Executa o parser com o arquivo de entrada
run: $(EXEC) $(INPUT)
	./$(EXEC) < $(INPUT)

# Gera o LLVM IR e executa via Clang
run-llvm: run
	clang nrLLVM.ll -o $(LLVM_EXEC)
	./$(LLVM_EXEC)

# Limpeza
clean:
	rm -f lex.yy.c nr.tab.c nr.tab.h nr.output $(EXEC) $(LLVM_EXEC) nrLLVM.ll