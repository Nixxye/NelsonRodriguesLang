%{
    #include <stdio.h>
    #include <stdlib.h>

    int yylex(void);
    int yyerror(const char *s);
%}


/* Declaração dos tokens */
%token ATO SAEM TODOS SOMAR SUBTRAIR DIVIDIR MULTIPLICAR
%token INICIO FIM ABRE_COLCHETES FECHA_COLCHETES
%token ABRE_PARENTESES FECHA_PARENTESES
%token NUMERO VIRGULA TOKEN

/* Precedência (caso vá trabalhar com expressões aritméticas) */
%left SOMAR SUBTRAIR
%left MULTIPLICAR DIVIDIR

%%

/* Regras da gramática */

programa:
    | programa bloco
    ;

bloco:
      ato
    /* | cena */
    | comando
    ;

ato:
    ATO { printf("Ato encontrado\n"); }
    ;

/* cena:
    CENA { printf("Cena encontrada\n"); }
    ; */

comando:
      SAEM { printf("Saem\n"); }
    | TODOS { printf("Todos\n"); }
    | expressao FIM { printf("Expressão finalizada\n"); }
    ;

expressao:
      NUMERO
    | expressao SOMAR expressao
    | expressao SUBTRAIR expressao
    | expressao MULTIPLICAR expressao
    | expressao DIVIDIR expressao
    ;

%%

int main() {
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Erro: %s\n", s);
    return 0;
}
