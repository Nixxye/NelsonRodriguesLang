#include "../include/stringRuntime.h"
// --- Função para o Runtime de Strings ---

/**
 * @brief Cria uma nova string dinâmica no heap com um valor inicial.
 * @param valor_inicial A string literal para copiar.
 * @return Um ponteiro para a nova string alocada.
 */
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

/**
 * @brief Concatena uma string a outra, realocando a memória da primeira.
 * @param str_original Ponteiro para a string a ser modificada.
 * @param str_para_adicionar A string a ser concatenada.
 * @return O novo ponteiro para a string modificada (pode ser o mesmo ou um novo).
 */
char* string_concatenar(char* str_original, const char* str_para_adicionar) {
    if (!str_original || !str_para_adicionar) return str_original;
    
    size_t novo_tamanho = strlen(str_original) + strlen(str_para_adicionar) + 1;
    char* nova_str = (char*) realloc(str_original, novo_tamanho);
    if (!nova_str) {
        perror("Falha ao realocar string para concatenação");
        exit(EXIT_FAILURE);
    }
    strcat(nova_str, str_para_adicionar);
    return nova_str;
}

/**
 * @brief Substitui todas as ocorrências de uma substring em uma string.
 * Esta função libera a memória da string original e retorna uma nova.
 * @param original A string a ser modificada (será liberada).
 * @param alvo A substring a ser procurada.
 * @param substituto A string que substituirá o alvo.
 * @return Um ponteiro para a nova string com as substituições.
 */
char* string_substituir(char* original, const char* alvo, const char* substituto) {
    if (!original || !alvo || !substituto) return original;

    char* resultado;
    char* p;
    int cont = 0;
    size_t len_alvo = strlen(alvo);
    size_t len_substituto = strlen(substituto);

    // Conta as ocorrências
    for (p = original; (p = strstr(p, alvo)); p += len_alvo) {
        cont++;
    }

    // Aloca memória para a nova string
    resultado = (char*) malloc(strlen(original) + cont * (len_substituto - len_alvo) + 1);
    if (!resultado) {
         perror("Falha ao alocar string para substituição");
         exit(EXIT_FAILURE);
    }

    // Constrói a nova string
    char* r_ptr = resultado;
    p = original;
    while ((p = strstr(p, alvo))) {
        int len_prefixo = p - original;
        strncpy(r_ptr, original, len_prefixo);
        r_ptr += len_prefixo;
        strcpy(r_ptr, substituto);
        r_ptr += len_substituto;
        p += len_alvo;
        original = p;
    }
    strcpy(r_ptr, original);

    // Libera a memória da string antiga
    free(original);
    return resultado;
}