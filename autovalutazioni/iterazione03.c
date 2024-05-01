#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool selezionata(const size_t cols, const int riga[cols], const int prod_j[cols], 
int *sum_prod){
    bool ret = false;
    int r_sum_prod = 0;

    for (size_t c = 0; c < cols; c++)
    {
        if(riga[c]%3==0){
            r_sum_prod += prod_j[c];
        }
    }

    if(r_sum_prod != 0 && r_sum_prod%10 == 0){
        *sum_prod = r_sum_prod;
        ret = true;
    }

    return ret;
}

void calcola_prod_j(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows], int *prod)
{
    for (size_t c = 0; c < cols; c++){
        prod[c] = 1;
        for (size_t r = 0; r < rows; r++){
            if(c<rags[r]){
                prod[c] *= mat[r][c]; 
            }
        }
    }
}

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    int *pMinSumProd) 
{
    bool ret = false;

    int selezionate = 0;
    bool r_selezionata;
    int prod_j[cols];
    calcola_prod_j(rows, cols, mat, rags, prod_j);
    int min_sum = INT_MAX;

    for (size_t r = 0; r < rows; r++)
    {
        int sum_prod = 0;
        r_selezionata = selezionata(rags[r], mat[r], prod_j, &sum_prod);
        selezionate += r_selezionata;
        if(min_sum>sum_prod && r_selezionata)
            min_sum = sum_prod;
    }
    
    if(selezionate>=2){
        *pMinSumProd = min_sum;
        ret = true;
    }

    return ret;
}

int main(){
    const size_t rows=2, cols=4;
    int mat[2][4] = {
    {7, 3, 3},
    {6, 6, 4, 8}};
    size_t rags[2] = { 3, 4};
    int v;
    bool ret = e1(rows, cols, mat, rags, &v);
    if (ret) { printf("T %d\n", v); } else { printf("F\n"); }
}