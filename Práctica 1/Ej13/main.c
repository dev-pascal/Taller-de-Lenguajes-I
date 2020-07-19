#include <stdio.h>
#include <stdlib.h>

int Revertir (int);
int main()
{
    int num;
    printf("Ingrese un numero\n");
    scanf("%d",&num);
    printf("%d",Revertir(num));
    return 0;
}

int Revertir (int num)
{
    int dig=1;
    int inv=0;
    while (num!=0) {
        dig=num%10;
        num=num/10;
        inv=inv*10+dig;
    }
    return inv;
}
