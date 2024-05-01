#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define WORD_MAX 50

void capovolgi(const char *src, char *dst){
    char *f = dst + strlen(src) - 1;
    for(size_t i = 0; i < strlen(src); i++, f--){
        *f = src[i];
    }
}

int main(void) {
    char parola[WORD_MAX+1] = {0};

    scanf("%s", parola);

    bool palindroma = true;
    char *fineParola = parola + strlen(parola) - 1;

    for(size_t i = 0; i < strlen(parola) && palindroma; i++, fineParola--){
        if(parola[i] != *fineParola){
            palindroma = false;
        }
    }

    if(palindroma)
        printf("PALINDROMA");
    else{
        char capovolta[WORD_MAX+1] = {0};
        capovolgi(parola, capovolta);
        printf("%s %s", parola, capovolta);
    }
}