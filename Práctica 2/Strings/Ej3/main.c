#include <stdio.h>
#include <stdlib.h>
int * cambiar (char [],char a, char b);
void imprimir (char []);
int main()
{
    char cadena[] ="Hola! Esto es un ejemplo.";
    char a,b;
    imprimir(cadena);
    printf("\n");
    a=' ';
    b='_';
    cambiar(cadena,a,b);
    imprimir(cadena);
    return 0;
}
int * cambiar (char v[], char a, char b)
{
    int i;
    for (i=0;v[i]!='\0';i++) {
       if (v[i]==a)
            v[i]=b;
    }
    return v;
}
void imprimir (char v[])
{
    int i;
    for (i=0;v[i]!='\0';i++) {
        printf("%c",v[i]);
    }
}
