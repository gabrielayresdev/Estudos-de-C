#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    char country[20];
    int age;
} Pessoa;

void cadastraFuncionario(Pessoa *p) {
    // ! Resolver bug em que nome maior que 15 caracteres não é lido
    printf("Nome: \n");
    fgets(&p->name, 100, stdin);
    printf("%d", sizeof(p->name));
    printf("Pais: \n");
    fgets(&p->country, 20, stdin);
    printf("Idade: \n");
    scanf("%d", &p->age);
}

int main()
{
    char option;
    printf("a - Adicionar funcionario\n");
    printf("w - Criar nova lista de funcionarios\n");
    scanf("%c", &option);

    FILE * registro;
    if(option == 'a') {
        registro = fopen("registro.txt", "a");
    } else if (option == 'w') {
        registro = fopen("registro.txt", "w");
    } else return -1;


    Pessoa *funcionario;


    if(registro == NULL) return -1;

    getchar();
    cadastraFuncionario(funcionario);


    fprintf(registro, "\n%s | %s | %d anos", funcionario->name, funcionario->country, funcionario->age);
}
