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
    int DEBUG_LEX = 1;
%}
%%
#.+# { // Comentário 
}
^ATO[ ]+(XL|L|X{0,3})(IX|IV|V?I{0,3})?[:].+\. {
    char romano[16];
    sscanf(yytext, "ATO %15[^:]", romano);
    int numero = romano_para_inteiro(romano);
    if (DEBUG_LEX) printf("TOKEN: ATO (%s)\n", yytext);
    yylval.inteiro = numero;
    return ATO;
}

^\tCENA[ ]+(XL|L|X{0,3})(IX|IV|V?I{0,3})?: {
    char romano[16];
    sscanf(yytext, "CENA %15[^:]", romano);
    int numero = romano_para_inteiro(romano);
    if (DEBUG_LEX) printf("TOKEN: CENA (%s)\n", yytext);
    yylval.inteiro = numero;
    return CENA;
}
(^|[ \t])[eE]([ \t]|[.,?!]) {
    if (DEBUG_LEX) printf("TOKEN: E\n");
    yylval.texto = strdup(yytext);
    return E;
}

(?i:[o|a|os|as|um|uma|uns|umas])[ ] {
    if (DEBUG_LEX) printf("TOKEN: ARTIGO (%s)\n", yytext);
    yylval.texto = strdup(yytext);
    return ARTIGO;
}

(?i:onde[ ]estamos\?)|(?i:onde[ ]estou\?) {
    if (DEBUG_LEX) printf("TOKEN: ONDE_ESTAMOS\n");
    yylval.texto = strdup(yytext);
    return MOSTRAR_CENARIO;
}

[aA][dD][iI][cC][iI][oO][nN][eE][ ][aA][oO][ ][cC][eE][nN][aA][rR][iI][oO] {
    if (DEBUG_LEX) printf("TOKEN: ADICIONAR_CENARIO\n");
    yylval.texto = strdup(yytext);
    return ADICIONAR_CENARIO;
}

[Ss][Uu][Bb][Ss][Tt][Ii][Tt][Uu][Aa] {
    if (DEBUG_LEX) printf("TOKEN: SUBSTITUIR_CENARIO\n");
    yylval.texto = strdup(yytext);
    return SUBSTITUIR_CENARIO;
}

[Pp][Oo][Rr] {
    if (DEBUG_LEX) printf("TOKEN: POR\n");
    yylval.texto = strdup(yytext);
    return POR;
}

[Nn][Oo][ ][Cc][Ee][Nn][Aa][Rr][Ii][Oo] {
    if (DEBUG_LEX) printf("TOKEN: NO_CENARIO\n");
    yylval.texto = strdup(yytext);
    return NO_CENARIO;
}

(?i:entre)|(?i:de) {
    if (DEBUG_LEX) printf("TOKEN: ENTRE\n");
    yylval.texto = strdup(yytext);
    return ENTRE;
}
(?:mesma)|(?i:mesmo)|(?i:mesmas)|(?i:mesmos) {
    if (DEBUG_LEX) printf("TOKEN: MESMO\n");
    yylval.texto = strdup(yytext);
    return MESMO;
}
(?i:tu)|(?i:você) {
    if (DEBUG_LEX) printf("TOKEN: TU\n");
    yylval.texto = strdup(yytext);
    return TU;
}
(?i:é)|(?i:és) { // acentuação depois
    if (DEBUG_LEX) printf("TOKEN: É\n");
    yylval.texto = strdup(yytext);
    return EH;
}
(?i:saem)|(?i:sai) {
    if (DEBUG_LEX) printf("TOKEN: SAEM\n");
    yylval.texto = strdup(yytext);
    return SAEM;
}

(?i:todos) {
    if (DEBUG_LEX) printf("TOKEN: TODOS\n");
    yylval.texto = strdup(yytext);
    return TODOS;
}

(?i:entram)|(?i:entra) {
    if (DEBUG_LEX) printf("TOKEN: ENTRAM\n");
    yylval.texto = strdup(yytext);
    return ENTRAM;
}

, {
    if (DEBUG_LEX) printf("TOKEN: VIRGULA\n");
    return VIRGULA;
}
(?i:soma) {
    if (DEBUG_LEX) printf("TOKEN: SOMA\n");
    yylval.texto = strdup(yytext);
    return SOMAR;
}

(?i:subtração) {
    if (DEBUG_LEX) printf("TOKEN: SUBTRAÇÃO\n");
    yylval.texto = strdup(yytext);
    return SUBTRAIR;
}

(?i:divisão) {
    if (DEBUG_LEX) printf("TOKEN: DIVISÃO\n");
    yylval.texto = strdup(yytext);
    return DIVIDIR;
}

(?i:multiplicação) {
    if (DEBUG_LEX) printf("TOKEN: MULTIPLICAÇÃO\n");
    yylval.texto = strdup(yytext);
    return MULTIPLICAR;
}
(?i:mais) {
    if (DEBUG_LEX) printf("TOKEN: SOMAR\n");
    yylval.texto = strdup(yytext);
    return SOMAR;
}

(?i:menos) {
    if (DEBUG_LEX) printf("TOKEN: SUBTRAIR\n");
    yylval.texto = strdup(yytext);
    return SUBTRAIR;
}

(?i:razão) {
    if (DEBUG_LEX) printf("TOKEN: DIVIDIR\n");
    yylval.texto = strdup(yytext);
    return DIVIDIR;
}

(?i:produto) {
    if (DEBUG_LEX) printf("TOKEN: MULTIPLICAR\n");
    yylval.texto = strdup(yytext);
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

[0-9]+ {
    if (DEBUG_LEX) printf("TOKEN: NUMERO (%s)\n", yytext);
    yylval.texto = strdup(yytext);
    return NUMERO;
}

(?i:bacana)|(?i:legal)|(?i:belo)|(?i:bela)|(?i:code)|(?i:pudim)|(?i:doce) {
    if (DEBUG_LEX) printf("TOKEN: ADJETIVO_POSITIVO (%s)\n", yytext);
    yylval.texto = strdup(yytext);
    return ADJETIVO_POSITIVO;
}
(?i:podre)|(?i:canalha) {
    if (DEBUG_LEX) printf("TOKEN: ADJETIVO_NEGATIVO (%s)\n", yytext);
    yylval.texto = strdup(yytext);
    return ADJETIVO_NEGATIVO;
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