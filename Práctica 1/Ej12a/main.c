#include <stdio.h>
#include <stdlib.h>

int esPrimo (int);
int main()
{
    int n;
    printf("n=");
    scanf("%d",&n);
    if (esPrimo(n)==1)
        printf("Es primo\n");
    else
        printf("No es primo\n");
    return 0;
}
int esPrimo (int n)
{
    int exito;
    int i=2;
    if (n!=1) {
        exito=1;
        while ((i<n) && (exito!=0)) {
            if ((n%i)==0)
                exito=0;
            else
                i++;
        }
    }
    else
        exito=0;
    return exito;
}
