#include <stdio.h>

int main(){
    int a = 3;
    int* pA = &a;
    printf("Suca all'indirizzo %p ovvero %p vale %d\n\n", &a, pA, *pA);

    int** b = &pA;
    printf("Minchio all'indirizzo %p punta a %p che vale %d", &b, *b, **b);
    return 0;
}