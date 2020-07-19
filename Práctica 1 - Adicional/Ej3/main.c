#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double pi=3;
    double a=2,b=3,c=4;
    int i;
    for (i=1;i<1000000000;i++) {
        if ((i%2)!=0)
            pi=pi+4/(a*b*c);
        else
            pi=pi-4/(a*b*c);
        a+=2;
        b+=2;
        c+=2;
    }
    printf("%f",pi);
    return 0;
}
