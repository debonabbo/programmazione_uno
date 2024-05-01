#include <stdio.h>
#include <stdbool.h>

//------------------------------------------------------------------
// Prototipi delle funzioni (solo gli involucri)
//------------------------------------------------------------------

void leggi_array(const size_t aLen, int a[]);
int somma_array(const size_t aLen, int a[]);
bool esiste_val_in_array(const size_t aLen, const int a[], int val);
bool sottoinsieme(const size_t aLen, const int a[], 
			      const size_t bLen, const int b[]);

//------------------------------------------------------------------

int main(void) {
	size_t aLen, bLen;

	scanf("%zu", &aLen);
	int a[aLen];
	leggi_array(aLen, a);

	scanf("%zu", &bLen);
	int b[bLen];
	leggi_array(bLen, b);

	printf("%d %d\n", somma_array(aLen, a), somma_array(bLen, b));

	printf("%d %d\n", 
		   sottoinsieme(aLen, a, bLen, b),
		   sottoinsieme(bLen, b, aLen, a));
}

//------------------------------------------------------------------

void leggi_arrayR(const size_t aLen, int a[], const size_t i) {
    if(i >= aLen){
        //Fine
    } else {
        scanf("%d", &a[i]);
        leggi_arrayR(aLen, a, i+1);
    }
}
void leggi_array(const size_t aLen, int a[]) { 
	leggi_arrayR(aLen, a, 0);
}

//------------------------------------------------------------------

// COMPLETARE LE FUNZIONI RIMANENTI
int somma_arrayR(const size_t aLen, int a[], const size_t i){
    int somma = 0;

    if(i >= aLen){
        //Fine
    } else {
        somma += a[i] + somma_arrayR(aLen, a, i+1);
    }

    return somma;
}
int somma_array(const size_t aLen, int a[]){
    return somma_arrayR(aLen, a, 0);
}

bool esiste_val_in_arrayR(const size_t aLen, const int a[], const int val, 
                            const size_t i)
{
    bool esiste = false;

    if(i >= aLen){
        //Fine
    } else {
        esiste = (a[i] == val);
        if(!esiste)
            esiste = esiste_val_in_arrayR(aLen, a, val, i+1);
    }

    return esiste;
}

bool esiste_val_in_array(const size_t aLen, const int a[], int val){
    return esiste_val_in_arrayR(aLen, a, val, 0);
}

bool sottoinsiemeR(const size_t aLen, const int a[], const size_t bLen,
                    const int b[], const size_t i)
{
    bool issottoinsieme = true;

    if(i >= aLen){
        //Fine
    } else {
        issottoinsieme = esiste_val_in_array(bLen, b, a[i]);
        if(issottoinsieme)
            issottoinsieme = sottoinsiemeR(aLen, a, bLen, b, i+1);
    }

    return issottoinsieme;
}

bool sottoinsieme(const size_t aLen, const int a[], 
			      const size_t bLen, const int b[])
{
    return sottoinsiemeR(aLen, a, bLen, b, 0);
}