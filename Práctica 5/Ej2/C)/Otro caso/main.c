#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CONST 50
int main()
{   //este programa crea un nuevo archivo de texto,
    //copia contenido en el, y luego copia el contenido
    //generado en ese archivo para almacenarlo en otro vector
    FILE * arch=fopen("ejemplo.txt","wb+");
    if (!arch) {
        printf("Error al abrir el archivo.");
        return 1;
    }
    else {
        char texto[2][CONST];
        int i;
        for (i=0;i<2;i++) {
            scanf("%s",texto[i]);
            fwrite(texto[i], sizeof(char), CONST, arch);
        }
        rewind(arch); //reposiciona el arch al inicio
        char aux[2][CONST];
        printf("Aux:\n");
        for (i=0;i<2;i++)
            fread(aux[i], sizeof(char), CONST, arch);
        for (i=0;i<2;i++)
            printf("%s",aux[i]);
        fclose(arch);
        return 0;
    }

}
