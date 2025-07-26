#ifndef PILHA_RUNTIME_H
#define PILHA_RUNTIME_H

#include <stdlib.h>

// A estrutura que representa nossa pilha/vetor dinâmico.
// O compilador não precisará conhecer os detalhes internos,
// apenas o ponteiro para ela (PilhaInt*).
typedef struct {
    int* data;
    int tamanho;
    int capacidade;
} PilhaInt;

// Funções que serão chamadas pelo código compilado

// Cria uma nova pilha no heap e retorna um ponteiro para ela.
PilhaInt* criar_pilha(int capacidade_inicial);

// Libera a memória da pilha e de seus dados.
void destruir_pilha(PilhaInt* pilha);

// Adiciona um elemento ao topo da pilha (realocando se necessário).
void pilha_push(PilhaInt* pilha, int valor);

// Remove e retorna o elemento do topo da pilha.
int pilha_pop(PilhaInt* pilha);

#endif // PILHA_RUNTIME_H