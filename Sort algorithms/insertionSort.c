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
O insertion sort itera pelo array deslocando os elementos enquanto eles forem menor que os elementos anteriores
Melhor caso: O(n)
Pior caso: O(n^2)
*/
void insertionSort(int * vet, int tam) {
    int j;
    for(int i = 1; i < tam; i++) {
        int aux = vet[i];
        for(j = i; (j > 0) && (aux < vet[j - 1]) ; j--) {
            vet[j] = vet[j - 1];
        }
        vet[j] = aux;
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
    insertionSort(vet1, 10);
    insertionSort(vet2, 1);
    insertionSort(vet3, 2);

    printVet(vet1, 10);
    printVet(vet2, 1);
    printVet(vet3, 2);
    return 0;
}
