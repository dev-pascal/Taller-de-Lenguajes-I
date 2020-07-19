#include <stdio.h>
#include <stdlib.h>
int ** reservarMemoria(int,int);
int ** inicializar(int **,int,int);
void imprimir (int **,int,int);
int ** liberar (int **, int);
int main()
{
    //como sacar el warning aca??
    int n,m;
    printf("Ingrese fila\n");
    scanf("%d",&n);
    printf("Ingrese columna\n");
    scanf("%d",&m);
    int ** mat;
    mat=reservarMemoria(n,m);
    mat=inicializar(mat,n,m);
    imprimir(mat,n,m);
    mat=liberar(mat,n);
    return 0;
}
int ** reservarMemoria(int n, int m) {
    int ** mat, i;
    mat=(int **) malloc (n*sizeof(int*));
    for (i=0;i<n;i++)
        mat[i]=(int *) malloc (m*sizeof(int));
    return (mat);
}
int ** inicializar(int **mat, int n, int m) {
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<m;j++) {
            printf("Ingrese un numero entero en %dx%d\n",i+1,j+1);
            scanf("%d",&(mat[i][j]));
        }
    return mat;
}
void imprimir(int **mat, int n, int m) {
    int i,j;
    for (i=0;i<n;i++)
        for (j=0;j<m;j++)
            if (mat[i][j]%3==0)
                printf(" %d ",mat[i][j]);
}
int ** liberar(int **mat, int n) {
    int i;
    for (i=0;i<n;i++)
        free(mat);
    return (mat);
}
