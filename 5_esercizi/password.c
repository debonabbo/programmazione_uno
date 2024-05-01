#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_STRINGA 20

int main(){
    char password[MAX_STRINGA+1] = {0};
    bool P1 = false, P2 = true, P3 = false, P4 = false, P5 = false;

    scanf("%21s", password);

    for(size_t i = 0; i < MAX_STRINGA && !P1 && password[i] != '\0'; i++){
        P1 = isdigit(password[i]);
    }

    for(size_t i = 0; i < MAX_STRINGA && P2 && password[i] != '\0'; i++){
        P2 = isalpha(password[i]);
    }

    int lettereMaiuscole = 0;
    for(size_t i = 0; i < MAX_STRINGA && (lettereMaiuscole < 2) 
        && password[i] != '\0'; i++){
        if(isupper(password[i]))
            lettereMaiuscole++;
    }
    P3 = (lettereMaiuscole >= 2);

    for (size_t i = 0; i < MAX_STRINGA && !P4 && password[i] != '\0'; i++)
    {
        if(i < MAX_STRINGA-1)
            P4 = isdigit(password[i]) && isdigit(password[i+1]);
    }

    size_t dimensioniStringa = 0;
    while(dimensioniStringa < MAX_STRINGA+1 && password[dimensioniStringa] != '\0'){
        dimensioniStringa++;
    }
    P5 = (ispunct(password[dimensioniStringa-2]) && 
            ispunct(password[dimensioniStringa-1]));

    printf("%s %d %d %d %d %d", password, P1, P2, P3, P4, P5);

    return 0;
}