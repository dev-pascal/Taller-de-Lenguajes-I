#include <stdio.h>
#include <stdlib.h>

float promedio (float []);
float min (float []);
int max (float []);
int main()
{
    float vector[5]={1,2,3,4,5};
    printf("Promedio: %f\n",promedio(vector));
    printf("Minimo: %f\n",min(vector));
    printf("Posicion del maximo: %d\n",max(vector));
    return 0;
}
float promedio (float v [])
{
    float suma=0;
    int i,cant=0;
    for (i=0;i<5;i++) {
        suma=suma+v[i];
        ++cant;
    }
    return suma/(float)cant;
}
float min (float v [])
{
    float min=9999;
    int i;
    for (i=0;i<5;i++) {
        if (min>v[i])
            min=v[i];
    }
    return min;
}
int max (float v [])
{
    float max=-9999;
    int i,pos;
    for (i=0;i<5;i++) {
        if (v[i]>max) {
            max=v[i];
            pos=i;
        }
    }
    return pos;
}
