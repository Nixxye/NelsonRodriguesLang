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

