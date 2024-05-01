#include <stdio.h>
#include <math.h>

int main(){
    int prezzi[] = {150, 250};
    char *prodotti[] = {"Orecchiette","Pomodori"};
    int totale = 0;
    float quantita = 0;
    const int 🍝 = 0, 🍅 = 1;

    //Versione uno

    printf("Quante pacchi di orecchiette hai comprato? ");
    scanf("%f", &quantita);
    totale += floor(quantita) * prezzi[🍝];

    printf("Quanti kg di pomodori hai comprato? ");
    scanf("%f", &quantita);
    totale += quantita * prezzi[🍅];

    printf("Il totale della spesa e': %.2f", (totale / 100.0));

    //fine versione uno

    return 0;
}