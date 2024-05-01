#include <stdbool.h>
#include <stdio.h>

int main(){
    bool vero = true;
    bool falso = false;

    int dividendo, divisore;

    if(vero)
        printf("vero e' vera\n");
    if(!falso)
        printf("falso e' falsa\n");

    printf("Inserisci il dividendo e il divisore: ");
    scanf("%d %d", &dividendo, &divisore);

    if(!divisore)
        printf("Divisione per zero\n");
    else
        printf("Il risultato e' %d\n", dividendo/divisore);

    if(divisore%2)
        printf("Il divisore e' dispari\n");
    else
        printf("Il divisore e' pari\n");
    

    return 0;
}