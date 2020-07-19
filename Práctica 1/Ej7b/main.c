#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*Por què si no inicializo total se le asigna 80?
    Porque por defecto cuando una variable no se inicializa, la computadora
    automaticamente le inicializa un valor basura cualquiera.*/
    int total, x = 1;
    total=0;
    while (x <= 10) {
        total += x;
        ++x;
    }
    printf("Total = %d",total);
    return 0;
}
