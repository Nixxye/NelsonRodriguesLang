# Nome do executável
LEXER = nrlexer

# Arquivos
LEXFILE = nr.l
INPUT = program.nr

# Alvo padrão
all: $(LEXER)

# Compila o lexer
$(LEXER): lex.yy.c
	g++ -o $(LEXER) lex.yy.c

# Gera o código com flex
lex.yy.c: $(LEXFILE)
	flex $(LEXFILE)

# Executa o lexer com o arquivo de entrada
run: $(LEXER) $(INPUT)
	./$(LEXER) < $(INPUT)

# Limpeza
clean:
	rm -f lex.yy.c $(LEXER)
