#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
struct jugadorTenis {
    char nombre[SIZE];
    char apellido[SIZE];
    int edad, cant_titulos, rank;
    float fortuna;
};
typedef struct jugadorTenis jugador;
void leer (FILE *);
void lectura (jugador *);
void procesar (FILE *);
void actualizar (jugador j, int, int, int *, char *, char *);
int main()
{
    FILE * arch=fopen("jugadores.txt","wb+");
    if (!arch) {
        printf("Error al abrir el archivo\n");
        return 1;
    }
    else {
        leer(arch);
        procesar(arch);
        fclose(arch);
        return 0;
    }
}
void leer (FILE * arch) {
    int i;
    jugador j;
    for (i=0;i<20;i++) {
        lectura(&j);
        fwrite(&j, sizeof(jugador), 1, arch);
        printf("\n\n");
    }
    rewind(arch);
}
void lectura (jugador * j) {
    printf("Ingrese un nombre\n");
    scanf("%s",j->nombre);
    fflush(stdin);

    printf("Ingrese un apellido\n");
    scanf("%s",j->apellido);
    fflush(stdin);

    printf("Ingrese una edad\n");
    scanf("%d",&(j->edad));
    fflush(stdin);

    printf("Ingrese cantidad de titulos\n");
    scanf("%d",&(j->cant_titulos));
    fflush(stdin);

    printf("Ingrese ranking actual\n");
    scanf("%d",&(j->rank));
    fflush(stdin);

    printf("Ingrese fortuna acumulada\n");
    scanf("%f",&(j->fortuna));
    fflush(stdin);
}
void procesar (FILE *arch) {
    jugador j;
    char nombreMax_RANK[SIZE], apellidoMax_RANK[SIZE];
    char nombreMax_TITULO[SIZE], apellidoMax_TITULO[SIZE];
    int mejorRank=9999, maxTitulo=-1;
    fread(&j, sizeof(jugador), 1, arch);
    while (!feof(arch)) {
        actualizar(j, (mejorRank>j.rank), j.rank, &mejorRank, nombreMax_RANK, apellidoMax_RANK);
        actualizar(j, (maxTitulo<j.cant_titulos), j.cant_titulos, &maxTitulo, nombreMax_TITULO, apellidoMax_TITULO);
        fread(&j, sizeof(jugador), 1, arch);
    }
    printf("\nNombre y apellido del jugador con mejor ranking:\n");
    printf("%s %s", nombreMax_RANK, apellidoMax_RANK);
    printf("\n\nNombre y apellido del jugador con mayor cantidad de titulos:\n");
    printf("%s %s", nombreMax_TITULO, apellidoMax_TITULO);
}
void actualizar (jugador j, int condicion, int dato, int *max, char *nombremax, char *apellidomax) {
    if (condicion) {
        *max=dato;
        strcpy(nombremax, j.nombre);
        strcpy(apellidomax, j.apellido);
    }
}
