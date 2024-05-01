#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

bool verifica_primalita(size_t n);

int main(){
    clock_t partenza, arrivo;
    double delta;
    size_t trovati = 0;
    partenza = clock();

    for (size_t i = 0; i < 100; i++){
        if(verifica_primalita(i)){
            trovati++;
            printf("Il numero %zu e' primo.\n", i);
        }
    }

    arrivo = clock();
    delta = ((double)(arrivo - partenza))/CLOCKS_PER_SEC;

    printf("Ho trovato %zu numeri primi.\n", trovati);
    printf("L'intero processo e' durato %g secondi.", delta);

    return 0;
}

bool verifica_primalita(size_t n){
    bool primo = true;

    if(n>1){
        for(size_t i = (size_t)sqrt(n); i >= 2 && primo; i--){
            if(n%i == 0)
                primo = false;
        }
    } else {
        primo = false;
    }

    return primo;
}