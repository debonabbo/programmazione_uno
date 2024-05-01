#include <stdio.h>
#include <stdbool.h>

int e1(const size_t rows, const size_t cols, 
	   const int mat[rows][cols], const size_t rags[rows]) 
{
    int m = 1;

    for (size_t r = 0; r < rows && (m *= (rags[r] >= rows)); r++){
        bool trovato = false;
        for (size_t c = 0; c < rags[r] && !trovato; c++){
            if((trovato = (mat[r][c]%7 == 0)))
                m += mat[r][c];
        }
    }

    return m - (1*(m>0));
}

int main(){
     	

const size_t rows=4, cols=10;
int mat[4][10] = {
  {5, 3, 0, 7, 5, 6, 8, 9, 2},
  {9, 5, 9, 6, 9, 9, 8, 7},
  {1, 9, 8, 0, 3, 2, 6, 9},
  {3, 3, 2, 2, 6, 7, 2, 8, 0, 9}};
size_t rags[4] = { 9, 8, 8, 10};
printf("%d\n", e1(rows, cols, mat, rags));

    return 0;
}