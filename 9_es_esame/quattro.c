// Scrivere una funzione iterativa e1 con le seguenti caratteristiche:

//e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi, 
//ed un array di interi (aLen, a)
//definiamo come prodotto riga-array tra la riga i e l'array a[] la somma dei 
//prodotti elemento per elemento tra la riga i della matrice e l'array, fino al 
//limite della sequenza più piccola.
//e1 determina se esistono righe per le quali il prodotto riga-array è sia 
//maggiore di 0 che multiplo di 5: in quel caso, e1 restituisce true, e la 
//somma di tutti i prodotti riga-array viene scritta nella variabile pSum.
//In ogni altro caso, e1 restituisce false.

#include <stdio.h>
#include <stdbool.h>

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const size_t aLen, const int a[aLen],
	    int *pSum) 
{
    int sum = 0;
    bool ret = false;

    for (size_t r = 0; r < rows; r++){
        int prodotto = 0;
        for (size_t c = 0; c < rags[r] && c < aLen; c++){
            prodotto += mat[r][c]*a[c];
        }

        if(prodotto>0 && prodotto%5==0){
            ret = true;
            sum += prodotto;
        }
    }

    if(ret)
        *pSum = sum;

    return ret;
}

int main(){
    const size_t rows=2, cols=3;
    int mat[2][3] = {
    {8, 6, 8},
    {7, 3, 2}};
    size_t rags[2] = {3, 3};
    size_t aLen=4;
    int a[4] = {4, 6, -3, -4};
    int v;
    bool ret = e1(rows, cols, mat, rags, aLen, a, &v);
    if (ret) { printf("T %d\n", v); } else { printf("F\n"); }

    //T 40

    return 0;
}