%debug

%code requires {
  #include "table.h"
  #include "LLVMgen.h"
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

    char *cenarioAtual = NULL;

    int DEBUG_BISON = 1;
    // Funções auxiliares
    char* personagemDialogo = NULL; // Guarda o valor do personagem em uma fala
%}

%union {
    char* texto;
    int inteiro;
}

/* Declaração dos tokens */
%token <texto> SAEM ENTRAM TODOS SOMAR SUBTRAIR DIVIDIR MULTIPLICAR
%token <texto> INICIO FIM ABRE_COLCHETES FECHA_COLCHETES
%token <texto> ABRE_PARENTESES FECHA_PARENTESES
%token <texto> VIRGULA TOKEN ADJETIVO_POSITIVO ADJETIVO_NEGATIVO TU EH E ENTRE ARTIGO MESMO NUMERO ADICIONAR_CENARIO SUBSTITUIR_CENARIO POR NO_CENARIO MOSTRAR_CENARIO
%token <inteiro> ATO CENA 

%nterm <texto> declaracao declaracaoInicio dialogo inicioDialogo ato cena bloco texto palavra
%nterm <inteiro> adjetivos valor expressao 

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
    | declaracaoCenario
    | concatenarCenario
    | substituiCenario
    | alteracaoElenco
    ;


/* Cenários - manipulação de Strings */

declaracaoCenario:
    ABRE_PARENTESES texto VIRGULA texto FECHA_PARENTESES {
        if (estado == E_DECLARACOES) {
            add_symbol($2, STRING_VAR);
            set_string_value($2, $4);
            if (DEBUG_BISON) {
                printf("Cenário adicionado: %s = %s\n", $2, $4);
            }
            cenarioAtual = strdup($2);
        } else {
            yyerror("Declaração de cenário fora de contexto");
        }
    }

concatenarCenario:
    ADICIONAR_CENARIO INICIO texto FIM {
        if (estado != E_DECLARACOES) {
            char * valorCenario = get_string_value(cenarioAtual);

            if (valorCenario == NULL) {
                yyerror("Nenhum cenário atual definido");
            } else {
                char* novoCenario = concatena(valorCenario, $3);
                set_string_value(cenarioAtual, novoCenario);
                // free(novoCenario);
                if (DEBUG_BISON) {
                    printf("Cenário atualizado: %s\n", cenarioAtual);
                }
            }
        } else {
            yyerror("Adição de cenário fora de contexto");
        }
    }

substituiCenario:
    SUBSTITUIR_CENARIO texto POR texto NO_CENARIO FIM{
        if (estado != E_DECLARACOES) {
            char * valorCenario = get_string_value(cenarioAtual);
            if (valorCenario == NULL) {
                yyerror("Nenhum cenário atual definido");
            } else {
                char* novoValorCenario = substituir_ocorrencias(valorCenario, $2, $4);
                set_string_value(cenarioAtual, novoValorCenario);
                printf("Novo cenário: %s\n", get_string_value(cenarioAtual));
            }
        } else {
            yyerror("Substituição de cenário fora de contexto");
        }
    }

texto:
    palavra { 
        $$ = strdup($1);
    }
    | texto NUMERO {
        // if (DEBUG_BISON) {
        //     printf("Concatenando: %s + %s\n", $1, $2);
        // }
        $$ = concatena($1, $2);
    }
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
    | ADJETIVO_NEGATIVO { $$ = strdup($1); }
    | ARTIGO { $$ = strdup($1); }
    | ENTRE { $$ = strdup($1); }
    | SOMAR { $$ = strdup($1); }
    | ENTRAM { $$ = strdup($1); }
    | SAEM { $$ = strdup($1); }
    | TODOS { $$ = strdup($1); }
    | E { $$ = strdup($1); }
    | SUBSTITUIR_CENARIO { $$ = strdup($1); }
    | POR { $$ = strdup($1); }
    | NO_CENARIO { $$ = strdup($1); }
    ;

adjetivos:
    ADJETIVO_POSITIVO { 
        $$ = 1;
    }
    | ADJETIVO_NEGATIVO {
        $$ = -1;
    }
    | TOKEN {
        $$ = 0;
    }
    | adjetivos ADJETIVO_POSITIVO {
        if (DEBUG_BISON) {
            printf("Adjetivo positivo concatenado: %s\n", $2);
        }
        $$ = $1 + 1;
    }
    | adjetivos ADJETIVO_NEGATIVO {
        if (DEBUG_BISON) {
            printf("Adjetivo negativo concatenado: %s\n", $2);
        }
        $$ = $1 - 1;
    }
    | adjetivos TOKEN {
        $$ = $1;
    }
    | adjetivos ENTRE {
        $$ = $1;
    }

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

valor:
    NUMERO  {
        if (DEBUG_BISON) {
            printf("Valor numérico: %d\n", atoi($1));
        }
        $$ = atoi($1);
    } 
    | TU MESMO { 
        if (DEBUG_BISON) {
            printf("Valor de 'tu mesmo': %d\n", get_int_value(personagemDialogo));
        }
        if (personagemDialogo == NULL) {
            yyerror("Variável 'tu mesmo' não definida");
            $$ = 0; // Valor padrão
        } else {
            $$ = get_int_value(personagemDialogo);
        }
    }
    | texto {
        if (DEBUG_BISON) {
            printf("Valor de texto: %d\n", get_int_value($1));
        }
        $$ = get_int_value($1); //O texto todo é uma variável
    }



expressao:
    ARTIGO SOMAR ENTRE valor E valor {
        if (DEBUG_BISON) {
            printf("Expressão de soma: %s\n", $2);
        }
        $$ = $4 + $6; // Exemplo de operação
    }
    | ARTIGO SUBTRAIR ENTRE valor E valor {
        if (DEBUG_BISON) {
            printf("Expressão de subtração: %s\n", $2);
        }
        $$ = $4 - $6;
    }
    | ARTIGO MULTIPLICAR ENTRE valor E valor {
        if (DEBUG_BISON) {
            printf("Expressão de multiplicação: %s\n", $2);
        }
        $$ = $4 * $6;
    }
    | ARTIGO DIVIDIR ENTRE valor E valor {
        if (DEBUG_BISON) {
            printf("Expressão de divisão: %s\n", $2);
        }
        if ($6 == 0) {
            yyerror("Divisão por zero");
            $$ = 0; // Valor padrão em caso de erro
        } else {
            $$ = $4 / $6;
        }
    }

dialogo:
    inicioDialogo MOSTRAR_CENARIO {
        if (DEBUG_BISON) {
            printf("Cenário atual: %s\n", get_string_value(cenarioAtual));
        }
        gerar_print_string(cenarioAtual);
    }
    | inicioDialogo texto FIM {
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
    | inicioDialogo texto VIRGULA TU EH adjetivos FIM {
        switch (estado) {
            case E_TITULO:
                printf("Título com vírgula: %s\n", $3);
                break;
            case E_DECLARACOES:
                printf("Declarações com vírgula: %s\n", $3);
                break;
            case E_DIALOGO:
                printf("Diálogo com vírgula: %s\n", $2);
                if (DEBUG_BISON) {
                    // printf("Tabela de símbolos:\n");
                    // print_symbols();
                    printf("Alterando variável: %s\n", $2);
                    printf("    Valor atual: %d\n", get_int_value($2));
                }
                // pegar valor do texto !!!
                set_int_value($2, get_int_value($2) + $6);
                if (DEBUG_BISON) {
                    printf("    Novo valor: %d\n", get_int_value($2));
                }
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
    | inicioDialogo texto VIRGULA TU EH {
        personagemDialogo = $2;
    } expressao FIM {
        if (DEBUG_BISON) {
            printf("Valor do personagem antes do diálogo: %d\n", get_int_value(personagemDialogo));
        }
        set_int_value(personagemDialogo, $7);
        if (DEBUG_BISON) {
            printf("Valor do personagem após diálogo: %d\n", get_int_value(personagemDialogo));
        }
        free(personagemDialogo);
        personagemDialogo = NULL;
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
            printf("Ato: %d\n", $1);
            estado = E_ATO;
        } else if (estado != E_ATO) {
            yyerror("Ato fora de contexto");
        }
    }

cena: 
    CENA {
        if (estado == E_ATO) {
            printf("Cena: %d\n", $1);
            estado = E_CENA;
        } else if (estado == E_CENA) {
            // faz algo
        } else {
            printf("Cena fora de contexto, estado atual: %d", estado);
        }
    }


%%

int main() {
    iniciar_codegen();
    yyparse();
    finalizar_codegen();
    return 0;
}

int yyerror(const char *s) {
    fprintf(stderr, "Erro: %s\n", s);
    return 0;
}
