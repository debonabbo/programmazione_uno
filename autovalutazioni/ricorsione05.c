#include <stdio.h>
#include <stdbool.h>

// ritorna true se un elemento val esiste in un dato array
bool esiste_elemento(const size_t aLen, const int a[aLen], const int i,
                    const int val)
{
    if(i>=aLen){
        return false;
    } else {
        if(a[i] == val){
            return true;
        }

        return esiste_elemento(aLen, a, i+1, val);
    }
}

// rimuove tutte le occorrenze di un elemento val in un array, 
// partendo da un indice i data in input.
size_t rimuovi_elementiR(const size_t left, const size_t right, int a[],
                        const int val, size_t im)
{
    if(left>=right || im>=right){
        return 0;
    } else {
        size_t rimossi = 0;
        if(a[left] == val)
            rimossi = 1;
        else    
            a[im++] = a[left];
        
        return rimossi+rimuovi_elementiR(left+1, right, a, val, im);
    }
}

int e2R(size_t *p_aLen, int a[], const size_t bLen, const int b[], const int i)
{
    if(i>=*p_aLen){
        return 0;
    } else {
        if(esiste_elemento(bLen, b, 0, a[i])){
            *p_aLen -= rimuovi_elementiR(i+1, *p_aLen, a, a[i], i+1);
        }

        return e2R(p_aLen, a, bLen, b, i+1);
    }
}

int e2(size_t* p_aLen, int a[], const size_t bLen, const int b[]) {
    return e2R(p_aLen, a, bLen, b, 0);
}

void int_array_print(const size_t alen, const int a[alen]){
    for (size_t i = 0; i < alen; i++)
    {
        printf("%d ", a[i]);
    }
    
}

int main(){
    size_t aLen = 10; const size_t bLen = 4;
int a[10] = {10, -10, -9, -10, -2, 5, 4, 5, -7, -3};
const int b[4] = {-10, -2, -3, 4};
e2(&aLen, a, bLen, b);
int_array_print(aLen, a);
}