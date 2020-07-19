#include <stdio.h>
#include <stdlib.h>
void leer (FILE *);
void copiar (FILE *, FILE *);
int main()
{
    FILE * arch=fopen("archivos.txt","w+");
    if (!arch) {
        //tiene sentido preguntar esto si uso w? para crear el archivo.
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    else {
        leer(arch);
        FILE * nue= fopen("archivos.dat","wb+");
        copiar(arch,nue);
        fclose(arch);
        fclose(nue);
        return 0;
    }
}
void leer (FILE * arch) {
    char num;
    int cant,i;
    printf("Ingrese la cantidad de digitos que quiere leer\n");
    scanf("%d",&cant);
    fflush(stdin);
    for (i=0;i<cant;i++) {
        printf("Ingrese un digito\n");
        scanf("%c",&num);
        fprintf(arch, "%c", num);
        fflush(stdin);
    }
    printf("\nLectura exitosa en archivo.txt.\n\n");
}
void copiar (FILE * arch, FILE * nue) {
    rewind(arch);
    char nro;
    printf("Escribiendo en el archivo binario...\n");
    fscanf(arch,"%c",&nro);
    while (!feof(arch)) {
        fwrite(&nro, sizeof(char), 1, nue);
        fscanf(arch,"%c",&nro);
    }
    printf("\nImprimiendo el contenido del archivo binario...\n");
    rewind(nue);
    fread(&nro, sizeof(char), 1, nue);
    while (!feof(nue)) {
        printf("%c\n",nro);
        fread(&nro, sizeof(char), 1, nue);
    }
}
