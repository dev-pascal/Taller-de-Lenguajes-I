#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CONST 50
int cargarArchivo (FILE *);
void copiarEnNuevo (FILE *, FILE *, int);
int main()
{
    FILE * arch=fopen("ejemplo.txt","wb+");
    if (!arch) {
        printf("Error al abrir el archivo.");
        return 1;
    }
    else {
        int cant=cargarArchivo(arch);
        FILE * nue=fopen("nuevo.txt","wb+");
        copiarEnNuevo(arch,nue,cant);
        fclose(nue);
        fclose(arch);
        return 0;
    }
}
int cargarArchivo(FILE * arch) {
    int n,num,i=0,grabados=0;
    do {
        printf("Ingrese la cantidad de numeros que quiere ingresar:\n");
        scanf("%d",&n);
        if (n<0)
            printf("Ingrese un numero que sea positivo.\n");
    }
    while (n<0);
    int valores[n];
    if (n!=0)
        do {
            printf("Ingrese un numero\n");
            scanf("%d",&num);
            valores[i]=num;
            grabados+=fwrite(&valores[i], sizeof(int), 1, arch);
            i++;
        }
        while (i<n);
    rewind(arch);
    return grabados;
}
void copiarEnNuevo(FILE * arch, FILE * nue, int cant) {
    int v[cant], i;
    for (i=0;i<cant;i++) {
        fread(&v[i], sizeof(int), 1, arch);
        printf("%d\n",v[i]);
    }
}
