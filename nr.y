%debug

%code requires {
  #include "table.h"
}

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int yylex(void);
    int yyerror(const char *s);

    enum ESTADOS {
        E_TITULO = 0,
        E_DECLARACOES = 1,
        E_ATO = 2,
        E_CENA = 3,
        E_DIALOGO = 4,
    };
    int estado = 0;

    int DEBUG_BISON = 1;
    // Funções auxiliares
    char* concatena(char* a, char* b) {
        size_t len = strlen(a) + strlen(b) + 2;
        char* res = (char *) malloc(len);
        snprintf(res, len, "%s %s", a, b);
        free(a);
        return res;
    }
%}

%union {
    char* texto;
}

/* Declaração dos tokens */
%token <texto> ATO CENA SAEM ENTRAM TODOS SOMAR SUBTRAIR DIVIDIR MULTIPLICAR
%token <texto> INICIO FIM ABRE_COLCHETES FECHA_COLCHETES
%token <texto> ABRE_PARENTESES FECHA_PARENTESES
%token <texto> NUMERO VIRGULA TOKEN ADJETIVO_POSITIVO

%nterm <texto> declaracao declaracaoInicio dialogo inicioDialogo ato cena bloco texto palavra

%%

/* Regras da gramática */

programa:
    | programa bloco
    ;

bloco:
    ato
    | cena
    | dialogo
    | declaracao
    | alteracaoElenco
    ;

texto:
    palavra
    | texto palavra {
        // if (DEBUG_BISON) {
        //     printf("Concatenando: %s + %s\n", $1, $2);
        // }
        $$ = concatena($1, $2);
    }
    ;


palavra:
    TOKEN { $$ = strdup($1); }
    | ADJETIVO_POSITIVO { $$ = strdup($1); }
    | SOMAR { $$ = strdup($1); }
    | ENTRAM { $$ = strdup($1); }
    | SAEM { $$ = strdup($1); }
    | TODOS { $$ = strdup($1); }
    ;


declaracao:
    declaracaoInicio texto FIM {
        printf("Declaração: %s\n", $1);
    }

declaracaoInicio:
    texto VIRGULA {
        if (estado == E_DECLARACOES) {
            printf("Início da declaração\n");
            if (DEBUG_BISON) {
                printf("Criando variável: %s\n", $1);
            }
            add_symbol($1, INT_VAR);
        }
        $$ = $1;
    }

alteracaoElenco:
    ABRE_COLCHETES texto FECHA_COLCHETES {
        if (estado == E_CENA) {
            printf("Alteração de elenco: %s\n", $2);
        } if (estado == E_DIALOGO) {
            printf("Alteração de elenco: %s\n", $2);
        } else {
            printf("Alteração de elenco fora de contexto, estado atual: %d\n", estado);
        }
    }

dialogo:
    inicioDialogo texto FIM {
        printf("Diálogo: %s\n", $2);
        switch (estado) {
            case E_TITULO:
                printf("Título\n");
                break;
            case E_DECLARACOES:
                printf("Declarações\n");
                break;
            case E_DIALOGO:
                printf("Diálogo\n");
                break;
            case E_CENA:
                printf("Cena\n");
                break;
            case E_ATO:
                printf("Ato\n");
                break;
            default:
                yyerror("Estado desconhecido no diálogo\n");
                break;
        }
    }
    // Precisa ser mais importante do que texto com vírgula
    | inicioDialogo texto VIRGULA texto FIM {
        switch (estado) {
            case E_TITULO:
                printf("Título com vírgula: %s\n", $3);
                break;
            case E_DECLARACOES:
                printf("Declarações com vírgula: %s\n", $3);
                break;
            case E_DIALOGO:
                printf("Diálogo com vírgula: %s\n", $3);
                if (DEBUG_BISON) {
                    printf("Alterando variável: %s\n", $3);
                }
                set_int_value($3, get_int_value($3) + 1);// alterar para o valor do segundo texto
                break;
            case E_CENA:
                printf("Cena com vírgula: %s\n", $3);
                break;
            case E_ATO:
                printf("Ato com vírgula: %s\n", $3);
                break;
            default:
                yyerror("Estado desconhecido no diálogo com vírgula\n");
                break;
        }
        $$ = $1;
    }

inicioDialogo:   
    texto INICIO {
        if (estado == E_TITULO) {
            printf("Título: %s\n", $1);
            estado = E_DECLARACOES;
        } 
        else if (estado == E_DIALOGO) {
            printf("Apenas um texto\n");
        } else if (estado == E_CENA) {
            printf("Início do diálogo: %s\n", $1);
            estado = E_DIALOGO;
        } else {            
            yyerror("Diálogo fora de contexto\n");
        }
    }

ato: 
    ATO {
        if (estado == E_DECLARACOES) {
            printf("Ato: %s\n", $1);
            estado = E_ATO;
        } else if (estado != E_ATO) {
            yyerror("Ato fora de contexto");
        }
    }

cena: 
    CENA {
        if (estado == E_ATO) {
            printf("Cena: %s\n", $1);
            estado = E_CENA;
        } else if (estado == E_CENA) {
            // faz algo
        } else {
            printf("Cena fora de contexto, estado atual: %d", estado);
        }
    }


%%

int main() {
    yyparse();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Erro: %s\n", s);
    return 0;
}
