#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi, 
// ed un puntatore ad un intero pMinSumProd
// una riga i viene definita come selezionata in base a questo criterio. 
// Calcoliamo i prodotti degli elementi di ciascuna colonna j<rags[i] per la quale 
// l'elemento i,j è multiplo di 3. 
// La riga i è selezionata se almeno una colonna j soddisfa il criterio, e se la 
// somma di tutti questi prodotti è divisibile per 10.
// e1 restituisce true se esistono almeno due righe selezionate. In questo caso, 
// il valore di pMinSumProd viene inizializzato alla più piccola somma dei prodotti 
// presente in una riga selezionata

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    int *pMinSumProd) 
{
    int prodotti[cols];
    bool ret = false;
    int min = INT_MAX;

    for (size_t c = 0; c < cols; c++){
        prodotti[c] = 1;
        for (size_t r = 0; r < rows; r++){
            if(c<rags[r]){
                prodotti[c] *= mat[r][c];
            }
        }
    }

    size_t nSelezionate = 0;

    for (size_t r = 0; r < rows; r++){
        int somma = 0;
        bool sommato = false;
        for (size_t c = 0; c < rags[r]; c++){
            if(mat[r][c]%3==0){
                somma += prodotti[c];
                sommato = true;
            }
        }

        if(sommato && somma%10 ==0){
            nSelezionate++;
            if(somma<min)
                min=somma;
        }
    }
    
    if((ret = (nSelezionate >= 2)))
        *pMinSumProd = min;

    return ret;
}

int main(){
    const size_t rows=2, cols=4;
    int mat[2][4] = {
    {7, 3, 3},
    {6, 6, 4, 8}};
    size_t rags[2] = { 3, 4};
    int v;
    bool ret = e1(rows, cols, mat, rags, &v);
    if (ret) { printf("T %d\n", v); } else { printf("F\n"); }

    return 0;
}