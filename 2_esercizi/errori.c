#include <stdio.h>

int main(void) {
	float f1, f2;
	printf("Inserisci due numeri reali: ");
	scanf("%f %d", &f1, &f2);

	float risultato = ((f1 + f2) / 2);
	printf("Risultato = %f %d\n", &risultato);

	// Calcoliamo il quadrato
	float quadrato = risultato * risultato;
	printf("Il quadrato e' \n", quadrato);
}

