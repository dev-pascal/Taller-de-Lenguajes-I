#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void reservarMemoria (int ***, int);
void imprimir(int **,int);
void cargar (int **,int);
void liberar (int **,int);
int main()
{
    int n;
    printf("Escriba un numero n\n");
    scanf("%d",&n);
    int ** mat=NULL;
    reservarMemoria(&mat,n);
    cargar(mat,n);
    imprimir(mat,n);
    liberar(mat,n);
    return 0;
}
void reservarMemoria(int ***mat, int n) {
    *mat=(int **)malloc(n*sizeof(int*));
    int i,j=n-1;
    for (i=0;i<n;i++,j--)
        (*mat)[i]=(int *)malloc((n-j)*sizeof(int));
}
void imprimir (int ** mat, int n) {
    int i,j,k,u=n-1;
    printf("\n");
    for (i=0;i<n;i++,u--) {
        for (k=0;k<u;k++)
            printf("  ");
        for (j=0;j<(n-u);j++)
            printf(" %d  ",mat[i][j]);
        for (k=0;k<u;k++)
            printf("  ");
        printf("\n");
    }
}
void cargar (int ** mat, int n) {
    int i,j,k=n;
    for (i=0;i<n;i++,k--)
        for (j=0;j<=(n-k);j++)
            if ((j==0) || (j==n-k))
                mat[i][j]=1;
            else {
                mat[i][j]=mat[i-1][j-1]+mat[i-1][j];
            }
}
void liberar (int ** mat, int n) {
    int i;
    for (i=0;i<n;i++)
        free(mat);
}
