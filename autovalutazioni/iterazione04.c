#include <stdio.h>
#include <stdbool.h>

// Scrivere una funzione iterativa e1 con le seguenti caratteristiche:

// e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi,
// ed un array di interi (aLen, a)
// definiamo come prodotto riga-array tra la riga i e l'array a[] la somma dei 
// prodotti elemento per elemento tra la riga i della matrice e l'array, fino al
//  limite della sequenza più piccola.
// e1 determina se esistono righe per le quali il prodotto riga-array è sia 
// maggiore di 0 che multiplo di 5: in quel caso, e1 ritorna true, e la somma di 
// tutti i prodotti riga-array viene scritta nella variabile pSum.
// In ogni altro caso, e1 ritorna false.

int prodotto_r_a(const size_t size, const int r[size], const int a[size]){
    int prodotto = 0;

    for (size_t i = 0; i < size; i++){
        prodotto += r[i]*a[i];
    }

    return prodotto;
}

int min(const int a, const int b){
    int minimo = a;
    if(a>b)
        minimo = b;
    return minimo;
}

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const size_t aLen, const int a[aLen],
	    int *pSum) 
{
    bool esistono_righe = false;
    *pSum = 0;

    for (size_t r = 0; r < rows; r++)
    {
        int prodotto = prodotto_r_a(min(aLen, rags[r]), mat[r], a);
        
        if(prodotto>0 && prodotto%5==0){
            esistono_righe = true;
            *pSum += prodotto;
        }
    }
    
    return esistono_righe;
}

int main(){
    const size_t rows=3, cols=5;
    int mat[3][5] = {
    {1, 6, 1, 1, 5},
    {4, 1, 6, 6},
    {9, 7, 6}};
    size_t rags[3] = {5, 4, 3};
    size_t aLen=4;
    int a[4] = {3, 4, -4, -3};
    int v;
    bool ret = e1(rows, cols, mat, rags, aLen, a, &v);
    if (ret) { printf("T %d\n", v); } else { printf("F\n"); }
    return 0;
}