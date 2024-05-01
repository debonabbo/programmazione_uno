#include <stdio.h>

// copia in pB (dimensione massima nmaxB) tutti gli elementi 
// dell'array pA (dimensione lenA) seguendo le regole.
// ritorna il numero di elementi copiati
size_t trasforma_array(const int* pA, const size_t lenA,
					   int *pB, const size_t nmaxB)
{
	size_t iB = 0;

    for (size_t iA = 0; iA < lenA && iB < nmaxB; iA++)
    {
        if(pA[iA]>=10 && !(pA[iA]%3==0 && pA[iA]%2==1)){
            pB[iB++] = pA[iA];
            if(pA[iA]%2==0 && iB < nmaxB){
                pB[iB++] = pA[iA];
                if(pA[iA]%4==0 && iB < nmaxB-1){
                    pB[iB++] = pA[iA];
                    pB[iB++] = pA[iA];
                }
            }
        }
    }

    return iB;
}

//------------------------------------------------------------------
// stampa gli elementi dell'array *pA (di dimensione lenA)
void stampa_array(const int* pA, const size_t lenA) 
{
	printf("len=%zu: [ ", lenA);
	for (size_t i=0; i<lenA; i++) {
		printf("%d ", pA[i]);
	}
	printf("]\n");
}

//------------------------------------------------------------------
// leggi da standard input un array, riempi il buffer pA 
// e ritorna il numero di elementi inseriti nel buffer
size_t leggi_array(int* pA, const size_t nmaxA) 
{
	size_t n, lenA=0;
	scanf("%zu", &n); // numero di elementi da leggere
	for (size_t i=0; i<n; i++) {
		int elem;
		scanf("%d", &elem);
		if (lenA < nmaxA) {
			pA[lenA] = elem;
			lenA++;
		}
	}
	return lenA;
}

//------------------------------------------------------------------
#define NMAX  10
int main(void) {
    int A[NMAX], B[NMAX]; 
    size_t nA = leggi_array(A, NMAX); 
    size_t nB = trasforma_array(A, nA, B, NMAX); 
    stampa_array(B, nB);
}

//------------------------------------------------------------------
