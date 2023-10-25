#include <stdio.h>
#include <stdlib.h>

double converteEmMinutos(int h, int m, int s);
int verificarVencedor(FILE* file);


int main()
{
    FILE* f = fopen("src.txt", "r");

    if(!f) {
        printf("Arquivo não aberto");
        return -1;
    }

    int maisRapido = verificarVencedor(f);

    printf("Corredor mais rápido: %d", maisRapido);

    return 0;
}


double converteEmMinutos(int h, int m, int s) {
    return h * 60 + m + s / 60;
}

int verificarVencedor(FILE* file) {
    int competidores, corridas, maisRapido;

    fscanf(file, "%d %d", &competidores, &corridas);
    double menorTempo;
    for(int i = 0; i < competidores; i++) {
        int h = 0,m = 0,s = 0;
        for(int j = 0; j < corridas; j++) {
            int htemp, mtemp, stemp;

            fscanf(file, "%d %d %d", &htemp, &mtemp, &stemp);
            h += htemp;
            m += mtemp;
            s += stemp;
        }
        double currentTime = converteEmMinutos(h,m,s);
        printf("%f\n", currentTime);
        if(i == 0) menorTempo = currentTime;

        if(currentTime < menorTempo) {
            menorTempo = currentTime;
            maisRapido = i;
        }
    }
    return maisRapido;

}
