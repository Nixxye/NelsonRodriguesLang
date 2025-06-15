%{
    #include <stdio.h>
    #include <stdlib.h>

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
%}

%union {
    char* texto;
}

/* Declaração dos tokens */
%token <texto> ATO CENA SAEM ENTRAM TODOS SOMAR SUBTRAIR DIVIDIR MULTIPLICAR
%token <texto> INICIO FIM ABRE_COLCHETES FECHA_COLCHETES
%token <texto> ABRE_PARENTESES FECHA_PARENTESES
%token <texto> NUMERO VIRGULA TOKEN ADJETIVO_POSITIVO

%nterm <texto> declaracao declaracaoInicio dialogo inicioDialogo ato cena bloco texto

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
    TOKEN
    | ADJETIVO_POSITIVO
    | SOMAR
    | ENTRAM
    | SAEM
    | TODOS
    | texto SAEM
    | texto ENTRAM
    | texto SOMAR
    | texto ADJETIVO_POSITIVO
    | texto TOKEN
    ;

declaracao:
    declaracaoInicio texto FIM {
        printf("Declaração: %s\n", $1);
    }

declaracaoInicio:
    texto VIRGULA {
        if (estado == E_DECLARACOES) {
            printf("Início da declaração\n");
        }
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
