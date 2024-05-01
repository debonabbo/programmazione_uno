#include <stdio.h>

int main(void) {
    // COMPLETA IL CODICE
    int m, n;
    //printf("Inserisci i numeri n e m: ");
    scanf("%d %d", &n, &m);
    
    if(n%2 == 0){
        if(n>m)
            printf("C1");
        else
            printf("C2");
    } else {
        if(m%2 == 1)
            printf("C3");
        else if((n*2)<m)
            printf("C4");
        else
            printf("ALTRO");
    }
}