#include <stdio.h>
#include <stdbool.h>

int e2R(const size_t left, const size_t right, const int a[], const int val)
{
    if(left>=right){
        return 0;   //Fuori intervallo
    } else if(right-left == 1){
        //Opero sull'unico valore presente
        if(a[left]>=(-val) && a[left]<=val)
            return a[left];
        return 0;
    } else {
        size_t mid = left+((right-left)/2);

        return e2R(left, mid, a, val) + e2R(mid, right, a, val);
    }
}

int e2(const size_t aLen, const int a[], const int val) {
    return e2R(0, aLen, a, val);
}

int main(){
    const size_t aLen = 3;
    const int a[3] = {-1,7,-20};
    printf("%d\n", e2(aLen, a, 10));

    return 0;
}