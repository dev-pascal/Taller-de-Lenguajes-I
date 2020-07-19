#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int cant=0;
    char texto[40]="-1";
    while (strcmp(texto,"ZZZ")!=0) {
        scanf("%s",texto);
        if (strlen(texto)==5)
            cant++;
    }
    printf("Cantidad de textos con longitud 5: %d",cant);
    return 0;
}
