#include <stdio.h>

#define MAX_STRINGA 50

void CopiaArray(char *origine, char *destinazione);

int main(){

    char nomeMontagna[MAX_STRINGA + 1] = {0};
    char nomeMontagnaMax[MAX_STRINGA + 1] = {0};
    int altezzaMontagna, altezzaMontagnaMax = 0;

    while(scanf("%51s %d", nomeMontagna, &altezzaMontagna) == 2){
        if(altezzaMontagna > altezzaMontagnaMax){
            altezzaMontagnaMax = altezzaMontagna;
            CopiaArray(nomeMontagna, nomeMontagnaMax);
        }
    }

    printf("%s", nomeMontagnaMax);

    return 0;
}

void CopiaArray(char *origine, char *destinazione){
    for(int i = 0; i < (MAX_STRINGA + 1); i++){
        destinazione[i] = origine[i];
    }
}