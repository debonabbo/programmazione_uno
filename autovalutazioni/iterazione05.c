#include <stdio.h>
#include <stdbool.h>

// Scrivere una funzione iterativa e1 con le seguenti caratteristiche:
// e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi;
// e1 modifica in-place la matrice irregolare;
// per ciascuna riga i, la funzione e1 scorre le colonne valide e, per ogni colonna 
// j il cui elemento è maggiore di 0 e multiplo di 3, aggiunge in fondo alla riga I 
// l'elemento stesso diviso 3.
// L'aggiunta degli elementi si interrompe se la riga raggiunge la capacità massima 
// cols.
// e1 ritorna true se tutte le righe hanno ricevuto almeno un'aggiunta di elementi. 
// Ritorna false altrimenti.

bool e1(const size_t rows, const size_t cols, 
	    int mat[rows][cols], size_t rags[rows]) 
{
    size_t modificate = 0;

    for (size_t i = 0; i < rows; i++){
        bool modificata = false;

        for (size_t j = 0; (j < rags[i]) && (rags[i] < cols); j++){
            if(mat[i][j]>0 && mat[i][j]%3==0){
                mat[i][(rags[i]++)] = (mat[i][j]/3);
                modificata = true;
            }
        }

        if(modificata){
            modificate++;
        }
    }

    return (modificate == rows);
}

void int_ragmat_print(size_t rows, size_t cols, int mat[rows][cols], 
                        size_t rags[rows])
{
    for (size_t r = 0; r < rows; r++){
        for (size_t c = 0; c < rags[r]; c++){
            printf("%d ", mat[r][c]);
        }
        printf("\n");
    }
}

int main(){
    const size_t rows=2, cols=4;
    int mat[2][4] = {
    {9, -9},
    {3}};
    size_t rags[2] = {2, 1};
    bool ret = e1(rows, cols, mat, rags);
    int_ragmat_print(rows, cols, mat, rags);
    puts(ret?"T":"F");
    return 0;
}