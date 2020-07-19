#include <stdio.h>
#include <stdlib.h>

int Factorial (int);
int main()
{
    int n;
    printf("n!=");
    scanf("%d",&n);
    printf("%d",Factorial(n));
    return 0;
}
int Factorial (int n)
{
    int i,aux;
    aux=1;
    for (i=1;i<=n;i++)
        aux=aux*i;
    return aux;
}
