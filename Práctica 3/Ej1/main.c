#include <stdio.h>
#include <stdlib.h>
typedef struct{
        float base;
        float altura;
    } rectangulo;
void Inicializar(rectangulo * r);
float calcularArea (rectangulo * r);
int main()
{
    rectangulo v[10];
    int i;
    float min,area;
    for (i=0;i<10;i++)
        Inicializar(&v[i]);
    min=99999;
    for (i=0;i<10;i++) {
        area=calcularArea(&v[i]);
        min=(min>area) ? area : min;
    }
    if (min>area)
        min=area;
    printf("Area minima: %f",min);
    return 0;
}
void Inicializar(rectangulo * r) {
    printf("Ingrese base\n");
    scanf("%f",&(r->base));
    printf("Ingrese altura\n");
    scanf("%f",&(r->altura));
}
float calcularArea(rectangulo * r) {
    return (r->base)*(r->altura);
}
