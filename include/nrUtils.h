#ifndef NR_UTILS_H
#define NR_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LLVMgen.h"

#define TABLE_SIZE 100

typedef enum {
    INT_VAR,
    STRING_VAR,
    BOOL_VAR
} VarType;

typedef struct Symbol {
    char *name;
    VarType type;
    struct Symbol *next;
    int active; // 1 para ativo, 0 para inativo
    //LLVM:
    LLVMValueRef llvm_ref; // ponteiro alocado com LLVMBuildAlloca
    LLVMTypeRef llvm_type;        // tipo LLVM (ex: LLVMInt32Type())
    PilhaInt *pilha;
} Symbol;

typedef struct node {
    struct node *next;
    int value;
} node;

typedef struct IntValue {
    char *name;
    node *head;
    struct IntValue *next;
} IntValue;


typedef struct BoolValue {
    char *name;
    int value;
    struct BoolValue *next;
} BoolValue;

typedef struct StringValue {
    char *name;
    char *value;
    struct StringValue *next;
} StringValue;

// Tabelas globais 
extern Symbol *symbolTable[TABLE_SIZE];
extern IntValue *intTable[TABLE_SIZE];
extern BoolValue *boolTable[TABLE_SIZE];
extern StringValue *stringTable[TABLE_SIZE];

// Funções utilitárias tabela de símbolos
unsigned int hash(const char *str);
void add_symbol(const char *name, VarType type);
void set_int_value(const char* name, int value);
void set_float_value(const char *name, float value);
void set_bool_value(const char *name, int value);
void set_string_value(const char *name, const char *value);
void print_symbols(void);
void print_values(void);
int get_int_value(const char *name);
float get_float_value(const char *name);
int get_bool_value(const char *name);
char *get_string_value(const char *name);
VarType get_variable_type(const char *name);
Symbol* get_symbol(const char *name);
void gerar_print_string(const char *nome);
void gerar_print_int(const char *nome);
void gerar_leitura_inteiro(const char *nome);
void desativar_todos_personagens(void);
void ativar_cenario(const char *nome);
// Funções utilitárias de manipulação de strings
char* substituir_ocorrencias(const char* original, const char* alvo, const char* substituto);
char* trim(char* str);
char* concatena(char* a, char* b);

void push_int_value(const char *name, int value);
int pop_int_value(const char *name);
int peek_int_value(const char *name);
int is_empty_int_stack(const char *name);
int get_int_stack_size(const char *name);


#define MAX_WHILE_NESTING 64

typedef struct {
    LLVMBasicBlockRef cond_bb;
    LLVMBasicBlockRef body_bb;
    LLVMBasicBlockRef after_bb;
} WhileBlocks;

 extern WhileBlocks while_stack[MAX_WHILE_NESTING];

void push_while_blocks(LLVMBasicBlockRef cond, LLVMBasicBlockRef body, LLVMBasicBlockRef after);

WhileBlocks pop_while_blocks();

WhileBlocks *peek_while_blocks();


void set_value_from_llvm(const char *name, LLVMValueRef val);
#endif // NR_UTILS_H