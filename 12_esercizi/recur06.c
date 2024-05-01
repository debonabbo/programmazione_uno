#include <stdio.h>
#include <stdbool.h>

void e2R(size_t *p_aVal, int a[], const int min, const int max, const size_t i,
            size_t m)
{
    if(i>=(*p_aVal)){
        *p_aVal = m;
    } else {
        if(a[i]>=min && a[i]<=max)
            a[m++] = a[i];
        e2R(p_aVal, a, min, max, i+1, m);
    }
}

void e2(size_t *p_aVal, int a[], const int min, const int max){
    e2R(p_aVal, a, min, max, 0, 0);
}







//TEST
void int_array_print(const size_t len, const int a[]){
    for (size_t i = 0; i < len; i++){
        printf("%d, ", a[i]);
    }
    printf("\n");
}

int main(){
    size_t aLen = 4;
    int a[4] = {1,2,3,4};
    e2(&aLen, a, 2, 3);
    int_array_print(aLen, a);
    return 0;
}