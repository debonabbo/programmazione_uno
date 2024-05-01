#include <stdio.h>
#include <stdbool.h>

// Scrivere una funzione iterativa e1 con le seguenti caratteristiche:

// e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi;
// e1 modifica in-place la matrice irregolare;
// per ciascuna riga i, la funzione e1 scorre le colonne valide e, per ogni colonna 
// j il cui elemento è maggiore di 0 e multiplo di 3, aggiunge in fondo alla riga I 
// l'elemento stesso diviso 3.
// L'aggiunta degli elementi si interrompe se la riga raggiunge la capacità massima cols.
// e1 restituisce true se tutte le righe hanno ricevuto almeno un'aggiunta di 
// elementi, false altrimenti.

bool e1(const size_t rows, const size_t cols, 
	    int mat[rows][cols], size_t rags[rows]) 
{
    bool ret = true;
    for (size_t r = 0; r < rows; r++){
        size_t i = 0;
        bool ret_riga = false;
        for (size_t c = 0; c < rags[r] && rags[r]+i<cols; c++){
            if(mat[r][c]>0 && mat[r][c]%3 == 0){
                mat[r][rags[r]+++i] = mat[r][c]/3;
                ret_riga = true;
            }
        }
        if(!ret_riga)
            ret = false;
    }
    
    return ret;
}

int main(){
    const size_t rows=2, cols=4;
    int mat[2][4] = {
    {-5, -6},
    {7, 2, -9}};
    size_t rags[2] = {2, 3};
    bool ret = e1(rows, cols, mat, rags);
    // int_ragmat_print(rows, cols, mat, rags);

    for (size_t r = 0; r < rows; r++){
        for (size_t c = 0; c < rags[r]; c++){
            printf("%d ", mat[r][c]);
        }
        printf("\n");
    }
    
    puts(ret?"T":"F");

    return 0;
}