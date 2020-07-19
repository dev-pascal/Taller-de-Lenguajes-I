#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
/*sqrt(a) = Calcula la raiz de a.
pow(a,b) = Calcula a elevado a b (a^b).*/
/*DUDA: esta bien considerar la parte decimal de las potencias?
ya que por ejemplo si no la considero en 10 al cuadrado me sale 99.
RESP: Si. Porque pow funciona con numeros flotantes, por lo que estaría bien
considerarla. Si no te interesa la parte decimal podes usar "%.01lf",<var> para
no mostrar la parte decimal de un numero flotatne, pero eso no quiere decir que
este no se encuentre ahí, simplemente no lo mostras.*/
int main() {
    int i;
    for (i=1;i<=10;++i)
    {
        printf("-----\n");
        printf("Numero: %d\n",i);
        printf("Raiz cuadrada: %f\n",sqrt(i));
        printf("El cuadrado: %.0lf\n",pow(i,2));
        printf("El cubo: %f\n",pow(i,3));
    }
    return 0;
}
