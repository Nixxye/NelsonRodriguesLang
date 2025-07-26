// codegen.h
#ifndef LLVMgen_H
#define LLVMgen_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <llvm-c/Core.h>


extern LLVMModuleRef modulo;
extern LLVMBuilderRef builder;
extern LLVMContextRef contexto;
extern LLVMValueRef funcao_main;
extern LLVMBasicBlockRef bloco_main;


void iniciar_codegen();
void finalizar_codegen();
void gerar_print_variavel(const char *nome);
void gerar_atribuicao_variavel(const char *nome, int valor);
LLVMValueRef gerar_pop_llvm(LLVMModuleRef module, LLVMBuilderRef builder, const char* name);
LLVMValueRef gerar_peek_llvm(LLVMModuleRef module, LLVMBuilderRef builder, const char* name);
void gerar_push_llvm(LLVMModuleRef module, LLVMBuilderRef builder, const char* name, LLVMValueRef value);
void gerar_set_topo_pilha_llvm(LLVMModuleRef module, LLVMBuilderRef builder, const char* name, LLVMValueRef value);
#endif