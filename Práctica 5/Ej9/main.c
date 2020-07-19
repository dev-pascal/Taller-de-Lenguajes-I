#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
struct jugadorTenis {
    char nombre[SIZE];
    char apellido[SIZE];
    int edad, cant_titulos, rank;
    float fortuna;
};
typedef struct jugadorTenis jugador;
int getSize (FILE *);
int main()
{
    FILE * arch=fopen("jugadores.txt","rb");
    if (!arch) {
        printf("Error al abrir el archivo\n");
        return 1;
    }
    else {
        //la cantidad de bytes del archivo será n*sizeof(jugador)
        //siendo n la cantidad de jugadores que se hayan leido.
        printf("El archivo jugadores.txt pesa %d bytes", getSize(arch));
        fclose(arch);
        return 0;
    }
}
int getSize (FILE * arch) {
    int size=0;
    jugador j;
    fread(&j, sizeof(jugador), 1, arch);
    while (!feof(arch)) {
        size+=sizeof(jugador);
        fread(&j, sizeof(jugador), 1, arch);
    }
    return size;
}
