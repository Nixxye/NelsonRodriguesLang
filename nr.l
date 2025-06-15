%{
    #include <stdio.h>
    #include <string.h> 
    #include "nrUtils.h"
    #include "nr.tab.h"
    // enum ESTADOS {
    //     TITULO = 0,
    //     ATO = 1,
    //     CENA = 2,
    // };
    // int estado = 0;
%}

%%
#.+\n { // Comentário 
}
^ATO[ ]+(XL|L|X{0,3})(IX|IV|V?I{0,3})?[:].+\. {
    char romano[16];
    // Extrai a parte do número romano, usando a regex para segurança
    sscanf(yytext, "ATO %15[^:]", romano);

    int numero = romano_para_inteiro(romano);
    return ATO;
}

^\tCENA[ ]+(XL|L|X{0,3})(IX|IV|V?I{0,3})?: {
    char romano[16];
    sscanf(yytext, "CENA %15[^:]", romano);

    int numero = romano_para_inteiro(romano);
    printf("\tCENA: %d\n", numero);
}
(?i:saem) {
    return SAEM;
}
(?i:todos) {
    return TODOS;
}

(?i:mais) {
    return SOMAR;
}

(?i:menos) {
    return SUBTRAIR;
}

(?i:razão) {
   return DIVIDIR; 
}

(?i:produto) {
    return MULTIPLICAR;
}

: {
    return INICIO;
}

[.!?] {
    return FIM;
}
"[" {
    return ABRE_COLCHETES;
}
"]" {
    return FECHA_COLCHETES;
}
"(" {
    return ABRE_PARENTESES;
}
")" {
    return FECHA_PARENTESES;
}

[0-9]+\.[0-9]+ {
    return NUMERO;
}

.|\n                            { /* ignora tudo o resto */ }

(?i:bacana)|(?i:legal)|(?i:belo)|(?i:bela) {
   return VIRGULA; 
}

[A-Za-z]+ { // Token
    return TOKEN;
}


%%


int yywrap() {
    return 1;
}