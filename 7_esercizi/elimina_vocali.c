#include <stdio.h>
#include <stdbool.h>

#define MAX 50

// ritorna true se il carattere ch è una vocale
bool is_vowel(char ch) {
#   define NUM_VOWELS 10
    const char vowels[NUM_VOWELS] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    bool is_v = false;
    for (size_t i=0; i<NUM_VOWELS && !is_v; i++) {
        if (ch == vowels[i])
            is_v = true;
    }
    return is_v;
}

void elimina_vocali(char *str){
    size_t v = 0;

    for (size_t i = 0; str[i] != '\0'; i++){
        if(!is_vowel(str[i]))
            str[v++] = str[i];
    }
    
    str[v] = '\0';
}

int main(void) {
    char stringa[MAX+1] = {0};
    scanf("%50s", stringa);
    elimina_vocali(stringa);
    printf("%s", stringa);
}
