#include <stdio.h>
#include <stdlib.h>
int strlen (char *);
int main()
{
    char cadena[]="Hola.";
    printf("%d",strlen(cadena));
    return 0;
}
int strlen (char *v)
{
    int i;
    int cant=0;
    for (i=0;v[i]!='\0';i++)
        cant++;
    return cant;
}
