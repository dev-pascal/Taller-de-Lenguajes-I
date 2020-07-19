#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * arch=fopen("ejemplo.txt","r");
    if (!arch) {
        printf("Error al abrir el archivo");
        return 1;
    }
    else {
        FILE * nue=fopen("nuevo.txt","w");
        char c=fgetc(arch);
        while (!feof(arch)) {
            fputc(c,nue);
            c=fgetc(arch);
        }
        return 0;
    }
}
