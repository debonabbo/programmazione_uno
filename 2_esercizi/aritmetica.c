#include <stdio.h>
#include <limits.h>   // per INT_MAX e INT_MIN

// Esempi per sperimentare sui tipi di base del linguaggio C, 
// e sugli operatori che ne manipolano i valori.
int main(void) {
    int m1 = 3; // assegnamento
    int n1 = m1 + 1;
    double p = 2.3;
    long t = 2000000000;

    // operatori aritmetici: + - * / ecc. 
    // attenzione: / se chiamato su interi effettua la divisione intera
    printf("99 / 50 = %d\n", 99 / 50); // divisione intera
    printf("99 %% 50 = %d\n", 99 % 50); // resto della divisione intera
    printf("99 / 50.0 = %f\n", 99 / 50.0); // divisione reale
    printf("99.0 / 50 = %f\n", 99.0 / 50); // divisione reale

    puts(""); // stampa la stringa vuota, seguita dal ritorno a capo

    double d = 99;
    int m = 99;
    int n = 50;
    printf("m / n = %d\nd / n = %f\n", m / n, d / n); // divisione intera e reale
    printf("m / n, con cast su m: %f\n", (double) m / n);
    printf("m / n, con cast sul risultato: %f\n", (double) (m / n));
    puts("");

    // overflow (superamento dei limiti dei tipi interi)
    printf("INT_MIN = %d\n", INT_MIN);

    int max = INT_MAX;
    printf("INT_MAX = %d\n", max);
    max = max + 3;
    printf("dopo aver sommato 3 = %d\n", max);

    printf("L'indirizzo di memoria della variabile max e' %p\n", &max);    
}
