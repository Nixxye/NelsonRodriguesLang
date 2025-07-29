// codegen.c
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

// Gera chamada para a função C: void push_int_value(const char* name, int value)
void gerar_push_llvm(LLVMModuleRef module, LLVMBuilderRef builder, const char* name, LLVMValueRef value) {
    // Declara a função: void push_int_value(i8*, i32)
    LLVMTypeRef args_types[] = {LLVMPointerType(LLVMInt8Type(), 0), LLVMInt32Type()};
    LLVMTypeRef func_type = LLVMFunctionType(LLVMVoidType(), args_types, 2, 0);
    LLVMValueRef func = LLVMGetNamedFunction(module, "push_int_value");
    if (!func) {
        func = LLVMAddFunction(module, "push_int_value", func_type);
    }

    // Argumentos da chamada
    LLVMValueRef name_str = LLVMBuildGlobalStringPtr(builder, name, "stack_name");
    LLVMValueRef args[] = {name_str, value};

    // Gera a chamada
    LLVMBuildCall2(builder, func_type, func, args, 2, "");
}

// Gera chamada para a função C: int pop_int_value(const char* name)
LLVMValueRef gerar_pop_llvm(LLVMModuleRef module, LLVMBuilderRef builder, const char* name) {
    // Declara a função: i32 pop_int_value(i8*)
    LLVMTypeRef args_types[] = {LLVMPointerType(LLVMInt8Type(), 0)};
    LLVMTypeRef func_type = LLVMFunctionType(LLVMInt32Type(), args_types, 1, 0);
    LLVMValueRef func = LLVMGetNamedFunction(module, "pop_int_value");
    if (!func) {
        func = LLVMAddFunction(module, "pop_int_value", func_type);
    }

    // Argumento da chamada
    LLVMValueRef name_str = LLVMBuildGlobalStringPtr(builder, name, "stack_name");
    LLVMValueRef args[] = {name_str};

    // Gera a chamada e retorna o valor inteiro
    return LLVMBuildCall2(builder, func_type, func, args, 1, "popped_val");
}

// Gera chamada para a função C: int peek_int_value(const char* name)
LLVMValueRef gerar_peek_llvm(LLVMModuleRef module, LLVMBuilderRef builder, const char* name) {
    // Declara a função: i32 peek_int_value(i8*)
    LLVMTypeRef args_types[] = {LLVMPointerType(LLVMInt8Type(), 0)};
    LLVMTypeRef func_type = LLVMFunctionType(LLVMInt32Type(), args_types, 1, 0);
    LLVMValueRef func = LLVMGetNamedFunction(module, "pilha_peek");
    if (!func) {
        func = LLVMAddFunction(module, "pilha_peek", func_type);
    }

    LLVMValueRef name_str = LLVMBuildGlobalStringPtr(builder, name, "stack_name");
    LLVMValueRef args[] = {name_str};

    return LLVMBuildCall2(builder, func_type, func, args, 1, "peeked_val");
}

void gerar_set_topo_pilha_llvm(LLVMModuleRef module, LLVMBuilderRef builder, const char* name, LLVMValueRef value) {
    // 1. Declarar a função do runtime C: void set_int_value(const char*, int)
    //    Em LLVM, o tipo será: void (i8*, i32)

    LLVMTypeRef args_types[] = {
        LLVMPointerType(LLVMInt8Type(), 0), // const char* -> i8*
        LLVMInt32Type()                     // int -> i32
    };

    LLVMTypeRef func_type = LLVMFunctionType(
        LLVMVoidType(), // Retorno void
        args_types,     // Array de tipos dos argumentos
        2,              // Número de argumentos
        0               // Não é variádica
    );

    // Procura pela função no módulo; se não existir, a adiciona.
    LLVMValueRef func = LLVMGetNamedFunction(module, "set_int_value");
    if (!func) {
        func = LLVMAddFunction(module, "set_int_value", func_type);
    }

    // 2. Preparar os argumentos para a chamada
    // O nome da variável precisa ser uma constante string global no código LLVM.
    LLVMValueRef name_str_arg = LLVMBuildGlobalStringPtr(builder, name, "stack_name_arg");

    LLVMValueRef args[] = { name_str_arg, value };

    // 3. Gerar a instrução de chamada para a função do runtime
    LLVMBuildCall2(builder, func_type, func, args, 2, ""); // "" porque a função é void
}

/**
 * Gera uma chamada LLVM para a função de runtime 'criar_pilha'.
 * Esta função C aloca uma nova pilha no heap e retorna um ponteiro para ela.
 *
 * @param module O módulo LLVM atual.
 * @param builder O builder LLVM atual.
 * @param capacidade_val O LLVMValueRef (i32) para a capacidade inicial da pilha.
 * @return LLVMValueRef que representa o ponteiro para a nova estrutura de pilha (PilhaInt*).
 */
LLVMValueRef gerar_criar_pilha(LLVMModuleRef module, LLVMBuilderRef builder, LLVMValueRef capacidade_val) {
    // --- PARTE 1: Criar a pilha vazia (lógica existente) ---

    // Define o tipo "PilhaInt*" no LLVM
    LLVMTypeRef pilha_type = LLVMStructCreateNamed(LLVMGetGlobalContext(), "PilhaInt");
    LLVMTypeRef pilha_ptr_type = LLVMPointerType(pilha_type, 0);

    // Declara a função C 'criar_pilha'
    LLVMTypeRef criar_args_types[] = { LLVMInt32Type() };
    LLVMTypeRef criar_func_type = LLVMFunctionType(pilha_ptr_type, criar_args_types, 1, 0);
    LLVMValueRef criar_func = LLVMGetNamedFunction(module, "criar_pilha");
    if (!criar_func) {
        criar_func = LLVMAddFunction(module, "criar_pilha", criar_func_type);
    }

    // Gera a chamada para 'criar_pilha' e obtém o ponteiro
    LLVMValueRef args_criar[] = { capacidade_val };
    LLVMValueRef nova_pilha_ptr = LLVMBuildCall2(builder, criar_func_type, criar_func, args_criar, 1, "nova_pilha_ptr");


    // --- PARTE 2: Empilhar o valor 0 na pilha recém-criada (nova lógica) ---

    // Declara a função C 'pilha_push'
    // Assinatura: void pilha_push(PilhaInt*, int) -> void (%PilhaInt*, i32)
    LLVMTypeRef push_args_types[] = { pilha_ptr_type, LLVMInt32Type() };
    LLVMTypeRef push_func_type = LLVMFunctionType(LLVMVoidType(), push_args_types, 2, 0);
    LLVMValueRef push_func = LLVMGetNamedFunction(module, "pilha_push");
    if (!push_func) {
        push_func = LLVMAddFunction(module, "pilha_push", push_func_type);
    }

    // Prepara os argumentos para o push: o ponteiro da pilha e a constante 0
    LLVMValueRef zero_const = LLVMConstInt(LLVMInt32Type(), 0, 0);
    LLVMValueRef args_push[] = { nova_pilha_ptr, zero_const };

    // Gera a chamada para 'pilha_push'
    LLVMBuildCall2(builder, push_func_type, push_func, args_push, 2, "");


    // --- PARTE 3: Retornar o ponteiro para a pilha, que agora já tem o 0 ---
    return nova_pilha_ptr;
}