#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int esPalindromo (char []);
int main()
{
    char palabra[50];
    scanf("%s",palabra);
    printf("%s\n",palabra);
    printf("%d",esPalindromo(palabra));
    return 0;
}
int esPalindromo(char v[]) {
    int i;
    int exito=1;
    int pos=strlen(v)-1;
    for (i=0;v[i]!=v[strlen(v)/2];i++) {
        if (v[i]!=v[pos-i])
            exito=0;
    }
    return exito;
}
