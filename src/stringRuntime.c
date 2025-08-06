#include "../include/stringRuntime.h"

char* string_criar(const char* valor_inicial) {
    if (!valor_inicial) return NULL;
    char* nova_str = (char*) malloc(strlen(valor_inicial) + 1);
    if (!nova_str) {
        perror("Falha ao alocar string");
        exit(EXIT_FAILURE);
    }
    strcpy(nova_str, valor_inicial);
    return nova_str;
}

char* string_concatenar(char* str_original, const char* str_para_adicionar) {
    if (!str_original || !str_para_adicionar) return str_original;
    
    size_t novo_tamanho = strlen(str_original) + strlen(str_para_adicionar) + 3; // +1 para o espaço, +1 para o '\0'
    
    char* nova_str = (char*) realloc(str_original, novo_tamanho);
    if (!nova_str) {
        perror("Falha ao realocar string para concatenação");
        exit(EXIT_FAILURE);
    }
    
    strcat(nova_str, ", ");
    
    strcat(nova_str, str_para_adicionar);
    
    return nova_str;
}

char* string_substituir(char* original, const char* alvo, const char* substituto) {
    if (!original || !alvo || !substituto) return original;

    char* resultado;
    int cont = 0;
    size_t len_alvo = strlen(alvo);
    size_t len_substituto = strlen(substituto);

    const char* p_busca = original;
    while ((p_busca = strstr(p_busca, alvo))) {
        cont++;
        p_busca += len_alvo;
    }

    size_t novo_tamanho = strlen(original) + cont * (len_substituto - len_alvo) + 1;
    resultado = (char*) malloc(novo_tamanho);
    if (!resultado) {
        perror("Falha ao alocar string para substituição");
        exit(EXIT_FAILURE);
    }

    char* r_ptr = resultado;
    p_busca = original; // Usa um ponteiro temporário para a busca
    while (cont > 0) {
        char* ocorrencia = strstr(p_busca, alvo);
        if (!ocorrencia) break;

        // Copia a parte antes da ocorrência
        size_t len_prefixo = ocorrencia - p_busca;
        strncpy(r_ptr, p_busca, len_prefixo);
        r_ptr += len_prefixo;

        // Copia o substituto
        strcpy(r_ptr, substituto);
        r_ptr += len_substituto;

        // Avança o ponteiro de busca
        p_busca = ocorrencia + len_alvo;
        cont--;
    }
    strcpy(r_ptr, p_busca);

    free(original);

    return resultado;
}