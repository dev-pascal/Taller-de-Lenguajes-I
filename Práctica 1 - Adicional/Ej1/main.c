#include <stdio.h>
#include <stdlib.h>
int main()
{
    int codigo;
    int i,min1info,min2info;
    float cant,min1,min2,porcentaje,esp=0,total=0;
    min1=9999;
    min2=9999;
    for (i=1;i<=14;i++) {
        printf("------\n");
        printf("Ingrese codigo de pais\n");
        scanf("%d",&codigo);
        printf("Ingrese cantidad de especies\n");
        scanf("%f",&cant);
        total=total+cant;
        if (cant>40)
            ++esp;
        if (min1>cant) {
            min2=min1;
            min2info=min1info;
            min1=cant;
            min1info=codigo;
        }
        else {
            if (min2>cant) {
                min2info=codigo;
                min2=cant;
            }
        }
    }
    porcentaje=esp*100/total;
    printf("Porcentaje de paises con mas de 40 especies: %f\n %", porcentaje);
    printf("Minimo 1: %d / Especies: %f\n",min1info,min1);
    printf("Minimo 2: %d / Especies: %f\n",min2info,min2);
    return 0;
}
