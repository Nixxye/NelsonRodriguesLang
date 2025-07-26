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
    LLVMValueRef func = LLVMGetNamedFunction(module, "peek_int_value");
    if (!func) {
        func = LLVMAddFunction(module, "peek_int_value", func_type);
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