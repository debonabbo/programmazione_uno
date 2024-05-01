#include <stdio.h>
#include <stdbool.h>

#define MAX_NUMERI 5

bool CalcolaMediaVarianza(size_t *media, size_t *varianza);

int main(){
    size_t media, varianza;

    if(CalcolaMediaVarianza(&media, &varianza)){
        printf("La media della sequenza inserita e' %zu.\n", media);
        printf("La varianza della sequenza inserita e' %zu.\n", varianza);
    }


    return 0;
}

bool CalcolaMediaVarianza(size_t *media, size_t *varianza){
    bool tuttoOk = false;
    size_t somma = 0, numeri = 0, n;
    size_t sequenza[MAX_NUMERI] = {0};

    while(numeri < MAX_NUMERI && scanf("%zu", &n) == 1){
        somma += n;
        sequenza[numeri] = n;
        numeri++;
    }

    if(numeri == MAX_NUMERI){
        *media = somma / numeri;
        *varianza = 0;
        for(size_t i = 0; i < MAX_NUMERI; i++){
            *varianza += ((sequenza[i]-1)*(sequenza[i]-1));
        }
        *varianza /= 5;
        tuttoOk = true;
    }

    return tuttoOk;
}