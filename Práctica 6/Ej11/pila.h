#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
struct Pila {
    int dato;
    struct Pila* sig;
};
typedef struct Pila pila;
pila ** s_create() {
    pila **p=malloc(sizeof(pila*));
    *p=malloc(sizeof(pila));
    return p;
}
int s_push (pila **s, int n) {
    pila * aux = malloc(sizeof(pila));
    aux->dato=n;
    aux->sig=*s;
    *s=aux;
    return n;
}
void s_pop (pila *s) {
}
int s_top (pila **s) {
    int *dato;
    pila *p=*s;
    while (p!=NULL) {
        dato=(p->dato);
        p=p->sig;
    }
    return dato;
}
int s_empty (pila *s) {
    return (s!=NULL);
}
int s_length (pila *s) {
    int cant=0;
    return cant;
}
#endif // PILA_H_INCLUDED
