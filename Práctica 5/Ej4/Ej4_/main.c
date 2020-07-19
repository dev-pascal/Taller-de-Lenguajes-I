#include <stdio.h>
#include <stdlib.h>
int calcularMax (FILE *);
void actualizarMax (int, int, int *, int *);
int main()
{
    FILE * arch=fopen("precipitaciones.txt","r");
    if (!arch) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    else {
        printf("%d",calcularMax(arch));
        fclose(arch);
        return 0;
    }
}
int calcularMax(FILE * arch) {
    int maxdia=-1,dia=1,precipitacion=0, maxprec=-1;
    fscanf(arch, "%d-",&precipitacion);
    while (!feof(arch)) {
        actualizarMax(precipitacion, dia, &maxprec, &maxdia);
        fscanf(arch, "%d-",&precipitacion);
        dia++;
    }
    return maxdia;
}
void actualizarMax(int precipitacion, int dia, int * maxprec, int * maxdia) {
    if (precipitacion>*maxprec) {
        *maxprec=precipitacion;
        *maxdia=dia;
    }
}
