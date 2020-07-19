#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int getSize (FILE *);
void copiar (FILE *, FILE *);
int main()
{
    FILE * arch=fopen("ejemplo.txt","r");
    if (!arch) {
        printf("Error al abrir el archivo");
        return 1;
    }
    else {
        FILE * nue=fopen("nuevo.txt","w");
        while (!feof(arch)) {
            copiar(arch,nue);
            fgetc(arch);
        }
        return 0;
    }
}
int getSize (FILE * arch) {
    int i=0;
    char c=fgetc(arch);
    while ((c!='\n') && (!feof(arch))) {
        c=fgetc(arch);
        i++;
    }
    int j;
    if (c=='\n') {
        for (j=0;j<(i+2);j++)
            fseek(arch, -1, SEEK_CUR);
    }
    else {
        for (j=0;j<i;j++)
            fseek(arch, -1, SEEK_CUR);
    }
    return i;
}
void copiar (FILE * arch, FILE * nue) {
    int n=getSize(arch);
    char * texto=calloc(n, sizeof(char));
    fgets(texto, n+1, arch);
    fputs(texto,nue);
    fputs("\n",nue);
}
