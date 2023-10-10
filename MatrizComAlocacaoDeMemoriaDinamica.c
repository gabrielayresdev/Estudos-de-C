#include <stdio.h>
#include <stdlib.h>

int main()
{
    char **funcionarios;
    int x, y;
    printf("Quantidade de profissionais na sua equipe: \n");
    scanf("%d", &x);

    funcionarios = (int*) malloc(x * sizeof(char*));

    printf("Tamanho máximo dos nomes dos funcionários: \n");
    scanf("%d", &y);

    for(int i = 0; i < y; i++) {
        funcionarios[i] = malloc(y * sizeof(char));
    }


    getchar();
    for(int i = 0; i < x; i++) {
        printf("Digite o nome do funcionário: \n");
        fgets(funcionarios[i], y, stdin);
    }

    for(int i = 0; i < x; i++) {
        printf("Funcionário %d: %s \n", i, funcionarios[i]);
    }

}
