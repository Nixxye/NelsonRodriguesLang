#include "../include/LLVMgen.h"
#include <stdio.h> // Para printf em caso de erro
#include <stdlib.h> // Para exit()

LLVMModuleRef modulo;
LLVMBuilderRef builder;
LLVMContextRef contexto;
LLVMValueRef funcao_main;
LLVMBasicBlockRef bloco_main;

// Variável global para a nossa pilha.
PilhaControleFluxo pilhaControleFluxo;


// Funções para manipular a pilha
void pilha_init(PilhaControleFluxo* p) {
    p->topo = -1;
}

void pilha_push(PilhaControleFluxo* p, ControleFluxo item) {
    if (p->topo >= MAX_PILHA_ANINHAMENTO - 1) {
        fprintf(stderr, "Erro: Estouro da pilha de controlo de fluxo! Aninhamento muito profundo.\n");
        exit(1);
    }
    p->itens[++p->topo] = item;
}

ControleFluxo pilha_pop(PilhaControleFluxo* p) {
    if (p->topo < 0) {
        fprintf(stderr, "Erro: Underflow da pilha de controlo de fluxo!\n");
        exit(1);
    }
    return p->itens[p->topo--];
}

ControleFluxo pilha_peek(PilhaControleFluxo* p) {
    if (p->topo < 0) {
        fprintf(stderr, "Erro: Pilha de controlo de fluxo vazia!\n");
        exit(1);
    }
    return p->itens[p->topo];
}
void iniciar_codegen() {
    contexto = LLVMContextCreate();
    modulo = LLVMModuleCreateWithNameInContext("NelsonRodriguesLang", contexto);
    builder = LLVMCreateBuilderInContext(contexto);

    LLVMTypeRef tipo_main = LLVMFunctionType(LLVMInt32TypeInContext(contexto), NULL, 0, 0);
    funcao_main = LLVMAddFunction(modulo, "main", tipo_main);
    bloco_main = LLVMAppendBasicBlockInContext(contexto, funcao_main, "entrada");
    LLVMPositionBuilderAtEnd(builder, bloco_main);

    
}

void finalizar_codegen() {
    LLVMBuildRet(builder, LLVMConstInt(LLVMInt32TypeInContext(contexto), 0, 0));

    // Escreve o módulo em um arquivo LLVM IR
    if (LLVMPrintModuleToFile(modulo, "nrLLVM.ll", NULL) != 0) {
        fprintf(stderr, "Erro ao salvar o módulo LLVM em nrLLVM.ll\n");
    } else {
        printf("Código LLVM IR salvo em 'nrLLVM.ll'\n");
    }

    LLVMDisposeBuilder(builder);
    LLVMDisposeModule(modulo);
    LLVMContextDispose(contexto);
}


// ============================================================================
// Funções de Geração de Código para a Pilha de Inteiros
// ============================================================================

/**
 * @brief Gera o código LLVM para criar uma nova pilha e inicializá-la com o valor 0.
 *
 * Gera duas chamadas ao runtime:
 * 1. call @criar_pilha(capacidade) -> retorna ptr
 * 2. call @pilha_push(ptr, 0)
 *
 * @param capacidade_val O LLVMValueRef (i32) para a capacidade inicial da pilha.
 * @return LLVMValueRef que representa o ponteiro para a nova estrutura de pilha (PilhaInt*).
 */
LLVMValueRef gerar_criar_pilha_e_inicializar(LLVMValueRef capacidade_val) {
    if (!capacidade_val) {
        fprintf(stderr, "Erro: capacidade da pilha é nula!\n");
        exit(EXIT_FAILURE);
    }
    // --- PARTE 1: Criar a pilha vazia ---
    LLVMTypeRef pilha_type = LLVMStructCreateNamed(LLVMGetGlobalContext(), "PilhaInt");
    LLVMTypeRef pilha_ptr_type = LLVMPointerType(pilha_type, 0);

    LLVMTypeRef criar_args_types[] = { LLVMInt32Type() };
    LLVMTypeRef criar_func_type = LLVMFunctionType(pilha_ptr_type, criar_args_types, 1, 0);
    LLVMValueRef criar_func = LLVMGetNamedFunction(modulo, "criar_pilha");
    if (!criar_func) {
        criar_func = LLVMAddFunction(modulo, "criar_pilha", criar_func_type);
    }
    LLVMValueRef args_criar[] = { capacidade_val };
    LLVMValueRef nova_pilha_ptr = LLVMBuildCall2(builder, criar_func_type, criar_func, args_criar, 1, "nova_pilha_ptr");

    // --- PARTE 2: Empilhar o valor 0 na pilha recém-criada ---
    LLVMTypeRef push_args_types[] = { pilha_ptr_type, LLVMInt32Type() };
    LLVMTypeRef push_func_type = LLVMFunctionType(LLVMVoidType(), push_args_types, 2, 0);
    LLVMValueRef push_func = LLVMGetNamedFunction(modulo, "pilha_push");
    if (!push_func) {
        push_func = LLVMAddFunction(modulo, "pilha_push", push_func_type);
    }
    LLVMValueRef zero_const = LLVMConstInt(LLVMInt32Type(), 0, 0);
    LLVMValueRef args_push[] = { nova_pilha_ptr, zero_const };
    LLVMBuildCall2(builder, push_func_type, push_func, args_push, 2, "");

    // --- PARTE 3: Retornar o ponteiro para a pilha inicializada ---
    return nova_pilha_ptr;
}


/**
 * @brief Gera o código LLVM para chamar a função de runtime 'pilha_push'.
 *
 * @param pilha_ptr O LLVMValueRef que aponta para a pilha (PilhaInt*).
 * @param valor O LLVMValueRef (i32) do valor a ser empilhado.
 */
void gerar_push_pilha(LLVMValueRef pilha_ptr, LLVMValueRef valor) {
    if (!pilha_ptr) {
        fprintf(stderr, "Erro: ponteiro da pilha é nulo!\n");
        exit(EXIT_FAILURE);
    }
    if (!valor) {
        fprintf(stderr, "Erro: valor a ser empilhado é nulo!\n");
        exit(EXIT_FAILURE);
    }
    LLVMTypeRef pilha_type = LLVMStructCreateNamed(LLVMGetGlobalContext(), "PilhaInt");
    LLVMTypeRef pilha_ptr_type = LLVMPointerType(pilha_type, 0);

    LLVMTypeRef func_args_types[] = { pilha_ptr_type, LLVMInt32Type() };
    LLVMTypeRef func_type = LLVMFunctionType(LLVMVoidType(), func_args_types, 2, 0);
    LLVMValueRef func = LLVMGetNamedFunction(modulo, "pilha_push");
    if (!func) {
        func = LLVMAddFunction(modulo, "pilha_push", func_type);
    }

    LLVMValueRef args[] = { pilha_ptr, valor };
    LLVMBuildCall2(builder, func_type, func, args, 2, "");
}

/**
 * @brief Gera o código LLVM para chamar a função de runtime 'pilha_pop'.
 *
 * @param pilha_ptr O LLVMValueRef que aponta para a pilha (PilhaInt*).
 * @return LLVMValueRef (i32) com o valor retornado pela função pop.
 */
LLVMValueRef gerar_pop_pilha(LLVMValueRef pilha_ptr) {
    if (!pilha_ptr) {
        fprintf(stderr, "Erro: ponteiro da pilha é nulo!\n");
        exit(EXIT_FAILURE);
    }
    LLVMTypeRef pilha_type = LLVMStructCreateNamed(LLVMGetGlobalContext(), "PilhaInt");
    LLVMTypeRef pilha_ptr_type = LLVMPointerType(pilha_type, 0);

    LLVMTypeRef func_args_types[] = { pilha_ptr_type };
    LLVMTypeRef func_type = LLVMFunctionType(LLVMInt32Type(), func_args_types, 1, 0);
    LLVMValueRef func = LLVMGetNamedFunction(modulo, "pilha_pop");
    if (!func) {
        func = LLVMAddFunction(modulo, "pilha_pop", func_type);
    }

    LLVMValueRef args[] = { pilha_ptr };
    return LLVMBuildCall2(builder, func_type, func, args, 1, "popped_val");
}

/**
 * @brief Gera o código LLVM para chamar a função de runtime 'pilha_peek'.
 *
 * @param pilha_ptr O LLVMValueRef que aponta para a pilha (PilhaInt*).
 * @return LLVMValueRef (i32) com o valor do topo da pilha.
 */
LLVMValueRef gerar_peek_pilha(LLVMValueRef pilha_ptr) {
    if (!pilha_ptr) {
        fprintf(stderr, "Erro: ponteiro da pilha é nulo!\n");
        exit(EXIT_FAILURE);
    }
    LLVMTypeRef pilha_type = LLVMStructCreateNamed(LLVMGetGlobalContext(), "PilhaInt");
    LLVMTypeRef pilha_ptr_type = LLVMPointerType(pilha_type, 0);

    LLVMTypeRef func_args_types[] = { pilha_ptr_type };
    LLVMTypeRef func_type = LLVMFunctionType(LLVMInt32Type(), func_args_types, 1, 0);
    LLVMValueRef func = LLVMGetNamedFunction(modulo, "pilha_peek");
    if (!func) {
        func = LLVMAddFunction(modulo, "pilha_peek", func_type);
    }

    LLVMValueRef args[] = { pilha_ptr };
    return LLVMBuildCall2(builder, func_type, func, args, 1, "peeked_val");
}

void gerar_set_topo_pilha(LLVMValueRef pilha_ptr, LLVMValueRef valor_ref) {
    if (!pilha_ptr) {
        fprintf(stderr, "Erro: ponteiro da pilha é nulo!\n");
        exit(EXIT_FAILURE);
    }
    if (!valor_ref) {
        fprintf(stderr, "Erro: valor a ser definido no topo da pilha é nulo!\n");
        exit(EXIT_FAILURE);
    }
    LLVMTypeRef pilha_type = LLVMStructCreateNamed(LLVMGetGlobalContext(), "PilhaInt");
    LLVMTypeRef pilha_ptr_type = LLVMPointerType(pilha_type, 0);
    
    LLVMTypeRef func_args_types[] = { pilha_ptr_type, LLVMInt32Type() };
    LLVMTypeRef func_type = LLVMFunctionType(LLVMVoidType(), func_args_types, 2, 0);
    
    LLVMValueRef func = LLVMGetNamedFunction(modulo, "pilha_set_topo");
    if (!func) {
        func = LLVMAddFunction(modulo, "pilha_set_topo", func_type);
    }

    LLVMValueRef args[] = { pilha_ptr, valor_ref };
    LLVMBuildCall2(builder, func_type, func, args, 2, "");
}

/**
 * @brief Gera o código LLVM para chamar a função de runtime 'pilha_obter_tamanho'.
 *
 * @param pilha_ptr O LLVMValueRef que aponta para a pilha (PilhaInt*).
 * @return LLVMValueRef (i32) com o tamanho da pilha.
 */
LLVMValueRef gerar_obter_tamanho_pilha(LLVMValueRef pilha_ptr) {
    // 1. Define os tipos LLVM necessários
    LLVMTypeRef pilha_type = LLVMStructCreateNamed(LLVMGetGlobalContext(), "PilhaInt");
    LLVMTypeRef pilha_ptr_type = LLVMPointerType(pilha_type, 0);

    // 2. Declara a função do runtime C: int pilha_obter_tamanho(PilhaInt*)
    LLVMTypeRef func_args_types[] = { pilha_ptr_type };
    LLVMTypeRef func_type = LLVMFunctionType(LLVMInt32Type(), func_args_types, 1, 0);
    
    LLVMValueRef func = LLVMGetNamedFunction(modulo, "pilha_obter_tamanho");
    if (!func) {
        func = LLVMAddFunction(modulo, "pilha_obter_tamanho", func_type);
    }

    // 3. Gera a chamada para a função do runtime
    LLVMValueRef args[] = { pilha_ptr };
    return LLVMBuildCall2(builder, func_type, func, args, 1, "tamanho_pilha");
}

/**
 * @brief Gera 'call' para string_criar(valor_inicial), retornando o ponteiro da nova string.
 */
LLVMValueRef gerar_criar_string(const char* valor_inicial) {
    // Declara a função: ptr string_criar(ptr)
    LLVMTypeRef arg_types[] = { LLVMPointerType(LLVMInt8Type(), 0) };
    LLVMTypeRef func_type = LLVMFunctionType(LLVMPointerType(LLVMInt8Type(), 0), arg_types, 1, 0);
    LLVMValueRef func = LLVMGetNamedFunction(modulo, "string_criar");
    if (!func) {
        func = LLVMAddFunction(modulo, "string_criar", func_type);
    }

    // Argumento: a string literal global
    LLVMValueRef str_const = LLVMBuildGlobalStringPtr(builder, valor_inicial, "init_str");
    LLVMValueRef args[] = { str_const };
    return LLVMBuildCall2(builder, func_type, func, args, 1, "nova_str_ptr");
}

/**
 * @brief Gera 'call' para string_concatenar(str_atual, str_nova), retornando o ponteiro atualizado.
 */
LLVMValueRef gerar_concatenar_string(LLVMValueRef str_atual_ptr, const char* str_para_adicionar) {
    // Declara a função: ptr string_concatenar(ptr, ptr)
    LLVMTypeRef arg_types[] = { LLVMPointerType(LLVMInt8Type(), 0), LLVMPointerType(LLVMInt8Type(), 0) };
    LLVMTypeRef func_type = LLVMFunctionType(LLVMPointerType(LLVMInt8Type(), 0), arg_types, 2, 0);
    LLVMValueRef func = LLVMGetNamedFunction(modulo, "string_concatenar");
    if (!func) {
        func = LLVMAddFunction(modulo, "string_concatenar", func_type);
    }

    // Argumentos: o ponteiro da string atual e a nova string literal
    LLVMValueRef str_add_const = LLVMBuildGlobalStringPtr(builder, str_para_adicionar, "add_str");
    LLVMValueRef args[] = { str_atual_ptr, str_add_const };
    return LLVMBuildCall2(builder, func_type, func, args, 2, "str_concatenada_ptr");
}

/**
 * @brief Gera 'call' para string_substituir(str_atual, alvo, substituto), retornando o ponteiro atualizado.
 */
LLVMValueRef gerar_substituir_string(LLVMValueRef str_atual_ptr, const char* alvo, const char* substituto) {
    // Declara a função: ptr string_substituir(ptr, ptr, ptr)
    LLVMTypeRef arg_types[] = { LLVMPointerType(LLVMInt8Type(), 0), LLVMPointerType(LLVMInt8Type(), 0), LLVMPointerType(LLVMInt8Type(), 0) };
    LLVMTypeRef func_type = LLVMFunctionType(LLVMPointerType(LLVMInt8Type(), 0), arg_types, 3, 0);
    LLVMValueRef func = LLVMGetNamedFunction(modulo, "string_substituir");
    if (!func) {
        func = LLVMAddFunction(modulo, "string_substituir", func_type);
    }

    // Argumentos
    LLVMValueRef alvo_const = LLVMBuildGlobalStringPtr(builder, alvo, "alvo_str");
    LLVMValueRef substituto_const = LLVMBuildGlobalStringPtr(builder, substituto, "subst_str");
    LLVMValueRef args[] = { str_atual_ptr, alvo_const, substituto_const };
    return LLVMBuildCall2(builder, func_type, func, args, 3, "str_substituida_ptr");
}

/**
 * @brief Gera o código LLVM para criar (alocar e inicializar) uma variável booleana.
 *
 * @param nome O nome da variável para depuração no LLVM IR.
 * @param valor_inicial O valor C inicial (0 para false, 1 para true).
 * @return LLVMValueRef O ponteiro para a variável alocada na memória (do tipo i1*).
 */
LLVMValueRef gerar_criar_booleano(const char* nome, int valor_inicial) {
    // 1. Define o tipo booleano do LLVM, que é um inteiro de 1 bit (i1).
    LLVMTypeRef bool_type = LLVMInt1TypeInContext(contexto);

    // 2. Aloca espaço na memória da função para a variável (retorna um i1*).
    LLVMValueRef var_ref = LLVMBuildAlloca(builder, bool_type, nome);

    // 3. Cria a constante LLVM para o valor inicial.
    LLVMValueRef const_val = LLVMConstInt(bool_type, valor_inicial, 0);

    // 4. Armazena o valor inicial na variável recém-alocada.
    LLVMBuildStore(builder, const_val, var_ref);

    // 5. Retorna a referência para a variável (o ponteiro i1*).
    return var_ref;
}

/**
 * @brief Gera o código LLVM para atribuir um novo valor a uma variável booleana.
 *
 * @param var_ref A referência para a variável booleana (um i1* obtido do Symbol).
 * @param novo_valor_ref O novo valor (um i1) a ser armazenado.
 */
void gerar_set_booleano(LLVMValueRef var_ref, LLVMValueRef novo_valor_ref) {
    // Gera uma única instrução 'store' para atualizar o valor na memória.
    LLVMBuildStore(builder, novo_valor_ref, var_ref);
}

/**
 * @brief Gera o código LLVM para ler (carregar) o valor de uma variável booleana.
 *
 * @param var_ref A referência para a variável booleana (um i1* obtido do Symbol).
 * @return LLVMValueRef O valor booleano (i1) lido da memória.
 */
LLVMValueRef gerar_get_booleano(LLVMValueRef var_ref) {
    // 1. Define o tipo do valor que estamos carregando (i1).
    LLVMTypeRef bool_type = LLVMInt1TypeInContext(contexto);

    // 2. Gera a instrução 'load' e retorna o valor carregado.
    // O último argumento é o nome do registrador temporário no LLVM IR.
    return LLVMBuildLoad2(builder, bool_type, var_ref, "load_bool_tmp");
}