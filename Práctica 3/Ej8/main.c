#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

float * reservarMemoria (float *,int);
float * Inicializar (float *,int);
float calcularPromedio (float *,int);
void imprimir (float *,int n);
int main()
{
    printf("Ingrese la cantidad n de elementos que quiere almacenar\n");
    int n;
    scanf("%d",&n);
    float * ptr=NULL;
    ptr=reservarMemoria(ptr,n);
    printf("\nArreglo dinamico con memoria reservada:\n");
    imprimir(ptr,n);
    ptr=Inicializar(ptr,n);
    printf("\nArreglo dinamico con contenido ingresado por teclado:\n");
    imprimir(ptr,n);
    printf("\nPromedio: %f",calcularPromedio(ptr,n));
    free(ptr);
    return 0;
}
float * reservarMemoria(float *ptr, int n) {
    ptr=(float *) malloc(n*sizeof(float));
    return ptr;
}
float * Inicializar(float *ptr,int n) {
    int i;
    float elem=-1;
    for (i=0;i<n;i++) {
        printf("Escriba un numero\n");
        scanf("%f",&elem);
        *(ptr+i)=elem;
    }
    return ptr;
}
float calcularPromedio(float *ptr,int n) {
    int i;
    float suma=0;
    for (i=0;i<n;i++)
        suma+=*(ptr+i);
    return (suma/n);
}
void imprimir (float *ptr,int n) {
    int i;
    for (i=0;i<n;i++)
        printf(" %f -",*(ptr+i));
    printf("\n");
}
