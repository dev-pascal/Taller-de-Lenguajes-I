#include <stdio.h>
#include <stdlib.h>
int damePar ();
int main()
{
    int i,n;
    printf("n=");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        printf("%d\n",damePar());
    }
    return 0;
}
int damePar ()
{
    static int cant=-2;
    cant=cant+2;
    return cant;
}
