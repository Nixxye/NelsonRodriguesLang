#include "../include/nrUtils.h"

// Definições das tabelas globais
Symbol *symbolTable[TABLE_SIZE] = {0};
IntValue *intTable[TABLE_SIZE] = {0};
BoolValue *boolTable[TABLE_SIZE] = {0};
StringValue *stringTable[TABLE_SIZE] = {0};
WhileBlocks while_stack[MAX_WHILE_NESTING] = {0};


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
            LLVMTypeRef pilha_type = LLVMStructCreateNamed(LLVMGetGlobalContext(), "PilhaInt");
            LLVMTypeRef pilha_ptr_type = LLVMPointerType(pilha_type, 0);
            newSymbol->llvm_type = pilha_ptr_type;

            // 2. Aloca espaço na memória para guardar o PONTEIRO para a pilha (PilhaInt**)
            newSymbol->llvm_ref = LLVMBuildAlloca(builder, newSymbol->llvm_type, name);

            // 3. Gera a chamada para o runtime C: call @criar_pilha(capacidade_inicial)
            LLVMValueRef capacidade_inicial = LLVMConstInt(LLVMInt32Type(), 8, 0); // Capacidade padrão 8
            LLVMValueRef nova_pilha_ptr = gerar_criar_pilha(modulo, builder, capacidade_inicial); // Função que criamos antes

            // 4. Armazena o ponteiro retornado na variável
            LLVMBuildStore(builder, nova_pilha_ptr, newSymbol->llvm_ref);

            IntValue *newIntValue = (IntValue*) malloc(sizeof(IntValue));
            if (!newIntValue) { perror("malloc failed"); exit(EXIT_FAILURE); }
            newIntValue->name = strdup(name);
            newIntValue->head = NULL; // A pilha começa vazia
            newIntValue->next = intTable[index];
            intTable[index] = newIntValue;
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
// Função auxiliar para encontrar ou criar um IntValue
IntValue* get_or_create_int_value(const char* name) {
    unsigned int index = hash(name);
    IntValue* val = intTable[index];
    while (val) {
        if (strcmp(val->name, name) == 0) {
            printf("Achou a pilha de inteiros '%s'\n", name);
            return val;
        }
        val = val->next;
    }

    // Se não encontrou, cria um novo
    IntValue* newValue = (IntValue*)malloc(sizeof(IntValue));
    if (!newValue) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    newValue->name = strdup(name);
    newValue->head = NULL; // A pilha começa vazia
    newValue->next = intTable[index];
    intTable[index] = newValue;
    return newValue;
}

// Adiciona um valor ao topo da pilha de uma variável
void push_int_value(const char* name, int value) {
    IntValue* iv = get_or_create_int_value(name);

    // Cria um novo nó para a lista ligada
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    newNode->value = value;
    newNode->next = iv->head; // O novo nó aponta para o antigo topo
    iv->head = newNode;      // O topo agora é o novo nó
}

// Remove e retorna o valor do topo da pilha
int pop_int_value(const char* name) {
    IntValue* iv = get_or_create_int_value(name);
    if (iv->head == NULL) {
        fprintf(stderr, "Erro: Tentativa de pop na pilha vazia '%s'.\n", name);
        exit(EXIT_FAILURE);
    }

    node* top = iv->head;
    int value = top->value;
    iv->head = top->next; // Atualiza o topo para o próximo elemento
    free(top);            // Libera o nó removido

    return value;
}

// Retorna o valor do topo sem remover
int peek_int_value(const char* name) {
    IntValue* iv = get_or_create_int_value(name);
    if (iv->head == NULL) {
        fprintf(stderr, "Erro: Tentativa de peek na pilha vazia '%s'.\n", name);
        exit(EXIT_FAILURE);
    }
    return iv->head->value;
}

// Verifica se a pilha está vazia
int is_empty_int_stack(const char* name) {
    IntValue* iv = get_or_create_int_value(name);
    return (iv->head == NULL);
}

// Retorna o tamanho da pilha
int get_int_stack_size(const char* name) {
    IntValue* iv = get_or_create_int_value(name);
    int count = 0;
    node* current = iv->head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
// Em nrUtils.c (ou onde suas funções de runtime estão)

void set_int_value(const char* name, int value) {
    // 1. Encontra a estrutura da pilha para a variável
    IntValue* iv = get_or_create_int_value(name);

    // 2. Verifica se a pilha está vazia
    if (iv->head != NULL) {
        // Se não estiver vazia, apenas atualiza o valor do topo
        iv->head->value = value;
    } else {
        // Se estiver vazia, empilha o valor.
        // Ele se tornará o novo topo.
        push_int_value(name, value);
    }
    // gerar_set_topo_pilha_llvm(modulo, builder, name, )
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
    // Symbol *sym = get_symbol(name);
    // if (!sym || sym->type != INT_VAR) {
    //     fprintf(stderr, "Erro: variável inteira '%s' não encontrada ou tipo incorreto!\n", name);
    //     exit(EXIT_FAILURE);
    // }

    // // Se tiver llvm_ref e contexto de compilação (builder), tenta ler de LLVM
    // if (sym->llvm_ref) {
    //     // Gera instrução de load
    //     LLVMValueRef loaded = LLVMBuildLoad2(builder, LLVMInt32Type(), sym->llvm_ref, "tmp_load");

    //     // Se for constante (LLVMConstInt), conseguimos extrair valor em tempo de compilação
    //     if (LLVMIsAConstantInt(loaded)) {
    //         return (int) LLVMConstIntGetSExtValue((LLVMConstantIntRef) loaded);
    //     } else {
    //         fprintf(stderr, "Erro: valor de '%s' não é constante em tempo de compilação\n", name);
    //         exit(EXIT_FAILURE);
    //     }
    // }

    // // Se não tem llvm_ref, busca na tabela de valores
    // unsigned int index = hash(name);
    // IntValue *val = intTable[index];
    // while (val) {
    //     if (strcmp(val->name, name) == 0) {
    //         return val->value;
    //     }
    //     val = val->next;
    // }

    // fprintf(stderr, "Erro: valor de '%s' não encontrado na tabela de inteiros!\n", name);
    // exit(EXIT_FAILURE);
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
    // for (int i = 0; i < TABLE_SIZE; i++) {
    //     IntValue *val = intTable[i];
    //     while (val) {
    //         printf("[%s = %d] -> ", val->name, val->value);
    //         val = val->next;
    //     }
    // }
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
void desativar_todos_personagens(void) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Symbol *symbol = symbolTable[i];
        while (symbol) {
            if (symbol->type == INT_VAR) {
                symbol->active = 0; // Desativa o personagem
            }
            symbol = symbol->next;
        }
    }
}
// Ativa o cenário atual e desativa todos os outros
void ativar_cenario(const char *nome) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Symbol *symbol = symbolTable[i];
        while (symbol) {
            if (symbol->type == STRING_VAR) {
                if (strcmp(symbol->name, nome) == 0) {
                    symbol->active = 1; // Ativa o cenário
                } else {
                    symbol->active = 0; // Desativa outros personagens
                }
            }
            symbol = symbol->next;
        }
    }
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
    size_t len = strlen(a_trim) + strlen(b_trim) + 2;
    char* res = (char *) malloc(len);
    snprintf(res, len, "%s %s", a_trim, b_trim);
    // free(a);
    // free(b);
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
    // 1. Obtém o símbolo e verifica se é uma PILHA de inteiros
    Symbol *sym = get_symbol(nome);
    if (!sym || sym->type != INT_VAR) {
        fprintf(stderr, "Erro: variável '%s' não é uma pilha de inteiros.\n", nome);
        return;
    }

    // 2. Declara a função printf (código existente está correto)
    LLVMTypeRef printf_type = LLVMFunctionType(
        LLVMInt32TypeInContext(contexto),
        (LLVMTypeRef[]){ LLVMPointerType(LLVMInt8TypeInContext(contexto), 0) },
        1, 1);
    LLVMValueRef printf_func = LLVMGetNamedFunction(modulo, "printf");
    if (!printf_func) {
        printf_func = LLVMAddFunction(modulo, "printf", printf_type);
    }

    // 3. Cria as strings de formato para o printf (código existente está correto)
    LLVMValueRef fmt = LLVMBuildGlobalStringPtr(builder, "%s: Sou %d!\\n", "fmt_str");
    LLVMValueRef nome_str = LLVMBuildGlobalStringPtr(builder, nome, "var_name_str");

    // 4. OBTÉM O VALOR DO TOPO DA PILHA (gera call @peek_int_value)
    //    Esta é a principal mudança.
    LLVMValueRef valor = gerar_peek_llvm(modulo, builder, nome);

    // 5. Define os argumentos e gera a chamada para o printf (código existente está correto)
    LLVMValueRef args[] = { fmt, nome_str, valor };
    LLVMBuildCall2(builder, printf_type, printf_func, args, 3, "");
}

void gerar_leitura_inteiro(const char *nome) {
    Symbol *sym = get_symbol(nome);
    if (!sym) {
        fprintf(stderr, "Erro: A variável '%s' não foi declarada.\n", nome);
        print_symbols();
        return;
    }
    if (sym->type != INT_VAR) {
        fprintf(stderr, "Erro: A variável '%s' não é do tipo inteiro.\n", nome);
        return;
    }
    if (!sym->llvm_ref) {
        fprintf(stderr, "Erro: Referência de memória para a variável '%s' é inválida.\n", nome);
        return;
    }

    // printf("Digite valor de <nome>: ");
    LLVMTypeRef printf_type = LLVMFunctionType(
        LLVMInt32Type(), (LLVMTypeRef[]){ LLVMPointerType(LLVMInt8Type(), 0) }, 1, 1);
    LLVMValueRef printf_func = LLVMGetNamedFunction(modulo, "printf");
    if (!printf_func)
        printf_func = LLVMAddFunction(modulo, "printf", printf_type);

    char msg[256];
    snprintf(msg, sizeof(msg), "Digite o valor de %s: ", nome);
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

int while_stack_top = -1;

void push_while_blocks(LLVMBasicBlockRef cond, LLVMBasicBlockRef body, LLVMBasicBlockRef after) {
    if (while_stack_top + 1 >= MAX_WHILE_NESTING) {
        fprintf(stderr, "Erro: pilha de while cheia!\n");
        exit(EXIT_FAILURE);
    }
    while_stack_top++;
    while_stack[while_stack_top].cond_bb = cond;
    while_stack[while_stack_top].body_bb = body;
    while_stack[while_stack_top].after_bb = after;
}

WhileBlocks pop_while_blocks() {
    if (while_stack_top < 0) {
        fprintf(stderr, "Erro: pilha de while vazia!\n");
        exit(EXIT_FAILURE);
    }
    return while_stack[while_stack_top--];
}

WhileBlocks *peek_while_blocks() {
    if (while_stack_top < 0) return NULL;
    return &while_stack[while_stack_top];
}


void set_value_from_llvm(const char *name, LLVMValueRef val) {
    Symbol *sym = get_symbol(name);
    if (!sym) {
        fprintf(stderr, "Erro: variável '%s' não declarada!\n", name);
        exit(EXIT_FAILURE);
    }
    if (sym->type != INT_VAR) {
        fprintf(stderr, "Erro: variável '%s' não é do tipo inteiro!\n", name);
        exit(EXIT_FAILURE);
    }
    if (!sym->llvm_ref) {
        fprintf(stderr, "Erro: variável '%s' não tem referência LLVM!\n", name);
        exit(EXIT_FAILURE);
    }

    if (LLVMIsAConstantInt(val)) {
        int intval = (int) LLVMConstIntGetSExtValue(val);
        set_int_value(name, intval);
    } else {
        LLVMBuildStore(builder, val, sym->llvm_ref);
    }
}

