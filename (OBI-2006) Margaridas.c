#include <stdio.h>
#include <stdlib.h>

int contaFlores(FILE* file);

int main()
{
    FILE* f = fopen("src.txt", "r");

    if(!f) printf("Arquivo nao encontrado");


    int max = contaFlores(f);

    printf("%d", max);

    return 0;
}


int contaFlores(FILE* file) {
    int L, C, M, N;

    fscanf(file, "%d %d %d %d", &L, &C, &M, &N);

    int ** flores = malloc(L * sizeof(int*));

    for(int i = 0; i < L; i++) {
        flores[i] = malloc(C * sizeof(int));
    }

    for(int i = 0; i < L; i++) {
        for(int j = 0; j < C; j++) {
            fscanf(file, "%d", &flores[i][j]);
        }
    }

    int max = 0;
    for(int i = 0; i < L; i += M) {
        for(int j = 0; j < C; j += N) {
            int atual = 0;
            for(int a = 0; a < M; a++) {
                for(int b = 0; b < N; b++) {
                    //printf("%d\n", flores[i + a][j + b]);
                    atual +=  flores[i + a][j + b];
                }
            }
            if(atual > max) max = atual;
        }
    }

    return max;
}