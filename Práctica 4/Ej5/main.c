#include <stdio.h>
#include <stdlib.h>
int * reservarMemoria(int);
int * inicializar(int *,int);
void imprimir (int *,int);
int * liberar (int *,int);
int main()
{
    int n,m;
    printf("Ingrese fila\n");
    scanf("%d",&n);
    int *fila=reservarMemoria(n);
    printf("Ingrese columna\n");
    scanf("%d",&m);
    int *columna=reservarMemoria(m);

    //hay alguna manera de invocar la funciòn dos veces?

    printf("Fila: \n");
    fila=inicializar(fila,n);
    printf("\n");
    printf("Columna: \n");
    columna=inicializar(columna,m);
    printf("\n");
    printf("Fila:");
    imprimir(fila,n);
    printf("\nColumna:");
    imprimir(columna,m);
    fila=liberar(fila,n);
    columna=liberar(columna,m);

    return 0;
}
int * reservarMemoria(int n) {
    int *mat=malloc (n*sizeof(int));
    return (mat);
}
int * inicializar(int *mat, int n) {
    int i;
    for (i=0;i<n;i++) {
        printf("Ingrese un numero: \n");
        scanf("%d",&mat[i]);
    }
    return mat;
}
void imprimir(int *mat, int n) {
    int i;
    for (i=0;i<n;i++)
        if (mat[i]%3==0)
            printf(" %d ",mat[i]);
}
int * liberar(int *mat, int n) {
    int i;
    for (i=0;i<n;i++)
        free(mat);
    return (mat);
}
