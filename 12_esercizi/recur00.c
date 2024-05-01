#include <stdio.h>
#include <stdbool.h>

void e2R(const size_t aLen, const int a[], size_t *p_postiLiberiB, int b[], 
            const int val, const size_t i)
{
    if(i>=aLen || (*p_postiLiberiB)<=0){
        return;   //Fine - fuori lunghezza massima
    } else {
        if(a[i]>val){
            *(b++) = a[i]-val;          //Copio il valore in b
            (*p_postiLiberiB)--;    //Tolgo un posto libero in b
        }
        return e2R(aLen, a, p_postiLiberiB, b, val, i+1);
    }
}

void e2(const size_t aLen, const int a[], size_t* p_bLen, int b[], 
		const int val)
{
    size_t postiLiberiB = *p_bLen;
    e2R(aLen, a, &postiLiberiB, b, val, 0);
    (*p_bLen) -= postiLiberiB;
}

void int_array_print(const size_t len, const int a[]){
    for (size_t i = 0; i < len; i++){
        printf("%d, ", a[i]);
    }
}

int main(){
    const size_t aLen = 6; size_t bLen = 3;
    const int a[6] = {4,25,5,26,27,28};
    int b[4] = {};
    e2(aLen, a, &bLen, b, 5);
    int_array_print(bLen, b);

    return 0;
}