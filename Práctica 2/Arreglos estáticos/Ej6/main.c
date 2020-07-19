#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero=4032;
    int cant=0;
    while (numero!=0) {
        numero=numero/10;
        cant++;
    }
    printf("%d",cant);
    return 0;
}
