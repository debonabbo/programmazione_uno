#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

bool 
ricerca_binaria(const int a[], const int val, size_t *pIndice,
                const size_t left, const size_t right) 
{
    if(left >= right){
        return false;   //Il ramo e' finito
    } else if(right-left == 1){
        if(a[left] == val){  //Il ramo e' finito, opero sull'unico valore che ho
            *pIndice = left;
            return true;
        }
        return false;
    } else {
        int mid = left+((right-left)/2);    //Calcolo il pivot

        //Continuo la ricerca nella diramazione migliore
        if(val < a[mid])
            return ricerca_binaria(a, val, pIndice, left, mid);
        else
            return ricerca_binaria(a, val, pIndice, mid, right);
    }
}

int main(){
    size_t i;
    const int aLen = 400000; //Array da quattrocentomila elementi
    int a[aLen];

    srand(time(NULL));

    for (size_t it = 0; it < aLen; it++){
        a[it] = it;
    }

    int val = aLen+1;
    a[aLen-1] = val;  //Lo metto in ultima posizione

    clock_t begin = clock();

    if(ricerca_binaria(a, val, &i, 0, aLen)){
        printf("%d esiste e si trova a %zu.\n", val, i);
    } else {
        printf("%d non esiste.\n", val);
    }
    
    clock_t end = clock();
    double time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
    printf("Ho impiegato %f secondi.", time_spent);

    return 0;
}