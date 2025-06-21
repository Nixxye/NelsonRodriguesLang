#include "../include/nrUtils.h"

// Definições das tabelas globais
Symbol *symbolTable[TABLE_SIZE] = {0};
IntValue *intTable[TABLE_SIZE] = {0};
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
    if (!newSymbol) { perror("malloc failed"); exit(EXIT_FAILURE); }

    newSymbol->name = strdup(name);
    newSymbol->type = type;
    newSymbol->active = 0;
    newSymbol->next = symbolTable[index];
    newSymbol->llvm_ref = NULL;
    newSymbol->llvm_type = NULL;

    symbolTable[index] = newSymbol;

    // LLVM type and allocation
    switch (type) {
        case INT_VAR:
            newSymbol->llvm_type = LLVMInt32TypeInContext(contexto);
            newSymbol->llvm_ref = LLVMBuildAlloca(builder, newSymbol->llvm_type, name);
            set_int_value(name, 0);
            break;

        case BOOL_VAR:
            newSymbol->llvm_type = LLVMInt1TypeInContext(contexto);
            newSymbol->llvm_ref = LLVMBuildAlloca(builder, newSymbol->llvm_type, name);
            set_bool_value(name, 0);
            break;

        case STRING_VAR:
            newSymbol->llvm_type = LLVMPointerType(LLVMInt8TypeInContext(contexto), 0);
            newSymbol->llvm_ref = LLVMBuildAlloca(builder, newSymbol->llvm_type, name);

            // Inicializa string com ""
            StringValue *newStringValue = (StringValue*) malloc(sizeof(StringValue));
            if (!newStringValue) { perror("malloc failed"); exit(EXIT_FAILURE); }
            newStringValue->name = strdup(name);
            newStringValue->value = strdup("");
            unsigned int strIndex = hash(name);
            newStringValue->next = stringTable[strIndex];
            stringTable[strIndex] = newStringValue;
            break;
    }
}

// Adiciona valor inteiro
void set_int_value(const char *name, int value) {
    // LLVM:
        Symbol *sym = get_symbol(name);
    if (!sym) {
        fprintf(stderr, "Erro: variável '%s' não declarada!\n", name);
        exit(EXIT_FAILURE);
    }
    if (sym->type != INT_VAR) {
        fprintf(stderr, "Erro: tipo incompatível ao atribuir a '%s'!\n", name);
        exit(EXIT_FAILURE);
    }
    if (!sym->llvm_ref) {
        fprintf(stderr, "Erro: variável '%s' não tem referência LLVM!\n", name);
        exit(EXIT_FAILURE);
    }

    LLVMValueRef valConst = LLVMConstInt(LLVMInt32Type(), value, 0);
    LLVMBuildStore(builder, valConst, sym->llvm_ref);
    // Tabela de valores inteiros:
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


// Adiciona valor booleano
void set_bool_value(const char *name, int value) {
    // LLVM:
    Symbol *sym = get_symbol(name);
    if (!sym) {
        fprintf(stderr, "Erro: variável '%s' não declarada!\n", name);
        exit(EXIT_FAILURE);
    }
    if (sym->type != BOOL_VAR) {
        fprintf(stderr, "Erro: tipo incompatível ao atribuir booleano a '%s'!\n", name);
        exit(EXIT_FAILURE);
    }
    if (!sym->llvm_ref) {
        fprintf(stderr, "Erro: variável '%s' não tem referência LLVM!\n", name);
        exit(EXIT_FAILURE);
    }

    LLVMValueRef valConst = LLVMConstInt(LLVMInt1Type(), value ? 1 : 0, 0);
    LLVMBuildStore(builder, valConst, sym->llvm_ref);

    // Atualiza tabela de valores booleanos
    unsigned int index = hash(name);
    BoolValue *val = boolTable[index];
    while (val) {
        if (strcmp(val->name, name) == 0) {
            val->value = value ? 1 : 0;
            return;
        }
        val = val->next;
    }
    BoolValue *newValue = (BoolValue *) malloc(sizeof(BoolValue));
    newValue->name = strdup(name);
    newValue->value = value ? 1 : 0;
    newValue->next = boolTable[index];
    boolTable[index] = newValue;
}


// Adiciona valor string
void set_string_value(const char *name, const char *value) {
    // LLVM:
    Symbol *sym = get_symbol(name);
    if (!sym) {
        fprintf(stderr, "Erro: variável '%s' não declarada!\n", name);
        exit(EXIT_FAILURE);
    }
    if (sym->type != STRING_VAR) {
        fprintf(stderr, "Erro: tipo incompatível ao atribuir string a '%s'!\n", name);
        exit(EXIT_FAILURE);
    }
    if (!sym->llvm_ref) {
        fprintf(stderr, "Erro: variável '%s' não tem referência LLVM!\n", name);
        exit(EXIT_FAILURE);
    }

    // Cria constante string no módulo LLVM
    LLVMValueRef strConst = LLVMBuildGlobalStringPtr(builder, value, "strtmp");
    LLVMBuildStore(builder, strConst, sym->llvm_ref);

    // Atualiza tabela de valores string
    unsigned int index = hash(name);
    StringValue *val = stringTable[index];
    while (val) {
        if (strcmp(val->name, name) == 0) {
            free(val->value);
            val->value = strdup(value);
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

Symbol* get_symbol(const char *name) {
    unsigned int index = hash(name);
    Symbol *symbol = symbolTable[index];
    while (symbol) {
        if (strcmp(symbol->name, name) == 0) {
            return symbol;
        }
        symbol = symbol->next;
    }
    return NULL; // Não encontrado
}

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

    printf("Tabela de Booleanos:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        BoolValue *val = boolTable[i];
        while (val) {
            printf("[%s = %s] -> ", val->name, val->value ? "true" : "false");
            val = val->next;
        }
    }
    printf("\n");

    printf("Tabela de Strings:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        StringValue *val = stringTable[i];
        while (val) {
            printf("[%s = %s] -> ", val->name, val->value);
            val = val->next;
        }
    }
    printf("\n");
}

const char* vartype_to_string(VarType type) {
    switch (type) {
        case INT_VAR: return "int";
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

char* trim(char* str) {
    // Remove espaços do início
    while (*str == ' ' || *str == '\t'|| *str == '\r') str++;

    // Remove espaços do fim
    char* end = str + strlen(str) - 1;
    while (end > str && *end == ' ') {
        *end = '\0';
        end--;
    }

    return str;
}
char* concatena(char* a, char* b) {
    char* a_trim = trim(a);
    char* b_trim = trim(b);
    size_t len = strlen(a) + strlen(b) + 2;
    char* res = (char *) malloc(len);
    snprintf(res, len, "%s %s", a, b);
    // free(a);
    return res;
    // ajustar os free onde usa concatena
}

void gerar_print_string(const char *nome) {
    // Obtém símbolo da variável
    Symbol *sym = get_symbol(nome);
    if (!sym || sym->type != STRING_VAR || !sym->llvm_ref) {
        fprintf(stderr, "Erro: variável de string '%s' inválida ou não declarada\n", nome);
        return;
    }

    // Declara printf (se ainda não foi)
    LLVMTypeRef printf_type = LLVMFunctionType(LLVMInt32Type(), (LLVMTypeRef[]){ LLVMPointerType(LLVMInt8Type(), 0) }, 1, 1);
    LLVMValueRef printf_func = LLVMGetNamedFunction(modulo, "printf");
    if (!printf_func)
        printf_func = LLVMAddFunction(modulo, "printf", printf_type);

    // Cria string global "%s\n"
    LLVMValueRef fmt = LLVMBuildGlobalStringPtr(builder, "%s\n", "fmt");

    // Carrega o valor da variável
    LLVMValueRef valor = LLVMBuildLoad2(builder, LLVMPointerType(LLVMInt8Type(), 0), sym->llvm_ref, "tmpstr");

    // Chamada para printf
    LLVMBuildCall2(builder, printf_type, printf_func, (LLVMValueRef[]){ fmt, valor }, 2, "");
}

void gerar_print_int(const char *nome) {
    // Obtém símbolo da variável
    Symbol *sym = get_symbol(nome);
    if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
        fprintf(stderr, "Erro: variável inteira '%s' inválida ou não declarada\n", nome);
        return;
    }

    // Declara printf (se ainda não foi)
    LLVMTypeRef printf_type = LLVMFunctionType(
        LLVMInt32TypeInContext(contexto),
        (LLVMTypeRef[]){ LLVMPointerType(LLVMInt8TypeInContext(contexto), 0) },
        1,  // 1 argumento fixo (formato)
        1   // é varargs
    );
    LLVMValueRef printf_func = LLVMGetNamedFunction(modulo, "printf");
    if (!printf_func)
        printf_func = LLVMAddFunction(modulo, "printf", printf_type);

    // Cria string global para formato "%d\n"
    LLVMValueRef fmt = LLVMBuildGlobalStringPtr(builder, "%d\n", "fmt");

    // Carrega o valor inteiro da variável
    LLVMValueRef valor = LLVMBuildLoad2(builder, LLVMInt32TypeInContext(contexto), sym->llvm_ref, "tmpint");

    // Chamada para printf
    LLVMBuildCall2(builder, printf_type, printf_func, (LLVMValueRef[]){ fmt, valor }, 2, "");
}

void gerar_leitura_inteiro(const char *nome) {
    Symbol *sym = get_symbol(nome);
    if (!sym || sym->type != INT_VAR || !sym->llvm_ref) {
        fprintf(stderr, "Erro: variável inteira '%s' inválida ou não declarada\n", nome);
        return;
    }

    // printf("Digite valor de <nome>: ");
    LLVMTypeRef printf_type = LLVMFunctionType(
        LLVMInt32Type(), (LLVMTypeRef[]){ LLVMPointerType(LLVMInt8Type(), 0) }, 1, 1);
    LLVMValueRef printf_func = LLVMGetNamedFunction(modulo, "printf");
    if (!printf_func)
        printf_func = LLVMAddFunction(modulo, "printf", printf_type);

    char msg[256];
    snprintf(msg, sizeof(msg), "Digite valor de %s: ", nome);
    LLVMValueRef prompt = LLVMBuildGlobalStringPtr(builder, msg, "prompt");
    LLVMBuildCall2(builder, printf_type, printf_func, (LLVMValueRef[]){ prompt }, 1, "");

    // scanf("%d", &var)
    LLVMTypeRef scanf_type = LLVMFunctionType(
        LLVMInt32Type(), (LLVMTypeRef[]){ LLVMPointerType(LLVMInt8Type(), 0) }, 1, 1);
    LLVMValueRef scanf_func = LLVMGetNamedFunction(modulo, "scanf");
    if (!scanf_func)
        scanf_func = LLVMAddFunction(modulo, "scanf", scanf_type);

    LLVMValueRef fmt = LLVMBuildGlobalStringPtr(builder, "%d", "fmt");
    LLVMValueRef result = LLVMBuildCall2(builder, scanf_type, scanf_func,
                                         (LLVMValueRef[]){ fmt, sym->llvm_ref }, 2, "res_scanf");

    // if (result != 1)
    LLVMValueRef cond = LLVMBuildICmp(builder, LLVMIntNE,
                                      result, LLVMConstInt(LLVMInt32Type(), 1, 0),
                                      "scanf_failed");

    LLVMBasicBlockRef okBlock = LLVMAppendBasicBlock(funcao_main, "ok");
    LLVMBasicBlockRef errBlock = LLVMAppendBasicBlock(funcao_main, "erro");

    LLVMBuildCondBr(builder, cond, errBlock, okBlock);

    // erro:
    LLVMPositionBuilderAtEnd(builder, errBlock);
    LLVMValueRef errMsg = LLVMBuildGlobalStringPtr(builder, "Erro: valor inválido (esperado inteiro)\n", "errmsg");
    LLVMBuildCall2(builder, printf_type, printf_func, (LLVMValueRef[]){ errMsg }, 1, "");
    LLVMBuildBr(builder, okBlock);

    // ok:
    LLVMPositionBuilderAtEnd(builder, okBlock);
}