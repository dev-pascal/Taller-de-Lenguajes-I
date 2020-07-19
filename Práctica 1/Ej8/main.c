#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1,n2;
    char car;
    printf("Ingrese un numero 1:\n");
    scanf("%d",&n1);
    fflush(stdin);
    printf("Ingrese un numero 2:\n");
    scanf("%d",&n2);
    fflush(stdin);
    printf("Ingrese un caracter:\n");
    scanf("%c",&car);
    switch (car)
    {
        case '+': printf("n1+n2=%d",(n1+n2));
        break;
        case '-': printf("n1-n2=%d",(n1-n2));
        break;
        case '/': printf("n1/n2=%f",(double)n1/n2);
        break;
        case '*': printf("n1*n2=%d",n1*n2);
        break;
        default: printf("Error.");
    }
    return 0;
}

