#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int ** reservarMemoria (int);
void imprimir(int **,int);
int ** cargar (int **,int);
int ** liberar (int **,int);
int main()
{
    int n;
    printf("Escriba un numero n\n");
    scanf("%d",&n);
    int ** mat=reservarMemoria(n);
    mat=cargar(mat,n);
    imprimir(mat,n);
    mat=liberar(mat,n);
    return 0;
}
int ** reservarMemoria(int n) {
    int **mat=(int **)malloc(n*sizeof(int*));
    int i;
    for (i=0;i<n;i++) {
        mat[i]=(int *)malloc((n-i)*sizeof(int));
    }
    return mat;
}
void imprimir (int ** mat, int n) {
    int i,j;
    printf("\n");
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++)
            if (i>=j) {
                if (mat[i][j]>=10)
                    printf("%d  ",mat[i][j]);
                else
                    printf("%d   ",mat[i][j]);
            }
        printf("\n");
    }
}
int ** cargar (int ** mat, int n) {
    int i,j;
    srand(time(NULL));
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            if (i>=j)
                mat[i][j]=rand()%21;
    return mat;
}
int ** liberar (int ** mat, int n) {
    int i;
    for (i=0;i<n;i++)
        free(mat);
    return mat;
}
