#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char calle[50];
    char ciudad[30];
    int codigo_postal;
    char pais[40];
} direccion;
typedef struct alumno{
    char apellido[50];
    char nombre[50];
    char legajo[8];
    float promedio;
    direccion domicilio;
} alu;
void Inicializar (alu * a);
float actualizarMax (alu * a,char *,char *);
int main()
{
    alu v[30];
    char maxnombre[50];
    char maxapellido[50];
    int i;
    float max=-9999;
    for (i=0;i<30;i++) {
        Inicializar(&v[i]);
        max=(max<v[i].promedio) ? (actualizarMax(&v[i],maxnombre,maxapellido)) : max;
    }
    printf("Nombre y apellido que tiene el maximo promedio: %s %s\n",maxnombre,maxapellido);
    return 0;
}
float actualizarMax(alu * a, char * maxnombre, char * maxapellido) {
    strcpy(maxnombre,(a->nombre));
    strcpy(maxapellido,(a->apellido));
    return ((a->promedio));
}
void Inicializar(alu * a) {
    printf("Ingrese nombre\n");
    scanf("%s",(a->nombre));
    printf("Ingrese apellido\n");
    scanf("%s",(a->apellido));
    printf("Ingrese legajo\n");
    scanf("%s",(a->legajo));
    printf("Ingrese promedio\n");
    scanf("%f",&(a->promedio));
    printf("Domicilio.\n");
    printf("Ingrese calle\n");
    scanf("%s",(a->domicilio.calle));
    printf("Ingrese ciudad\n");
    scanf("%s",(a->domicilio.ciudad));
    printf("Ingrese codigo_postal\n");
    scanf("%s",&(a->domicilio.codigo_postal));
    printf("Ingrese pais\n");
    scanf("%s",(a->domicilio.pais));
}
