# Nome do executável
EXEC = nrparser

# Arquivos
LEXFILE = nr.l
YACCFILE = nr.y
INPUT = program.nr

# Alvo padrão
all: $(EXEC)

# Gera o parser com bison
nr.tab.c nr.tab.h: $(YACCFILE)
	bison -d $(YACCFILE)

# Gera o lexer com flex
lex.yy.c: $(LEXFILE) nr.tab.h
	flex $(LEXFILE)

# Compila tudo
$(EXEC): lex.yy.c nr.tab.c
	g++ -o $(EXEC) nr.tab.c lex.yy.c

# Executa o parser com o arquivo de entrada
run: $(EXEC) $(INPUT)
	./$(EXEC) < $(INPUT)

# Limpeza
clean:
	rm -f lex.yy.c nr.tab.c nr.tab.h $(EXEC)