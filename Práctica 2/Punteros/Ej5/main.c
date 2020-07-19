#include <stdio.h>
#include <stdlib.h>
#define dimF 5
void swap(int *, int *);
void cambiar(int []);
void imprimir (int []);
void sust (int [], int [],int);
int main()
{
    int v[dimF]={1,6,2,1,4};
    printf("\nArreglo original:\n");
    imprimir(v);
    cambiar(v);
    printf("\nArreglo invertido:\n");
    imprimir(v);
    return 0;
}
void swap(int *a, int *b)
{
    int aux=*a;
    *a=*b;
    *b=aux;
}
void sust (int v[], int w[], int a)
{
    int i;
    int aux=a;
    for (i=0;i<a;i++) {
        aux--;
        w[i]=v[aux];
    }
    for (i=0;i<dimF;i++)
        v[i]=w[i];
}
void cambiar (int v[])
{
    int pri=0;
    int ult=dimF;
    swap(&pri,&ult);
    int w[dimF]={0};
    if (pri>ult)
        sust(v,w,pri);
    else
        if (pri<ult)
            sust(v,w,ult);
}
void imprimir(int v[])
{
    int i;
    for (i=0;i<dimF;i++)
        printf(" %d ",v[i]);
    printf("\n");
}
