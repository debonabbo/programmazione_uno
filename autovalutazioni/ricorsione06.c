#include <stdio.h>
#include <stdbool.h>

bool esiste_val_in_arrayR(const size_t aLen, const int a[], const int val,
                            const size_t i)
{
    if(i>=aLen){
        return false;
    } else {
        if(a[i] == val){
            return true;
        }

        return esiste_val_in_arrayR(aLen, a, val, i+1);
    }
}

int e2R(const size_t rows, const size_t cols, const int mat[rows][cols],
        const size_t rags[rows], const int val, const int i) 
{
    if(i>=rows){
        return 0;
    } else {
        int somma = 0;
        if(esiste_val_in_arrayR(rags[i], mat[i], val, 0)){
            somma += rags[i];
        }

        return somma + e2R(rows, cols, mat, rags, val, i+1);
    }
}

int e2(const size_t rows, const size_t cols,
       const int mat[rows][cols], const size_t rags[rows], 
       const int val)
{
    return e2R(rows, cols, mat, rags, val, 0);
}