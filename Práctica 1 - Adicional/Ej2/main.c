#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Ingrese un numero natural:\n");
    scanf("%d",&n);
    while (n<=0) {
        printf("Error! Se ha ingresado un numero que no es natural.\n");
        printf("Ingrese un numero natural:\n");
        scanf("%d",&n);
    }
    int bin=0;
    int base=1;
    do
    {
        bin=bin+base*(n%2);
        base=base*10;
        n=n/2;
    }
    while (n>0);
    printf("%d",bin);
    return 0;
}
