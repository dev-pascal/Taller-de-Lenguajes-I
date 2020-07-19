#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Dada una cadena de caracteres, ingresar una palabra por teclado e informar
cuantas veces aparece esa palabra en la cadena.*/
int analizar (char *,char *);
int main()
{
    char cadena[50]="sssTALLERsss!'%&TALLER%& ''2222' TAL LER.";
    char palabra[50]="TALLER";
    printf("\n%s",cadena);
    printf("\n%d",analizar(cadena,palabra));
    return 0;
}
int analizar(char *v, char *palabra)
{
    int i;
    int exito,pos,dimL;
    int cant=0;
    for (i=0;v[i]!='\0';i++) {
        exito=0;
        pos=0;
        dimL=0;
        if (v[i]==palabra[dimL]) {
            pos=i;
            while ((v[pos]!='\0') && (exito==0) && (dimL!=(strlen(palabra)))) {
                if (v[pos]==palabra[dimL]) {
                    pos++;
                    dimL++;
                }
                else
                    exito=1;
            }
            if ((exito==0) && (v[pos]==palabra[dimL]))
                cant++;
            else
                exito=1;
        }
    }
    return cant;
}
