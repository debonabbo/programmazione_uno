#include <stdio.h>
#include <stdbool.h>

#define MAX 20

bool is_vowel(char c){
    bool vocale = false;
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        vocale = true;
    return vocale;
}

bool esistono_vocali(char *s){
    bool esistono = false;

    while(*s++ != '\0' && !esistono){
        esistono = is_vowel(*s);
    }

    return esistono;
}

void stampa_vocali(char *s){
    while(*s++ != '\0') {
        if(is_vowel(*s))
            printf("%c", *s);
    }
}

int main(){
    char parola[MAX] = {0};

    scanf("%s", parola);

    if(esistono_vocali(parola))
        printf("1");
    else    
        printf("0");

    printf(" ");

    stampa_vocali(parola);

    return 0;
}