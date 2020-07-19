#include <stdio.h>
#include <stdlib.h>

int main()
{
    int edad;
    scanf("%d",&edad);
    if (edad >= 40)
        printf("Tiene %d años o más",40);
    else
        printf("Tiene menos de %d años",40);
    return 0;
}
