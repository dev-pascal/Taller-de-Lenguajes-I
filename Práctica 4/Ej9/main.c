#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j=0;
    printf("Ingrese un numero n\n");
    scanf("%d",&n);
    int *v=NULL;
    for (i=1;i<=n;i++)
        if (n%i==0) {
            j++;
            v=realloc(v,j*sizeof(int));
            v[j-1]=i;
        }
    for (i=0;i<j;i++)
        printf(" %d ",v[i]);
    return 0;
}
