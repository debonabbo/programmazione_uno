#include <stdio.h>
#include <stdbool.h>

// Scrivere ua funzione iterativa e1 con le seguenti caratteristiche:

// e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi;
// e1 modifica in-place la matrice irregolare;
// e1 non modifica la riga 0;
// per ciascuna riga i>0, la funzione e1 scorre gli elementi e filtra via tutti gli 
// elementi che compaiono sulla riga precedente;
// e1 ritorna true se esiste almeno una riga che è stata modificata.

bool contiene(const size_t aLen, const int a[aLen], const int val){
    bool contenuto = false;

    for (size_t i = 0; i < aLen && !contenuto; i++){
        if(a[i]==val)
            contenuto = true;
    }

    return contenuto;
}

bool e1(const size_t rows, const size_t cols, 
	    int mat[rows][cols], size_t rags[rows]) 
{
    bool modificate = false;

    for (size_t r = 1; r < rows; r++)
    {
        size_t m = 0;
        for (size_t c = 0; c < rags[r]; c++){
            if(!contiene(rags[r-1], mat[r-1], mat[r][c]))
                mat[r][m++] = mat[r][c];
        }
        
        if(rags[r] != m){
            modificate = true;
            rags[r] = m;
        }
    }
    
    return modificate;
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
    const size_t rows=2, cols=3;
    int mat[2][3] = {
    {0, -9, -2},
    {-4, -9, -9}};
    size_t rags[2] = {3, 3};
    bool ret = e1(rows, cols, mat, rags);
    int_ragmat_print(rows, cols, mat, rags);
    puts(ret?"T":"F");
    return 0;
}