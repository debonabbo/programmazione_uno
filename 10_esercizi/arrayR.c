#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

// capovolgi gli elementi dell'array a[]
void capovolgi_array(const size_t aLen, int a[]);

// restituisce true se tutti gli elementi dell'array sono pari
bool tutti_pari(const size_t aLen, const int a[]);

// restituisce la somma di tutti gli elementi dispari dell'array
// restituisce 0 se non ci sono elementi
int somma_elem_dispari(const size_t aLen, const int a[]);

// restituisce l'indice dell'elemento più grande dell'array
// se l'array è vuoto, restituiscere -1.
size_t indice_elem_massimo(const size_t aLen, const int a[]);

// raddoppia il valore di tutti gli elementi dell'array a[]
void raddoppia_elem(const size_t aLen, int a[]);

// copia in b[] tutti gli elementi di a[] che sono uguali o maggiori di val
// fino alla capacita' massima di b[] passata per puntatore come *p_bLen.
// Al ritorno, il valore puntato da p_bLen viene aggiornato per riflettere
// la dimensione effettiva di b[] (gli elementi effettivamente copiati)
// SUGGERIMENTO: aggiungere due parametri alla funzione ricorsiva:
// - un indice di ricorsione i che scorre l'array a[]
// - un indice j che avanza ogni volta che viene copiato un elemento in b[]
void copia_maggiori_di(const size_t aLen, const int a[],
                       size_t* p_bLen, int b[], const size_t val);

// modifica in-place l'array a[] mantenendo solo gli elementi compresi
// compresi nell'intervallo chiuso [min, max]. Al ritorno, il valore puntato 
// da p_aLen viene aggiornato al numero di elementi mantenuti in a[].
void filtro_intervallo(size_t* p_aLen, int a[], 
                       const int min, const int max);

//------------------------------------------------------------------

void stampa_array(const size_t aLen, int a[]) {
    for (size_t i=0; i<aLen; i++) {
        printf("%d ", a[i]);
    }
    puts("");
}

//------------------------------------------------------------------


int main(void) {
    #define A1_LEN 9
    int a1[A1_LEN] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

    #define A2_LEN 5
    int a2[A2_LEN] = { 16, 8, 24, 22, 6 };

    #define A3_LEN 13
    int a3[A3_LEN] = { 61, 39, 10, 70, 3, 88, 35, 49, 71, 89, 90, 6, 73 };

    puts("Unit test per capovolgi_array:");
    stampa_array(A1_LEN, a1);
    capovolgi_array(A1_LEN, a1);
    stampa_array(A1_LEN, a1);

    puts("\nUnit test per tutti_pari:");
    printf("tutti_pari(a1) = %d [atteso: 0]\n", tutti_pari(A1_LEN, a1));
    printf("tutti_pari(a2) = %d [atteso: 1]\n", tutti_pari(A2_LEN, a2));

    puts("\nUnit test per somma elementi dispari:");
    printf("somma_elem_dispari(a1) = %3d [atteso:  16]\n", somma_elem_dispari(A1_LEN, a1));
    printf("somma_elem_dispari(a2) = %3d [atteso:   0]\n", somma_elem_dispari(A2_LEN, a2));
    printf("somma_elem_dispari(a3) = %3d [atteso: 420]\n", somma_elem_dispari(A3_LEN, a3));

    #define MARI_LEN  10
    const char* nomi_mari[MARI_LEN] = {
        "Oceano Atlantico", "Golfo del Messico", "Mar Mediterraneo", 
        "Oceano Artico", "Mar dei Caraibi", "Mare di Bering", 
        "Mar del Giappone", "Oceano Indiano", "Oceano Pacifico", 
        "Mar cinese meridionale", 
    };
    const int profondita_media[MARI_LEN] = { 
        3926, 1486, 1429, 1205, 2647, 
        1547, 1350, 3963, 4028, 1652, 
    };

    puts("\nUnit test per indice_elem_massimo:");
    int a_empty[] = {};
    size_t i_max = indice_elem_massimo(0, a_empty);
    printf("indice_elem_massimo(a_empty) = %3d [atteso:  -1]\n", (int)i_max);

    i_max = indice_elem_massimo(MARI_LEN, profondita_media);
    printf("Maggior profondita' media: '%s' con %d metri.\n",
           nomi_mari[i_max], profondita_media[i_max]);

    puts("\nUnit test per raddoppio elementi:");
    raddoppia_elem(A2_LEN, a2);
    stampa_array(A2_LEN, a2);
    printf("32 16 48 44 12  [atteso]\n");

    puts("\nUnit test per copia elementi:");
    #define BUF1_LEN 10
    int buf1[BUF1_LEN];
    size_t buf1_len = 2;
    copia_maggiori_di(A2_LEN, a2, &buf1_len, buf1, 20);
    stampa_array(buf1_len, buf1);
    printf("32 48    [atteso]\n");

    buf1_len = 8;
    copia_maggiori_di(A2_LEN, a2, &buf1_len, buf1, 20);
    stampa_array(buf1_len, buf1);
    printf("32 48 44 [atteso]\n");

    puts("\nUnit test per filtro intervallo:");
    size_t a3Len = A3_LEN;
    filtro_intervallo(&a3Len, a3, 10, 71);
    stampa_array(a3Len, a3);
    printf("61 39 10 70 35 49 71  [atteso]\n");
}

//------------------------------------------------------------------

// COMPLETARE

//------------------------------------------------------------------
// capovolgi gli elementi dell'array a[]
void swap_int(int *a, int *b){
    int x = *a;
    *a = *b;
    *b = x;
}

void capovolgi_arrayR(int a[], size_t *i, size_t *f){
    if((*f - *i) < 2){  //Ultimo passo
        swap_int(&a[*i], &a[*f]);
    } else {
        swap_int(&a[(*i)++], &a[(*f)--]);
        capovolgi_arrayR(a, i, f);
    }
}

void capovolgi_array(const size_t aLen, int a[]){
    if(aLen > 0){
        size_t i = 0; 
        size_t f = aLen-1;
        capovolgi_arrayR(a, &i, &f);
    }
}

bool tutti_pariR(size_t *i, const size_t aLen, const int a[]){
    bool tutti = (a[(*i)++]%2==0);

    if(tutti && *i<aLen){
        tutti = tutti_pariR(i, aLen, a);
    }

    return tutti;
}

// restituisce true se tutti gli elementi dell'array sono pari
bool tutti_pari(const size_t aLen, const int a[]){
    size_t i = 0;
    return tutti_pariR(&i, aLen, a);
}

int somma_elem_dispariR(size_t *i, const size_t aLen, const int a[]){
    int somma = 0;

    somma += (a[*i]%2==1)*a[(*i)++];   //caso base e generale

    if(*i<aLen)
        somma += somma_elem_dispariR(i, aLen, a);   //Passo induttivo

    return somma;
}

// restituisce la somma di tutti gli elementi dispari dell'array
// restituisce 0 se non ci sono elementi
int somma_elem_dispari(const size_t aLen, const int a[]){
    int somma = 0;
    size_t i = 0;

    somma = somma_elem_dispariR(&i, aLen, a);

    return somma;
}

size_t indice_elem_massimoR(size_t *i, size_t *i_max, size_t aLen, const int a[]){
    size_t ret;

    if(a[*i] > a[*i_max]){
        *i_max = *i;
    }

    if(*i == aLen-1){
        ret = *i_max;   //Caso base
    } else {
        (*i)++;
        ret = indice_elem_massimoR(i, i_max, aLen, a);
    }

    return ret;
}

// restituisce l'indice dell'elemento più grande dell'array
// se l'array è vuoto, restituiscere -1.
size_t indice_elem_massimo(const size_t aLen, const int a[]){
    size_t ret = 0, i = 0, imax = 0;

    if(aLen > 0)
        ret = indice_elem_massimoR(&i, &imax, aLen, a);

    return ret;
}

void raddoppia_elemR(size_t *i, const size_t aLen, int a[]){
    a[*i] = a[*i]*2;

    if(*i >= aLen){
        //fine
    } else {
        //continuo
        (*i)++;
        raddoppia_elemR(i, aLen, a);
    }
}

// raddoppia il valore di tutti gli elementi dell'array a[]
void raddoppia_elem(const size_t aLen, int a[]){
    size_t i = 0;
    raddoppia_elemR(&i, aLen, a);
}

void copia_maggiori_diR(size_t *ia, size_t *ib, const size_t aLen, const int a[],
                        size_t p_bLen, int b[], const size_t val)
{
    if(a[*ia] >= val)
        b[(*ib)++] = a[*ia]; 

    if(*ia >= aLen || *ib >= p_bLen){
        //fine
    } else {
        //continuo
        (*ia)++;
        copia_maggiori_diR(ia, ib, aLen, a, p_bLen, b, val);
    }
}

// copia in b[] tutti gli elementi di a[] che sono uguali o maggiori di val
// fino alla capacita' massima di b[] passata per puntatore come *p_bLen.
// Al ritorno, il valore puntato da p_bLen viene aggiornato per riflettere
// la dimensione effettiva di b[] (gli elementi effettivamente copiati)
// SUGGERIMENTO: aggiungere due parametri alla funzione ricorsiva:
// - un indice di ricorsione i che scorre l'array a[]
// - un indice j che avanza ogni volta che viene copiato un elemento in b[]
void copia_maggiori_di(const size_t aLen, const int a[],
                       size_t* p_bLen, int b[], const size_t val)
{
    size_t ia = 0, ib = 0;

    copia_maggiori_diR(&ia, &ib, aLen, a, *p_bLen, b, val);

    *p_bLen = ib;
}

void filtro_intervalloR(size_t *i, size_t *j, size_t p_aLen, int a[], 
                        const size_t min, const size_t max){
    if(a[*i] > min && a[*i] < max)
        a[(*j)++] = a[(*i)];

    (*i)++;

    if(*i >= p_aLen){
        //fine
    } else {
        //continuo
        filtro_intervalloR(i, j, p_aLen, a, min, max);
    }
}

// modifica in-place l'array a[] mantenendo solo gli elementi compresi
// compresi nell'intervallo chiuso [min, max]. Al ritorno, il valore puntato 
// da p_aLen viene aggiornato al numero di elementi mantenuti in a[].
void filtro_intervallo(size_t* p_aLen, int a[], const int min, const int max)
{
    size_t i = 0, j = 0;

    filtro_intervalloR(&i, &j, p_aLen, a, min, max);

    *p_aLen = j;
}