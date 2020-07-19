#include <stdio.h>
#include <stdlib.h>
//cuando el enunciado dice "procesar un texto"
//si ni bien no hay que asumir el archivo de texto existe,
//es necesario hacer un modulo donde se haga la lectura en caso
//de que el archivo exista pero no tenga ningun texto? (este vacio)
void Informar (FILE *);
int main()
{
    FILE * arch=fopen("ejemplo.txt","r");
    if (!arch) {
        printf("Error al abrir el archivo");
        return 1;
    }
    else {
        Informar(arch);
        fclose(arch);
        return 0;
    }
}
void Informar (FILE * arch) {
    int min=0,may=0,dig=0;
    rewind(arch);
    char c=getc(arch);
    while (!feof(arch)) {
        if (c>=65 && c<=90)
            may++;
        else
            if (c>=97 && c<=122)
                min++;
            else
                if (c>=48 && c<=57)
                    dig++;
        c=getc(arch);
    }
    printf("Minusculas: %d\t Mayusculas: %d\t Digitos:%d\n",min,may,dig);
}
