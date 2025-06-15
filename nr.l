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
    int DEBUG_LEX = 0;
%}

%%
#.+# { // Comentário 
}
^ATO[ ]+(XL|L|X{0,3})(IX|IV|V?I{0,3})?[:].+\. {
    char romano[16];
    sscanf(yytext, "ATO %15[^:]", romano);
    int numero = romano_para_inteiro(romano);
    if (DEBUG_LEX) printf("TOKEN: ATO (%s)\n", yytext);
    return ATO;
}

^\tCENA[ ]+(XL|L|X{0,3})(IX|IV|V?I{0,3})?: {
    char romano[16];
    sscanf(yytext, "CENA %15[^:]", romano);
    int numero = romano_para_inteiro(romano);
    if (DEBUG_LEX) printf("TOKEN: CENA (%s)\n", yytext);
    return CENA;
}

(?i:saem)|(?i:sai) {
    if (DEBUG_LEX) printf("TOKEN: SAEM\n");
    return SAEM;
}

(?i:todos) {
    if (DEBUG_LEX) printf("TOKEN: TODOS\n");
    return TODOS;
}

(?i:entram)|(?i:entra) {
    if (DEBUG_LEX) printf("TOKEN: ENTRAM\n");
    return ENTRAM;
}

, {
    if (DEBUG_LEX) printf("TOKEN: VIRGULA\n");
    return VIRGULA;
}

(?i:mais) {
    if (DEBUG_LEX) printf("TOKEN: SOMAR\n");
    return SOMAR;
}

(?i:menos) {
    if (DEBUG_LEX) printf("TOKEN: SUBTRAIR\n");
    return SUBTRAIR;
}

(?i:razão) {
    if (DEBUG_LEX) printf("TOKEN: DIVIDIR\n");
    return DIVIDIR;
}

(?i:produto) {
    if (DEBUG_LEX) printf("TOKEN: MULTIPLICAR\n");
    return MULTIPLICAR;
}

: {
    if (DEBUG_LEX) printf("TOKEN: INICIO\n");
    return INICIO;
}

[.!?] {
    if (DEBUG_LEX) printf("TOKEN: FIM\n");
    return FIM;
}

"[" {
    if (DEBUG_LEX) printf("TOKEN: ABRE_COLCHETES\n");
    return ABRE_COLCHETES;
}

"]" {
    if (DEBUG_LEX) printf("TOKEN: FECHA_COLCHETES\n");
    return FECHA_COLCHETES;
}

"(" {
    if (DEBUG_LEX) printf("TOKEN: ABRE_PARENTESES\n");
    return ABRE_PARENTESES;
}

")" {
    if (DEBUG_LEX) printf("TOKEN: FECHA_PARENTESES\n");
    return FECHA_PARENTESES;
}

[0-9]+\.[0-9]+ {
    if (DEBUG_LEX) printf("TOKEN: NUMERO (%s)\n", yytext);
    return NUMERO;
}

(?i:bacana)|(?i:legal)|(?i:belo)|(?i:bela) {
    if (DEBUG_LEX) printf("TOKEN: ADJETIVO_POSITIVO (%s)\n", yytext);
    return ADJETIVO_POSITIVO;
}

[A-Za-z]+ {
    if (DEBUG_LEX) printf("TOKEN: TOKEN (%s)\n", yytext);
    yylval.texto = strdup(yytext);   // <-- AQUI ATRIBUI O VALOR
    return TOKEN;
}


.|\n                            { /* ignora tudo o resto */ }

%%


int yywrap() {
    return 1;
}