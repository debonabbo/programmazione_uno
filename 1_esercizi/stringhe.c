#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // int lunghezza = 5;
    // char* stringa = malloc(lunghezza*sizeof(char));

    // *stringa = 'c';
    // *(stringa+1) = 'i';
    // *(stringa+2) = 'a';
    // *(stringa+3) = 'o';
    // *(stringa+4) = '\0';

    // for(int i = 0; i < lunghezza; i++){
    //     printf("%c", *(stringa + i));
    // }

    int max_lunghezza = 16;
    char* parola;
    parola = (char*)malloc(max_lunghezza*sizeof(char));

    printf("Ciao, inserisci una parola e la ripetero': ");
    scanf("%s", parola);    //parola e' gia' un puntatore

    printf("%s\n\n", parola);
    for(int x = 0; x < 1; x++){
        for(int i = 0; i < strlen(parola)+10000; i++){
            printf("%c", *(parola + i));
        }
        printf("\n");
    }

    // printf("%d: %s", stringa, *stringa);

    return 0;
}