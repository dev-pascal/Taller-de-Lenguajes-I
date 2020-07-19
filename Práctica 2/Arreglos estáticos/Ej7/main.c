#include <stdio.h>
#include <stdlib.h>
#define meses 12
#define dias 30
#define anios 10
void Cargar (float [anios][meses][dias]);
void calcularMin (float [anios][meses][dias], float *);
int main()
{
    float precipitaciones[anios][meses][dias]={0};
    Cargar(precipitaciones);
    float min_promedio=0;
    calcularMin(precipitaciones, &min_promedio);
    return 0;
}
void Cargar (float v[anios][meses][dias]) {
    int i,j,k;
    for (i=0;i<anios;i++)
        for (j=0;j<meses;j++)
            for (k=0;k<dias;k++)
                v[i][j][k]=rand();
}
void calcularMin(float v[anios][meses][dias], float * min_anio) {
    int i,j,k;
    float min_promedio=99999, min_mes=0, min=0, suma=0;
    for (i=0;i<anios;i++) {
        suma=0;
        min=99999;
        for (j=0;j<meses;j++) {
            for (k=0;k<dias;k++) {
                suma=suma+v[i][j][k];
            }
            if (min>suma) {
                min=suma;
                min_mes=j;
            }
        }
        suma=suma/anios;
        if (min_promedio>suma) {
            min_promedio=suma;
            *min_anio=i;
        }
        printf("En el anio &d el mes que menos llovio fue el &d",i,min_mes); /*por que tira un warning?*/
    }
}
