#include <stdio.h>
#include <stdlib.h>

int main()
{   /*Què hace la sentencia break en el operador switch?*/
    int valor;
    scanf("%d",&valor);
    switch (valor % 2) {
        case 0: printf("El valor es par");
        break;
        case 1: printf("El valor es impar");
        break;
    }
    return 0;
}
