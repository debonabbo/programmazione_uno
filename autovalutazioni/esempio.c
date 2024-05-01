#include <stdio.h>
#include <stdbool.h>

// Scrivere una funzione e2 con le seguenti caratteristiche:

//     e2 prende in ingresso un'array (aLen, a), un secondo array (*p_bLen, b), ed 
//     un valore val.
//     e2 é una funzione involucro che chiama una funzione ricorsiva e2R.

// Scrivere inoltre una funzione e2R con le seguenti caratteristiche:

//     e2R considera ciascun elemento di a: se tale elemento é strettamente 
//     maggiore di val, allora e2R copia nell'array b la differenza dell'elemento 
//     di a con il valore val.
//     Al più *p_bLen elementi vengono scritti nell'array b. Quando e2R termina, 
//     il valore puntato da *p_bLen viene modificato con il numero di elementi 
//     effettivamente scritti nell'array b.

void e2R(const size_t aLen, const int a[], size_t* p_bLen, int b[],
            const int val, const size_t ia, size_t ib)
{
    if(ia >= aLen || ib >= *p_bLen){
        *p_bLen = ib;
        return; //FINE DI TUTTO
    } else {
        if(a[ia]>val){
            //b[ib] = differenza;
            b[ib] = (a[ia]-val);
            ib++;   //Conto quanti elementi scrivo
        }

        e2R(aLen, a, p_bLen, b, val, ia+1, ib);
    }
}

void e2(const size_t aLen, const int a[], size_t* p_bLen, int b[], 
		const int val)
{
	return e2R(aLen, a, p_bLen, b, val, 0, 0);
}