#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    srand(getpid()); /*hay un warning aca*/
    for (i=1; i<=14; i++)
    {
        printf("%d\n",rand());
    }
    return 0;
}
