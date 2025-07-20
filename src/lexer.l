%{
    #include <stdio.h>
    #include <string.h> 
    #include "parser.tab.h"

    int DEBUG_LEX = 1;
    
    // Função auxiliar para converter números romanos para inteiros
    int romano_para_inteiro(const char *romano) {
        int valor = 0;
        while (*romano) {
            switch (*romano) {
                case 'M': valor += 1000; break;
                case 'D': valor += 500; break;
                case 'C':
                    if (*(romano + 1) == 'M') { valor += 900; romano++; }
                    else if (*(romano + 1) == 'D') { valor += 400; romano++; }
                    else valor += 100;
                    break;
                case 'L': valor += 50; break;
                case 'X':
                    if (*(romano + 1) == 'C') { valor += 90; romano++; }
                    else if (*(romano + 1) == 'L') { valor += 40; romano++; }
                    else valor += 10;
                    break;
                case 'V': valor += 5; break;
                case 'I':
                    if (*(romano + 1) == 'X') { valor += 9; romano++; }
                    else if (*(romano + 1) == 'V') { valor += 4; romano++; }
                    else valor += 1;
                    break;
            }
            romano++;
        }
        return valor;
    }
%}
%%
"#"([^\n#]|(\n))*"#"      { /* comentário multilinha */ }

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
(^|[ \t])E([ \t]|[.,?!]) {
    if (DEBUG_LEX) printf("TOKEN: E\n");
    yylval.texto = strdup(yytext);
    return E;
}

(O|A|AO|OS|AS|UM|UMA|UNS|UMAS)[ ] {
    if (DEBUG_LEX) printf("TOKEN: ARTIGO (%s)\n", yytext);
    yylval.texto = strdup(yytext);
    return ARTIGO;
}

"ONDE ESTAMOS?"|"ONDE ESTOU?" {
    if (DEBUG_LEX) printf("TOKEN: ONDE_ESTAMOS\n");
    yylval.texto = strdup(yytext);
    return MOSTRAR_CENARIO;
}

ADICIONE[ ]AO[ ]CENARIO {
    if (DEBUG_LEX) printf("TOKEN: ADICIONAR_CENARIO\n");
    yylval.texto = strdup(yytext);
    return ADICIONAR_CENARIO;
}

SUBSTITUIR[ ]CENARIO {
    if (DEBUG_LEX) printf("TOKEN: SUBSTITUIR_CENARIO\n");
    yylval.texto = strdup(yytext);
    return SUBSTITUIR_CENARIO;
}

POR {
    if (DEBUG_LEX) printf("TOKEN: POR\n");
    yylval.texto = strdup(yytext);
    return POR;
}

NO[ ]CENARIO {
    if (DEBUG_LEX) printf("TOKEN: NO_CENARIO\n");
    yylval.texto = strdup(yytext);
    return NO_CENARIO;
}

SE {
    if (DEBUG_LEX) printf("TOKEN: SE\n");
    yylval.texto = strdup(yytext);
    return SE;
}

SIM {
    if (DEBUG_LEX) printf("TOKEN: SIM\n");
    yylval.texto = strdup(yytext);
    return SIM;
}

NAO {
    if (DEBUG_LEX) printf("TOKEN: NAO\n");
    yylval.texto = strdup(yytext);
    return NAO;
}

EU {
    if (DEBUG_LEX) printf("TOKEN: EU\n");
    yylval.texto = strdup(yytext);
    return EU;
}

ENTAO {
    if (DEBUG_LEX) printf("TOKEN: ENTAO\n");
    yylval.texto = strdup(yytext);
    return ENTAO;
}

FOR {
    if (DEBUG_LEX) printf("TOKEN: FOR\n");
    yylval.texto = strdup(yytext);
    return FOR;
}
 
(ENTRE)|(DE) {
    if (DEBUG_LEX) printf("TOKEN: ENTRE\n");
    yylval.texto = strdup(yytext);
    return ENTRE;
}
(MESMA|MESMO|MESMAS|MESMOS) {
    if (DEBUG_LEX) printf("TOKEN: MESMO\n");
    yylval.texto = strdup(yytext);
    return MESMO;
}
(TU|VOCÊ) {
    if (DEBUG_LEX) printf("TOKEN: TU\n");
    yylval.texto = strdup(yytext);
    return TU;
}
(É|ÉS) {
    if (DEBUG_LEX) printf("TOKEN: É\n");
    yylval.texto = strdup(yytext);
    return EH;
}
(SAEM|SAI) {
    if (DEBUG_LEX) printf("TOKEN: SAEM\n");
    yylval.texto = strdup(yytext);
    return SAEM;
}

TODOS {
    if (DEBUG_LEX) printf("TOKEN: TODOS\n");
    yylval.texto = strdup(yytext);
    return TODOS;
}

(ENTRAM|ENTRA) {
    if (DEBUG_LEX) printf("TOKEN: ENTRAM\n");
    yylval.texto = strdup(yytext);
    return ENTRAM;
}

, {
    if (DEBUG_LEX) printf("TOKEN: VIRGULA\n");
    return VIRGULA;
}
SOMA {
    if (DEBUG_LEX) printf("TOKEN: SOMA\n");
    yylval.texto = strdup(yytext);
    return SOMAR;
}

SUBTRAÇÃO {
    if (DEBUG_LEX) printf("TOKEN: SUBTRAÇÃO\n");
    yylval.texto = strdup(yytext);
    return SUBTRAIR;
}

DIVISÃO {
    if (DEBUG_LEX) printf("TOKEN: DIVISÃO\n");
    yylval.texto = strdup(yytext);
    return DIVIDIR;
}

MULTIPLICAÇÃO {
    if (DEBUG_LEX) printf("TOKEN: MULTIPLICAÇÃO\n");
    yylval.texto = strdup(yytext);
    return MULTIPLICAR;
}

(MAIS[ \t]+QUE)|(MAIOR[ \t]+QUE)   {
    if (DEBUG_LEX) printf("TOKEN: MAIOR\n");
    yylval.texto = strdup(yytext);
    return MAIOR;
}

(MENOS[ \t]+QUE)|(MENOR[ \t]+QUE) {
    if (DEBUG_LEX) printf("TOKEN: MENOR\n");
    yylval.texto = strdup(yytext);
    return MENOR;
}

ABRE[ ]TEU[ ]CORACAO[ ]MISERAVEL {
    if (DEBUG_LEX) printf("TOKEN: MOSTRA_VALOR\n");
    yylval.texto = strdup(yytext);
    return MOSTRA_VALOR;
}
ESCUTA[ ]TEU[ ]CORACAO[ ]MISERAVEL {
    if (DEBUG_LEX) printf("TOKEN: LE_VALOR\n");
    yylval.texto = strdup(yytext);
    return LE_VALOR;
}

IGUAL[ \t]+QUE {
    if (DEBUG_LEX) printf("TOKEN: IGUAL\n");
    yylval.texto = strdup(yytext);
    return IGUAL;
}

ENQUANTO {
    if (DEBUG_LEX) printf("TOKEN: ENQUANTO_COMECO\n");
    yylval.texto = strdup(yytext);
    return ENQUANTO_COMECO;
}

ACABA {
    if (DEBUG_LEX) printf("TOKEN: ENQUANTO_FIM\n");
    yylval.texto = strdup(yytext);
    return ENQUANTO_FIM;
}

"ASSIM SE CALA O DESTINO!"|"E TUDO SE ENCERRA!"|"FIM DAS ILUSÕES!"|"A VERDADE SE RECOLHE!"|"A SENTENÇA FINDA!" {
    if (DEBUG_LEX) printf("TOKEN: ENDIF\n");
    yylval.texto = strdup(yytext);
    return ENDIF;
}

PRIMEIRO {
    if (DEBUG_LEX) printf("TOKEN: FACA\n");
    yylval.texto = strdup(yytext);
    return FACA;
}

RAZÃO {
    if (DEBUG_LEX) printf("TOKEN: DIVIDIR\n");
    yylval.texto = strdup(yytext);
    return DIVIDIR;
}

PRODUTO {
    if (DEBUG_LEX) printf("TOKEN: MULTIPLICAR\n");
    yylval.texto = strdup(yytext);
    return MULTIPLICAR;
}

: {
    if (DEBUG_LEX) printf("TOKEN: INICIO\n");
    return INICIO;
}

[.!] {
    if (DEBUG_LEX) printf("TOKEN: FIM\n");
    return FIM;
}
\? {
    if (DEBUG_LEX) printf("TOKEN: INTERROGACAO\n");
    return INTERROGACAO;
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

(BACANA|LEGAL|BELO|BELA|DOCE) {
    if (DEBUG_LEX) printf("TOKEN: ADJETIVO_POSITIVO (%s)\n", yytext);
    yylval.texto = strdup(yytext);
    return ADJETIVO_POSITIVO;
}
(PODRE|CANALHA) {
    if (DEBUG_LEX) printf("TOKEN: ADJETIVO_NEGATIVO (%s)\n", yytext);
    yylval.texto = strdup(yytext);
    return ADJETIVO_NEGATIVO;
}
(VAMOS|VOLTEMOS) {
    if (DEBUG_LEX) printf("TOKEN: VOLTAR CENÁRIO\n");
    yylval.texto = strdup(yytext);
    return VOLTAR_CENARIO;
}
[A-Za-z]+ {
    if (DEBUG_LEX) printf("TOKEN: TOKEN (%s)\n", yytext);
    yylval.texto = strdup(yytext);
    return TOKEN;
}


.|\n                                { /* ignora tudo o resto */ }

%%


int yywrap() {
    return 1;
}