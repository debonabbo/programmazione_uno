#include <stdio.h>

size_t ContaOccorrenze(int n, int *array, size_t dimensione);

int main(){
    int numeri[10] = {3,1,6,5,4,7,9,1,4,3};
    int n = 3;

    printf("Il numero %d compare %zu volte", n, ContaOccorrenze(n, numeri, 10));

    return 0;
}

size_t ContaOccorrenze(int n, int *array, size_t dimensione){
    size_t occorrenze = 0;

    for(size_t i = 0; i < dimensione; i++){
        if(array[i] == n)
            occorrenze++;
    }

    return occorrenze;
}