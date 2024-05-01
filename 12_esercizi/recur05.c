#include <stdio.h>
#include <stdbool.h>

bool esiste_val_in_arrayR(const size_t right, const int a[], const int val){
    if(right<=0){
        return false;
    } else {
        if(a[right-1] == val)
            return true;
        return esiste_val_in_arrayR(right-1, a, val);
    }
}

size_t e2R(const size_t rows, const size_t cols, const int mat[rows][cols],
            const size_t rags[rows], const int val) 
{
    if(rows<=0){
        return 0;   //Fine
    } else {
        return esiste_val_in_arrayR(rags[rows-1], mat[rows-1], val)*rags[rows-1]
                + e2R(rows-1, cols, mat, rags, val);
    }
}

int e2(const size_t rows, const size_t cols,
       const int mat[rows][cols], const size_t rags[rows], 
       const int val)
{
    return (int)e2R(rows, cols, mat, rags, val);
}



//TEST
int main(){
    const size_t rows = 2, cols = 2;
    int mat[2][2] = {
    {0,10},
    {0}};
    size_t rags[2] = {2,1};
    int val = 10;
    printf("%d\n", e2(rows, cols, mat, rags, val));
}