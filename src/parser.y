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

    int DEBUG_BISON = 1;
    // Funções auxiliares
    char* personagemDialogo = NULL; // Guarda o valor do personagem em uma fala
    char* personagemQueFala = NULL; // Guarda o valor do personagem que tá falando
    int result = 0; // guarda o resultado do if
    // TODO: FAZER OS YYABORTS ENCERRAREM O PROGRAMA E NÃO APENAS O PARSER

%}

%union {
    // Felipe e Hyon: https://github.com/FelipecSanto/DisciplinaCompiladores/blob/main/ProjetoCompilador/compiler/parser.y

    struct {
        LLVMBasicBlockRef cond_bb;
        LLVMBasicBlockRef body_bb;
        LLVMBasicBlockRef after_bb;
    } WhileBlocks; // Estrutura para blocos de while
    char* texto;
    int inteiro;
    LLVMValueRef llmValueRef; // Referência para valores LLM
}

/* Declaração dos tokens */
%token <texto> FACA ENDIF ENQUANTO_COMECO ENQUANTO_FIM MAIOR MENOR IGUAL NAO FOR ENTAO EU SE SAEM ENTRAM TODOS SOMAR SUBTRAIR DIVIDIR MULTIPLICAR
%token <texto> INICIO FIM SIM INTERROGACAO ABRE_COLCHETES FECHA_COLCHETES VOLTAR_CENARIO
%token <texto> ABRE_PARENTESES FECHA_PARENTESES
%token <texto> VIRGULA TOKEN ADJETIVO_POSITIVO ADJETIVO_NEGATIVO TU EH E ENTRE ARTIGO MESMO NUMERO ADICIONAR_CENARIO SUBSTITUIR_CENARIO POR NO_CENARIO MOSTRAR_CENARIO MOSTRA_VALOR LE_VALOR
%token <inteiro> ATO CENA 

%nterm <texto> declaracao declaracaoInicio dialogo inicioDialogo ato cena bloco texto palavra
%nterm <inteiro> adjetivos if_sentenca while
%nterm <llmValueRef> condicao valor expressao
%type <WhileBlocks> while_aux
%%

/* Regras da gramática */

programa:
    | programa bloco
    ;

bloco:
    instrucao                   {  }
  | bloco instrucao            {  }
  ;

instrucao:
        ato
    | cena
    | dialogo
    | declaracao
    | declaracaoCenario
    | declaracaoQuestionamento
    | concatenarCenario
    | substituiCenario
    | trocarCenario
    | alteracaoElenco
    | if_sentenca 
    | if_bloco
    | while
    | personagensEntrando
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
            ativar_cenario(cenarioAtual);
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
/* Booleanos - operações lógicas */

trocarCenario: 
    inicioDialogo VOLTAR_CENARIO ARTIGO texto FIM {
        if (estado == E_DECLARACOES) {
            yyerror("Troca de cenário fora de contexto");
            YYABORT;
        } else {
            if (DEBUG_BISON) {
                printf("Trocando cenário para: %s\n", $4);
            }
            char *novoCenario = get_string_value($4);
            if (novoCenario == NULL) {
                yyerror("Cenário não declarado");
                YYABORT;
            } else {
                cenarioAtual = strdup($4);
                ativar_cenario(cenarioAtual);
            }
        }
    }
declaracaoQuestionamento:
    texto INTERROGACAO NAO FIM {
        if (DEBUG_BISON) {
            printf("Declaração de questionamento negativo: %s\n", $1);
        }
        Symbol *sym = get_symbol($1);
        if (!sym) {
            add_symbol($1, BOOL_VAR);
        } else if (sym->type != BOOL_VAR) {
            yyerror("Tipo incorreto para questionamento (esperado BOOL_VAR)");
            YYABORT;
        }
        set_bool_value($1, 0); // Inicializa como falso
    }
    | texto INTERROGACAO SIM FIM {
        if (DEBUG_BISON) {
            printf("Declaração de questionamento afirmativo: %s\n", $1);
        }
        Symbol *sym = get_symbol($1);
        if (!sym) {
            add_symbol($1, BOOL_VAR);
        } else if (sym->type != BOOL_VAR) {
            yyerror("Tipo incorreto para questionamento (esperado BOOL_VAR)");
            YYABORT;
        }
        set_bool_value($1, 1); // Inicializa como verdadeiro
    }
    | texto INTERROGACAO {
        if (DEBUG_BISON) {
            printf("Declaração de questionamento: %s\n", $1);
        }
        Symbol *sym = get_symbol($1);
        if (!sym) {
            add_symbol($1, BOOL_VAR);
        } else if (sym->type != BOOL_VAR) {
            yyerror("Tipo incorreto para questionamento (esperado BOOL_VAR)");
            YYABORT;
        }
        set_bool_value($1, 0); // Inicializa como falso
    }


texto:
    palavra { 
        $$ = strdup($1);
    }
    | texto NUMERO {
        //  if (DEBUG_BISON) {
        //      printf("Concatenando: %s + %s\n", $1, $2);
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

personagensEntrando:
    texto {
        Symbol *sym = get_symbol($1);
        if (!sym) {
            printf("Personagem não declarado: %s", $1);
            YYABORT;
        } else if (sym->type != INT_VAR) {
            yyerror("Tipo incorreto para personagem (esperado INT_VAR)");
            YYABORT;
        }
        sym->active = 1;
    } 
    | personagensEntrando VIRGULA texto {
        Symbol *sym = get_symbol($3);
        if (!sym) {
            printf("Personagem não declarado: %s", $3);
            YYABORT;
        } else if (sym->type != INT_VAR) {
            yyerror("Tipo incorreto para personagem (esperado INT_VAR)");
            YYABORT;
        }
        sym->active = 1;
    }
    | personagensEntrando E texto {
        Symbol *sym = get_symbol($3);
        if (!sym) {
            printf("Personagem não declarado: %s", $3);
            YYABORT;
        } else if (sym->type != INT_VAR) {
            yyerror("Tipo incorreto para personagem (esperado INT_VAR)");
            YYABORT;
        }
        sym->active = 1;
    }
personagensSaindo:
    texto {
        Symbol *sym = get_symbol($1);
        if (!sym) {
            printf("Personagem não declarado: %s", $1);
            YYABORT;
        } else if (sym->type != INT_VAR) {
            yyerror("Tipo incorreto para personagem (esperado INT_VAR)");
            YYABORT;
        }
        sym->active = 0;
    } 
    | personagensSaindo VIRGULA texto {
        Symbol *sym = get_symbol($3);
        if (!sym) {
            printf("Personagem não declarado: %s", $3);
            YYABORT;
        } else if (sym->type != INT_VAR) {
            yyerror("Tipo incorreto para personagem (esperado INT_VAR)");
            YYABORT;
        }
        sym->active = 0;
    }
    | personagensSaindo E texto {
        Symbol *sym = get_symbol($3);
        if (!sym) {
            printf("Personagem não declarado: %s", $3);
            YYABORT;
        } else if (sym->type != INT_VAR) {
            yyerror("Tipo incorreto para personagem (esperado INT_VAR)");
            YYABORT;
        }
        sym->active = 0;
    }

alteracaoElenco:
    ABRE_COLCHETES ENTRAM personagensEntrando FECHA_COLCHETES {
        if (estado == E_CENA) {
            if (DEBUG_BISON) {
                printf("Alteração de elenco: %s\n", $2);
            }
        } else if (estado == E_DIALOGO) {
            if (DEBUG_BISON) {
                printf("Alteração de elenco: %s\n", $2);
            }
        } else {
            printf("Alteração de elenco fora de contexto, estado atual: %d\n", estado);
        }
    }
    | ABRE_COLCHETES SAEM personagensSaindo FECHA_COLCHETES {
        if (estado == E_CENA) {
            if (DEBUG_BISON) {
                printf("Alteração de elenco: %s\n", $2);
            }
        } else if (estado == E_DIALOGO) {
            if (DEBUG_BISON) {
                printf("Alteração de elenco: %s\n", $2);
            }
        } else {
            printf("Alteração de elenco fora de contexto, estado atual: %d\n", estado);
        }
    }
    | ABRE_COLCHETES TODOS SAEM FECHA_COLCHETES {
        if (DEBUG_BISON) {
            printf("Todos os personagens estão inativos\n");
        }
        // Ativa todos os personagens
        desativar_todos_personagens();
    }

valor:
    NUMERO {
        if (DEBUG_BISON) {
            printf("Valor numérico: %d\n", atoi($1));
        }
        $$ = LLVMConstInt(LLVMInt32Type(), atoi($1), 0);
    }
  | TU MESMO {
        if (personagemDialogo == NULL) {
            yyerror("Variável 'tu mesmo' não definida");
            $$ = LLVMConstInt(LLVMInt32Type(), 0, 0);
        } else {
            if (DEBUG_BISON) {
                // printf("Valor de 'tu mesmo': %d\n", get_int_value(personagemDialogo));
            }
            Symbol *sym = get_symbol(personagemDialogo);
            if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
                yyerror("Variável 'tu mesmo' inválida ou não declarada");
                $$ = LLVMConstInt(LLVMInt32Type(), 0, 0);
            } else {
                $$ = LLVMBuildLoad2(builder, LLVMInt32Type(), sym->llvm_ref, "load_tu");
            }
        }
    }
  | EU {
        if (personagemQueFala == NULL) {
            yyerror("Variável 'eu' não definida");
            $$ = LLVMConstInt(LLVMInt32Type(), 0, 0);
        } else {
            if (DEBUG_BISON) {
                // printf("Valor de 'eu': %d\n", get_int_value(personagemQueFala));
            }
            Symbol *sym = get_symbol(personagemQueFala);
            if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
                yyerror("Variável 'eu' inválida ou não declarada");
                $$ = LLVMConstInt(LLVMInt32Type(), 0, 0);
            } else {
                $$ = LLVMBuildLoad2(builder, LLVMInt32Type(), sym->llvm_ref, "load_eu");
            }
        }
    }
  | texto {
        if (DEBUG_BISON) {
            printf("Valor de variável: %s\n", $1);
        }
        Symbol *sym = get_symbol($1);
        if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
            printf("Variável inválida ou não declarada: %s\n", $1);
            $$ = LLVMConstInt(LLVMInt32Type(), 0, 0);
        } else {
            $$ = LLVMBuildLoad2(builder, LLVMInt32Type(), sym->llvm_ref, "load_var");
        }
    };


expressao:
    valor {
        $$ = $1; // valor já retorna LLVMValueRef
    }
  | ARTIGO SOMAR ENTRE valor E valor {
        if (DEBUG_BISON) printf("Expressão de soma\n");
        $$ = LLVMBuildAdd(builder, $4, $6, "addtmp");
    }
  | ARTIGO SUBTRAIR ENTRE valor E valor {
        if (DEBUG_BISON) printf("Expressão de subtração\n");
        $$ = LLVMBuildSub(builder, $4, $6, "subtmp");
    }
  | ARTIGO MULTIPLICAR ENTRE valor E valor {
        if (DEBUG_BISON) printf("Expressão de multiplicação\n");
        $$ = LLVMBuildMul(builder, $4, $6, "multmp");
    }
  | ARTIGO DIVIDIR ENTRE valor E valor {
        if (DEBUG_BISON) printf("Expressão de divisão\n");

        // Divisão por zero em tempo de compilação não pode ser detectada aqui
        $$ = LLVMBuildSDiv(builder, $4, $6, "divtmp");
    };


if_sentenca:
    SE condicao VIRGULA texto expressao{
        if (DEBUG_BISON) {
            printf("IF BLOCO DETECTADO\n");
            printf("Condicao do IF: %d\n", $2);
            printf("resultado do IF: %d\n", $5);
        }
    }

if_bloco:
    SE condicao VIRGULA texto INICIO bloco ENDIF{
        if (DEBUG_BISON) { 
            printf("IF BLOCO DETECTADO\n");
        }
    }

while_aux
    : {
        LLVMBasicBlockRef cond_bb = LLVMAppendBasicBlock(funcao_main, "while_cond");
        LLVMBasicBlockRef body_bb = LLVMAppendBasicBlock(funcao_main, "while_body");
        LLVMBasicBlockRef after_bb = LLVMAppendBasicBlock(funcao_main, "while_end");

        LLVMBuildBr(builder, cond_bb);
        LLVMPositionBuilderAtEnd(builder, cond_bb);

        $$.cond_bb = cond_bb;
        $$.body_bb = body_bb;
        $$.after_bb = after_bb;
    }
    ;



while:
    ENQUANTO_COMECO while_aux condicao VIRGULA texto INICIO
    {
        if (DEBUG_BISON) printf("WHILE DETECTADO\n");

        LLVMBuildCondBr(builder, $3, $2.body_bb, $2.after_bb);

        LLVMPositionBuilderAtEnd(builder, $2.body_bb);
    }
    bloco texto ENQUANTO_FIM FIM
    {
        LLVMBuildBr(builder, $2.cond_bb);
        LLVMPositionBuilderAtEnd(builder, $2.after_bb);
    }
  | FACA VIRGULA texto INICIO
    {
        if (DEBUG_BISON) printf("DO-WHILE DETECTADO\n");

        LLVMBasicBlockRef body_bb = LLVMAppendBasicBlock(funcao_main, "do_body");
        LLVMBasicBlockRef cond_bb = LLVMAppendBasicBlock(funcao_main, "do_cond");
        LLVMBasicBlockRef after_bb = LLVMAppendBasicBlock(funcao_main, "do_end");

        push_while_blocks(cond_bb, body_bb, after_bb);

        LLVMBuildBr(builder, body_bb);
        LLVMPositionBuilderAtEnd(builder, body_bb);
    }
    bloco ENQUANTO_COMECO condicao VIRGULA texto FIM
    {
        WhileBlocks blocks = pop_while_blocks();

        LLVMBuildBr(builder, blocks.cond_bb);
        LLVMPositionBuilderAtEnd(builder, blocks.cond_bb);

        LLVMValueRef cond = $7;
        LLVMBuildCondBr(builder, cond, blocks.body_bb, blocks.after_bb);

        LLVMPositionBuilderAtEnd(builder, blocks.after_bb);
    }
;


condicao:
        expressao FOR MAIOR expressao {
            $$ = LLVMBuildICmp(builder, LLVMIntSGT, $1, $4, "cmpgt");
        }
    | expressao FOR MENOR expressao {
            $$ = LLVMBuildICmp(builder, LLVMIntSLT, $1, $4, "cmplt");
        }
    | expressao FOR IGUAL expressao {
            $$ = LLVMBuildICmp(builder, LLVMIntEQ, $1, $4, "cmpeq");
        }
    | expressao NAO FOR MENOR expressao {
            $$ = LLVMBuildICmp(builder, LLVMIntSGE, $1, $5, "cmpnlt");
        }
    | expressao NAO FOR MAIOR expressao {
            $$ = LLVMBuildICmp(builder, LLVMIntSLE, $1, $5, "cmpngt");
        }
    | expressao NAO FOR IGUAL expressao {
            $$ = LLVMBuildICmp(builder, LLVMIntNE, $1, $5, "cmpneq");
        };


dialogo:
    inicioDialogo MOSTRAR_CENARIO {
        if (DEBUG_BISON) {
            printf("Cenário atual: %s\n", get_string_value(cenarioAtual));
        }
        gerar_print_string(cenarioAtual);
    }
    | inicioDialogo if_sentenca FIM {
        if (DEBUG_BISON) {
            printf("if sentença\n");
        }
    }
    | inicioDialogo texto FIM {
        if (DEBUG_BISON) {
            printf("Diálogo: %s\n", $2);
            switch (estado) {
                case E_TITULO:    printf("Título\n"); break;
                case E_DECLARACOES: printf("Declarações\n"); break;
                case E_DIALOGO:   printf("Diálogo\n"); break;
                case E_CENA:      printf("Cena\n"); break;
                case E_ATO:       printf("Ato\n"); break;
                default:
                    yyerror("Estado desconhecido no diálogo\n");
            }
        }
    }
    | inicioDialogo texto VIRGULA TU EH expressao FIM {
        personagemDialogo = strdup($2);

        if (DEBUG_BISON) {
            // printf("Valor do personagem antes do diálogo: %d\n", get_int_value(personagemDialogo));
        }

        Symbol *sym = get_symbol(personagemDialogo);
        if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
            yyerror("Variável inteira inválida ou não declarada");
            YYABORT;
        }  else if (!sym->active) {
            printf("Variável %s não está ativa\n", personagemDialogo);
            YYABORT;
        } else {
            LLVMValueRef valorAtual = LLVMBuildLoad2(builder, LLVMInt32Type(), sym->llvm_ref, "tmp_load");
            LLVMValueRef incremento = $6;
            LLVMValueRef soma = LLVMBuildAdd(builder, valorAtual, incremento, "tmp_sum");
            LLVMBuildStore(builder, soma, sym->llvm_ref);
        }

        // Atualiza na tabela de valores também (se precisar)
        // int novoValor = get_int_value(personagemDialogo) + $6;
        // set_int_value(personagemDialogo, novoValor);

        if (DEBUG_BISON) {
            // printf("Valor do personagem após diálogo: %d\n", get_int_value(personagemDialogo));
        }

        free(personagemDialogo);
        personagemDialogo = NULL;
    }
    | inicioDialogo texto VIRGULA TU EH adjetivos FIM {
        personagemDialogo = strdup($2);

        if (DEBUG_BISON) {
            // printf("Valor do personagem antes do diálogo: %d\n", get_int_value(personagemDialogo));
        }

        // LLVM: gerar incremento personagem = personagem + $6
        Symbol *sym = get_symbol(personagemDialogo);
        if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
            yyerror("Variável inteira inválida ou não declarada");
            YYABORT;
        }  else if (!sym->active) {
            printf("Variável %s não está ativa\n", personagemDialogo);
            YYABORT;
        } else {
            gerar_set_topo_pilha_llvm(module, builder, personagemDialogo, LLVMConstInt(LLVMInt32Type(), $6, 0));
        }

        // Atualiza na tabela de valores também
        // int novoValor = get_int_value(personagemDialogo) + $6;
        // set_int_value(personagemDialogo, novoValor);

        if (DEBUG_BISON) {
            // printf("Valor do personagem após diálogo: %d\n", get_int_value(personagemDialogo));
        }

        free(personagemDialogo);
        personagemDialogo = NULL;
    }

    | inicioDialogo texto VIRGULA MOSTRA_VALOR FIM {
        if (DEBUG_BISON) {
            // int val = get_int_value($2);
            // if (val == -1) {
            //     yyerror("Variável não definida");
            // } else {
            //     printf("Valor de %s: %d\n", $2, val);
            // }
        }
        Symbol *sym = get_symbol($2);
        if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
            yyerror("Variável inteira inválida ou não declarada");
            YYABORT;
        }  else if (!sym->active) {
            printf("Variável %s não está ativa\n", sym->name);
            YYABORT;
        }
        gerar_print_int($2);

    }
    | inicioDialogo texto VIRGULA LE_VALOR FIM {
        // Scanf
        if (DEBUG_BISON) {
            printf("Lendo valor de %s\n", $2);
        }
        Symbol *sym = get_symbol($2);
        if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
            yyerror("Variável inteira inválida ou não declarada");
            YYABORT;
        }  else if (!sym->active) {
            printf("Variável %s não está ativa\n", sym->name);
            YYABORT;
        }
        gerar_leitura_inteiro($2);
    }
;


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
                printf("Início do diálogo\n");
            }   
            Symbol *sym = get_symbol($1);
            if (!sym) {
                yyerror("Personagem não declarado");
                YYABORT;
            } else if (!sym->active) {
                yyerror("Personagem não está ativo");
                YYABORT;
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