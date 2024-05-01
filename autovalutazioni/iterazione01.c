#include <stdio.h>
#include <stdbool.h>

// Scrivere una funzione iterativa e1 con le seguenti caratteristiche:

// e1 riceve in input una matrice irregolare VLA (rows, cols, mat, rags) di interi
// e1 determina se le righe della matrice in ingresso sono tutte lunghe almeno quanto 
// rows, e se in ciascuna riga i esiste un elemento multiplo di 7. In questo caso, 
// ritorna la somma dei primi multipli di 7 che compaiono sulla sinistra di ciascuna 
// riga. Altrimenti, ritorna 0.

int e1(const size_t rows, const size_t cols, 
	   const int mat[rows][cols], const size_t rags[rows]) 
{
    int ret = 0;
    bool lunghezza = true;

    for (size_t i = 0; i < rows && lunghezza; i++)
    {
        bool trovato = false;

        if(rags[i]>=rows){
            for (size_t c = 0; c < rags[i] && !trovato; c++){
                if(trovato = (mat[i][c]%7==0))
                    ret += mat[i][c];
            }
        } else {
            lunghezza = false;
        }

        if(!trovato)            //Invalido l'output e interrompo il ciclo
            lunghezza = false;
    }
    
    if(!lunghezza)
        ret = 0;

    return ret;
}

int main(){
    const size_t rows=2, cols=4;
    int mat[2][4] = {
    {2, 6, 7, 4},
    {7, 8}};
    size_t rags[2] = {4, 2};
    printf("%d\n", e1(rows, cols, mat, rags));
}