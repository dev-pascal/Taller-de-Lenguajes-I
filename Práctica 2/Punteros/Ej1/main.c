#include <stdio.h>
#include <stdlib.h>
#define dimF 5
void Cargar (float []);
void Imprimir (float []);
void devuelvoParametros (float[], float *, float *, int *);
int main()
{
    float vector[dimF]={0};
    Cargar(vector);
    Imprimir(vector);
    float promedio, min;
    int pos;
    devuelvoParametros(vector, &promedio,&min,&pos);
    printf("\nMinimo: %f\n",min);
    printf("Promedio: %f\n",promedio);
    printf("Posicion del maximo de los valores del arreglo: %d\n",pos);
    return 0;
}
void Cargar (float v[])
{
    int i;
    srand(getpid());
    for (i=0;i<dimF;i++) {
        v[i]=(float)rand();
    }
}
void Imprimir (float v[]) {
    int i;
    printf("Arreglo: \n");
    for (i=0;i<dimF;i++) {
        printf("%f - ",v[i]);
    }
}
void devuelvoParametros(float v[], float * promedio, float * min, int * pos)
{
    float suma=0;
    float minimo=9999999;
    int i;
    int max=-1;
    for (i=0;i<dimF;i++) {
        suma+=v[i];
        if (minimo>v[i]) {
            minimo=v[i];
            *min=v[i];
        }
        if (v[i]>max) {
            max=v[i];
            *pos=i;
        }
    }
    *promedio=suma/dimF;
}
