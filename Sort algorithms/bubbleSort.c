#include <stdio.h>
#include <stdlib.h>

void printVet(int * vet, int tam) {
    printf("{");
    for(int i = 0; i < tam; i++) {
        printf(" %d ", vet[i]);
    }
    printf("}\n");
}

void changeItens(int * a, int * b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

/*
O bubble sort se baseia na comparação de elementos consecutivos do array e na troca desses elementos quando o primeiro for maior que o segundo.
Melhor caso: O(n)
Pior caso: O(n^2)
*/
void bubbleSort(int * vet, int tam) {
    for(int i = tam - 1; i > 0; i--) {
        for(int j = 0; j < i ; j++) {
            if(vet[j] > vet[j + 1]) changeItens(&vet[j], &vet[j + 1]);
        }
    }
}

int main()
{
    int vet1[] = {1, 32, -1, 0, 34223, 512, 3, 5, 9, 8};
    int vet2[] = {1};
    int vet3[] = {3, 1};

    printVet(vet1, 10);
    printVet(vet2, 1);
    printVet(vet3, 2);
    printf("--------------- SORT ---------------\n");
    bubbleSort(vet1, 10);
    bubbleSort(vet2, 1);
    bubbleSort(vet3, 2);

    printVet(vet1, 10);
    printVet(vet2, 1);
    printVet(vet3, 2);
    return 0;
}
