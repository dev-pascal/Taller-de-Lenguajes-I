#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    //Imprime la ruta del programa que se ejecuta porque por convención en C.
    //argc hace referencia a la cantidad de parametros pasados a la función main.
    printf("\nargc = %d",argc);
    printf("\nargv[0] => %s",argv[0]);
    return 0;
}
