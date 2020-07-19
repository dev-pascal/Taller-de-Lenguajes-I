#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000
struct ListaDeEnteros{
    char dato[SIZE];
    struct ListaDeEnteros *sig;
};
typedef struct ListaDeEnteros Lista;
Lista * agregarInicio (Lista *, char *);
Lista * guardarLista (FILE *, Lista *);
void buscarenArchivo(FILE *);
void buscar (FILE *, char *);
void buscarenLista (Lista *, char *);
int main()
{
    FILE * arch=fopen("diccionario.txt","r");
    if (!arch) {
        printf("Error al abrir el archivo");
        return 1;
    }
    else {
        buscarenArchivo(arch);

        Lista *l=NULL;
        l=guardarLista(arch,l);
        buscarenLista(l,"hola");
        return 0;
    }
}
void buscarenArchivo (FILE * arch) {
    char palabra[SIZE];
    scanf("%s",palabra);
    while (strcmp(palabra,"ZZZ")) {
        buscar(arch,palabra);
        scanf("%s",palabra);
    }
}
void buscar (FILE * arch, char *palabra) {
    rewind(arch);
    int encontro=0;
    char aux[SIZE];
    //por que aca si lo proceso un fscanf afuera del while, pierdo el ultimo?
    //no deberia procesarlo afuera del while almenos una vez?
    while (!feof(arch) && !encontro) {
        fscanf(arch,"%s",aux);
        if (!strcmp(aux,palabra))
            encontro=1;
    }
    if (encontro)
        printf("La palabra se encuentra en el diccionario\n");
    else
        printf("La palabra no se encuentra en el diccionario\n");
}
Lista * agregarInicio (Lista *l, char *palabra) {
    Lista * aux;
    aux=(Lista *) malloc(sizeof(Lista));
    strcpy(aux->dato,palabra);
    aux->sig=l;
    return aux;
}
Lista * guardarLista(FILE * arch, Lista *l) {
    char palabra[SIZE];
    fscanf(arch,"%s",palabra);
    while (!feof(arch)) {
        l=agregarInicio(l,palabra);
        fscanf(arch,"%s",palabra);
    }
    return l;
}
void buscarenLista(Lista * l, char *palabra) {
    int exito=0;
    while (l!=NULL && !exito) {
        if (!strcmp(l->dato,palabra))
            exito=1;
        l=l->sig;
    }
    if (exito)
        printf("La palabra se encuentra en el diccionario\n");
    else
        printf("La palabra no se encuentra en el diccionario\n");
}
