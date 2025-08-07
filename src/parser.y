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
    void yyerror(const char *s);

    enum ESTADOS {
        E_DECLARACOES = 0,
        E_ATO = 1,
        E_CENA = 2,
    };
    int estado = 0;

    char *cenarioAtual = NULL;

    int DEBUG_BISON = 1;
    // Funções auxiliares
    char* personagemDialogo = NULL; // Guarda o valor do personagem em uma fala
    char* personagemQueFala = NULL; // Guarda o valor do personagem que tá falando
    char* ultimoPersonagemQueFala = NULL; // Guarda o valor do último personagem que falou
    char* personagemVoce = NULL; // guarda o valor do ultimo personagem que falou e diferente do atual
    int result = 0; // guarda o resultado do if
    int n_erros = 0; // flag global para guardar o número de erros
    extern int yylineno; // Variável global para o número da linha atual
    // TODO: FAZER OS YYABORTS ENCERRAREM O PROGRAMA E NÃO APENAS O PARSER

    void atualiza_personagemVoce(){
        if (!ultimoPersonagemQueFala) {
            return;
        }
        if (!personagemVoce || strcmp(ultimoPersonagemQueFala, personagemQueFala) != 0) {
            if (DEBUG_BISON) {
                printf("Atualizando personagemVoce: %s\n", ultimoPersonagemQueFala);
            }
            personagemVoce = ultimoPersonagemQueFala;
        }
        ultimoPersonagemQueFala = personagemQueFala;
    }

    void yyerror(const char *str)
    {
        fprintf(stderr, "[O PONTO, em sussurros]: Roteiro falho na linha %d: %s\n", yylineno, str);
        n_erros++;
        exit(1);
    }
%}



%union {
    char* texto;
    int inteiro;
    LLVMValueRef llmValueRef; // Referência para valores LLM
}


/* Declaração dos tokens */
%token <texto> FINALIZACAO FACA ENDIF ENQUANTO_COMECO ENQUANTO_FIM MAIOR MAIOR_IGUAL MENOR MENOR_IGUAL IGUAL NAO FOR EU SE SAEM ENTRAM TODOS SOMAR SUBTRAIR DIVIDIR MULTIPLICAR
%token <texto> INICIO FIM SIM INTERROGACAO ABRE_COLCHETES FECHA_COLCHETES VOLTAR_CENARIO VOCE
%token <texto> ABRE_PARENTESES FECHA_PARENTESES
%token <texto> VIRGULA SERA TOKEN ADJETIVO_POSITIVO ADJETIVO_NEGATIVO TU EH E ENTRE ARTIGO MESMO NUMERO ADICIONAR_CENARIO SUBSTITUIR_CENARIO POR NO_CENARIO MOSTRAR_CENARIO MOSTRA_VALOR LE_VALOR GUARDE INTERIOR LEMBRE
%token <text> IF_MOSTRA_VALOR IF_LE_VALOR O_TAMANHO_DE
%token <inteiro> ATO CENA 

%nterm <texto> declaracao declaracaoInicio dialogo inicioDialogo ato cena bloco texto palavra personagem
%nterm <inteiro> adjetivos if_sentenca while
%nterm <llmValueRef> condicao valor expressao

%type <texto> nome_variavel_int nome_cenario nome_questionamento nome_personagem valor_string

%nonassoc MAIOR MAIOR_IGUAL MENOR MENOR_IGUAL IGUAL
%left FOR
%left NAO

// Precedência para operadores aritméticos
%left SOMAR SUBTRAIR
%left MULTIPLICAR DIVIDIR
%locations // Habilita rastreamento de localização de tokens
%define parse.error custom
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
    ato {
        if (estado == E_DECLARACOES || estado == E_CENA) {
            estado = E_ATO;
        } else {
            if (DEBUG_BISON) {
                char msg[256];
                sprintf(msg, "ERRO SEMÂNTICO (Ato fora de contexto, estado atual: %d).", estado);
                yyerror(msg);
            }
        }
    }
    | cena {
        if (estado == E_ATO || estado == E_CENA) {
            estado = E_CENA;
        } else {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Cena fora de contexto, estado atual: %d).", estado);
            yyerror(msg);
        }
    }
    | dialogo { 
        if (estado == E_CENA) {

        } else {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Diálogo fora de contexto, estado atual: %d).", estado);
            yyerror(msg);
        }
    }
    | declaracao { 
        if (estado == E_DECLARACOES) {

        } else {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Declaração fora de contexto, estado atual: %d).", estado);
            yyerror(msg);
        }
    }
    | declaracaoCenario {
        if (estado == E_DECLARACOES) {
            
        } else {
            // Cria a mensagem de erro
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Declaracao de cenario fora de contexto, estado atual: %d).", estado);
            yyerror(msg);
        }
    }
    | declaracaoQuestionamento {
        if (estado == E_DECLARACOES || estado == E_CENA) {

        } else {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Declaração de questionamento fora de contexto, estado atual: %d).", estado);
            yyerror(msg);
        }
    }
    | concatenarCenario {
        if (estado == E_CENA) {
            
        } else {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Adição de cenário fora de contexto, estado atual: %d).", estado);
            yyerror(msg);
        }
    }
    | substituiCenario {
        if (estado == E_CENA) {
        } else {
            yyerror("ERRO SEMÂNTICO (Substituição de cenário fora de contexto, estado atual: %d).");
        }
    }
    | trocarCenario {
        if (estado == E_CENA) {
            
        } else {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Troca de cenário fora de contexto, estado atual: %d)", estado);
            yyerror(msg);
        }
    }
    | alteracaoElenco {
        if(estado == E_ATO || estado == E_CENA){
            
        } else {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Alteração de elenco fora de contexto, estado atual: %d)", estado);
            yyerror(msg);
        }
    }
    | if_sentenca {
        if (estado == E_CENA) {

        } else {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Sentença 'if' fora de contexto, estado atual: %d)", estado);
            yyerror(msg);
        }
    }
    | if_bloco {
        if (estado == E_CENA) {

        } else {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Bloco 'if' fora de contexto, estado atual: %d)", estado);
            yyerror(msg);
        }
    }
    | while {
        if (estado == E_CENA) {

        } else {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Laço 'while' fora de contexto, estado atual: %d)", estado);
            yyerror(msg);
        }
    }
    | saida
    ;

saida:
    FINALIZACAO {
        gerar_exit();
    }


/* Cenários - manipulação de Strings */

declaracaoCenario:
    ABRE_PARENTESES nome_cenario VIRGULA valor_string FECHA_PARENTESES {
        if (DEBUG_BISON) {
            printf("Declaração de cenário: %s com valor inicial: %s\n", $2, $4);
        }
        add_symbol($2, STRING_VAR);
        cenarioAtual = strdup($2);
        ativar_cenario(cenarioAtual);

        Symbol* sym = get_symbol(cenarioAtual);
        LLVMValueRef nova_str_ptr = gerar_criar_string($4);
        // Armazena o ponteiro na variável
        LLVMBuildStore(builder, nova_str_ptr, sym->llvm_ref);
    }

concatenarCenario:
    ADICIONAR_CENARIO INICIO valor_string FIM {
        if (cenarioAtual == NULL) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Cenário atual igual a NULL!)");
            yyerror(msg);
        } else {
            Symbol* sym = get_symbol(cenarioAtual);
            // 1. LOAD: Carrega o ponteiro atual da string
            LLVMValueRef str_atual_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "load_str");
            
            // 2. CALL: Gera a chamada para a função de concatenação
            LLVMValueRef str_nova_ptr = gerar_concatenar_string(str_atual_ptr, $3);

            // 3. STORE: Armazena o novo ponteiro de volta na variável (MUITO IMPORTANTE!)
            LLVMBuildStore(builder, str_nova_ptr, sym->llvm_ref);
            if (DEBUG_BISON) {
                printf("Cenário atualizado: %s\n", cenarioAtual);
            }
        }
    }

substituiCenario:
    SUBSTITUIR_CENARIO valor_string POR valor_string NO_CENARIO FIM{
        if (cenarioAtual == NULL) {
            yyerror("Nenhum cenário atual definido");
        } else {
            Symbol* sym = get_symbol(cenarioAtual);
            if (sym) {
                // 1. LOAD: Carrega o ponteiro atual da string
                LLVMValueRef str_atual_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "load_str");

                // 2. CALL: Gera a chamada para a função de substituição
                LLVMValueRef str_nova_ptr = gerar_substituir_string(str_atual_ptr, $2, $4);

                // 3. STORE: Armazena o novo ponteiro de volta na variável (MUITO IMPORTANTE!)
                LLVMBuildStore(builder, str_nova_ptr, sym->llvm_ref);
            }
        }
    }

trocarCenario: 
    inicioDialogo VOLTAR_CENARIO ARTIGO nome_cenario FIM {
        if (DEBUG_BISON) {
            printf("Trocando cenário para: %s\n", $4);
        }
        char *novoCenario = get_string_value($4);
        if (novoCenario == NULL) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Cenário '%s' não declarado)", $4);
            yyerror(msg);
        } else {
            cenarioAtual = strdup($4);
            ativar_cenario(cenarioAtual);
        }
    }

/* Booleanos - operações lógicas */

declaracaoQuestionamento:
    nome_questionamento INTERROGACAO NAO FIM {
        if (DEBUG_BISON) {
            printf("Declaração de questionamento negativo: %s\n", $1);
        }
        Symbol *sym = get_symbol($1);
        if (!sym) {
            add_symbol($1, BOOL_VAR);
            Symbol *sym = get_symbol($1);
            sym->llvm_ref = gerar_criar_booleano($1, 0);
        } else if (sym->type != BOOL_VAR) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Tipo incorreto para questionamento '%s' (esperado BOOL_VAR))", $1);
            yyerror(msg);
        } else {
            LLVMValueRef valor_false = LLVMConstInt(LLVMInt1Type(), 0, 0);
            gerar_set_booleano(sym->llvm_ref, valor_false);
        }
    }
    | nome_questionamento INTERROGACAO SIM FIM {
        if (DEBUG_BISON) {
            printf("Declaração de questionamento afirmativo: %s\n", $1);
        }
        Symbol *sym = get_symbol($1);
        if (!sym) {
            add_symbol($1, BOOL_VAR);
            Symbol *sym = get_symbol($1); // Colocar isso no add_symbol?
            sym->llvm_ref = gerar_criar_booleano($1, 1);
        } else if (sym->type != BOOL_VAR) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Tipo incorreto para questionamento '%s' (esperado BOOL_VAR))", $1);
            yyerror(msg);
        } else {
            LLVMValueRef valor_true = LLVMConstInt(LLVMInt1Type(), 1, 0);
            gerar_set_booleano(sym->llvm_ref, valor_true);// Inicializa como verdadeiro
        }
    }
    | nome_questionamento INTERROGACAO {
        if (DEBUG_BISON) {
            printf("Declaração de questionamento: %s\n", $1);
        }
        Symbol *sym = get_symbol($1);
        if (!sym) {
            add_symbol($1, BOOL_VAR);
            Symbol *sym = get_symbol($1); // Colocar isso no add_symbol?
            sym->llvm_ref = gerar_criar_booleano($1, 0);
        } else if (sym->type != BOOL_VAR) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Tipo incorreto para questionamento '%s' (esperado BOOL_VAR))", $1);
            yyerror(msg);
        } else {
            LLVMValueRef valor_false = LLVMConstInt(LLVMInt1Type(), 0, 0);
            gerar_set_booleano(sym->llvm_ref, valor_false);
        }
    }


texto:
    palavra { 
        $$ = strdup($1);
    }
    | texto NUMERO {
        $$ = concatena($1, $2);
    }
    | texto palavra {
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
    | texto {
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
    | adjetivos texto {
        $$ = $1;
    }
;


declaracao:
    declaracaoInicio nome_variavel_int FIM {
        if (DEBUG_BISON) {
            printf("Declaração: %s\n", $2);
        }
    }
;
declaracaoInicio:
    nome_variavel_int VIRGULA {
        if (estado == E_DECLARACOES) {
            if (DEBUG_BISON) {
                printf("Criando variável: %s\n", $1);
            }
            add_symbol($1, INT_VAR);
        }
        $$ = $1;
    }
;
personagensEntrando:
    nome_personagem {
        Symbol *sym = get_symbol($1);
        if (!sym) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Personagem não declarado '%s')", strdup($1));
            yyerror(msg);
        } else if (sym->type != INT_VAR) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Tipo incorreto para personagem '%s' (esperado INT_VAR))", strdup($1));
            yyerror(msg);
        }
        sym->active = 1;
        personagemVoce = $1; // Atualiza personagemVoce com o personagem que está entrando
    } 
    | personagensEntrando VIRGULA nome_personagem {
        Symbol *sym = get_symbol($3);
        if (!sym) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Personagem não declarado '%s')", strdup($3));
            yyerror(msg);
        } else if (sym->type != INT_VAR) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Tipo incorreto para personagem '%s' (esperado INT_VAR))", $3);
            yyerror(msg);
        }
        sym->active = 1;
        personagemVoce = $3; // Atualiza personagemVoce com o personagem que está entrando
    }
    | personagensEntrando E nome_personagem {
        Symbol *sym = get_symbol($3);
        if (!sym) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Personagem não declarado '%s')", strdup($3));
            yyerror(msg);
        } else if (sym->type != INT_VAR) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Tipo incorreto para personagem '%s' (esperado INT_VAR))", $3);
            yyerror(msg);
        }
        sym->active = 1;
        personagemVoce = $3; // Atualiza personagemVoce com o personagem que está entrando
    }
;
personagensSaindo:
    nome_personagem {
        Symbol *sym = get_symbol($1);
        if (!sym) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Personagem não declarado '%s')", strdup($1));
            yyerror(msg);
        } else if (sym->type != INT_VAR) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Tipo incorreto para personagem '%s' (esperado INT_VAR))", $1);
            yyerror(msg);
        }
        sym->active = 0;
    } 
    | personagensSaindo VIRGULA nome_personagem {
        Symbol *sym = get_symbol($3);
        if (!sym) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Personagem não declarado '%s')", strdup($3));
            yyerror(msg);
        } else if (sym->type != INT_VAR) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Tipo incorreto para personagem '%s' (esperado INT_VAR))", $3);
            yyerror(msg);
        }
        sym->active = 0;
    }
    | personagensSaindo E nome_personagem {
        Symbol *sym = get_symbol($3);
        if (!sym) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Personagem não declarado '%s')", strdup($3));
            yyerror(msg);
        } else if (sym->type != INT_VAR) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Tipo incorreto para personagem '%s' (esperado INT_VAR))", $3);
            yyerror(msg);
        }
        sym->active = 0;
    }
;
alteracaoElenco:
    ABRE_COLCHETES ENTRAM personagensEntrando FECHA_COLCHETES {
        if (DEBUG_BISON) {
            printf("Alteração de elenco: %s\n", $2);
        }
    }
    | ABRE_COLCHETES SAEM personagensSaindo FECHA_COLCHETES {
        if (DEBUG_BISON) {
            printf("Alteração de elenco: %s\n", $2);
        }
    }
    | ABRE_COLCHETES TODOS SAEM FECHA_COLCHETES {
        if (DEBUG_BISON) {
            printf("Todos os personagens estão inativos\n");
        }
        desativar_todos_personagens();
    }
;
personagem:
    EU {
        $$ = personagemQueFala;
    }
    | VOCE {
        $$ = personagemVoce;
    }
    | nome_personagem {
        $$ = $1;
    }
;

valor:
    NUMERO {
        if (DEBUG_BISON) {
            printf("Valor numérico: %d\n", atoi($1));
        }
        $$ = LLVMConstInt(LLVMInt32Type(), atoi($1), 0);
    }
    | TU MESMO {
        if (personagemDialogo == NULL) {
            yyerror("ERRO SEMÂNTICO (Variável 'tu mesmo' não definida)");
            $$ = LLVMConstInt(LLVMInt32Type(), 0, 0);
        } else {
            Symbol *sym = get_symbol(personagemDialogo);
            if (!sym || sym->type != INT_VAR) { // INT_VAR é uma pilha
                yyerror("ERRO SEMÂNTICO (Variável 'tu mesmo' inválida ou não declarada)");
                $$ = LLVMConstInt(LLVMInt32Type(), 0, 0);
            } else {
                if (DEBUG_BISON) {
                    printf("Valor de 'tu mesmo': %s\n", sym->name);
                }
                // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
                LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr_tu");
                // 2. Gera a chamada ao runtime para obter o valor do topo
                $$ = gerar_peek_pilha(pilha_ptr);
            }
        }
    }
    | EU {
        if (personagemQueFala == NULL) {
            yyerror("ERRO SEMÂNTICO (Variável 'eu' não definida)");
            $$ = LLVMConstInt(LLVMInt32Type(), 0, 0);
        } else {
            Symbol *sym = get_symbol(personagemQueFala);
            if (!sym || sym->type != INT_VAR) {
                yyerror("ERRO SEMÂNTICO (Variável 'eu' inválida ou não declarada)");
                $$ = LLVMConstInt(LLVMInt32Type(), 0, 0);
            } else {
                // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
                LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr_eu");
                // 2. Gera a chamada ao runtime para obter o valor do topo
                $$ = gerar_peek_pilha(pilha_ptr);
            }
        }
    }
    | VOCE {
        if (personagemVoce == NULL) {
            yyerror("ERRO SEMÂNTICO (Variável 'voce' não definida)");
            $$ = LLVMConstInt(LLVMInt32Type(), 0, 0);
        } else {
            Symbol *sym = get_symbol(personagemVoce);
            if (!sym || sym->type != INT_VAR) {
                yyerror("ERRO SEMÂNTICO (Variável 'voce' inválida ou não declarada)");
                $$ = LLVMConstInt(LLVMInt32Type(), 0, 0);
            } else {
                // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
                LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr_voce");
                // 2. Gera a chamada ao runtime para obter o valor do topo
                $$ = gerar_peek_pilha(pilha_ptr);
            }
        }
    }
    | O_TAMANHO_DE nome_variavel_int {
        // $2 é o nome da pilha (const char*)
        const char* nome_pilha = $2;
        Symbol* sym = get_symbol(nome_pilha);

        // Valida se a variável existe e é uma pilha
        if (!sym || sym->type != INT_VAR) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Variável de pilha inválida ou não declarada: %s).", nome_pilha);
            yyerror(msg);
            $$ = LLVMConstInt(LLVMInt32Type(), 0, 0); // Retorna 0 em caso de erro
        } else {
            // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
            LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr_size");

            // 2. Gera a chamada ao runtime para obter o tamanho da pilha
            $$ = gerar_obter_tamanho_pilha(pilha_ptr);
        }
    }
    | nome_variavel_int {
        Symbol *sym = get_symbol($1);
        if (!sym || sym->type != INT_VAR) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Variável de pilha inválida ou não declarada: %s).", $1);
            yyerror(msg);
            $$ = LLVMConstInt(LLVMInt32Type(), 0, 0);
        } else {
            // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
            LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr_var");
            // 2. Gera a chamada ao runtime para obter o valor do topo
            $$ = gerar_peek_pilha(pilha_ptr);
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
    SE condicao VIRGULA personagem SERA expressao {
        // $2 é a condição (LLVMValueRef do tipo i1)
        // $4 é o nome da variável de pilha (const char*)
        // $6 é o novo valor para o topo (LLVMValueRef do tipo i32)

        // 1. Cria os blocos básicos para os caminhos do if.
        LLVMBasicBlockRef then_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "if_then");
        LLVMBasicBlockRef merge_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "if_merge");

        // 2. Gera o desvio condicional.
        // Se a condição ($2) for true, pula para 'then_block', senão, pula para 'merge_block'.
        LLVMBuildCondBr(builder, $2, then_block, merge_block);

        // 3. Posiciona o builder para começar a escrever o código do bloco 'then'.
        // Este código só será executado se a condição for verdadeira.
        LLVMPositionBuilderAtEnd(builder, then_block);
        {
            // Lógica para atualizar o topo da pilha
            const char* nome_pilha = $4;
            LLVMValueRef novo_valor = $6;
            Symbol* sym = get_symbol(nome_pilha);

            if (sym && sym->type == INT_VAR) {
                // Carrega o ponteiro para a estrutura da pilha
                LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr");
                // Gera a chamada ao runtime para atualizar o topo
                gerar_set_topo_pilha(pilha_ptr, novo_valor);
            } else {
                yyerror("ERRO SEMÂNTICO (Variável de destino no 'SE' não é uma pilha válida)");
            }
            
            // Ao final do bloco 'then', pula incondicionalmente para o bloco de continuação.
            LLVMBuildBr(builder, merge_block);
        }

        // 4. Move o builder para o bloco 'merge' para as próximas instruções do programa.
        LLVMPositionBuilderAtEnd(builder, merge_block);
    }
    | SE condicao VIRGULA personagem IF_MOSTRA_VALOR {
        // --- Padrão de 'if' em LLVM ---
        // 1. Cria os blocos para os caminhos 'then' (se verdadeiro) e 'merge' (continuação).
        LLVMBasicBlockRef then_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "if_then");
        LLVMBasicBlockRef merge_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "if_merge");

        // 2. Gera o desvio condicional baseado na condição ($2).
        LLVMBuildCondBr(builder, $2, then_block, merge_block);

        // 3. Posiciona o builder para preencher o bloco 'then'.
        LLVMPositionBuilderAtEnd(builder, then_block);
        {
            const char *nome = $4;
            Symbol *sym = get_symbol(nome);
            if (!sym || sym->type != INT_VAR) {
                yyerror("ERRO SEMÂNTICO (Variável inválida ou não declarada no SE)");
            } else if (!sym->active) {
                char msg[256];
                sprintf(msg, "ERRO SEMÂNTICO (Variável %s não está ativa no SE)", sym->name);
                yyerror(msg);
            } else {
                gerar_print_topo_pilha(nome);
                // atualiza_personagemVoce();
            }

            // 4. No final do bloco 'then', pula para o bloco 'merge'.
            LLVMBuildBr(builder, merge_block);
        }
        // 5. Move o builder para o bloco 'merge' para continuar o resto do programa.
        LLVMPositionBuilderAtEnd(builder, merge_block);
    }
    | SE condicao VIRGULA personagem IF_LE_VALOR {
        LLVMBasicBlockRef then_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "if_then");
        LLVMBasicBlockRef merge_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "if_merge");
        LLVMBuildCondBr(builder, $2, then_block, merge_block);

        LLVMPositionBuilderAtEnd(builder, then_block);
        {
            const char *nome = $4;
            Symbol *sym = get_symbol(nome);
            if (!sym || sym->type != INT_VAR) {
                char msg[256];
                sprintf(msg, "ERRO SEMÂNTICO (Variável %s inválida ou não declarada no SE)", nome);
                yyerror(msg);
            } else if (!sym->active) {
                char msg[256];
                sprintf(msg, "ERRO SEMÂNTICO (Variável %s não está ativa no SE)", sym->name);
                yyerror(msg);
            } else {
                gerar_leitura_inteiro(nome);
                // atualiza_personagemVoce();
            }
            LLVMBuildBr(builder, merge_block);
        }
        LLVMPositionBuilderAtEnd(builder, merge_block);
    }

if_bloco:
    SE condicao VIRGULA texto INICIO
    {
        ControleFluxo controle;
        controle.then_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "if_then");
        controle.merge_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "if_merge");
        controle.else_block = controle.merge_block;

        LLVMBuildCondBr(builder, $2, controle.then_block, controle.merge_block);

        // Empilha a estrutura de controlo
        pilha_push(&pilhaControleFluxo, controle);

        // Move o builder para o bloco 'then'
        LLVMPositionBuilderAtEnd(builder, controle.then_block);
    }
    bloco ENDIF
    {
        // Pega a estrutura de controlo do topo da pilha e remove-a.
        ControleFluxo controle = pilha_pop(&pilhaControleFluxo);

        // Cria um desvio incondicional do final do bloco 'then' para o 'merge',
        // mas apenas se o bloco atual ainda não tiver uma instrução de terminação.
        LLVMBasicBlockRef current_block = LLVMGetInsertBlock(builder);
        LLVMValueRef last_instruction = LLVMGetLastInstruction(current_block);

        // Um bloco não tem terminador se estiver vazio (last_instruction == NULL)
        // ou se a sua última instrução não for um terminador.
        if (last_instruction == NULL || !LLVMIsATerminatorInst(last_instruction)) {
            LLVMBuildBr(builder, controle.merge_block);
        }

        // Move o builder para o bloco 'merge' para continuar a geração de código.
        LLVMPositionBuilderAtEnd(builder, controle.merge_block);
    }
;

while:
    ENQUANTO_COMECO
    {
        // WHILE
        ControleFluxo controle;
        controle.else_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "while_cond");
        controle.then_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "while_body");
        controle.merge_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "while_merge");

        // 1. Pula para o bloco da condição para o primeiro teste.
        LLVMBuildBr(builder, controle.else_block);

        // 2. Empilha a estrutura para uso futuro.
        pilha_push(&pilhaControleFluxo, controle);

        // 3. Posiciona o builder no bloco da CONDIÇÃO.
        // É aqui que o código da regra 'condicao' será gerado.
        LLVMPositionBuilderAtEnd(builder, controle.else_block);
    }
    condicao VIRGULA texto INICIO
    {
        // 1. Pega a estrutura de controle (sem remover da pilha).
        ControleFluxo controle = pilha_peek(&pilhaControleFluxo);

        // 2. A condição ($3) acabou de ser processada. Agora geramos o desvio.
        // Se for true -> vai para o corpo. Se for false -> sai do laço.
        LLVMBuildCondBr(builder, $3, controle.then_block, controle.merge_block);

        // 3. Move o builder para o corpo do laço para gerar o código do 'bloco'.
        LLVMPositionBuilderAtEnd(builder, controle.then_block);
    }
    bloco texto ENQUANTO_FIM FIM
    {
        // 1. Pega a estrutura de controle e remove da pilha.
        ControleFluxo controle = pilha_pop(&pilhaControleFluxo);

        // 2. No final do corpo do laço, cria um pulo de volta para o teste da condição.
        LLVMBuildBr(builder, controle.else_block);

        // 3. Move o builder para o bloco de continuação.
        LLVMPositionBuilderAtEnd(builder, controle.merge_block);
    }
    | FACA VIRGULA texto INICIO
    {
        // DO WHILE
        ControleFluxo controle;
        controle.then_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "do_body");
        controle.else_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "do_cond");
        controle.merge_block = LLVMAppendBasicBlockInContext(contexto, funcao_main, "do_merge");

        // Começamos no corpo
        LLVMBuildBr(builder, controle.then_block);
        LLVMPositionBuilderAtEnd(builder, controle.then_block);

        pilha_push(&pilhaControleFluxo, controle);
    }
    bloco ENQUANTO_COMECO condicao VIRGULA texto FIM
    {
        ControleFluxo controle = pilha_pop(&pilhaControleFluxo);

        LLVMBasicBlockRef current_block = LLVMGetInsertBlock(builder);
        LLVMValueRef last_instruction = LLVMGetLastInstruction(current_block);
        if (last_instruction == NULL || !LLVMIsATerminatorInst(last_instruction)) {
            // No final do corpo, pula para o bloco de teste da condição.
            LLVMBuildBr(builder, controle.else_block);
        }

        // Posiciona o builder no bloco da condição.
        LLVMPositionBuilderAtEnd(builder, controle.else_block);

        // Se a condição ($8) for true, volta para o corpo; senão, sai do laço.
        LLVMBuildCondBr(builder, $8, controle.then_block, controle.merge_block);
        
        // Move o builder para o bloco de continuação.
        LLVMPositionBuilderAtEnd(builder, controle.merge_block);

    }

condicao:
    expressao FOR MAIOR expressao {
            $$ = LLVMBuildICmp(builder, LLVMIntSGT, $1, $4, "cmpgt");
        }
    | expressao FOR MAIOR_IGUAL expressao {
            $$ = LLVMBuildICmp(builder, LLVMIntSGE, $1, $4, "cmpge");
        }
    | expressao FOR MENOR expressao {
            $$ = LLVMBuildICmp(builder, LLVMIntSLT, $1, $4, "cmplt");
        }
    | expressao FOR MENOR_IGUAL expressao {
            $$ = LLVMBuildICmp(builder, LLVMIntSLE, $1, $4, "cmple");
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
    }
    | texto {
        Symbol* sym = get_symbol($1);
        if (sym && sym->type == BOOL_VAR) {
            // Chama a função para gerar a instrução 'load'.
            // $$ agora contém o valor i1 (true/false) da variável.
            $$ = gerar_get_booleano(sym->llvm_ref);
        } else {
            yyerror("ERRO SEMÂNTICO (Variável de condição não é um booleano válido).");
        }
    }


dialogo:
    inicioDialogo MOSTRAR_CENARIO {
        if (DEBUG_BISON) {
        }
        gerar_print_string(cenarioAtual);
        atualiza_personagemVoce();
    }
    | inicioDialogo if_sentenca FIM {
        if (DEBUG_BISON) {
            printf("if sentença\n");
        }
        atualiza_personagemVoce();
    }
    | inicioDialogo nome_personagem FIM {
        if (DEBUG_BISON) {
            printf("Diálogo: %s\n", $2);
        }
        atualiza_personagemVoce();
    }
    | inicioDialogo texto VIRGULA TU EH expressao FIM {
        if (DEBUG_BISON) {
            printf("Diálogo com expressão: %s\n", $2);
        }
        personagemDialogo = strdup($2);
        Symbol *sym = get_symbol(personagemDialogo);
        if (!sym || sym->type != INT_VAR) { // INT_VAR é uma pilha
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Variável %s inválida ou não declarada", personagemDialogo);
            yyerror(msg);
        } else if (!sym->active) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Variável %s não está ativa", personagemDialogo);
            yyerror(msg);
        } else {

            // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
            LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr");

            // Atualiza o valor no topo da pilha
            gerar_set_topo_pilha(pilha_ptr, $6);
        }
        free(personagemDialogo);
        personagemDialogo = NULL;
        atualiza_personagemVoce();
    }
    | inicioDialogo texto INTERROGACAO {
        if (DEBUG_BISON) {
            printf("Diálogo: %s\n", $2);

        }
        atualiza_personagemVoce();
    }
    | inicioDialogo texto VIRGULA TU EH adjetivos FIM {
        personagemDialogo = strdup($2);



        // LLVM: gerar incremento personagem = personagem + $6

        Symbol *sym = get_symbol(personagemDialogo);
        if (!sym || sym->type != INT_VAR) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO ( Variável %s inválida ou não declarada", personagemDialogo);
            yyerror(msg);
        } else if (!sym->active) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO ( Variável %s não está ativa", personagemDialogo);
            yyerror(msg);
        } else {

            // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
            LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr");

            // 2. Lê o valor atual do topo da pilha
            LLVMValueRef valorAtual = gerar_peek_pilha(pilha_ptr);

            // 3. Converte o valor do adjetivo (int) para um LLVMValueRef
            LLVMValueRef incremento = LLVMConstInt(LLVMInt32Type(), $6, 0);

            // 4. Calcula o novo valor
            LLVMValueRef soma = LLVMBuildAdd(builder, valorAtual, incremento, "tmp_sum");

            // 5. Atualiza o valor no topo da pilha
            gerar_set_topo_pilha(pilha_ptr, soma);
        }

        free(personagemDialogo);
        personagemDialogo = NULL;
        atualiza_personagemVoce();
    }
    | inicioDialogo texto VIRGULA MOSTRA_VALOR FIM {
        Symbol *sym = get_symbol($2);
        if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Variável %s inválida ou não declarada).", $2);
            yyerror(msg);
        }  else if (!sym->active) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Variável %s não está ativa).", sym->name);
            yyerror(msg);
        }
        gerar_print_topo_pilha($2);
        atualiza_personagemVoce();
    }
    | inicioDialogo nome_personagem VIRGULA LE_VALOR FIM {
        // Scanf
        if (DEBUG_BISON) {
            printf("Lendo valor de %s\n", $2);
        }
        Symbol *sym = get_symbol($2);
        if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Variável %s inválida ou não declarada).", $2);
            yyerror(msg);
        }  else if (!sym->active) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Variável %s não está ativa).", sym->name);
            yyerror(msg);
        }
        gerar_leitura_inteiro($2);
        atualiza_personagemVoce();
    }
    | inicioDialogo nome_personagem VIRGULA GUARDE texto INTERIOR FIM {
        Symbol *sym = get_symbol($2);
        if (!sym || sym->type != INT_VAR) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Variável %s não é uma pilha de inteiros ou não foi declarada).", $2);
            yyerror(msg);
        } else {
            // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
            LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr");

            // 2. Cria uma constante LLVM para o valor 0
            LLVMValueRef zero_const = LLVMConstInt(LLVMInt32Type(), 0, 0);
            
            // 3. Gera a chamada para a função de push do runtime com o valor 0
            gerar_push_pilha(pilha_ptr, zero_const);
        }
    }
    | inicioDialogo nome_personagem VIRGULA LEMBRE texto FIM {
        Symbol *sym = get_symbol($2);
        if (!sym || sym->type != INT_VAR) {
            char msg[256];
            sprintf(msg, "ERRO SEMÂNTICO (Variável %s não é uma pilha de inteiros ou não foi declarada).", $2);
            yyerror(msg);
        } else {
            // 1. Carrega o ponteiro para a estrutura da pilha (PilhaInt*)
            LLVMValueRef pilha_ptr = LLVMBuildLoad2(builder, sym->llvm_type, sym->llvm_ref, "pilha_ptr");
            
            gerar_pop_pilha(pilha_ptr);
        }
    }


inicioDialogo:   
    texto INICIO {
        personagemQueFala = $1;
        if (DEBUG_BISON) {
            printf("Início do diálogo: %s\n", $1);
        }
    }

ato: 
    ATO {
        if (DEBUG_BISON) {
            printf("Ato: %d\n", $1);
        }
    }

cena: 
    CENA {
        if (DEBUG_BISON) {
            printf("Cena: %d\n", $1);
        }
    }

nome_variavel_int:
    texto           { $$ = $1; }
    ;

nome_cenario:
    texto           { $$ = $1; }
    ;

nome_questionamento:
    texto           { $$ = $1; }
    ;

nome_personagem:
    texto           { $$ = $1; printf("Nome personagem: %s\n", $1); }
    ;

valor_string:
    texto           { $$ = $1; }
    ;


%%

int main() {
    printf("\n\n--- Iniciando a peça: Compilador de Nelson Rodrigues Lang ---\n\n");
    printf("Entram o LLVM e o Bison...\n\n");
    iniciar_codegen();

    yyparse();

    printf("\n");

    if (n_erros) {
        printf("ERRO: Compilação falhou devido a erros.\n");
        return 1;
    }

    finalizar_codegen();
    return 0;
}
// https://www.gnu.org/software/bison/manual/html_node/Syntax-Error-Reporting-Function.html
static int
yyreport_syntax_error (const yypcontext_t *ctx) {
    int token = yypcontext_token (ctx);
    fprintf(stderr, "[DIRETOR]: (ERRO SINTÁTICO na linha %d).\n", yylineno);
    n_erros++;
    return 0; // Retorna 0 para tentar recuperação, ou 1 para parar.
}