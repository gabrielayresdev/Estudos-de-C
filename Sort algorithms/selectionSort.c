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
O selection sort ordena um array através de consecutivas iterações que buscam o menor ou maior valor e o coloca na posição correta.
Melhor caso: O(n^2)
Pior caso: O(n^2)
*/
void selectionSort(int * vet, int tam) {
    for(int i = tam - 1; i > 0; i--) {
        int biggest = i;
        for(int j = 0; j < i ; j++) {
            if(vet[j] > vet[biggest]) biggest = j;
        }
        changeItens(&vet[i], &vet[biggest]);
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
    selectionSort(vet1, 10);
    selectionSort(vet2, 1);
    selectionSort(vet3, 2);

    printVet(vet1, 10);
    printVet(vet2, 1);
    printVet(vet3, 2);
    return 0;
}
