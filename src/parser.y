%debug

%code requires {
  #include "../include/nrUtils.h"
  #include "../include/LLVMgen.h"
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

    int DEBUG_BISON = 0;
    // Funções auxiliares
    char* personagemDialogo = NULL; // Guarda o valor do personagem em uma fala
    char* personagemQueFala = NULL; // Guarda o valor do personagem que tá falando
    int result = 0; // guarda o resultado do if
%}

%union {
    char* texto;
    int inteiro;
}

/* Declaração dos tokens */
%token <texto> MAIOR MENOR IGUAL NAO FOR ENTAO EU SE SAEM ENTRAM TODOS SOMAR SUBTRAIR DIVIDIR MULTIPLICAR
%token <texto> INICIO FIM ABRE_COLCHETES FECHA_COLCHETES
%token <texto> ABRE_PARENTESES FECHA_PARENTESES
%token <texto> VIRGULA TOKEN ADJETIVO_POSITIVO ADJETIVO_NEGATIVO TU EH E ENTRE ARTIGO MESMO NUMERO ADICIONAR_CENARIO SUBSTITUIR_CENARIO POR NO_CENARIO MOSTRAR_CENARIO MOSTRA_VALOR LE_VALOR
%token <inteiro> ATO CENA 

%nterm <texto> declaracao declaracaoInicio dialogo inicioDialogo ato cena bloco texto palavra
%nterm <inteiro> adjetivos valor expressao condicao if_sentenca

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
    | if_sentenca
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
                if (DEBUG_BISON) {
                    printf("Novo cenário: %s\n", get_string_value(cenarioAtual));
                }
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
         if (DEBUG_BISON) {
             printf("Concatenando: %s + %s\n", $1, $2);
        }
        $$ = concatena($1, $2);
    }
    | texto palavra {
        if (DEBUG_BISON) {
            printf("Concatenando: %s + %s\n", $1, $2);
        }
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
    | ENTAO { $$ = strdup($1); }
    | NAO { $$ = strdup($1); }
    | FOR { $$ = strdup($1); }
    | MAIOR { $$ = strdup($1); }
    | MENOR { $$ = strdup($1); }
    | IGUAL { $$ = strdup($1); }
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
        if (DEBUG_BISON) {
            printf("Declaração: %s\n", $2);
        }
    }

declaracaoInicio:
    texto VIRGULA {
        if (estado == E_DECLARACOES) {
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
            if (DEBUG_BISON) {
                printf("Alteração de elenco: %s\n", $2);
            }
        } if (estado == E_DIALOGO) {
            if (DEBUG_BISON) {
                printf("Alteração de elenco: %s\n", $2);
            }
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
    | EU {
        if (DEBUG_BISON) {
            printf("Valor de 'eu': %d\n", get_int_value(personagemQueFala));
        }
        if (personagemDialogo == NULL) {
            yyerror("Variável 'eu' não definida");
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
    valor
    | ARTIGO SOMAR ENTRE valor E valor {
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

if_sentenca:
    SE condicao VIRGULA ENTAO expressao{
        if (DEBUG_BISON) {
            printf("Condicao do IF: %d\n", $2);
            printf("resultado do IF: %d\n", $5);
        }
        if ($2) {
            $<inteiro>$ = $5;
        } else {
            $<inteiro>$ = 0; // valor padrão 
        }
    }

condicao:
    expressao FOR MAIOR expressao {
        $$ = $1 > $4;
    }
    | expressao FOR MENOR expressao{
        $$ = $1 < $4;
    }
    | expressao FOR IGUAL expressao{
        $$ = $1 = $4;
    }
    | expressao NAO FOR MENOR expressao{
        $$ = !($1 < $5);
    }
    | expressao NAO FOR MAIOR expressao{
        $$ = !($1 > $5);
    }
    | expressao NAO FOR IGUAL expressao{
        $$ = !($1 = $5);
    }

dialogo:
    inicioDialogo MOSTRAR_CENARIO {
        if (DEBUG_BISON) {
            printf("Cenário atual: %s\n", get_string_value(cenarioAtual));
        }
        gerar_print_string(cenarioAtual);
    }
    | inicioDialogo if_sentenca FIM{

    }
    | inicioDialogo texto FIM {
        if (DEBUG_BISON) {
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

    }
    // Precisa ser mais importante do que texto com vírgula
    | inicioDialogo texto VIRGULA TU EH adjetivos FIM {
        switch (estado) {
            case E_TITULO:
                if (DEBUG_BISON) {
                    printf("Título com vírgula: %s\n", $3);
                }
                break;
            case E_DECLARACOES:
                if (DEBUG_BISON) {
                    printf("Declarações com vírgula: %s\n", $3);
                }
                break;
            case E_DIALOGO:
                if (DEBUG_BISON) {
                    printf("Diálogo com vírgula: %s\n", $2);
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
    | inicioDialogo texto VIRGULA MOSTRA_VALOR FIM {
        if (DEBUG_BISON) {
            if (get_int_value($2) == -1) {
                yyerror("Variável não definida");
            } else {
                printf("Valor de %s: %d\n", $2, get_int_value($2));
            }
        }
        gerar_print_int($2);
    }
    | inicioDialogo texto VIRGULA LE_VALOR FIM {
        if (DEBUG_BISON) {
            printf("Lendo valor de %s\n", $2);
        }
        gerar_leitura_inteiro($2);
    }


inicioDialogo:   
    texto INICIO {
        personagemQueFala = $1;
        if (estado == E_TITULO) {
            if (DEBUG_BISON) {
                printf("Título: %s\n", $1);
            }
            estado = E_DECLARACOES;
        } 
        else if (estado == E_DIALOGO) {
            if (DEBUG_BISON) {
                printf("Apenas um texto\n");
            }    
        } else if (estado == E_CENA) {
            if (DEBUG_BISON) {
                printf("Início do diálogo: %s\n", $1);
            }
            estado = E_DIALOGO;
        } else {     
            if (DEBUG_BISON) {
                yyerror("Diálogo fora de contexto\n");
            }        
        }
    }

ato: 
    ATO {
        if (estado == E_DECLARACOES) {
            if (DEBUG_BISON) {
                printf("Ato: %d\n", $1);
            }
            estado = E_ATO;
        } else if (estado != E_ATO) {
            if (DEBUG_BISON) {
                yyerror("Ato fora de contexto");
            }
        }
    }

cena: 
    CENA {
        if (estado == E_ATO) {
            if (DEBUG_BISON) {
                printf("Cena: %d\n", $1);
            }
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