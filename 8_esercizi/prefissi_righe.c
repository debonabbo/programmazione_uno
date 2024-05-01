#include <stdio.h>
#include <stdbool.h>

void leggi_matrice_irregolare(const size_t rows, const size_t cols,
				              int mat[rows][cols], size_t rags[rows]) 
{
	for (size_t r=0; r<rows; r++) {
	    scanf("%zu", &rags[r]);
		for (size_t c=0; c<rags[r]; c++) {
			scanf("%d", &mat[r][c]);
		}
	}
}

void trova_prefissi(const size_t rowsA, const size_t colsA, size_t ragsA[rowsA],
                        int matA[rowsA][colsA], const size_t rowsB, const 
                        size_t colsB, size_t ragsB[rowsB], int matB[rowsB][colsB]);

int main(void) {
	// leggi la matrice irregolare A
	size_t rowsA, colsA;
	scanf("%zu %zu", &rowsA, &colsA);
	int matA[rowsA][colsA];
	size_t ragsA[rowsA];
	leggi_matrice_irregolare(rowsA, colsA, matA, ragsA);

	// leggi la matrice irregolare B
	size_t rowsB, colsB;
	scanf("%zu %zu", &rowsB, &colsB);
	int matB[rowsB][colsB];
	size_t ragsB[rowsB];
	leggi_matrice_irregolare(rowsB, colsB, matB, ragsB);

	// COMPLETARE
    trova_prefissi(rowsA, colsA, ragsA, matA, rowsB, colsB, ragsB, matB);
}

void trova_prefissi(const size_t rowsA, const size_t colsA, size_t ragsA[rowsA],
                        int matA[rowsA][colsA], const size_t rowsB, const 
                        size_t colsB, size_t ragsB[rowsB], int matB[rowsB][colsB])
{
    for (size_t rA = 0; rA < rowsA; rA++){
        for (size_t rB = 0; rB < rowsB; rB++)
        {
            if(ragsA[rA] <= ragsB[rB]){
                bool prefisso = true;
                for (size_t i = 0; i < ragsA[rA] && prefisso; i++){
                    if(matA[rA][i] != matB[rB][i])
                        prefisso = false;
                }
                if(prefisso)
                    printf("%zu %zu\n", rA, rB);
            }
        }
    }
}