#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define NUM_PERS 24
#define DIM_INDIZI 16

// I nomi dei soggetti fermati
const char* nomi[NUM_PERS] = {
    "Claire","Eric",   "Maria", "George","Bernard","Sam",    "Tom",    "Paul",
    "Joe",   "Frans",  "Anne",  "Max",   "Alex",   "Philip", "Bill",   "Anita",  
    "David", "Charles","Herman","Peter", "Susan",  "Robert", "Richard","Alfred", 
};

// Gli attributi dei soggetti fermati, codificati come stringa
const char* attributi[NUM_PERS] = {
    "drco", "bc",   "dtc", "wc",   "tcg",  "wpo",  "npzo", "wo",  
    "bo",   "r",    "dn",  "nfsg", "nfs",  "nal",  "rpal", "dblz", 
    "ba",   "bfs",  "rpg", "wszg", "dwls", "tlzg", "tpfa", "rfz", 
};

bool IsSospetto(char *indizi, const char *attributi);

int main(void) {
	char indizi[DIM_INDIZI] = {0};
    scanf("%16s", indizi);

    size_t numeroSospetti = 0;

    for (size_t i = 0; i < NUM_PERS; i++){
        if(IsSospetto(indizi, attributi[i])){
            printf("%s\n", nomi[i]);
            numeroSospetti++;
        }
    }

    printf("%zu", numeroSospetti);
}

bool IsSospetto(char *indizi, const char *attributi){
    bool sospetto = true;

    for (size_t i = 0; indizi[i] != '\0' && sospetto; i++){
        if(isalpha(indizi[i])){
            if(isupper(indizi[i])){
                //Per rimanere sospetto, non deve avere questa lettera
                //Trovo la lettera, non e' piu' sospetto
                for (size_t j = 0; attributi[j] != '\0' && sospetto; j++){
                    sospetto = !(attributi[j] == tolower(indizi[i]));
                }
            } else {
                //Per rimanere sospetto deve avere questa lettera
                //Non trovo la lettera, non e' piu' sospetto
                sospetto = false;
                for (size_t j = 0; attributi[j] != '\0' && !sospetto; j++){
                    sospetto = (attributi[j] == indizi[i]);
                }
            }
        }
    }

    return sospetto;
}