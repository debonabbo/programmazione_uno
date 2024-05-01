// Scrivere ua funzione iterativa e1 con le seguenti caratteristiche:

//e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi;
//e1 modifica in-place la matrice irregolare;
//e1 non modifica la riga 0;
//per ciascuna riga i>0, la funzione e1 scorre gli elementi e filtra via tutti 
//gli elementi che compaiono sulla riga precedente;
//e1 restituisce true se esiste almeno una riga che è stata modificata.

#include <stdio.h>
#include <stdbool.h>

bool e1(const size_t rows, const size_t cols, 
	    int mat[rows][cols], size_t rags[rows]) 
{
    bool ret = false;

    for (size_t r = 1; r < rows; r++){
        size_t i = 0;
        for (size_t c = 0; c < rags[r]; c++){
            bool trovato = false;
            for (size_t p = 0; p < rags[r-1] && !trovato; p++){
                trovato = (mat[r][c]==mat[r-1][p]);
            }
            if(!trovato)
                mat[r][i++] = mat[r][c];
            else
                ret = true;
        }
        rags[r] = i;
    }
    
    return ret;
}

int main(){
    const size_t rows=4, cols=6;
int mat[4][6] = {
  {-1, 7, 5},
  {8, 3, 0},
  {1, 0, -1},
  {-2, -1, 1, 6, -2, -2}};
size_t rags[4] = {3, 3, 3, 6};
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