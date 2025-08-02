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


#define MAX_PILHA_ANINHAMENTO 50 // Define a profundidade máxima de if's/laços aninhados


// Estrutura para guardar os blocos básicos de uma estrutura de controlo.
typedef struct {
    LLVMBasicBlockRef then_block;   // Para o código do 'then'
    LLVMBasicBlockRef else_block;   // Para o código do 'else' (opcional)
    LLVMBasicBlockRef merge_block;  // Para onde o fluxo converge no final
} ControleFluxo;

typedef struct {
    ControleFluxo itens[MAX_PILHA_ANINHAMENTO];
    int topo;
} PilhaControleFluxo;



void pilha_init(PilhaControleFluxo* p);
void pilha_push(PilhaControleFluxo* p, ControleFluxo item);
ControleFluxo pilha_pop(PilhaControleFluxo* p);
void iniciar_codegen();
void finalizar_codegen();
LLVMValueRef gerar_criar_pilha_e_inicializar(LLVMValueRef capacidade_val);
void gerar_push_pilha(LLVMValueRef pilha_ptr, LLVMValueRef valor);
LLVMValueRef gerar_pop_pilha(LLVMValueRef pilha_ptr);
LLVMValueRef gerar_peek_pilha(LLVMValueRef pilha_ptr);
void gerar_set_topo_pilha(LLVMValueRef pilha_ptr, LLVMValueRef valor_ref);
#endif
