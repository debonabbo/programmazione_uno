#include <stdio.h>

int main() {
    const int forbici = 1;
    const int carta = 2;
    const int sasso = 3;
    const int lucertola = 4;
    const int spock = 5;
    
    int sheldon, leonard;

    //printf("Inserisci la scelta di Sheldon e Leonard: ");

    if(scanf("%d%d", &sheldon, &leonard) == 2 &&
        sheldon <= 5 && 
        sheldon >= 1 && 
        leonard <= 5 && 
        leonard >= 1)
    {
        if(sheldon == leonard){
            printf("Pareggio");
        } else {
            if(sheldon == forbici){
                if(leonard == carta || leonard == lucertola){
                    printf("Sheldon");
                } else {
                    printf("Leonard");
                }
            } else if(sheldon == carta){
                if(leonard == spock || leonard == sasso){
                    printf("Sheldon");
                } else {
                    printf("Leonard");
                }
            } else if(sheldon == sasso){
                if(leonard == forbici || leonard == lucertola){
                    printf("Sheldon");
                } else {
                    printf("Leonard");
                }
            } else if (sheldon == lucertola){
                if(leonard == spock || leonard == carta){
                    printf("Sheldon");
                } else {
                    printf("Leonard");
                }
            } else { //sheldon == spock
                if(leonard == forbici || leonard == sasso){
                    printf("Sheldon");
                } else {
                    printf("Leonard");
                }
            }
        }
    } else {
        printf("Non valido");
    }
    
    return 0;
}