#include <stdio.h>
#include <stdbool.h>

// Scrivere un funzione iterativa e1 con le seguenti caratteristiche:

//     e1 riceve in input una matrice rettangolare (rows, cols, mat[rows][cols]) di 
//     interi.
//     e1 stampa in output tutte le coppie (i,j) che rappresentano l'indice di un 
//     punto di sella.
//         Chiamiamo 'punto di sella' un elemento nella matrice mat[i][j] alla 
//         posizione (i,j) che ha le seguenti caratteristiche:
//             l'elemento mat[i][j] è il massimo nella riga i e minimo nella colonna j.
//     e1 ritorna true se ogni riga ha almeno un punto di sella. Ritorna false in
//     tutti gli altri casi.

// NOTA: (i1, j1) deve essere stampata prima della coppia (i2, j2) se i1<i2 oppure 
// se (i1==i2 && j1<j2).

void calcola_max_righe(const size_t rows, const size_t cols,
                        const int mat[rows][cols], int massimi[rows])
{
    for (size_t r = 0; r < rows; r++){
        int max = mat[r][0];
        for (size_t c = 1; c < cols; c++){
            if(mat[r][c]>max){
                max = mat[r][c];
            }
        }
        massimi[r] = max;
    }
}

void calcola_min_colonne(const size_t rows, const size_t cols,
                            const int mat[rows][cols], int minimi[cols])
{
    for (size_t c = 0; c < cols; c++){
        int min = mat[0][c];
        for (size_t r = 1; r < rows; r++){
            if(mat[r][c]<min){
                min = mat[r][c];
            }
        }
        minimi[c] = min;
    }
}

bool e1(const size_t rows, const size_t cols, const int mat[rows][cols])
{
    int min_colonne[rows];
    int max_righe[cols];

    calcola_max_righe(rows, cols, mat, max_righe);
    calcola_min_colonne(rows, cols, mat, min_colonne);

    bool tutte_selle = true;

    for (size_t r = 0; r < rows; r++){
        bool sella = false;
        for (size_t c = 0; c < cols; c++)
        {
            if(mat[r][c] == min_colonne[c] && mat[r][c] == max_righe[r]){
                printf("%zu %zu\n", r, c);
                sella = true;
            }
        }
        if(!sella)
            tutte_selle = false;
    }
    
    return tutte_selle;
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