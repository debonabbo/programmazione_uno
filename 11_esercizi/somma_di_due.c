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


//VERSIONE RICORSIVA 1
bool
trova_coppia(const int a[], const int somma_target,
             const size_t left, const size_t right,
             size_t *pIndice1, size_t *pIndice2)
{
    // SUGGERIMENTO: 
    // assumere che il primo termine della coppia sia a[left],
    // ed usare ricerca_binaria() per trovare il secondo termine (se esiste)
    if(left >= right){
        return false; //Fine - fuori lunghezza massima
    } else {
        size_t iB = right;

        if(ricerca_binaria(a, somma_target-a[left], &iB, left, right)){
            *pIndice1 = left;
            *pIndice2 = iB;
            return true;    //Trovato
        }

        //Procedo con la ricerca
        return trova_coppia(a, somma_target, left+1, right, pIndice1, pIndice2);
    }
}

//VERSIONE RICORSIVA 2
// bool
// trova_coppia(const int a[], const int somma_target,
//              const size_t left, const size_t right,
//              size_t *pIndice1, size_t *pIndice2)
// {
//     // SUGGERIMENTO: 
//     // assumere che il primo termine della coppia sia a[left],
//     // ed usare ricerca_binaria() per trovare il secondo termine (se esiste)
//     if(left >= right){
//         return false; //Fine - fuori lunghezza massima
//     } else {
//         size_t iB = right;

//         if(ricerca_binaria(a, somma_target-a[left], &iB, left, right)){
//             *pIndice1 = left;
//             *pIndice2 = iB;
//             return true;    //Trovato
//         }

//         //Procedo con la ricerca
//         return trova_coppia(a, somma_target, left+1, right, pIndice1, pIndice2);
//     }
// }

//VERSIONE ITERATIVA
// bool
// trova_coppia(const int a[], const int somma_target,
//              const size_t left, const size_t right,
//              size_t *pIndice1, size_t *pIndice2)
// {
//     size_t iB = right;

//     for (size_t iA = left; iA < right; iA++)
//     {
//         if(ricerca_binaria(a, somma_target-a[iA], &iB, iA, right)){
//             *pIndice1 = iA;
//             *pIndice2 = iB;
//             return true;    //Trovato
//         }
//     }
    
//     return false;
// }

int main(){
    const int aLen = 400000; //Array da quattrocentomila elementi
    int a[aLen];

    srand(time(NULL));

    for (size_t i = 0; i < aLen; i++){
        a[i] = i;
    }

    size_t iA, iB;
    int somma_target = aLen + 3000;

    clock_t begin = clock();
    if(trova_coppia(a, somma_target, 0, aLen, &iA, &iB)){
        printf("La coppia con somma %d  esiste (%d, %d) e si trova a %zu e %zu.\n", 
                somma_target, a[iA], a[iB], iA, iB);
    } else {
        printf("Non esiste alcuna coppia con somma %d.\n", somma_target);
    }
    clock_t end = clock();
    double time_spent = (float)(end - begin) / CLOCKS_PER_SEC;
    printf("Ho impiegato %f secondi.", time_spent);

    return 0;
}