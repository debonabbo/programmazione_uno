#include <stdio.h>
#include <stdbool.h>

// Scrivere un funzione iterativa e1 con le seguenti caratteristiche:

// e1 riceve in input una matrice rettangolare (rows, cols, mat[rows][cols]) di 
// interi.
// e1 stampa in output tutte le coppie (i,j) che rappresentano l'indice di un 
// punto di sella.
// Chiamiamo 'punto di sella' un elemento nella matrice mat[i][j] alla posizione
// (i,j) che ha le seguenti caratteristiche:
// l'elemento mat[i][j] è il massimo nella riga i e minimo nella riga j.

// NOTA: (i1, j1) deve essere stampata prima della coppia (i2, j2) se i1<i2 
// oppure se (i1==i2 && j1<j2).

bool is_max_row(const size_t cols, const int a[cols], const int x){
    int max = a[0];
    for (size_t i = 1; i < cols; i++){
        if(a[i]>max)
            max = a[i];
    }
    return max == x;
}

bool is_min_col(const size_t rows, const size_t cols, const int mat[rows][cols],
const int c, const int x){
    int min = mat[0][c];
    for (size_t r = 0; r < rows; r++){
        if(mat[r][c] < min)
            min = mat[r][c];
    }
    
    return min == x;
}

bool e1(const size_t rows, const size_t cols, const int mat[rows][cols])
{
    bool ret = true;

    for (size_t r = 0; r < rows; r++){
        bool ret_r = false;

        for (size_t c = 0; c < cols; c++){
            if(is_max_row(cols, mat[r], mat[r][c]) && 
                is_min_col(rows, cols, mat, c, mat[r][c])){
                printf("%zu %zu\n", r, c);
                ret_r = true;
            }
        }

        if(!ret_r)
            ret = false;
    }

    return ret;
}

int main(){
    const size_t rows=3, cols=5;
    int mat[3][5] = {
    {8, 8, -1, 1, 0},
    {-6, 8, -2, -8, -2},
    {-3, 8, -2, -4, 6}};
    puts(e1(rows, cols, mat) ? "T" : "F");

    return 0;
}