#include <stdio.h>
#include <stdlib.h>
typedef struct pun3D {
    float x;
    float y;
    float z;
} punto3D;
int main()
{
    punto3D punto;
    printf("punto3D: %d bytes\n",sizeof(punto));
    struct pun3D puntoAux;
    printf("pun3D: %d bytes\n",sizeof(puntoAux));
    punto3D v[4];
    printf("Vector de puntos 3D: %d bytes\n",sizeof(v));
}
