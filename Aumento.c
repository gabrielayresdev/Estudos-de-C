#include <stdio.h>
#include <stdlib.h>

void implementaAumento(double* salario, double aumento);

int main()
{
    double salario = 1200;
    double aumento = 0.1;

    implementaAumento(&salario, aumento);

    printf("%f", salario);
    return 0;
}

void implementaAumento(double* salario, double aumento) {
    *salario = *salario * (aumento + 1);
}
