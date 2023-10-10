#include <stdio.h>
#include <stdlib.h>

int main()
{
    char color[20], flowerName[20], personName[20];

    printf("Enter a color: \n");
    scanf("%s", &color);
    printf("Enter a flower name: \n");
    scanf("%s", &flowerName);
    printf("Enter a celebrity name: \n");
    scanf("%s", &personName);

    printf("roses are %s \n", color);
    printf("%s are blue \n", flowerName);
    printf("I love %s \n", personName);
    return 0;
}
