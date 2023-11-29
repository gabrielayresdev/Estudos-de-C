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

void merge(int start, int middle, int end, int * vet) {

    int tam1 = middle - start  + 1;
    int tam2 = end - middle;


    int seq1[tam1];
    for(int i = 0; i < tam1; i++) {
        seq1[i] = vet[start + i];
    }
    //printf("Seq1 - tam: %d - ", tam1);
    //printVet(seq1, tam1);

    int seq2[tam2];
    for(int i = 0; i < tam2; i++) {
        seq2[i] = vet[middle + 1 + i];
    }
    //printf("Seq2 - tam: %d - ", tam2);
    //printVet(seq2, tam2);

    int i = 0, j = 0, z = start;
    while(i < tam1 && j < tam2) {
        if(seq1[i] <= seq2[j]) {
            vet[z] = seq1[i];
            i++;
        } else {
            vet[z] = seq2[j];
            j++;
        }
        z++;
    }

    while(i < tam1) vet[z++] = seq1[i++];

    while(j < tam2) vet[z++] = seq2[j++];

}

/*
O merge sort utiliza da técnica dividir para conquistar, onde o array é divido em dois consecutivamente até que exista apenas um elemento no array, então essas pequenas partes são ordenadas pelo algoritmo merge.
Melhor caso: O(n log(n))
Pior caso: O(n log(n))
*/
void mergeSort(int * vet, int start, int end) {
    if(start < end) {
        int meio = (start + end) / 2;
        mergeSort(vet, start, meio);
        mergeSort(vet, meio + 1, end);
        merge(start, meio, end, vet);
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
    mergeSort(vet1, 0, 10);
    //mergeSort(vet2, 0, 1);
    //mergeSort(vet3, 0, 2);

    printVet(vet1, 10);
    printVet(vet2, 1);
    printVet(vet3, 2);
    return 0;
}
