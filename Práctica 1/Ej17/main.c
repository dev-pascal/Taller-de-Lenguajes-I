#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(getpid());
    int op,op1,op2,resultado,puntaje;
    puntaje=0;
    resultado=0;
    for (op=1;op<=4;op++)
    {
        op1=rand() % 11;
        op2=rand() % 11;
        printf("%d + %d ?= ",op1,op2);
        scanf("%d",&resultado);
        if ((op1+op2)==resultado)
            ++puntaje;
    }
    printf("\nSu nota es: ");
    switch (puntaje)
    {
        case 4: printf("A");
        break;
        case 3: printf("B");
        break;
        case 2: printf("C");
        break;
        case 1: printf("D");
        break;
        case 0: printf("E");
        break;
    }
    return 0;
}
