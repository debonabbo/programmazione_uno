#include <stdio.h>

void swap(int *a, int *b){
    int app = *b;
    *b = *a;
    *a = app;
}

int main(void) {
    // Leggi i dati dallo standard input usando scanf
    int x1, x2, x3, x4;
    scanf("%d%d%d%d", &x1, &x2, &x3, &x4);
    
    // Scambia per riordinare le variabili, in modo che
    //  x1 <= x2 <= x3 <= x4
    
    // COMPLETARE IL CODICE
    while(x1 > x2 || x2 > x3 || x3 > x4){
        if(x1 > x2)
            swap(&x1, &x2);
        if(x2 > x3)
            swap(&x2, &x3);
        if(x3 > x4)
            swap(&x3, &x4);
    }
    
    // Stampa le variabili ordinate
    printf("%d %d %d %d\n", x1, x2, x3, x4);
    
    return 0;
}