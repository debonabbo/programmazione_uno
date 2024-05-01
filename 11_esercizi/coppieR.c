#include <stdio.h>
#include <stdbool.h>

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

/*
    Scrivere una funzione che prende in input due array a[] e b[] di interi,
    di lunghezza aLen e bLen rispettivamente.

    - La funzione considera ciascuna coppia di elementi di a[] e b[] nella medemisa posizione
    fino alla lunghezza minima di entrambi gli array (cioè i=0,...,min(aLen, bLen)-1);
    - Per ogni coppia (a[i], b[i]), la funzione calcola la differenza tra i due elementi, cioè a[i]-b[i];
    - La funzione restituisce un intero pari alla somma di tutte le differenze calcolate.
*/

// Usa la ricorsione controvariante (crescente):
int somma_diff_con(const size_t aLen, const int a[],
                   const size_t bLen, const int b[]);

// Usa la ricorsione controvariante (decrescente):
int somma_diff_cov(const size_t aLen, const int a[],
                   const size_t bLen, const int b[]);

// Usa la ricorsione dicotomica (dimezzamento intervalli):
int somma_diff_dic(const size_t aLen, const int a[],
                   const size_t bLen, const int b[]);

//------------------------------------------------------------------

/*
    Scrivere una funzione che prende in input due array a[] e b[] di interi,
    di lunghezza aLen e bLen rispettivamente.

    - La funzione considera ciascuna coppia di elementi di a[] e b[] nella medemisa posizione
    fino alla lunghezza massima di entrambi gli array (cioè i=0,...,max(aLen, bLen)-1);
    - Per ogni coppia (a[i], b[i]), la funzione calcola il massimo tra i due elementi, cioè max(a[i], b[i]);
    - La funzione restituisce un intero pari alla somma di tutti gli elementi massimi calcolati.
*/

// Usa la ricorsione controvariante (crescente):
int max_sum_con(const size_t aLen, const int a[],
                const size_t bLen, const int b[]);

// Usa la ricorsione controvariante (decrescente):
int max_sum_cov(const size_t aLen, const int a[],
                const size_t bLen, const int b[]);

// Usa la ricorsione dicotomica (dimezzamento intervalli):
int max_sum_dic(const size_t aLen, const int a[],
                const size_t bLen, const int b[]);

//------------------------------------------------------------------

/*
    Scrivere una funzione che prende in input due array a[] e b[] di interi,
    di lunghezza aLen e bLen rispettivamente.

    - La funzione considera ciascuna coppia di elementi di a[] e b[] nella medemisa posizione
    fino alla lunghezza massima di entrambi gli array (cioè i=0,...,max(aLen, bLen)-1);
    - Per ogni coppia (a[i], b[i]), la funzione restituisce true se almeno uno dei due elementi è pari,
    false altrimenti;
    - La funzione restituisce true se tutte le coppie (a[i], b[i]) soddisfano la condizione,
    false altrimenti.
*/

// Usa la ricorsione controvariante (crescente):
bool almeno_uno_pari_con(const size_t aLen, const int a[],
                         const size_t bLen, const int b[]);

// Usa la ricorsione controvariante (decrescente):
bool almeno_uno_pari_cov(const size_t aLen, const int a[],
                         const size_t bLen, const int b[]);

// Usa la ricorsione dicotomica (dimezzamento intervalli):
bool almeno_uno_pari_dic(const size_t aLen, const int a[],
                         const size_t bLen, const int b[]);

//------------------------------------------------------------------
// Unit testing
//------------------------------------------------------------------

int main(void){
    // matrice irregolare per il test
    #define ROWS 8
    #define COLS 15
    int mat1[ROWS][COLS] = {
        {16,20,30},
        {18,3,30,22,18,71,82,6,98,57,35,35,84,19,5},
        {79,41,99,12,66},
        {63,56,79,48,28,62,15,78},
        {},
        {30,66,14,88,30,23,29,50},
        {50,45,72,55,10,9,71,59,95,85,16,42,37,32,70},
        {31,10,60,57,86,30,72,76,84}
    };
    size_t rags1[ROWS] = {3,15,5,8,0,8,15,9};

    int mat2[ROWS][COLS] = {
        {95,45,99,92},
        {56,3,19,78,45,28,54,44,35,39,7,31,23},
        {86,52,18,66},
        {35,22,35,69,13,24,50,94,2,57,83},
        {52,33,59,14,99,26,28,22,75,11,78,85,89,14,41},
        {72,58,30,94,66,42,2,78,40,36,48,32,72,96,90},
        {60,26,30,57,73,32,30,14,16,8,3,37,53,89},
        {68,82,8,30,62,23,90,60,32,66,16,88}
    };
    size_t rags2[ROWS] = {4,13,4,11,15,15,14,12};

    // Unit test per Somma differenze
    puts("Somma differenze:     controvariante  covariante  dicotomico");
    const int somma_diffs[ROWS] = {-173, 97, 9, 87, 0, -112, 150, 51};
    for (size_t r=0; r<ROWS; r++) {
        int diff1 = somma_diff_con(rags1[r], mat1[r], rags2[r], mat2[r]);
        int diff2 = somma_diff_cov(rags1[r], mat1[r], rags2[r], mat2[r]);
        int diff3 = somma_diff_dic(rags1[r], mat1[r], rags2[r], mat2[r]);
        printf("[%s] Array %zu: minimo  %-16d%-12d%-7d\n",
               (diff1==somma_diffs[r] && diff2==diff1 && diff3==diff1 ? "ok" : "NO"), r, diff1, diff2, diff3);
    }
    puts("");

    // Unit test per Somma massimi
    puts("Somma massimi:           controvariante  covariante  dicotomico");
    const int somma_massimi[ROWS] = {331, 742, 369, 643, 726, 891, 919, 803};
    for (size_t r=0; r<ROWS; r++){
        int max1 = max_sum_con(rags1[r], mat1[r], rags2[r], mat2[r]);
        int max2 = max_sum_cov(rags1[r], mat1[r], rags2[r], mat2[r]);
        int max3 = max_sum_dic(rags1[r], mat1[r], rags2[r], mat2[r]);
        printf("[%s] Array %zu: somma max  %-16d%-12d%-15d\n",
               (max1==somma_massimi[r] && max2==max1 && max3==max1 ? "ok" : "NO"), r, max1, max2, max3);
    }
    puts("");

    // Unit test per Almeno uno pari
    puts("Almeno uno pari:               controvariante  covariante  dicotomico");
    const bool pari[ROWS] = {true, false, true, false, false, true, false, true};
    for (size_t r=0; r<ROWS; r++){
        bool pari1 = almeno_uno_pari_con(rags1[r], mat1[r], rags2[r], mat2[r]);
        bool pari2 = almeno_uno_pari_cov(rags1[r], mat1[r], rags2[r], mat2[r]);
        bool pari3 = almeno_uno_pari_dic(rags1[r], mat1[r], rags2[r], mat2[r]);
        printf("[%s] Array %zu: almeno uno pari  %-16s%-12s%-12s\n",
               (pari1==pari[r] && pari2==pari[r] && pari3==pari[r] ? "ok" : "NO"), 
               r, (pari1 ? "true" : "false"), (pari2 ? "true" : "false"), (pari3 ? "true" : "false")
            );
    }
    
}

//------------------------------------------------------------------
// Funzioni ausiliarie
//------------------------------------------------------------------

int min(int a, int b) {
    return (a<b) ? a : b;
}

int max(int a, int b) {
    return (a>b) ? a : b;
}

//------------------------------------------------------------------
// Funzioni ricorsive (non involucro)
//------------------------------------------------------------------
int somma_diff_conR(const int a[], const int b[], 
                    const size_t left, const size_t right)
{
    if(left >= right){
        return 0;   //Fine - fuori lunghezza massima
    } else {
        int diff = a[left]-b[left];

        return diff + somma_diff_conR(a, b, left+1, right);
    }
}
int somma_diff_covR(const int a[], const int b[], 
                    const size_t left, const size_t right)
{
    if(right <= left){
        return 0;   //Fine - fuori intervallo
    } else {
        int diff = a[right-1]-b[right-1];

        return diff + somma_diff_covR(a, b, left, right-1);
    }
}
int somma_diff_dicR(const int a[], const int b[], 
                    const size_t left, const size_t right)
{
    if(left>=right){
        return 0;   //Fine del ramo
    } else if (right-left == 1){
        return a[left] - b[left];   //Fine - Opero sull'unica coppia che ho
    } else {
        size_t mid = left + ((right-left)/2);   //Calcolo il pivot

        //Procedo lungo le due diramazioni
        return somma_diff_dicR(a, b, left, mid)+somma_diff_dicR(a, b, mid, right);
    }
}

int max_sum_conR(const size_t aLen, const int a[], 
                 const size_t bLen, const int b[], 
                 const size_t i)
{
    if(i>=aLen && i>=bLen){
        return 0;   //Fine - fuori lunghezza massima
    } else {
        int nmax = 0;

        if(i>=aLen){
            nmax = b[i];    //L'array b e' ancora valido
        } else if (i>=bLen){
            nmax = a[i];    //L'array a e' ancora valido
        } else {
            nmax = max(a[i], b[i]);
        }

        return nmax + max_sum_conR(aLen, a, bLen, b, i+1);
    }
}
int max_sum_covR(const size_t aLen, const int a[], 
                 const size_t bLen, const int b[], 
                 const size_t i)
{
    if(i<=0){
        return 0; //Fine degli array
    } else {
        int nmax = 0;

        if(i>aLen){
            nmax = b[i-1]; //L'array b e' valido, e' il maggiore per via del wrapper
        } else if(i>bLen){
            nmax = a[i-1]; //L'array a e' valido, e' il maggiore per via del wrapper
        } else {
            nmax = max(a[i-1], b[i-1]);
        }

        return nmax + max_sum_covR(aLen, a, bLen, b, i-1);
    } 
}
int max_sum_dicR(const size_t aLen, const int a[], 
                 const size_t bLen, const int b[], 
                 const size_t left, const size_t right)
{
    if(left >= right){
        return 0;   //Fine del ramo
    } else if(right-left == 1){
        //Fine - Opero sull'unica coppia che ho
        if(left >= aLen)
            return b[left]; //L'array b e' valido grazie al wrapper
        if(left >= bLen)
            return a[left]; //L'array a e' valido grazie al wrapper
        return max(a[left], b[left]);   //Entrambi gli array sono validi
    } else {
        size_t mid = left + ((right-left)/2);   //Calcolo il pivot

        //Procedo lungo le due diramazioni
        return  max_sum_dicR(aLen, a, bLen, b, left, mid) + 
                max_sum_dicR(aLen, a, bLen, b, mid, right);
    }
}

bool almeno_uno_pari_conR(const size_t aLen, const int a[], 
                          const size_t bLen, const int b[], 
                          const size_t i)
{
    if(i >= aLen && i >= bLen){
        return true;    //Fine - fuori lunghezza massima
    } else {
        bool coppia_pari = false;

        if(i >= aLen){
            coppia_pari = (b[i]%2 == 0);  //b e' ancora valido
        } else if(i >= bLen){
            coppia_pari = (a[i]%2 == 0);  //a e' ancora valido
        } else {
            coppia_pari = ((a[i]%2 == 0) || (b[i]%2 == 0));
        }

        if(coppia_pari) //Procedo lungo l'array
            return almeno_uno_pari_conR(aLen, a, bLen, b, i+1);
        
        return false;
    }
}
bool almeno_uno_pari_covR(const size_t aLen, const int a[], 
                          const size_t bLen, const int b[], 
                          const size_t i)
{
    if(i<=0){
        return true; //Fine - entrambi gli array sono finiti
    } else {
        bool coppia_pari = false;

        if(i>aLen){
            coppia_pari = (b[i-1]%2 == 0);  //b e' il maggiore (vedi wrapper)
        } else if(i>bLen){
            coppia_pari = (a[i-1]%2 == 0);  //a e' il maggiore (vedi wrapper)
        } else {
            coppia_pari = ((a[i-1]%2 == 0) || (b[i-1]%2 == 0));
        }

        if(coppia_pari)
            return almeno_uno_pari_covR(aLen, a, bLen, b, i-1);
        
        return false;
    }
}
bool almeno_uno_pari_dicR(const size_t aLen, const int a[], 
                          const size_t bLen, const int b[], 
                          const size_t left, const size_t right)
{
    if(left >= right){
        return true;    //Fine - fuori intervallo
    } else if(right-left == 1){
        //Opero sull'unica coppia che ho
        if(left >= aLen){
            return (b[left]%2 == 0);    //L'array b e' valido grazie al wrapper
        } else if (left >= bLen){
            return (a[left]%2 == 0);    //L'array a e' valido grazie al wrapper
        } else {
            return ((a[left]%2 == 0) || (b[left]%2 == 0));
        }
    } else {
        size_t mid = left + ((right-left)/2);

        if(almeno_uno_pari_dicR(aLen, a, bLen, b, left, mid))
            return almeno_uno_pari_dicR(aLen, a, bLen, b, mid, right);

        return false;
    }
}

//------------------------------------------------------------------

// da completare
/*
    Scrivere una funzione che prende in input due array a[] e b[] di interi,
    di lunghezza aLen e bLen rispettivamente.

    - La funzione considera ciascuna coppia di elementi di a[] e b[] nella medemisa posizione
    fino alla lunghezza minima di entrambi gli array (cioè i=0,...,min(aLen, bLen)-1);
    - Per ogni coppia (a[i], b[i]), la funzione calcola la differenza tra i due elementi, cioè a[i]-b[i];
    - La funzione restituisce un intero pari alla somma di tutte le differenze calcolate.
*/

// Usa la ricorsione controvariante (crescente):
int somma_diff_con(const size_t aLen, const int a[],
                   const size_t bLen, const int b[])
{
    return somma_diff_conR(a, b, 0, min(aLen, bLen));
}

// Usa la ricorsione controvariante (decrescente):
int somma_diff_cov(const size_t aLen, const int a[],
                   const size_t bLen, const int b[])
{
    return somma_diff_covR(a, b, 0, min(aLen, bLen));
}

// Usa la ricorsione dicotomica (dimezzamento intervalli):
int somma_diff_dic(const size_t aLen, const int a[],
                   const size_t bLen, const int b[])
{
    return somma_diff_dicR(a, b, 0, min(aLen, bLen));
}

//------------------------------------------------------------------

/*
    Scrivere una funzione che prende in input due array a[] e b[] di interi,
    di lunghezza aLen e bLen rispettivamente.

    - La funzione considera ciascuna coppia di elementi di a[] e b[] nella medemisa posizione
    fino alla lunghezza massima di entrambi gli array (cioè i=0,...,max(aLen, bLen)-1);
    - Per ogni coppia (a[i], b[i]), la funzione calcola il massimo tra i due elementi, cioè max(a[i], b[i]);
    - La funzione restituisce un intero pari alla somma di tutti gli elementi massimi calcolati.
*/

// Usa la ricorsione controvariante (crescente):
int max_sum_con(const size_t aLen, const int a[],
                const size_t bLen, const int b[])
{
    return max_sum_conR(aLen, a, bLen, b, 0);
}

// Usa la ricorsione controvariante (decrescente):
int max_sum_cov(const size_t aLen, const int a[],
                const size_t bLen, const int b[])
{
    return max_sum_covR(aLen, a, bLen, b, max(aLen, bLen));
}

// Usa la ricorsione dicotomica (dimezzamento intervalli):
int max_sum_dic(const size_t aLen, const int a[],
                const size_t bLen, const int b[])
{
    return max_sum_dicR(aLen, a, bLen, b, 0, max(aLen, bLen));
}

//------------------------------------------------------------------

/*
    Scrivere una funzione che prende in input due array a[] e b[] di interi,
    di lunghezza aLen e bLen rispettivamente.

    - La funzione considera ciascuna coppia di elementi di a[] e b[] nella medemisa posizione
    fino alla lunghezza massima di entrambi gli array (cioè i=0,...,max(aLen, bLen)-1);
    - Per ogni coppia (a[i], b[i]), la funzione restituisce true se almeno uno dei due elementi è pari,
    false altrimenti;
    - La funzione restituisce true se tutte le coppie (a[i], b[i]) soddisfano la condizione,
    false altrimenti.
*/

// Usa la ricorsione controvariante (crescente):
bool almeno_uno_pari_con(const size_t aLen, const int a[],
                         const size_t bLen, const int b[])
{
    return almeno_uno_pari_conR(aLen, a, bLen, b, 0);
}

// Usa la ricorsione controvariante (decrescente):
bool almeno_uno_pari_cov(const size_t aLen, const int a[],
                         const size_t bLen, const int b[])
{
    return almeno_uno_pari_covR(aLen, a, bLen, b, max(aLen, bLen));
}

// Usa la ricorsione dicotomica (dimezzamento intervalli):
bool almeno_uno_pari_dic(const size_t aLen, const int a[],
                         const size_t bLen, const int b[])
{
    return almeno_uno_pari_dicR(aLen, a, bLen, b, 0, max(aLen, bLen));
}