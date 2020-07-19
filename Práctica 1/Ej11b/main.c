#include <stdio.h>
#include <stdlib.h>
/*Cual es la diferencia entre poner unsigned o no en la función,
si cuando no lo pongo incluso se compila igual?*/
unsigned int Factorial (unsigned int); /*unsigned toma los valores positivos unicamente
dentro del rango, y además usa toda esa parte negativa omitida del rango para sumarselo
al rango en positivo para tener una mayor representación de numeros.*/
int main()
{
    int n;
    printf("n!=");
    scanf("%d",&n);
    printf("%d",Factorial(n));
    return 0;
}
unsigned int Factorial (unsigned int n)
{
    if ((n==0) || (n==1))
        return 1;
    else
        return (n*Factorial(n-1));
}
