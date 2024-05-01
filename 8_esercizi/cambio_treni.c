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

void calcola_percorso(const size_t from, const size_t to, const size_t rows, 
        const size_t cols, const size_t rags[rows], const int mat[rows][cols]){
    bool trovato = false;

    for (size_t c = 0; from < rows && c < rags[from] && !trovato; c++){
        if(mat[from][c] == to)
            trovato = true;
    }
    
    if(!trovato){
        for (size_t c = 0; c < rags[from] && !trovato; c++){
            size_t intermedia = mat[from][c];
            for (size_t i = 0; intermedia < rows && i < rags[intermedia] && !trovato; i++){
                if(mat[intermedia][i] == to)
                    trovato = true;
            }
        }
        if(trovato)
            printf("1 CAMBIO\n");
        else
            printf("NO\n");
    } else {
        printf("DIRETTO\n");
    }
}



int main(void) {
	// leggi la matrice irregolare
	size_t rows, cols;
	scanf("%zu %zu", &rows, &cols);
	int mat[rows][cols];
	size_t rags[rows];
	leggi_matrice_irregolare(rows, cols, mat, rags);

	// leggi il numero di interrogazioni
	size_t q, from, to;
	scanf("%zu", &q);
	
	// COMPLETARE
	for (size_t i = 0; i < q; i++){
        scanf("%zu %zu", &from, &to);
        calcola_percorso(from, to, rows, cols, rags, mat);
    }
}
