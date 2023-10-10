#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[100];
    char country[20];
    int age;
} Person;

int main()
{
    Person person1;

    printf("Digite seu nome: \n");
    fgets(&person1.name, 100, stdin);
    person1.name[strcspn(person1.name, "\n")] = '\0';
    printf("Digite seu país: \n");
    fgets(&person1.country, 20, stdin);
    printf("Digite sua idade: \n");
    scanf("%d", &person1.age);


    printf("===== Ficha %s ===== \n", person1.name);
    printf("Nacionalidade: %s \n", person1.country);
    printf("Idade: %d anos \n", person1.age);

}
