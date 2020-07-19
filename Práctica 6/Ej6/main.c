#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define AREA_CIRCULO(r) 3.14*r*r
int main()
{
    int i,r;
    srand(time(NULL));
    for (i=0;i<10;i++) {
        r=rand()%10;
        printf("Radio: %d\n",r);
        printf("Area: %.2f\n\n",AREA_CIRCULO(r));
    }
    return 0;
}
