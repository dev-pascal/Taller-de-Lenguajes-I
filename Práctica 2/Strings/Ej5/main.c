#include <stdio.h>
#include <stdlib.h>
char * strcopy (char *,char *);
int main()
{
    char c1[]="Hola";
    char c2[]="1234";
    printf("%s",c1);
    strcopy(c1,c2);
    printf("\n%s",c1);
    return 0;
}
char * strcopy (char *v1,char *v2)
{
    int i;
    for (i=0;v1[i]!='\0';i++)
        v1[i]=v2[i];
    return v1;
}
