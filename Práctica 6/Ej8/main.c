#include <stdio.h>
#include <stdlib.h>
#define DEBUG 0
//a) El codigo compila.
//b) El codigo no compilaria, pues la variable y no esta definida
//Los beneficios que se obtendran (si se define la variable y),
//es que se va a poder imprimir en pantalla el contenido de la variable x
//c) No es posible. Puesto que no es una decision que se toma en tiempo de
//ejecuci�n y es previo a la compilaci�n.
//d) Ya no incidir� el valor de la constante simb�lica DEBUG, sino m�s bien
//lo que incide es si el identificador DEBUG est� definido en el programa o no.
int main()
{
    int x=15,y;
    while (x<50) {
        #ifdef DEBUG
            printf("x=%d\n",x);
            y=y+1;
        #endif
        x++;
    }
    return 0;
}
