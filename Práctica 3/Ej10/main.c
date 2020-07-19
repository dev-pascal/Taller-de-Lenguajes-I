#include <stdio.h>
#include <stdlib.h>
struct ListaDeEnteros {
    int dato;
    struct ListaDeEnteros *sig;
};
typedef struct ListaDeEnteros Lista;
Lista * inicializar ();
Lista * eliminar (Lista *);
void eliminarElem (lista ** l, int n)
void agregarInicio (Lista **, int);
void agregarFinal (Lista **, int);
int calcularCantidad (Lista *);
void imprimir (Lista *);
int main()
{
    Lista *l=inicializar();
    int n;
    printf("Ingrese un numero: \n");
    scanf("%d",&n);
    while (n!=0) {
        agregarInicio(&l,n);
        printf("Ingrese un numero: \n");
        scanf("%d",&n);
    }
    imprimir(l);
    printf("Cantidad de elementos en la lista: %d", calcularCantidad(l));
    return 0;
}
Lista * inicializar() {
    return NULL;
}
Lista * eliminar (Lista *l) {
    Lista * aux;
    while (l!=NULL) {
        aux=l;
        l=l->sig;
        free(aux);
    }
    return l;
}
void agregarInicio(lista ** l, int n) {
    lista * aux= malloc(sizeof(lista));
    aux->dato=n;
    aux->sig=*l;
    *l=aux;
}
void agregarFinal (lista ** l, int n) {
    lista *aux;
    lista *pri;
    aux=(lista *) malloc(sizeof(lista));
    aux->dato=n;
    aux->sig=NULL;
    if ((*l)!=NULL) {
        pri=*l;
        while ((*l)->sig!=NULL) {
            *l=(*l)->sig;
        }
        (*l)->sig=aux;
        *l=pri;
    }
    else {
        (*l)=aux;
    }
}
void eliminarElem (lista ** l, int n) {
    lista * ant=*l;
    lista * act=*l;
    while (act!=NULL) {
        if (act->dato==n) {
            lista * aux=act;
            if ((*l)==act) {
                *l=act->sig;
                ant=*l;
            }
            else
                ant->sig=act->sig;
            act=act->sig;
            free(aux);
        }
        else {
            ant=act;
            act=act->sig;
        }
    }
}
void imprimir (Lista * l) {
    printf("Contenido de la lista: \n");
    while (l!=NULL) {
        if (l->sig!=NULL)
            printf("%d, ",(l->dato));
        else
            printf("%d",(l->dato));
        l=l->sig;
    }
    printf("\n");
}
int calcularCantidad(Lista *l) {
    int cant=0;
    while (l!=NULL) {
        cant++;
        l=l->sig;
    }
    return cant;
}
