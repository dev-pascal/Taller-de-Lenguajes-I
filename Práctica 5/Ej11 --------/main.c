#include <stdio.h>
#include <stdlib.h>
struct persona {
    int dato;
    int bytes;
};
typedef struct persona Persona;
void actualizarBytes (int *, char, FILE *);
int calcularDigitos (int);
void saltearLinea (FILE *, int *);
void generar (FILE *, FILE *);
int main()
{
    FILE * arch=fopen("personas.csv","r");
    if (!arch) {
        printf("Error al abrir el archivo\n");
        return 1;
    }
    else
    {
        FILE * nue=fopen("personas.idx","wb+");
        generar(arch,nue);
        fclose(arch);
        fclose(nue);
        return 0;
    }
}
int calcularDigitos(int dni) {
    int digitos=0;
    while (dni!=0) {
        digitos++;
        dni/=10;
    }
    return digitos;
}
void actualizarBytes(int * peso, char c, FILE * arch) {
    if (c=='\t' || c=='\n')
        (*peso)+=2;
    else
        if (!feof(arch))
            (*peso)+=sizeof(char);
}
void saltearLinea(FILE * arch, int *peso) {
    char c=fgetc(arch);
    while (!feof(arch) && c!='\n') {
        actualizarBytes(peso, c, arch);
        c=fgetc(arch);
    }
    actualizarBytes(peso, c, arch);
    c=fgetc(arch);
}
Persona buscarMin (Persona *v, int dimF) {
    int i,min=100000000, indice=0;
    Persona aux;
    for (i=0;i<dimF;i++) {
        if (min>v[i].dato) {
            min=v[i].dato;
            aux.dato=v[i].dato;
            aux.bytes=v[i].bytes;
            indice=i;
        }
    }
    v[indice].dato=100000000;
    return aux;
}
void generar (FILE * arch, FILE * nue) {
    int peso=0;
    saltearLinea(arch,&peso); // salteo encabezado
    Persona *v=NULL;
    int dni, i=0;
    fscanf(arch,";%d;",&dni);
    while (!feof(arch))  {
        v=realloc(v,++i);
        v[i-1].dato=dni;
        v[i-1].bytes=peso;
        saltearLinea(arch,&peso);
        peso+=calcularDigitos(dni)+3;
        fscanf(arch,";%d;",&dni);
    }
    int j;
    Persona min;
    for (j=0;j<i;j++) {
        min=buscarMin(v,i);
        fwrite(&min.dato, sizeof(int), 1, nue);
        fwrite(&min.bytes, sizeof(int), 1, nue);
    }
    rewind(nue);
    fread(&j, sizeof(int), 1, nue);
    while (!feof(nue)) {
        printf("%d\n",j);
        fread(&j, sizeof(int), 1, nue);
    }

}
