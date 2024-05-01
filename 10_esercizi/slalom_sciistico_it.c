#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

//NON HO USATO IL MCD :(
// #define RICORSIVA   //Attiva per usare le funzioni ricorsive al posto del for

void calcola_dmin_y(const int delta, const int d1, int *dmin, int *y){
    if(((*dmin)-delta) < d1){
        //Fine
    } else {
        (*y)++;
        (*dmin)-=delta;
        return calcola_dmin_y(delta, d1, dmin, y);
    }
}

void stampa_soluzioni(const int c, const int d, const int d2, const int delta,
                        const int y){
    if(d>=d2){
        return;//Fine
    } else {
        printf("d=%d x=%d y=%d\n", d, c-y, y);
        return stampa_soluzioni(c, d+delta, d2, delta, y-1);
    }
}

void soluzione_iterativa(const int a, const int b, const int c, const int d1,
                            const int d2, const FILE* output)
{
    int dmin = a*c;     //In realta' e' la distanza massima
    int delta = a-b;
    int y = 0;

    #ifdef RICORSIVA
        calcola_dmin_y(delta, d1, &dmin, &y);
        stampa_soluzioni(c, dmin, d2, delta, y);
    #else
        //Calcolo la distanza minima
        for (dmin; dmin > (d1+delta); dmin-=delta)
            y++;
        
        for (int d = dmin; d < d2; d+=delta){
            printf("d=%d x=%d y=%d\n", d, c-y, y);
            fprintf(output, "%d;%d;%d;%d;\n", c, d, c-y, y);
            y--;
        }
    #endif
}

int main() {
    int a, b, c, d1, d2;
    FILE *output;
    // scanf("%d%d%d%d%d", &a, &b, &c, &d1, &d2);
    a = 9;
    b = -7;
    // c = 6;
    d1 = 0;
    d2 = 15;
    #define CMAX 20
    d2 = a*CMAX;
    output = fopen("combinazioni.csv", "wt");

    fprintf(output, "Combinazioni di a=%d e b=%d tra d1=%d e d2=%d\n", a, b, 
            d1, d2);
    fprintf(output, "c;d;x;y;\n");

    for(c = 1; c<CMAX; c++){
        soluzione_iterativa(a, b, c, d1, d2, output);
    }

    fclose(output);
}