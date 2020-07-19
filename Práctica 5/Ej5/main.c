#include <stdio.h>
#include <stdlib.h>
float calcularTotal (FILE *);
int main()
{
    FILE * arch= fopen("apuestas.txt","r");
    if (!arch) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    else {
        printf("%.1f",calcularTotal(arch));
        return 0;
    }
}
float calcularTotal(FILE * arch) {
    int codigo_apuesta;
    float monto_apostado, total=0;
    fscanf(arch, "%d|%f;", &codigo_apuesta, &monto_apostado);
    while (!feof(arch)) {
        total+=monto_apostado;
        fscanf(arch, "%d|%f;", &codigo_apuesta, &monto_apostado);
    }
    return total;
}
