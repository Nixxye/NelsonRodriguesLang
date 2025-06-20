#include "table.h"

// Definições das tabelas globais
Symbol *symbolTable[TABLE_SIZE] = {0};
IntValue *intTable[TABLE_SIZE] = {0};
FloatValue *floatTable[TABLE_SIZE] = {0};
BoolValue *boolTable[TABLE_SIZE] = {0};
StringValue *stringTable[TABLE_SIZE] = {0};

// Função de hash simples
unsigned int hash(const char *str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + *str++;
    }
    return hash % TABLE_SIZE;
}

// Adiciona símbolo
void add_symbol(const char *name, VarType type) {
    unsigned int index = hash(name);
    Symbol *symbol = symbolTable[index];
    while (symbol) {
        if (strcmp(symbol->name, name) == 0) {
            if (symbol->type != type) {
                fprintf(stderr, "Erro: Variável '%s' já existe com tipo diferente!\n", name);
                exit(EXIT_FAILURE);
            }
            return;
        }
        symbol = symbol->next;
    }
    Symbol *newSymbol = (Symbol *) malloc(sizeof(Symbol));
    if (!newSymbol) {
      perror("malloc failed");
      exit(EXIT_FAILURE);
    }
    newSymbol->name = strdup(name);
    if (!newSymbol->name) {
      perror("strdup failed");
      exit(EXIT_FAILURE);
    }

    newSymbol->name = strdup(name);
    newSymbol->type = type;
    newSymbol->next = symbolTable[index];
    newSymbol->active = 0; // Marca como inativo
    symbolTable[index] = newSymbol;
    // Inicializa o valor da variável
    switch (type) {
        case INT_VAR:
            set_int_value(name, 0); // Inicializa com 0
            break;
        case FLOAT_VAR:
            set_float_value(name, 0.0f); // Inicializa com 0.0
            break;
        case BOOL_VAR:
            set_bool_value(name, 0); // Inicializa com false
            break;
        case STRING_VAR:
            // Inicializa com string vazia
            StringValue *newStringValue = (StringValue *) malloc(sizeof(StringValue));
            if (!newStringValue) {
              perror("malloc failed");
              exit(EXIT_FAILURE);
            }
            newStringValue->name = strdup(name);
            if (!newStringValue->name) {
              perror("strdup failed");
              exit(EXIT_FAILURE);
            }
            newStringValue->value = strdup(""); // Inicializa com string vazia
            newStringValue->next = NULL;
            unsigned int strIndex = hash(name);
            newStringValue->next = stringTable[strIndex];
            stringTable[strIndex] = newStringValue;
            break;
    }
}

// Adiciona valor inteiro
void set_int_value(const char *name, int value) {
    unsigned int index = hash(name);
    //add_symbol(name, INT_VAR);
    IntValue *val = intTable[index];
    while (val) {
        if (strcmp(val->name, name) == 0) {
            val->value = value;
            return;
        }
        val = val->next;
    }
    IntValue *newValue = (IntValue *) malloc(sizeof(IntValue));
    newValue->name = strdup(name);
    newValue->value = value;
    newValue->next = intTable[index];
    intTable[index] = newValue;
}

// Adiciona valor float
void set_float_value(const char *name, float value) {
    //add_symbol(name, FLOAT_VAR);
    unsigned int index = hash(name);
    FloatValue *val = floatTable[index];
    while (val) {
        if (strcmp(val->name, name) == 0) {
            val->value = value;
            return;
        }
        val = val->next;
    }
    FloatValue *newValue = (FloatValue *) malloc(sizeof(FloatValue));
    newValue->name = strdup(name);
    newValue->value = value;
    newValue->next = floatTable[index];
    floatTable[index] = newValue;
}

// Adiciona valor booleano
void set_bool_value(const char *name, int value) {
    //add_symbol(name, BOOL_VAR);
    unsigned int index = hash(name);
    BoolValue *val = boolTable[index];
    while (val) {
        if (strcmp(val->name, name) == 0) {
            val->value = value;
            return;
        }
        val = val->next;
    }
    BoolValue *newValue = (BoolValue *) malloc(sizeof(BoolValue));
    newValue->name = strdup(name);
    newValue->value = value;
    newValue->next = boolTable[index];
    boolTable[index] = newValue;
}

// Adiciona valor string
void set_string_value(const char *name, const char *value) {
    unsigned int index = hash(name);
    StringValue *val = stringTable[index];
    while (val) {
        if (strcmp(val->name, name) == 0) {
            free(val->value); // Libera memória da string antiga
            val->value = strdup(value); // Atribui nova string
            return;
        }
        val = val->next;
    }
    StringValue *newValue = (StringValue *) malloc(sizeof(StringValue));
    newValue->name = strdup(name);
    newValue->value = strdup(value);
    newValue->next = stringTable[index];
    stringTable[index] = newValue;
}



// Recupera valor inteiro
int get_int_value(const char *name) {
    unsigned int index = hash(name);
    IntValue *val = intTable[index];
    while (val) {
        if (strcmp(val->name, name) == 0) {
            return val->value;
        }
        val = val->next;
    }
    fprintf(stderr, "Erro: Variável '%s' não encontrada na tabela de inteiros!\n", name);
    exit(EXIT_FAILURE);
}

// Recupera valor float
float get_float_value(const char *name) {
    unsigned int index = hash(name);
    FloatValue *val = floatTable[index];
    while (val) {
        if (strcmp(val->name, name) == 0) {
            return val->value;
        }
        val = val->next;
    }
    fprintf(stderr, "Erro: Variável '%s' não encontrada na tabela de floats!\n", name);
    exit(EXIT_FAILURE);
}

// Recupera valor booleano
int get_bool_value(const char *name) {
    unsigned int index = hash(name);
    BoolValue *val = boolTable[index];
    while (val) {
        if (strcmp(val->name, name) == 0) {
            return val->value;
        }
        val = val->next;
    }
    fprintf(stderr, "Erro: Variável '%s' não encontrada na tabela de booleanos!\n", name);
    exit(EXIT_FAILURE);
}

// Recupera valor string
char *get_string_value(const char *name) {
    unsigned int index = hash(name);
    StringValue *val = stringTable[index];
    while (val) {
        if (strcmp(val->name, name) == 0) {
            return val->value; // Retorna a string
        }
        val = val->next;
    }
    fprintf(stderr, "Erro: Variável '%s' não encontrada na tabela de strings!\n", name);
    exit(EXIT_FAILURE);
}

// Recupera tipo da variável
VarType get_variable_type(const char *name) {
    unsigned int index = hash(name);
    Symbol *symbol = symbolTable[index];
    while (symbol) {
        if (strcmp(symbol->name, name) == 0) {
            return symbol->type;
        }
        symbol = symbol->next;
    }
    fprintf(stderr, "Erro: Variável '%s' não encontrada na tabela de símbolos!\n", name);
    exit(EXIT_FAILURE);
}

// Impressão das tabelas
// void print_symbols(void) {
//     printf("Tabela de Símbolos:\n");
//     for (int i = 0; i < TABLE_SIZE; i++) {
//         Symbol *symbol = symbolTable[i];
//         while (symbol) {
//             printf("[%s - %d] -> ", symbol->name, symbol->type);
//             symbol = symbol->next;
//         }
//     }
//     printf("\n");
// }

void print_values(void) {
    printf("Tabela de Inteiros:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        IntValue *val = intTable[i];
        while (val) {
            printf("[%s = %d] -> ", val->name, val->value);
            val = val->next;
        }
    }
    printf("\n");

    printf("Tabela de Floats:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        FloatValue *val = floatTable[i];
        while (val) {
            printf("[%s = %.2f] -> ", val->name, val->value);
            val = val->next;
        }
    }
    printf("\n");

    printf("Tabela de Booleanos:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        BoolValue *val = boolTable[i];
        while (val) {
            printf("[%s = %s] -> ", val->name, val->value ? "true" : "false");
            val = val->next;
        }
    }
    printf("\n");
}

const char* vartype_to_string(VarType type) {
    switch (type) {
        case INT_VAR: return "int";
        case FLOAT_VAR: return "float";
        case CHAR_VAR: return "char";
        case STRING_VAR: return "string";
        case BOOL_VAR: return "bool";
        default: return "unknown";
    }
}

void print_symbols(void) {
    printf("=== Tabela de Símbolos ===\n");
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Symbol *entry = symbolTable[i];
        while (entry != NULL) {
            printf("Nome: %-15s | Tipo: %-6s | Ativo: %s\n",
                   entry->name,
                   vartype_to_string(entry->type),
                   entry->active ? "sim" : "não");
            entry = entry->next;
        }
    }
}

char* substituir_ocorrencias(const char* original, const char* alvo, const char* substituto) {
    if (!original || !alvo || !substituto) return NULL;

    size_t len_original = strlen(original);
    size_t len_alvo = strlen(alvo);
    size_t len_substituto = strlen(substituto);

    // Estimar o número máximo de substituições
    int cont = 0;
    const char *p = original;
    while ((p = strstr(p, alvo)) != NULL) {
        cont++;
        p += len_alvo;
    }

    // Aloca memória para o novo texto
    size_t novo_tamanho = len_original + cont * (len_substituto - len_alvo) + 1;
    char *resultado = (char*) malloc(novo_tamanho);
    if (!resultado) return NULL;

    char *dest = resultado;
    p = original;
    while (*p) {
        if (strstr(p, alvo) == p) {
            strcpy(dest, substituto);
            dest += len_substituto;
            p += len_alvo;
        } else {
            *dest++ = *p++;
        }
    }
    *dest = '\0';
    return resultado;
}
