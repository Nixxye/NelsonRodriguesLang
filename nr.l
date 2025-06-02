%{
    #include <stdio.h>
    #include <string.h> 
    #include "nrUtils.h"
    enum ESTADOS {
        TITULO = 0,
        ATO = 1,
        CENA = 2,
    };
    int estado = 0;
%}

%%
#.+\n { // Comentário 
}
^ATO[ ]+(XL|L|X{0,3})(IX|IV|V?I{0,3})?[:].+\. {
    char romano[16];
    // Extrai a parte do número romano, usando a regex para segurança
    sscanf(yytext, "ATO %15[^:]", romano);

    int numero = romano_para_inteiro(romano);
    printf("ATO: %d\n", numero);
}

^\tCENA[ ]+(XL|L|X{0,3})(IX|IV|V?I{0,3})?: {
    char romano[16];
    sscanf(yytext, "CENA %15[^:]", romano);

    int numero = romano_para_inteiro(romano);
    printf("\tCENA: %d\n", numero);
}
(?i:saem) {
    printf("SAEM\n");
}
(?i:todos) {
    printf("TODOS\n");
}

(?i:mais) {
    printf("MAIS\n");
}

(?i:menos) {
    printf("MENOS\n");
}

(?i:razão) {
    printf("DIVIDIR\n");
}

(?i:produto) {
    printf("MULTIPLICAR\n");
}

: {
    printf("BEGIN\n");
}

[.!] {
    printf("END\n");
}
"[" {
    printf("ABRE COLCHETES\n");
}
"]" {
    printf("FECHA COLCHETES\n");
}
"(" {
    printf("ABRE PARENTESES\n");
}
")" {
    printf("FECHA PARENTESIS\n");
}

[0-9]+\.[0-9]+ {
    printf("NUMERO: %s\n", yytext);
}

.|\n                            { /* ignora tudo o resto */ }

[A-Za-z]+ { // Token
    printf("TOKEN: %s\n", yytext);
}


%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}