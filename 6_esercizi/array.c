#include <stdio.h>
#include <stdbool.h>

#define SZ 20

size_t leggi_array(int *array, const size_t sz){
    size_t dimArray = 0;
    scanf("%zu", &dimArray);

    if(dimArray>sz)
        dimArray=sz;
    
    for(size_t i = 0; i < dimArray; i++){
        scanf("%d", (array + (i)));
    }

    return dimArray;
}

int conta_occorrenze(const int *array, const size_t sz, int n){
    int occorrenze = 0;

    for(size_t i = 0; i < sz; i++){
        if(array[i] == n)
            occorrenze++;
    }

    return occorrenze;
}

int calcola_univoci(const int *array, const size_t sz){
    int univoci = 0;

    for(size_t i = 0; i < sz; i++){
        if(conta_occorrenze(array, sz, array[i]) == 1)
            univoci++;
    }

    return univoci;
}

void stampa_elementi_ripetuti(const int *a1, const size_t sz1, const int *a2, const size_t sz2){
    for(size_t i = 0; i < sz1; i++){
        if(conta_occorrenze(a2, sz2, a1[i]) > 0)
            printf("%d ", a1[i]);
    }
}

int main(){
    int array1[SZ] = {0};
    int array2[SZ] = {0};

    const size_t sz1 = leggi_array(array1, SZ);
    const size_t sz2 = leggi_array(array2, SZ);
    printf("%d ", calcola_univoci(array1, sz1));
    printf("%d ", calcola_univoci(array2, sz2));

    printf("\n");

    stampa_elementi_ripetuti(array1, sz1, array2, sz2);

    return 0;
}