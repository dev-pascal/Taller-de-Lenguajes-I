#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(getpid());
    int jugada,uno=0,dos=0,exito=-1;
    uno=rand();
    dos=rand();
    jugada=uno+dos;
    if ((jugada==7) || (jugada==11)) {
        exito=1;
    }
    else
        if ((jugada==2) || (jugada==12)) {
            exito=0;
            }
    int segunda=-1;
    if (exito==-1) {
        while (((segunda!=jugada) && (exito!=0)) || (exito!=1)) {
            uno=rand();
            dos=rand();
            segunda=uno+dos;
            if ((segunda==2) || (segunda==12))
                exito=0;
            else
                if (segunda==jugada)
                    exito=1;
        }
    }
    if (exito==1)
        printf("El jugador ha ganado");
    else
        if (exito==0)
            printf("El jugador ha perdido");
    return 0;
}
