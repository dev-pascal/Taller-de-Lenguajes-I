#include <stdio.h>
#include <stdlib.h>

void leoNumeros (int, float *, float *);
int main()
{
    int n;
    float min,max;
    printf("n=");
    scanf("%d",&n);
    leoNumeros(n,&min,&max);
    printf("min:%f ; max: %f", min,max);
    return 0;
}

void leoNumeros (int n, float * min, float * max)
{
    int i;
    *max=-9999;
    *min=9999;
    float num;
    for (i=1;i<=n;i++) {
        printf("Escriba un numero:\n");
        scanf("%f",&num);
        if (*min>num)
            *min=num;
        else
            if (*max<num)
                *max=num;
    }
}
