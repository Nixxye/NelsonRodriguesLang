#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Cria uma nova string dinâmica no heap com um valor inicial.
 * @param valor_inicial A string literal para copiar.
 * @return Um ponteiro para a nova string alocada.
 */
char* string_criar(const char* valor_inicial);

/**
 * @brief Concatena uma string a outra, realocando a memória da primeira.
 * @param str_original Ponteiro para a string a ser modificada.
 * @param str_para_adicionar A string a ser concatenada.
 * @return O novo ponteiro para a string modificada (pode ser o mesmo ou um novo).
 */
char* string_concatenar(char* str_original, const char* str_para_adicionar);

/**
 * @brief Substitui todas as ocorrências de uma substring em uma string.
 * Esta função libera a memória da string original e retorna uma nova.
 * @param original A string a ser modificada (será liberada).
 * @param alvo A substring a ser procurada.
 * @param substituto A string que substituirá o alvo.
 * @return Um ponteiro para a nova string com as substituições.
 */
char* string_substituir(char* original, const char* alvo, const char* substituto);