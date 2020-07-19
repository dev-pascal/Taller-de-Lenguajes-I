#include <stdio.h>
#include <stdlib.h>
//La situacion del enunciado serian varias listas que son creadas en forma consecutiva
//hasta que se lleguen a los 100 numeros?
struct ListaDeEnteros {
    int dato;
    struct Lista *sig;
};
typedef struct ListaDeEnteros Lista;
int cargarNumero (int);
Lista * Cargar (Lista *);
Lista * agregarOrdenado (Lista *, int);
int main()
{
    Lista * l=NULL;
    l=Cargar(l);
    return 0;
}
int cargarNumero (int n) {
    printf("Ingrese un numero entero positivo\n");
    scanf("%d",&n);
    while (n<0) {
        printf("Error. Ingrese un numero entero que sea positivo\n");
        printf("Ingrese un numero entero positivo\n");
        scanf("%d",&n);
    }
    return n;
}
Lista * Cargar (Lista * l) {
    int n=cargarNumero(n);
    while (n!=0) {
        l=agregarOrdenado(l,n);
        n=cargarNumero(n);
    }
    return l;
}
Lista * agregarOrdenado(Lista * l, int n) {
    Lista * aux= (Lista *) malloc (sizeof(Lista));
    aux->dato=n;
    aux->sig=l;
    return aux;
}
