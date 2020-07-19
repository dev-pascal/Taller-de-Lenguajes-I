#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void terminaO(char [],int *);
int main()
{
    int cant=0;
    char texto[40]="-1";
    while (strcmp(texto,"XXX")!=0) {
        scanf("%s",texto);
        terminaO(texto,&cant);
    }
    printf("Cantidad de textos que terminan con 'o': %d",cant);
    return 0;
}
void terminaO(char v[], int *cant)
{
    int i;
    char *aux=v;
    for (i=0;v[i+1]!='\0';i++);
    if (v[i]=='o')
        *cant=(*cant)+1;
    v=*aux;
}
