#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc<5) {
        printf("No se han pasado la suficiente cantidad de argumentos\n");
        return 1;
    }
    else {
        int i;
        float cant=0;
        for (i=1;i<argc;i++) {
            cant+=atoi(argv[i]);
        }
        printf("Promedio: %.1f",cant/(argc-1));
        return 0;
    }
}
