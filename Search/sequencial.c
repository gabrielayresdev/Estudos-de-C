#include <stdio.h>
#include <stdlib.h>


int sequencial(int * vet, int tam, int alvo) {
    int index = -1;
    for(int i = 0; i < tam; i++) {
        if(vet[i] == alvo) return i;
    }
    return index;
}

int main()
{
    int vet1[] = {1, 32, -1, 0, 34223, 512, 3, 5, 9, 8};

    int index = sequencial(vet1, 10, -1);

    if(index > -1) printf("O alvo esta no index %d", index);
    else printf("Alvo não encontrado");

    return 0;
}
