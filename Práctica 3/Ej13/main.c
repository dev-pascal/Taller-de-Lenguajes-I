#include <stdio.h>
#include <stdlib.h>

struct ListaDeEnteros {
    int dato;
    struct ListaDeEnteros *sig;
};
typedef struct ListaDeEnteros Lista;
Lista * agregarOrdenado(Lista *,int);
void imprimir(Lista *, char []);
void Liberar(Lista *);
int main()
{
    Lista *l=NULL;
    Lista *pares=NULL;
    Lista *impares=NULL;
    int n;
    printf("Ingrese un numero\n");
    scanf("%d",&n);
    while  (n!=0) {
        if (n%2!=0)
            impares=agregarOrdenado(impares,n);
        else
            pares=agregarOrdenado(pares,n);
        l=agregarOrdenado(l,n);
        printf("Ingrese un numero\n");
        scanf("%d",&n);
    }
    imprimir(l,"Original");
    imprimir(pares,"Par");
    imprimir(impares,"Impar");
    Liberar(l);
    Liberar(pares);
    Liberar(impares);
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
void imprimir (Lista *l, char op[]) {
    printf("---- Lista : %s -----\n",op);
    int cant=0;
    while (l!=NULL) {
        if (l->sig!=NULL)
            printf("%d, ",l->dato);
        else
            printf("%d",l->dato);
        l=l->sig;
        cant++;
    }
    printf("\nCantidad de elementos de la lista: %d\n",cant);
    printf("\n");
}
void Liberar (Lista *l) {
    Lista * aux;
    while (l!=NULL) {
        aux=l;
        l=l->sig;
        free(aux);
    }
}
