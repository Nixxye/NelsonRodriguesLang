#include "../include/LLVMgen.h"

LLVMModuleRef modulo;
LLVMBuilderRef builder;
LLVMContextRef contexto;
LLVMValueRef funcao_main;
LLVMBasicBlockRef bloco_main;

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


void gerar_print_variavel(const char *nome) {
    printf("Gerando IR para imprimir variável: %s (simulação)\n", nome);
    // Aqui, você pode construir uma chamada para printf usando a LLVM-C API
    // Isso requer incluir a função `printf` no módulo, criar a string e chamar.
    // Podemos expandir esse ponto depois.
}

void gerar_atribuicao_variavel(const char *nome, int valor) {
    printf("Gerando IR para atribuir %d à variável %s (simulação)\n", valor, nome);
    // Aqui poderíamos alocar uma variável global ou local e atribuir o valor
    // Isso também pode ser expandido depois
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

// Em codegen.c
void gerar_set_topo_pilha(LLVMValueRef pilha_ptr, LLVMValueRef valor_ref) {
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