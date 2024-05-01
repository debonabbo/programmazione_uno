#include <stdio.h>

int main(){
    int ora;

    printf("Inserisci l'orario: ");
    scanf("%d", &ora);

    if(ora > 23 || ora < 4)
        printf("Buonanotte.");
    else if(ora < 12)
        printf("Buongiorno!");
    else if(ora < 17)
        printf("Buon pomeriggio.");
    else    
        printf("Buonasera!");

    return 0;
}