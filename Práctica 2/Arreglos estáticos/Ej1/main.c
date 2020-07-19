#include <stdio.h>
#include <stdlib.h>
/*Como hacer un modulo de carga de un vector?*/
int main()
{
    srand(getpid());
    int v[50];
    int i,pares=0,impares=0;
    for (i=1;i<50;i++) {
        v[i]=rand();
        if (((i%2)!=0) && ((v[i]%2)==0))
            pares++;
        else
            if (((i%2)==0) && ((v[i]%2)!=0))
                impares++;
    }
    printf("Cantidad de numeros pares que se encuentran en posiciones impares: %d \n",pares);
    printf("Cantidad de numeros impares que se encuentran en posiciones pares: %d \n",impares);
    return 0;
}
