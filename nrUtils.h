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

