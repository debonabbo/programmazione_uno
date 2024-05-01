#include <stdio.h>
#define NUM_TAGLI 6 

const int tagli_monete[NUM_TAGLI] = {1,2,5,10,20,50};

int CambioTaglio(int totale, int moneta);

int main(){
    int cent = 0;

    printf("Inserisci un numero in centesimi: ");
    scanf("%d", &cent);

    printf("Il piu' piccolo cambio vale:\n");

    int resto = cent;
    for (int i = NUM_TAGLI-1; i >= 0; i--){
        resto = CambioTaglio(resto, tagli_monete[i]);
    }
    
    return 0;
}

int CambioTaglio(int totale, int moneta){
    int resto = totale;

    if((totale / moneta) != 0){
        int numero_cambi = totale / moneta;
        resto -= numero_cambi*moneta;
        printf("%d da %d cent\n", numero_cambi, moneta);
    }

    return resto;
}