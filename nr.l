%{
    #include <stdio.h>
    #include <string.h> 
    #include "nrUtils.h"
    // Máquina de estados para o programa
    enum {
        DetectandoTitulo = 0,
        DeclarandoVariaveis = 1,
        DeclarandoAto = 2,
        DeclarandoCena = 3
    };
    int estado = DetectandoTitulo;
%}

%%

^ATO[ ]+(XL|L|X{0,3})(IX|IV|V?I{0,3})?[:].+\. {
    if (estado == DeclarandoVariaveis) {
        estado = DeclarandoAto;

        char romano[16];
        // Extrai a parte do número romano, usando a regex para segurança
        sscanf(yytext, "ATO %15[^:]", romano);

        int numero = romano_para_inteiro(romano);
        printf("ATO: %d\n", numero);
    }
}

^\tCENA[ ]+(XL|L|X{0,3})(IX|IV|V?I{0,3})?: {
    if (estado == DeclarandoAto) {
        estado = DeclarandoCena;

        char romano[16];
        sscanf(yytext, "CENA %15[^:]", romano);

        int numero = romano_para_inteiro(romano);
        printf("\tCENA: %d\n", numero);
    }
}

^[^\n:]+:[^\n.!?]+[.!?]   { /* Título do programa */
    if (estado == DetectandoTitulo) {
        printf("TITULO: %s\n", yytext);
        estado = DeclarandoVariaveis; // Apenas para ser mais explícito (estado++)
    } 
}

[A-Za-z ]+,.+\. { // Variáveis
    // Pegando apenas o nome da variável
    char varname[100];
    int i = 0;
    while (yytext[i] != ',' && yytext[i] != '\0') {
        varname[i] = yytext[i];
        i++;
    }
    varname[i] = '\0';
    if (estado == DeclarandoVariaveis) {
        printf("VARIAVEL: %s\n", varname);
    }
}



"\\[Entra [A-Za-z ]+\\]" {
    if (estado == DeclarandoCena) {
        char entrada[256];
        strncpy(entrada, yytext + 7, yyleng - 8); // Remove "[Entra " e o "]"
        entrada[yyleng - 8] = '\0';

        // Separar os nomes pela palavra " e "
        char *token = strtok(entrada, "e");
        while (token != NULL) {
            // Limpar espaços
            while (*token == ' ') token++;
            char *end = token + strlen(token) - 1;
            while (end > token && *end == ' ') *end-- = '\0';

            printf("ENTRADA: %s\n", token);
            token = strtok(NULL, "e");
        }
    }
}

"\\[Sai [A-Za-z ]+\\]" {
    if (estado == DeclarandoCena) {
        char saida[256];
        strncpy(saida, yytext + 5, yyleng - 6); // Remove "[Sai " e "]"
        saida[yyleng - 6] = '\0';

        // Separar nomes pela palavra " e "
        char *token = strtok(saida, "e");
        while (token != NULL) {
            // Limpar espaços extras
            while (*token == ' ') token++;
            char *end = token + strlen(token) - 1;
            while (end > token && *end == ' ') *end-- = '\0';

            printf("SAIDA: %s\n", token);
            token = strtok(NULL, "e");
        }
    }
}


"\\[Todos saem\\]" {
    if (estado == DeclarandoCena) {
        printf("SAIDA: TODOS\n");
    }
}


.|\n                            { /* ignora tudo o resto */ }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}