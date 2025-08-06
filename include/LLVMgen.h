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

// Variável global para a pilha.
extern PilhaControleFluxo pilhaControleFluxo;

/**
 * @brief Inicializa uma pilha de controle de fluxo.
 * @param p Ponteiro para a pilha a ser inicializada.
 */
void pilha_init(PilhaControleFluxo* p);

/**
 * @brief Adiciona um item de controle de fluxo ao topo da pilha.
 * @param p Ponteiro para a pilha.
 * @param item A estrutura de controle (com os blocos LLVM) a ser adicionada.
 */
void pilha_push(PilhaControleFluxo* p, ControleFluxo item);

/**
 * @brief Remove e retorna o item do topo da pilha de controle de fluxo.
 * @param p Ponteiro para a pilha.
 * @return A estrutura de controle que estava no topo.
 */
ControleFluxo pilha_pop(PilhaControleFluxo* p);

/**
 * @brief Retorna o item do topo da pilha de controle de fluxo sem removê-lo.
 * @param p Ponteiro para a pilha.
 * @return A estrutura de controle que está no topo.
 */
ControleFluxo pilha_peek(PilhaControleFluxo* p);
/**
 * @brief Prepara o ambiente de geração de código LLVM.
 * Inicializa o contexto, módulo, builder e a função main.
 */
void iniciar_codegen();

/**
 * @brief Finaliza a geração de código.
 * Adiciona a instrução de retorno, imprime o módulo para um arquivo e libera os recursos LLVM.
 */
void finalizar_codegen();
/**
 * @brief Gera código LLVM para criar uma nova pilha e inicializá-la com o valor 0.
 * @param capacidade_val O LLVMValueRef (i32) para a capacidade inicial da pilha.
 * @return LLVMValueRef que representa o ponteiro para a nova pilha (PilhaInt*).
 */
LLVMValueRef gerar_criar_pilha_e_inicializar(LLVMValueRef capacidade_val);

/**
 * @brief Gera código LLVM para adicionar um elemento ao topo de uma pilha.
 * @param pilha_ptr O LLVMValueRef que aponta para a pilha (PilhaInt*).
 * @param valor O LLVMValueRef (i32) do valor a ser empilhado.
 */
void gerar_push_pilha(LLVMValueRef pilha_ptr, LLVMValueRef valor);

/**
 * @brief Gera código LLVM para remover e retornar o elemento do topo de uma pilha.
 * @param pilha_ptr O LLVMValueRef que aponta para a pilha (PilhaInt*).
 * @return LLVMValueRef (i32) com o valor que estava no topo.
 */
LLVMValueRef gerar_pop_pilha(LLVMValueRef pilha_ptr);

/**
 * @brief Gera código LLVM para ler o elemento do topo de uma pilha sem removê-lo.
 * @param pilha_ptr O LLVMValueRef que aponta para a pilha (PilhaInt*).
 * @return LLVMValueRef (i32) com o valor que está no topo.
 */
LLVMValueRef gerar_peek_pilha(LLVMValueRef pilha_ptr);

/**
 * @brief Gera código LLVM para obter o número de elementos em uma pilha.
 * @param pilha_ptr O LLVMValueRef que aponta para a pilha (PilhaInt*).
 * @return LLVMValueRef (i32) com o tamanho da pilha.
 */
LLVMValueRef gerar_obter_tamanho_pilha(LLVMValueRef pilha_ptr);

/**
 * @brief Gera código LLVM para alterar o valor do elemento no topo da pilha.
 * @param pilha_ptr O LLVMValueRef que aponta para a pilha (PilhaInt*).
 * @param valor_ref O novo LLVMValueRef (i32) para o topo.
 */
void gerar_set_topo_pilha(LLVMValueRef pilha_ptr, LLVMValueRef valor_ref);
/**
 * @brief Gera código LLVM para criar uma nova string dinâmica com um valor inicial.
 * @param valor_inicial A string C literal para inicializar a nova string.
 * @return LLVMValueRef que representa o ponteiro para a nova string (char*).
 */
LLVMValueRef gerar_criar_string(const char* valor_inicial);

/**
 * @brief Gera código LLVM para concatenar uma string a outra.
 * @param str_atual_ptr O LLVMValueRef (char*) da string a ser modificada.
 * @param str_para_adicionar A string C literal a ser adicionada.
 * @return LLVMValueRef com o novo ponteiro para a string concatenada.
 */
LLVMValueRef gerar_concatenar_string(LLVMValueRef str_atual_ptr, const char* str_para_adicionar);

/**
 * @brief Gera código LLVM para substituir ocorrências de uma substring em uma string.
 * @param str_atual_ptr O LLVMValueRef (char*) da string a ser modificada.
 * @param alvo A substring C a ser procurada.
 * @param substituto A string C que substituirá o alvo.
 * @return LLVMValueRef com o novo ponteiro para a string modificada.
 */
LLVMValueRef gerar_substituir_string(LLVMValueRef str_atual_ptr, const char* alvo, const char* substituto);
/**
 * @brief Gera código LLVM para criar (alocar e inicializar) uma variável booleana.
 * @param nome O nome da variável para depuração no LLVM IR.
 * @param valor_inicial O valor C inicial (0 para false, 1 para true).
 * @return LLVMValueRef, o ponteiro para a variável alocada (do tipo i1*).
 */
LLVMValueRef gerar_criar_booleano(const char* nome, int valor_inicial);

/**
 * @brief Gera código LLVM para atribuir um novo valor a uma variável booleana.
 * @param var_ref A referência para a variável booleana (um i1*).
 * @param novo_valor_ref O novo valor (um i1) a ser armazenado.
 */
void gerar_set_booleano(LLVMValueRef var_ref, LLVMValueRef novo_valor_ref);

/**
 * @brief Gera código LLVM para ler (carregar) o valor de uma variável booleana.
 * @param var_ref A referência para a variável booleana (um i1*).
 * @return LLVMValueRef, o valor booleano (i1) lido da memória.
 */
LLVMValueRef gerar_get_booleano(LLVMValueRef var_ref);
#endif
