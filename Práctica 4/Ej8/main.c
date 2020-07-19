#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int DNI;
    char nombre[40];
    char apellido[40];
    char sexo[40];
} persona;
int * reservarMemoria (persona ***, int, int *);
void leer (persona **, int *, int);
void imprimir (persona **, int *, int);
void liberar (persona **, int);
int main()
{
    persona **mat=NULL;
    int n;
    printf("Escriba la cantidad de barrios\n");
    scanf("%d",&n);
    while (n<0) {
        printf("Error. Ingrese un numero positivo.\n");
        printf("Escriba la cantidad de barrios\n");
        scanf("%d",&n);
    }
    int *cant=(int *)malloc(n*sizeof(int));
    cant=reservarMemoria(&mat,n,cant);
    leer(mat,cant,n);
    imprimir(mat,cant,n);
    liberar(mat,n);
    return 0;
}
int * reservarMemoria(persona *** mat, int n, int *v) {
   *mat=(persona **)malloc(n*sizeof(persona*));
   int i;
   int cant=-1;
   for (i=0;i<n;i++) {
        printf("Ingrese cantidad de personas en el barrio %d\n",i+1);
        scanf("%d",&cant);
        while (cant<0) {
            printf("Error. Ingrese un numero positivo.\n");
            printf("Ingrese cantidad de personas en el barrio %d\n",i+1);
            scanf("%d",&cant);
        }
        v[i]=cant;
        (*mat)[i]=(persona *)malloc(cant*sizeof(persona));
   }
   return v;
}
void leer (persona ** mat, int * cant, int n) {
    int i,j;
    for (i=0;i<n;i++) {
        printf("Leyendo personas del barrio %d\n",i+1);
        for (j=0;j<cant[i];j++) {
            printf("Ingrese DNI\n");
            scanf("%d",&mat[i][j].DNI);
            fflush(stdin);
            printf("Ingrese apellido\n");
            scanf("%s",mat[i][j].apellido);
            fflush(stdin);
            printf("Ingrese nombre\n");
            scanf("%s",mat[i][j].nombre);
            fflush(stdin);
            printf("Ingrese sexo\n");
            scanf("%s",mat[i][j].sexo);
            printf("------\n");
        }
        printf("...\n");
    }
}
void imprimir (persona ** mat, int * cant, int n) {
    int i,j;
    float mujeres;
    for (i=0;i<n;i++) {
        mujeres=0;
        for (j=0;j<cant[i];j++)
            if (strcmp(mat[i][j].sexo,"mujer")==0)
                mujeres++;
        printf("Porcentaje de mujeres en el barrio %d : %f\n",i+1,mujeres*100/(float)cant[i]);
    }
}
void liberar (persona ** mat, int n) {
    int i;
    for (i=0;i<n;i++)
        free(mat[i]);
}
