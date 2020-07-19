#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
void upperStr (char []);

void lowerStr (char []);

int invertir (int);
char * numToStr (char [], int); /*----------------*/

char * numToText (int);

int main()
{
    char cadena[]="Hola";
    upperStr(cadena);
    printf("upperStr: %s\n",cadena);
    lowerStr(cadena);
    printf("lowerStr: %s\n",cadena);
    int num;
    char numeros[50];
    scanf("%d",&num);
    printf("numToStr: %s\n",numToStr(numeros,num));
    return 0;
}
void upperStr(char v[]) {
    int i;
    for (i=0;v[i]!='\0';i++) {
        if ((v[i]>=97) && (v[i]<=122))
            v[i]=v[i]-32;
    }
}
void lowerStr(char v[]) {
    int i;
    for (i=0;v[i]!='\0';i++) {
        if ((v[i]>=65) && (v[i]<=90))
            v[i]=v[i]+32;
    }
}
int invertir (int num) {
    int dig=1;
    int inv=0;
    while (num!=0) {
        dig=num%10;
        num=num/10;
        inv=inv*10+dig;
    }
    return inv;
}
char * numToStr(char v[], int num) {
    int digito=-1;
    int i=0;
    num=invertir(num);
    while (num!=0) {
        digito=num%10;
        v[i]=digito+48;
        num=num/10;
        i++;
    }
    return v;
}
char * numToText (int num) {
    char v[50];

    char uno[]="uno",dos[]="dos",tres[]="tres",cuatro[]="cuatro",cinco[]="cinco",seis[]="seis",siete[]="siete",ocho[]="ocho",nueve[]="nueve";
    char diez[]="diez", once[]="once",doce[]="doce", trece[]="trece",catorce[]="catorce",quince[]="quince";
    char dieci[]="dieci", veinte[]="veinte",treinta[]="treinta",cuarenta[]="cuarenta";
    char cincuenta[]="cincuenta",sesenta[]="sesenta",setenta[]="setenta",ochenta[]="ochenta", noventa[]="noventa";
    switch (num) {
        case 10:
            strcopy(v,"diez");
        break;
        case 20:
            v[50]="veinte";
        break;
        case (num>20)
            v
        break;
        case 30:
            v[50]="treinta";
        break;
        case 40:
            v[50]="cuarenta";
        break;
        case 50:
            v[50]="cinco";
        break;
        case 60:
            v[50]="sesenta";
    }
    return v;
}
