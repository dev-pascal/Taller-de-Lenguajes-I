#include <stdio.h>
#include <stdlib.h>
double * reservarMemoria (int);
double * inicializar (double *, int n);
double calcularPromedio (double *, int n);
int main()
{
    double *ptr=NULL;
    int n;
    printf("Ingrese un numero entero n\n");
    scanf("%d",&n);
    ptr=reservarMemoria(n);
    ptr=inicializar(ptr,n);
    printf("Promedio: %lf",calcularPromedio(ptr,n));
}
double * reservarMemoria(int n) {
    double *ptr= malloc(sizeof(double)*n);
    return ptr;
}
double * inicializar(double * ptr, int n) {
    int i;
    printf("Lectura del arreglo:\n");
    for (i=0;i<n;i++) {
        printf("Ingrese un numero double\n");
        scanf("%lf",(ptr+i));
    }
    return ptr;
}
double calcularPromedio(double *ptr, int n) {
    int i;
    double cant=0;
    for (i=0;i<n;i++) {
        cant+=*(ptr+i);
    }
    return (double)(cant/n);
}
