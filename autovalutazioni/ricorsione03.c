#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Scrivere una funzione e2 con le seguenti caratteristiche:

//     e2 prende in ingresso un array (aLen, a) e un valore intero positivo val
//     e2 é una funzione involucro che chiama una funzione ricorsiva e2R.

// Scrivere inoltre una funzione e2R con le seguenti caratteristiche:

//     e2R esegue una ricorsione dicotomica sugli elementi di a[]
//     e2R ritorna la somma di tutti gli elementi di a[] il cui valore è compreso 
//     tra -val e +val, estremi inclusi.
//     Se non ci sono elementi nell'array a[], e2R ritorna 0.

int e2R(const size_t left, const size_t right, const int a[], const int val)
{
    if(left>=right){
        return 0;
    } else if (right-left == 1){
        if(a[left]>-val && a[left]<val)
            return a[left];
        return 0;
    } else {
        size_t mid = ((right-left)/2)+left;

        return e2R(left, mid, a, val) + e2R(mid, right, a, val);
    }
}

int e2(const size_t aLen, const int a[], const int val) {
    return e2R(0, aLen, a, val);
}

int main(){
    const size_t aLen = 3;
    const int a[3] = {-1,7,-20};
    printf("%d\n", e2(aLen, a, 10));
    return 0;
}