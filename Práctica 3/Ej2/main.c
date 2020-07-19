#include <stdio.h>
#include <stdlib.h>
double * reservarMemoria (int);
double * inicializar (double *, int n);
double calcularPromedio (double *, int n);

double * inicializarAux (double *, int);
double calcularPromedioAux(double *, int);
double * liberarMemoria (double *);
int main()
{
    //La notacion por punteros al realizar un desplazamiento implica en
    //modificar para que direccion de memoria apunta ese puntero.
    //Entonces, al realizar el desplazamiento al terminar el recorrido
    //serà necesario volver al lugar inicial para no perder el puntero al
    //primer lugar en caso de que se necesite luego el puntero al inicio del arreglo.
    printf("--- UTILIZANDO NOTACION DE PUNTEROS --- \n");
    double *ptr=NULL;
    int n;
    printf("Ingrese un numero entero n\n");
    scanf("%d",&n);
    ptr=reservarMemoria(n);
    ptr=inicializar(ptr,n);
    printf("Promedio: %lf\n",calcularPromedio(ptr,n));
    ptr=liberarMemoria(ptr);

    //Observar que aca no hará falta desplazarse de vuelta hacia el
    //puntero al inicio!!!! La notacion de arreglos es mucho mas factible
    //en ese sentido.
    printf("\n");
    printf("--- UTILIZANDO NOTACION DE ARREGLOS --- \n");
    ptr=inicializarAux(ptr,n);
    printf("Promedio: %lf\n",calcularPromedioAux(ptr,n));
    ptr=liberarMemoria(ptr);

    return 0;
}
double * reservarMemoria(int n) {
    double *ptr= malloc(sizeof(double)*n);
    return ptr;
}
double * inicializar(double * ptr, int n) {
    int i;
    for (i=0;i<n;i++) {
        printf("Ingrese un numero\n");
        scanf("%lf",ptr);
        ptr++;
    }
    for (i=0;i<n;i++)
        ptr--;
    return ptr;
}
double calcularPromedio(double *ptr, int n) {
    int i;
    double cant=0;
    for (i=0;i<n;i++) {
        cant+=*(ptr+i);
    }
    for (i=0;i<n;i++)
        ptr--;
    return (double)(cant/n);
}
double * inicializarAux(double *ptr, int n) {
    int i;
    for (i=0;i<n;i++) {
        printf("Ingrese un numero\n");
        scanf("%lf",&ptr[i]);
    }
    return ptr;
}
double calcularPromedioAux(double *ptr, int n) {
    int i;
    double cant=0;
    for (i=0;i<n;i++) {
        cant+=(ptr[i]);
    }
    return (double)(cant/n);
}
double * liberarMemoria(double *ptr) {
    free(ptr);
    return ptr;
}
