#include <stdio.h>
#include <stdbool.h>

int e2R(const size_t aLen, const int a[], const size_t bLen, const int b[], 
        const size_t i) 
{
    if(i>=aLen && i>= bLen){
        return 0;   //Entrambi gli array sono finiti
    } else {
        int prodotto;

        if(i>=aLen){
            prodotto = b[i]*b[i];   //L'array b e' ancora valido
        } else if(i>=bLen){
            prodotto = a[i]*a[i];   //L'array a e' ancora valido
        } else {
            prodotto = a[i]*b[i];   //Entrambi gli array sono validi
        }

        return prodotto + e2R(aLen, a, bLen, b, i+1);
    }
}

int e2(const size_t aLen, const int a[], const size_t bLen, const int b[]) {
    return e2R(aLen, a, bLen, b, 0);
}

int main(){
    const size_t aLen = 2, bLen = 1;
    const int a[2] = {10,3};
    const int b[1] = {4};
    printf("%d\n", e2(aLen, a, bLen, b));
}