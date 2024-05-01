#include <stdio.h>
#include <stdbool.h>

#define NMAX 50

bool calcola_match(int *subseq, size_t lenSub, int *seq, size_t lenSeq, 
                    size_t *left, size_t *right, size_t maxError, size_t *errori);

int main(){
    int subseq[NMAX] = {0}, seq[NMAX] = {0};
    size_t lenSub = 0, lenSeq = 0, maxError = 0;

    scanf("%zu", &lenSub);
    for(int i = 0; i < lenSub; i++){
        scanf("%d", &subseq[i]);
    }
    scanf("%zu", &maxError);

    do{
        scanf("%zu", &lenSeq);
        for(int i = 0; i < lenSeq; i++){
            scanf("%d", &seq[i]);
        }
        if(lenSeq != 0){
            size_t left = 0, right = 0, errori = 0;
            if(calcola_match(subseq, lenSub, seq, lenSeq, &left, &right, maxError, &errori))
                printf("[%zu, %zu) errori=%zu\n", left, right, errori);
            else
                printf("NO\n");
        }
    } while (lenSeq != 0);

    return 0;
}

bool calcola_match(int *subseq, size_t lenSub, int *seq, size_t lenSeq, 
                    size_t *left, size_t *right, size_t maxError, size_t *errori)
{
    *errori = lenSeq;
    int *pSeq = seq, *pSub = subseq;

    // while(pSeq <= (seq + lenSeq - lenSub)){      //Trova il miglior match
    while(pSeq <= (seq + lenSeq - lenSub) && (*errori > maxError)){  //Trova il primo match
        int parzErrori = 0;
        int i = 0;
        while(pSub < (subseq + lenSub)){
            if(*(pSeq + i++) != *pSub++)
                parzErrori++;
        }
        if(parzErrori < *errori){
            *errori = parzErrori;
            *left = (size_t)(pSeq - seq);
            *right = (size_t)(pSeq - seq + i);
        }
        pSeq++;
        pSub = subseq;
    }

    return (*errori <= maxError);
}