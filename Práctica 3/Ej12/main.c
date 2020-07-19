#include <stdio.h>
#include <stdlib.h>
//DUDA: Esta bien hecho el b?
//declaracion de lista
struct ListaDeEnteros {
    int dato;
    struct ListaDeEnteros * sig;
};
typedef struct ListaDeEnteros Lista;
//declaracion de procesos
Lista * agregarOrdenado (Lista *,int);
int Calcular();
void imprimir (Lista *);
int main()
{
    printf("Cantidad de elementos en la lista: %d",Calcular());
    return 0;
}
int Calcular() {
    Lista *l=NULL;
    int n;
    int cant=0;
    printf("Ingrese un numero\n");
    scanf("%d",&n);
    while  (n!=0) {
        l=agregarOrdenado(l,n);
        printf("Ingrese un numero\n");
        scanf("%d",&n);
        cant++;
    }
    return cant;
}
Lista * agregarOrdenado(Lista *l, int n) {
    Lista *act,*ant,*nue;
    act=l;
    ant=l;
    nue=(Lista *) malloc (sizeof(Lista));
    nue->dato=n;
    while ((act!=NULL) && ((act->dato)<(nue->dato))) {
        ant=act;
        act=act->sig;
    }
    if (ant!=act)
        ant->sig=nue;
    else {
        ant=nue;
        l=nue;
    }
    nue->sig=act;
    return l;
}
void imprimir (Lista *l) {
    while (l!=NULL) {
        printf("%d",l->dato);
        l=l->sig;
    }
}
