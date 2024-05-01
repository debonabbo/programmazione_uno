#include <stdio.h>
#include <stdbool.h>

void leggi_matrice(const size_t rows, const size_t cols,
				   int mat[rows][cols]) 
{
	for (size_t r=0; r<rows; r++) {
		for (size_t c=0; c<cols; c++) {
			scanf("%d", &mat[r][c]);
		}
	}
}

bool riga_pari_nn(const size_t cols, int mat[cols]){
    bool rpnn = true;

    for (size_t i = 0; i < cols && rpnn; i++){
        rpnn = (mat[i]%2 == 0 && mat[i]>=0);
    }
    
    return rpnn;
}

bool colonna_pari_nn(const size_t rows, const size_t cols, int mat[rows][cols], 
                    size_t colonna){
    bool cpnn = true;
    for (size_t i = 0; i < rows && cpnn; i++){
        cpnn = (mat[i][colonna]%2 == 0 && mat[i][colonna]>=0);
    }
    
    return cpnn;
}

int main(void) {
	// leggi le dimensioni della matrice rettangolare
	size_t rows, cols;
	scanf("%zu %zu", &rows, &cols);

	// riserva la memoria per la matrice di dimensione rows * cols
	int mat[rows][cols];
	
	// leggi i dati
	leggi_matrice(rows, cols, mat);

	// COMPLETARE
    for (size_t r = 0; r < rows; r++)
    {
        if(riga_pari_nn(cols, mat[r])){
            for (size_t c = 0; c < cols; c++)
            {
                if(colonna_pari_nn(rows, cols, mat, c))
                    printf("%zu %zu\n", r, c);
            }
        }
    }

    return 0;
}