#include <stdio.h>
#include <stdlib.h>
#define dimF 4
int buscarMinimo(int [], int *);
void Imprimir (int []);
void Ordenar (int []);
void Cargar (int []);
int main()
{
    int v[dimF]={0};
    Cargar(v);
    printf("Arreglo original:");
    Imprimir(v);
    Ordenar(v);
    printf("Arreglo ordenado:");
    Imprimir(v);
    return 0;
}
void Imprimir (int v[]) {
    int i;
    for (i=0;i<dimF;i++)
        printf(" %d - ",v[i]);
    printf("\n");
}
void Cargar (int v[]) {
    int i;
    srand(getpid());
    for (i=0;i<dimF;i++)
        v[i]=rand()%999;
}
int buscarMinimo(int v[], int *pos) {
    int i;
    int min=9999;
    int static ant_min=0;
    for (i=0;i<dimF;i++) {
        if ((min>v[i]) && (v[i]>ant_min)) {
            *pos=i;
            min=v[i];
        }
    }
    ant_min=min;
    return min;
}
void Ordenar (int v[]) {
    int i;
    int pos=-1;
    int aux=-1;
    for (i=0;i<dimF;i++) {
        aux=v[i];
        v[i]=buscarMinimo(v,&pos);
        v[pos]=aux;
    }
}
