#include <stdio.h>
#include <stdlib.h>

int main()
{
    int edad;
    scanf("%d",&edad);
    if (edad >= 40)
        printf("Tiene %d a�os o m�s",40);
    else
        printf("Tiene menos de %d a�os",40);
    return 0;
}
