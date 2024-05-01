#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// Scrivere un metodo iterativo e1 con le seguenti caratteristiche:

// e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi,
// un intero k, ed un puntatore ad interi pMaxSum
// e1 considera solo le righe che hanno lunghezza non zero. Per ciascuna di queste 
// righe, e1 determina se la somma degli elementi della riga è multiplo di k. 
// e1 ritorna true se tutte le righe di lunghezza non zero hanno somma degli 
// elementi multiplo di k, e se almeno una riga con queste caratteristiche esiste. 
// In tale caso, il massimo di tutte le somme deve essere scritto nell'intero 
// puntato da pMaxSum.
// In ogni altro caso e1 restituisce false.

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const int k, int *pMaxSum) 
{
    bool sommato = false;
    int sommaMax = INT_MIN;
    bool stop = false;

    for (size_t r = 0; r < rows && !stop; r++)
    {
        if(rags[r]>0){
            int somma = 0;

            for (size_t c = 0; c < rags[r]; c++)
            {
                somma += mat[r][c];
            }

            if(somma%k==0){
                sommato = true;
            
                if(sommaMax<somma)
                    sommaMax = somma;
            } else {
                sommato = false;
                stop = true;
            }
        }
    }
    
    if(sommato)
        *pMaxSum = sommaMax;

    return sommato;
}

int main(){
     	

const size_t rows=6, cols=8;
int mat[6][8] = {
  {9, 5, 6},
  {3, 1, 8, 3, 3, 7, 2, 9},
  {3, 5},
  {},
  {9, 9, 2},
  {3, 2, 3, 6, 2}};
size_t rags[6] = {3, 8, 2, 0, 3, 5};
int maxSum;
bool ret = e1(rows, cols, mat, rags, 4, &maxSum);
if (ret) { printf("T %d\n", maxSum); } else { printf("F\n"); }
}