#include <stdio.h>
#include <stdlib.h>
#define FIL 2
#define COL 2
void imprime (int m[FIL][COL]);
void traspuesta (int m[FIL][COL]);
int main()
{
    int A[FIL][COL]={1,2,3,4};
    traspuesta(A);
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
void traspuesta (int m[FIL][COL]) {
    int i,j;
    int aux[FIL][COL];
    for (i=0;i<FIL;i++)
        for (j=0;j<COL;j++)
            if (j>i) {
                aux[i][j]=m[i][j];
                m[i][j]=m[j][i];
            }
            else {
                aux[i][j]=m[i][j];
                m[i][j]=aux[j][i];
            }
    imprime(m);
}
