#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void Cargar (FILE *);
int buscarMaximo (FILE *);
int descomponerNumero (int *, int);
int buscarMaximo2 (FILE *); // otra solucion un poco mas sencilla.
int main()
{
    FILE * arch=fopen("precipitaciones.txt","r+");

    if (!arch) {
        printf("No se puede abrir el archivo");
        return 1;
    }
    else {
        //Cargar(arch); //se dispone.
        printf("Dia con mayor precipitacion: %d", buscarMaximo(arch));
        return 0;
    }
}
void Cargar (FILE * arch) {
    int i;
    srand(time(NULL));
    for (i=0;i<31;i++) {
        fprintf(arch,"%d",rand()%50);
        fprintf(arch,"%c",'-');
    }
}
int descomponerNumero(int *v, int dig) {
    int nro,i;
    if (dig%2==0)
        nro=0;
    else
        nro=1;
    for (i=0;i<dig;i++)
        nro+=pow(10,dig-(i+1))*v[i];
    return nro;
}
int buscarMaximo(FILE * arch) {
    int nro, max=-1, dig=0, maxdia=-1, dia=0;
    int *v=NULL;
    rewind(arch);
    int c=fgetc(arch);
    while (!feof(arch)) {
        while (c!='-') {
            v=realloc(v,(++dig)*sizeof(int));
            v[dig-1]=c-48;
            c=fgetc(arch);
        }
        dia++;
        nro=descomponerNumero(v,dig);
        do v=realloc(v,(--dig)*sizeof(int));
        while (dig!=0);
        if (nro>max) {
            maxdia=dia;
            max=nro;
        }
        c=fgetc(arch);
    }
    return maxdia;
}
