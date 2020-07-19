#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    switch (argv[3][0]) {
        case '+':
            printf("%d",atoi(argv[1])+atoi(argv[2]));
            break;
        case '-':
            printf("%d",atoi(argv[1])-atoi(argv[2]));
            break;
        case 'b': //por que cuando pongo * no funciona?
            printf("%d",atoi(argv[1])*atoi(argv[2]));
            break;
        case '/':
            printf("%d",atoi(argv[1])/atoi(argv[2]));
            break;
        default:
            printf("Error!");
            return 1;
    }
    return 0;
}
