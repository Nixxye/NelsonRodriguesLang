#include "../include/pilhaRuntime.h"
#include <stdio.h>
#include <stdlib.h>

PilhaInt* criar_pilha(int capacidade_inicial) {
    if (capacidade_inicial <= 0) {
        capacidade_inicial = 8; // Define uma capacidade mínima padrão
    }

    PilhaInt* pilha = (PilhaInt*) malloc(sizeof(PilhaInt));
    if (!pilha) {
        perror("Falha ao alocar a estrutura da pilha");
        exit(EXIT_FAILURE);
    }

    pilha->data = (int*) malloc(sizeof(int) * capacidade_inicial);
    if (!pilha->data) {
        perror("Falha ao alocar os dados da pilha");
        free(pilha);
        exit(EXIT_FAILURE);
    }

    pilha->tamanho = 0;
    pilha->capacidade = capacidade_inicial;
    return pilha;
}

void destruir_pilha(PilhaInt* pilha) {
    if (pilha) {
        free(pilha->data);
        free(pilha);
    }
}

void pilha_push(PilhaInt* pilha, int valor) {
    // Se a pilha estiver cheia, dobra sua capacidade
    if (pilha->tamanho >= pilha->capacidade) {
        int nova_capacidade = pilha->capacidade * 2;
        int* novo_data = (int*) realloc(pilha->data, sizeof(int) * nova_capacidade);
        if (!novo_data) {
            perror("Falha ao realocar a pilha para push");
            exit(EXIT_FAILURE);
        }
        pilha->data = novo_data;
        pilha->capacidade = nova_capacidade;
    }

    pilha->data[pilha->tamanho] = valor;
    pilha->tamanho++;
}

int pilha_pop(PilhaInt* pilha) {
    if (pilha->tamanho == 0) {
        fprintf(stderr, "Erro: Tentativa de pop em uma pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    pilha->tamanho--;
    return pilha->data[pilha->tamanho];
}

int pilha_peek(const PilhaInt* pilha) {
    if (pilha->tamanho == 0) {
        fprintf(stderr, "Erro: Tentativa de peek em uma pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    return pilha->data[pilha->tamanho - 1];
}

void pilha_set_topo(PilhaInt* pilha, int novo_valor) {
    if (pilha->tamanho == 0) {
        fprintf(stderr, "Erro: Tentativa de alterar o topo de uma pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    // Acessa o último elemento (o topo) e altera seu valor.
    pilha->data[pilha->tamanho - 1] = novo_valor;
}