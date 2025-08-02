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
LLVMValueRef gerar_criar_pilha_e_inicializar(LLVMValueRef capacidade_val);
void gerar_push_pilha(LLVMValueRef pilha_ptr, LLVMValueRef valor);
LLVMValueRef gerar_pop_pilha(LLVMValueRef pilha_ptr);
LLVMValueRef gerar_peek_pilha(LLVMValueRef pilha_ptr);
void gerar_set_topo_pilha(LLVMValueRef pilha_ptr, LLVMValueRef valor_ref);
#endif
