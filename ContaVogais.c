#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int contaVogais(char* str, int size);
int existemVogais(char ch);

int main()
{
    char str[] = "Gabriel Ayres Fortunato";
    int qtd = contaVogais(str, 25);


    printf("%d", qtd);
    return 0;
}

int contaVogais(char* str, int size) {
    int total = 0;

    for(int i = 0; i < size; i++) {
        if(existemVogais(*(str + i))) total += 1;
    }

    return total;
}

int existemVogais(char ch) {
    char c = tolower(ch);
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    return 0;
}

