#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void generar (FILE *, FILE *);
int getSize (FILE *);
void inicializar (float *, int, int);
void actualizar (int, float *, int, float);
void guardar (char *, int, float *, FILE *);
int main()
{
    FILE * arch=fopen("vinos.csv", "r+");
    if (!arch) {
        printf("Error al abrir el archivo\n");
        return 1;
    }
    else {
        FILE * nue=fopen("reporte_vinos.txt","w");
        generar(arch,nue);
        fclose(arch);
        fclose(nue);
        return 0;
    }
}
void generar (FILE * arch, FILE * nue) {
    int size=getSize(arch), i;
    float promedio[size], max[size], min[size], valor, cant=0;
    inicializar(promedio, size, 0);
    inicializar(max, size, -1);
    inicializar(min, size, 999);
    char string[100];
    while (!feof(arch)) {
        for (i=0;i<size;i++) {
            fscanf(arch, "%f;", &valor);
            printf("%.2f ",valor);
            actualizar((valor>max[i]), max, i, valor); //actualiza maximo
            actualizar((valor<min[i]), min, i, valor); //actualiza minimo
            promedio[i]+=valor;
        }
        printf("\n");
        fscanf(arch,"%s",string);
        cant++;
    }
    for (i=0;i<size;i++)
        promedio[i]/=cant;
    fprintf(nue, "Atributo\tAcidez Fija\tAcidez Volatil\tAcido Citrico\tAzucares Residuales\tPH\t\tSulfatos\tAlcohol\t\tCalidad");
    guardar("\nPromedio",size,promedio,nue);
    guardar("\nMinimo\t",size,min,nue);
    guardar("\nMaximo\t",size,max,nue);
}
int getSize (FILE * arch) {
    char c=fgetc(arch);
    int cant=0;
    while (c!='\n') {
        if (c==';')
            cant++;
        c=fgetc(arch);
    }
    return cant;
}
void inicializar (float *promedio, int size, int dato) {
    int i;
    for (i=0;i<size;i++)
        promedio[i]=dato;
}
void actualizar (int condicion, float *v, int pos, float dato) {
    if (condicion) {
        v[pos]=dato;
    }
}
void guardar (char *texto, int size, float *v, FILE * nue) {
    int i;
    fprintf(nue, "%s\t", texto);
    for (i=0;i<size;i++) {
        if (i!=3)
            fprintf(nue, "%.2f\t\t", v[i]);
        else
            fprintf(nue, "%.2f\t\t\t", v[i]);
    }
}
