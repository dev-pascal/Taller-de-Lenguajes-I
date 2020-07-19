#include <stdio.h>
#include <stdlib.h>
#define FIL 2
#define COL 3
void imprime (int m[FIL][COL]);
void modificar (int m[FIL][COL],int c);
int main()
{
    int A[FIL][COL]={{1,2,3},{4,5,6}};
    imprime(A);
    int c;
    scanf("%d",&c);
    modificar(&A,c);
    imprime(A);
    return 0;
}
void imprime (int m[FIL][COL])
{
    int i,j;
    for (i=0;i<FIL;i++) {
        for (j=0;j<COL;j++)
            printf(" %d ",m[i][j]);
        printf("\n");
    }
}
void modificar (int m[FIL][COL],int c)
{
    int i,j;
    for (i=0;i<FIL;i++) {
        for (j=0;j<COL;j++)
            m[i][j]=m[i][j]*c;
    }
}
