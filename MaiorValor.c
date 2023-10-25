#include <stdio.h>
#include <stdlib.h>

int maiorValor(int* valores, int tamanho);
void leValores(int* valores, int tamanho);

int main()
{
    int tamanho;
    printf("Qual o tamanho do vetor? \n");
    scanf("%d", &tamanho);

    int* valores = malloc(tamanho * sizeof(int));
    leValores(valores, tamanho);

    int maior = maiorValor(valores, tamanho);

    printf("Valor %d e o maior valor", maior + 1);

    return 0;
}

int maiorValor(int* valores, int tamanho) {
    int maior = 0;
    for(int i = 0; i < tamanho; i++) {
        if(valores[i] > valores[maior]) maior = i;
    }
    return maior;
}

void leValores(int* valores, int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("\nDigite o valor %d: ", i+1);
        scanf("%d", &valores[i]);
    }
}
