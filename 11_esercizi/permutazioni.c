#include <stdio.h>

//------------------------------------------------------------------

// scambia i due caratteri, passati per puntatore 
// (passaggio per riferimento)
void swap_char(char* p1, char* p2) {
    char c = *p1;
    *p1 = *p2;
    *p2 = c;
}

//------------------------------------------------------------------

// a[] = array di lunghezza right con gli elementi da permutare
// [left, right) = intervallo che deve ancora essere permutato
void permutazioniR(char a[], const size_t left, const size_t right) 
{
    // caso base: non ci sono piu' caratteri da scambiare
    // stampiamo l'array dei caratteri (dall'inizio)
    if (left == right) {
        for (size_t i=0; i<right; i++)
            printf("%c", a[i]);
        puts("");
        return;
    }

    for (size_t i=left; i<right; i++) {
        // scambia l'elemento i-esimo con quello in posizione left
        swap_char(&a[i], &a[left]);
        // ricorsione sulla sotto-sequenza che esclude il carattere left
        permutazioniR(a, left+1, right);
        // ripristina il carattere i-esimo con quello in posizione 0
        swap_char(&a[i], &a[left]);
    }
}

// wrapper
void permutazioni(const size_t aLen, char a[]) {
    permutazioniR(a, 0, aLen);
}

//------------------------------------------------------------------

int main(void)
{
    #define N  4
    char str[4] = "ABCD";
    permutazioni(4, str);
}

//------------------------------------------------------------------

