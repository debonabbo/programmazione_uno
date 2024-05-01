#include <stdio.h>
#include <stdbool.h>

bool leggi_sequenza(int *somma,int *sommaQuadrata,int *massimo) {
    int numero;
    bool sequenzaRilevata = false;
    *somma = 0;
    *sommaQuadrata = 0;
    *massimo = 0;

    do{
        scanf("%d", &numero);
        if(numero != 0){
            *somma += numero;
            *sommaQuadrata += numero*numero;
            if(sequenzaRilevata){
                if(*massimo < numero)
                    *massimo = numero;
            } else {
                *massimo = numero;
            }

            sequenzaRilevata = true;
        }
    } while (numero != 0);

    return sequenzaRilevata;
}

int main(void) {
    int somma = 0, sommaQuadrata =0, massimo=0;

    while(leggi_sequenza(&somma, &sommaQuadrata, &massimo)){
        printf("%d %d %d\n", somma, sommaQuadrata, massimo);
    }

    return 0;
}