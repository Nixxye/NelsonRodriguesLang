#ifndef PILHA_RUNTIME_H
#define PILHA_RUNTIME_H

// Estrutura da pilha de inteiros.
typedef struct {
    int* data;      // Ponteiro para os dados (vetor dinâmico)
    int tamanho;    // Número de elementos atualmente na pilha
    int capacidade; // Tamanho alocado do vetor 'data'
} PilhaInt;

/**
 * @brief Cria e aloca uma nova pilha.
 * @param capacidade_inicial A capacidade inicial da pilha.
 * @return Um ponteiro para a nova pilha criada no heap.
 */
PilhaInt* criar_pilha(int capacidade_inicial);

/**
 * @brief Libera toda a memória usada pela pilha.
 * @param pilha O ponteiro para a pilha a ser destruída.
 */
void destruir_pilha(PilhaInt* pilha);

/**
 * @brief Adiciona um elemento no topo da pilha.
 * @param pilha O ponteiro para a pilha.
 * @param valor O valor inteiro a ser adicionado.
 */
void pilha_push(PilhaInt* pilha, int valor);

/**
 * @brief Remove e retorna o elemento do topo da pilha.
 * @param pilha O ponteiro para a pilha.
 * @return O valor que estava no topo.
 */
int pilha_pop(PilhaInt* pilha);

/**
 * @brief Retorna o elemento do topo da pilha sem removê-lo.
 * @param pilha O ponteiro para a pilha.
 * @return O valor que está no topo.
 */
int pilha_peek(const PilhaInt* pilha);

void pilha_set_topo(PilhaInt* pilha, int novo_valor);

/**
 * @brief Retorna o número de elementos em uma pilha.
 * @param pilha O ponteiro para a pilha.
 * @return O campo 'tamanho' da struct da pilha.
 */
int pilha_obter_tamanho(const PilhaInt* pilha);

#endif // PILHA_RUNTIME_H