#include <stdio.h>
#include <stdlib.h>
/*Dado un numero flotante, indicar cuantos digitos se encuentran en la parte decimal del mismo.*/
int main()
{
    double numero=3.123;
    int cant=0;
    while (((int)numero%10)!=0) {
        numero=numero*10;
        cant++;
    }
    cant--;
    printf("%d",cant);
    return 0;
}
