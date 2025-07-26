#include "pilha_runtime.c"
#include <stdio.h>

PilhaInt* criar_pilha(int capacidade_inicial) {
    if (capacidade_inicial <= 0) {
        capacidade_inicial = 8; // Um valor padrão
    }
    PilhaInt* pilha = (PilhaInt*) malloc(sizeof(PilhaInt));
    if (!pilha) return NULL;

    pilha->data = (int*) malloc(sizeof(int) * capacidade_inicial);
    if (!pilha->data) {
        free(pilha);
        return NULL;
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
    if (!pilha) return;

    // Se a pilha estiver cheia, dobramos sua capacidade
    if (pilha->tamanho >= pilha->capacidade) {
        int nova_capacidade = pilha->capacidade * 2;
        int* novo_data = (int*) realloc(pilha->data, sizeof(int) * nova_capacidade);
        if (!novo_data) {
            // Falha na realocação, pode tratar o erro aqui
            fprintf(stderr, "Erro: Falha ao realocar a pilha.\n");
            return;
        }
        pilha->data = novo_data;
        pilha->capacidade = nova_capacidade;
    }

    pilha->data[pilha->tamanho] = valor;
    pilha->tamanho++;
}

int pilha_pop(PilhaInt* pilha) {
    if (!pilha || pilha->tamanho == 0) {
        fprintf(stderr, "Erro: Tentativa de pop em pilha vazia.\n");
        return 0; // Ou um valor de erro
    }
    pilha->tamanho--;
    return pilha->data[pilha->tamanho];
}