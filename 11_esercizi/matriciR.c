#include <stdio.h>
#include <stdbool.h>

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

// Restituisce true se esiste un elemento pari nell'array a
bool esiste_pari(const size_t aLen, const int a[]); // involucro

// Restituisce il numero di righe su cui compaiono elementi pari
// La matrice in ingresso mat[] è una matrice irregolare.
size_t conta_righe_con_pari(const size_t rows, const size_t cols,
                            const int mat[rows][cols], 
                            const size_t rags[rows]); // involucro

//------------------------------------------------------------------

// Restituisce true se tutti gli elementi dell'array 
// appartengono all'intervallo [min, max]
bool tutti_in_intervallo(const size_t aLen, const int a[], 
                         const int min, const int max); // involucro

// Restituisce la somma delle lunghezze di tutte le righe i cui
// elementi appartengono tutti all'intervallo [min, max]
// (le righe i cui elementi non appartengono tutti all'intervallo 
// [min, max] non partecipano alla somma).
size_t somma_lungh_righe_minmax(const size_t rows, const size_t cols,
                                const int mat[rows][cols], 
                                const size_t rags[rows],
                                const int min, const int max); // involucro

//------------------------------------------------------------------

int main(void) {
    const size_t rowsA = 3, colsA = 6;
    int matA[3][6] = {
      {91,35,51},
      {9,83,75,87,41,65},
      {1,53,96,15}};
    size_t ragsA[3] = {3,6,4};

    const size_t rowsB = 4, colsB = 7;
    int matB[4][7] = {
      {19,7,25,59},
      {46,9},
      {55,1,44,65},
      {85,49,11,42,4,10,30}};
    size_t ragsB[4] = {4,2,4,7};

    const size_t rowsC = 5, colsC = 10;
    int matC[5][10] = {
      {29,65,20,12,19,15,30,60,14},
      {10,82,17,78},
      {35,74,68,18,36,94,10,62,93,16},
      {95,1,23,67},
      {92,59,92,81,86,46,24,17,24,51}};
    size_t ragsC[5] = {9,4,10,4,10};

    // Unit test per la conta delle righe con elementi pari
    puts("Righe con elementi pari");
    size_t crpA = conta_righe_con_pari(rowsA, colsA, matA, ragsA);
    size_t crpB = conta_righe_con_pari(rowsB, colsB, matB, ragsB);
    size_t crpC = conta_righe_con_pari(rowsC, colsC, matC, ragsC);
    printf("Matrice A: %2zu  [atteso: 1]\n", crpA);
    printf("Matrice B: %2zu  [atteso: 3]\n", crpB);
    printf("Matrice C: %2zu  [atteso: 4]\n", crpC);

    // Unit test per la conta delle righe con elementi pari
    puts("\nSomma lunghezze righe minmax");
    size_t slmA = somma_lungh_righe_minmax(rowsA, colsA, matA, ragsA, 5, 75);
    size_t slmB = somma_lungh_righe_minmax(rowsB, colsB, matB, ragsB, 5, 75);
    size_t slmC = somma_lungh_righe_minmax(rowsC, colsC, matC, ragsC, 5, 75);
    printf("Matrice A: %2zu  [atteso: 0]\n", slmA);
    printf("Matrice B: %2zu  [atteso: 6]\n", slmB);
    printf("Matrice C: %2zu  [atteso: 9]\n", slmC);
}

//------------------------------------------------------------------

bool esiste_pariR(const size_t aLen, const int a[], const size_t i){
  if(i>=aLen){
    return false;
  } else {
    if(a[i]%2 == 0)
      return true;
    else
      return esiste_pariR(aLen, a, i+1);
  }
}
// Restituisce true se esiste un elemento pari nell'array a
bool esiste_pari(const size_t aLen, const int a[]){
  return esiste_pariR(aLen, a, 0);
}

size_t conta_righe_con_pariR(const size_t rows, const size_t cols, 
                              const int mat[rows][cols],
                              const size_t rags[rows], const size_t i)
{
  if(i>=rows){
    return 0;
  } else {
    size_t somma = (size_t)esiste_pari(rags[i], mat[i]);

    return somma + conta_righe_con_pariR(rows, cols, mat, rags, i+1);
  }
}
// Restituisce il numero di righe su cui compaiono elementi pari
// La matrice in ingresso mat[] è una matrice irregolare.
size_t conta_righe_con_pari(const size_t rows, const size_t cols,
                            const int mat[rows][cols], 
                            const size_t rags[rows])
{
  return conta_righe_con_pariR(rows, cols, mat, rags, 0);
}

//------------------------------------------------------------------

bool tutti_in_intervalloR(const size_t aLen, const int a[], const int min,
                          const int max, const size_t i)
{
  if(i>=aLen){
    return true;
  } else {
    bool tutti = (a[i]<=max && a[i]>=min);

    if(tutti)
      return tutti_in_intervalloR(aLen, a, min, max, i+1);
    
    return false;
  }
}
// Restituisce true se tutti gli elementi dell'array 
// appartengono all'intervallo [min, max]
bool tutti_in_intervallo(const size_t aLen, const int a[], 
                         const int min, const int max)
{
  return tutti_in_intervalloR(aLen, a, min, max, 0);
}

size_t somma_lungh_righe_minmaxR(const size_t rows, const size_t cols,
                                  const int mat[rows][cols], 
                                  const size_t rags[rows],
                                  const int min, const int max, const size_t i)
{
  if(i>=rows){
    return 0;
  } else {
    size_t somma = tutti_in_intervallo(rags[i], mat[i], min, max) * rags[i];

    return somma+somma_lungh_righe_minmaxR(rows, cols, mat, rags, min, max, i+1);
  }
}
// Restituisce la somma delle lunghezze di tutte le righe i cui
// elementi appartengono tutti all'intervallo [min, max]
// (le righe i cui elementi non appartengono tutti all'intervallo 
// [min, max] non partecipano alla somma).
size_t somma_lungh_righe_minmax(const size_t rows, const size_t cols,
                                const int mat[rows][cols], 
                                const size_t rags[rows],
                                const int min, const int max)
{
  return somma_lungh_righe_minmaxR(rows, cols, mat, rags, min, max, 0);
}