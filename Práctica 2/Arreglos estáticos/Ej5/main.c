#include <stdio.h>
#include <stdlib.h>
#define FIL 2
#define COL 2
void suma (int A[FIL][COL], int B[FIL][COL], int C[FIL][COL]);
int main()
{
    int A[FIL][COL]={1,2,3,4};
    int B[FIL][COL]={5,6,7,8};
    int C[FIL][COL]={0};
    printf("Matriz A:\n");
    imprimir(A);
    printf("--\n");
    printf("Matriz B:\n");
    imprimir(B);
    suma(A,B,C);
    printf("--\n");
    printf("Matriz A+B=C\n");
    imprimir(C);
    return 0;
}
void imprimir (int m[FIL][COL]) {
    int i,j;
    for (i=0;i<FIL;i++) {
        for (j=0;j<COL;j++)
            printf(" %d ",m[i][j]);
        printf("\n");
    }
}
void suma (int A[FIL][COL], int B[FIL][COL], int C[FIL][COL])
{
    int i,j;
    for (i=0;i<FIL;i++)
        for (j=0;j<COL;j++)
            C[i][j]=A[i][j]+B[i][j];
}
