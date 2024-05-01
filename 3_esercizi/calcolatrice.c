#include <stdio.h>

int main(){
    int x1, x2, x3, richiesta;

    printf("Inserisci tre numeri interi: ");
    scanf("%d%d%d", &x1, &x2, &x3);

    printf("Seleziona l'operazione desiderata:\n");
    printf("Scrivi 1 per calcolare la somma\n");
    printf("Scrivi 2 per calcolare il prodotto\n");
    printf("Scrivi 3 per calcolare la media\n");
    printf("=> ");

    scanf("%d", &richiesta);

    if(richiesta < 1 || richiesta > 3){
        printf("Non esiste un'operazione associata.\n");
    } else {
        if(richiesta == 1){
            printf("La somma tra i tre numeri e': %d", (x1+x2+x3));
        } else if (richiesta == 2){
            printf("Il prodotto tra i tre numeri e': %d", (x1*x2*x3));
        } else {
            printf("La media tra i tre numeri e': %d", ((x1+x2+x3)/3));
        }
    }


    return 0;
}