#include <stdio.h>

int main(){
    int a, b;
    
    printf("Inserisci il primo numero: ");
    scanf("%d", &a);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &b);

    int somma = a + b;

    printf("La somma vale %d\n", somma);

    printf("Il prodotto di a e b vale %d\n", a * b);
    printf("La divisione intera di a / b vale %d\n", a / b);
    printf("La divisione reale di a / b vale %f\n", (float)a / b);
    printf("Il resto della divisione intera tra a e b vale %d\n", a % b);

    return 0;
}