#include <stdio.h>
#include <stdlib.h>
    /*Así como estaba el programa no pudo cumplir su cometido, pues
falta el comando fflush(stdin) luego de la primera leida
por teclado, ya que se va a contar con memoria basura con el caracter
ENTER presionado y este comando se encarga de limpiar la memoria del
buffer.*/

int main(){
     char a, b;
     printf("Ingrese el primer caracter:\n");
     scanf("%c", &a);
     fflush(stdin);
     printf("Se leyó el caracter: %c\n", a);
     printf("Ingrese el segundo caracter:\n");
     scanf("%c", &b);
     printf("Se leyó el caracter: %c\n", b);
     return 0;
}
