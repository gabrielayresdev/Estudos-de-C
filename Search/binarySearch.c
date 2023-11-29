#include <stdio.h>
#include <stdlib.h>


int binaria(int * vet, int inicio, int fim, int alvo) {
    if(inicio <= fim) {
        int meio = (inicio + fim)/2;
        if(alvo < vet[meio]) return binaria(vet, inicio, meio - 1, alvo);
        else if (alvo > vet[meio]) return binaria(vet, meio + 1, fim, alvo);
        else if (alvo == vet[meio]) return meio;
    }
    return -1;
}

int main()
{
    int vet1[] = {-1, 0, 1, 10, 15, 16, 20, 100, 101, 2000};

    int index = binaria(vet1, 0, 10, 0);

    if(index > -1) printf("O alvo esta no index %d", index);
    else printf("Alvo não encontrado");

    return 0;
}
