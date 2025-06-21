#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LLVMgen.h"

#define TABLE_SIZE 100

typedef enum {
    INT_VAR,
    FLOAT_VAR,
    CHAR_VAR,
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
} Symbol;

typedef struct IntValue {
    char *name;
    int value;
    struct IntValue *next;
} IntValue;

typedef struct FloatValue {
    char *name;
    float value;
    struct FloatValue *next;
} FloatValue;

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

// Tabelas globais - só devem ser **definidas** em um .c
extern Symbol *symbolTable[TABLE_SIZE];
extern IntValue *intTable[TABLE_SIZE];
extern FloatValue *floatTable[TABLE_SIZE];
extern BoolValue *boolTable[TABLE_SIZE];
extern StringValue *stringTable[TABLE_SIZE];

// Funções utilitárias
unsigned int hash(const char *str);
void add_symbol(const char *name, VarType type);
void set_int_value(const char *name, int value);
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
char* substituir_ocorrencias(const char* original, const char* alvo, const char* substituto);
char* trim(char* str);
char* concatena(char* a, char* b);

#endif // TABLE_H