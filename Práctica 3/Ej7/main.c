#include <stdio.h>
#include <stdlib.h>

int * reservarMemoria (int *,int);
void Inicializar (int *,int);
int calcularMaximo (int *,int);
void imprimir (int *,int n);
int main()
{
    printf("Ingrese un numero n\n");
    int n;
    scanf("%d",&n);
    int * ptr=NULL;
    ptr=reservarMemoria(ptr,n);
    printf("\nArreglo dinamico con memoria reservada:\n");
    imprimir(ptr,n);
    Inicializar(ptr,n);
    printf("\nArreglo dinamico con contenido aleatorio inicializado:\n");
    imprimir(ptr,n);
    int max=calcularMaximo(ptr,n);
    printf("\nMaximo: %d",max);
    free(ptr);
    return 0;
}
int * reservarMemoria(int *ptr, int n) {
    ptr=(int *) malloc(n*sizeof(int));
    return ptr;
}
void Inicializar(int *ptr,int n) {
    int i;
    unsigned semilla;
    srand(semilla);
    for (i=0;i<n;i++)
        *(ptr+i)=rand()%9999;
}
int calcularMaximo(int *ptr,int n) {
    int i;
    int max=-9999; // como puedo asegurarme de que este numero SEGURO es mas grande
    //que el resto que voy a ingresar?
    for (i=0;i<n;i++) {
        max= (max<*(ptr+i)) ? (*(ptr+i)) : max;
    }
    return max;
}
void imprimir (int *ptr,int n) {
    int i;
    for (i=0;i<n;i++)
        printf(" %d -",*(ptr+i));
    printf("\n");
}
