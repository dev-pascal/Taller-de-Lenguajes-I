#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char cadena[50];
    int abecedario[25]={0};
    scanf("%s",cadena);
    int i,letra;
    for (i=0;cadena[i]!='\0';i++) {
        letra=cadena[i]-'a';
        abecedario[letra]++;
    }
    for (i=0;i<25;i++) {
        if (abecedario[i]!=0)
            printf("Letra %c: %d\n",(i+'a'),abecedario[i]);
    }
    return 0;
}
