#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct {
    int horas, minutos;
} Tempo;

void contaTempo(int minutos, Tempo* tempo);

int main()
{

    Tempo* meuTempo = malloc(sizeof(Tempo));
    int minutos;

    printf("Quantos minutos se passaram desde o comeco do dia? \n");
    scanf("%d", &minutos);

    contaTempo(minutos, meuTempo);

    printf("%d horas e %d minutos", meuTempo->horas, meuTempo->minutos);

    return 0;
}

void contaTempo(int minutos, Tempo* tempo) {
    int htemp = minutos/60;
    int mtemp = minutos % 60;

    tempo->horas = htemp;
    tempo->minutos = mtemp;
}
