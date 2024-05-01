#include <stdio.h>
#include <stdbool.h>

// Scrivere una funzione e2 con le seguenti caratteristiche:

//     e2 prende in ingresso due array: (aLen, a) e (bLen, b)
//     e2 é una funzione involucro che chiama una funzione ricorsiva e2R.

// Scrivere inoltre una funzione e2R con le seguenti caratteristiche:

//     e2R considera ciascuna coppia di elementi di a e di b nella medesima 
//     posizione, fino alla lunghezza massima di entrambi gli array.
//     Per ciascuna posizione, e2R calcola il prodotto (se entrambi gli 
//     elementi della coppia sono disponibili), oppure il quadrato dell'elemento 
//     (se un solo elemento è disponibile, e l'altro array è terminato).
//     e2R ritorna la somma dei valori calcolati fino alla lunghezza massima di 
//     entrambi gli array.
//     Se non ci sono elementi nei due array, e2R ritorna 0.

int e2R(const size_t aLen, const int a[], const size_t bLen, const int b[], 
        const size_t i) {
    if(i>= aLen && i>=bLen){
        return 0;
    } else {
        int prodotto;
        if(i>=aLen){
            prodotto = b[i]*b[i];
        } else if (i>=bLen){
            prodotto = a[i]*a[i];
        } else {
            prodotto = a[i]*b[i];
        }

        return prodotto + e2R(aLen, a, bLen, b, i+1);
    }
}

int e2(const size_t aLen, const int a[], const size_t bLen, const int b[]) {
    return e2R(aLen, a, bLen, b, 0);
}

int main(){
    const size_t aLen = 2, bLen = 1;
    const int a[2] = {10,3};
    const int b[1] = {4};
    printf("%d\n", e2(aLen, a, bLen, b));
    return 0;
}