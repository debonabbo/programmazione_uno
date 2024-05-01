#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool e1(const size_t rows, const size_t cols, 
	    const int mat[rows][cols], const size_t rags[rows],
	    const int k, int *pMaxSum) 
{
    bool tutte = true;
    int max = INT_MIN;

    for (size_t r = 0; r < rows; r++){
        int somma = 0;
        for (size_t c = 0; c < rags[r]; c++){
            somma += mat[r][c];
        }

        if(tutte)
            tutte = (somma%k==0);
        
        if((somma%k==0) && somma > max && somma != 0)
            max = somma;
    }
    
    *pMaxSum = max;

    return tutte;
}

int main(){
    const size_t rows=1, cols=1;
    int mat[1][1] = {
    {}};
    size_t rags[1] = { 0};
    int maxSum;
    bool ret = e1(rows, cols, mat, rags, 4, &maxSum);
    if (ret) { printf("T %d\n", maxSum); } else { printf("F %d\n", maxSum); }

    return 0;
}