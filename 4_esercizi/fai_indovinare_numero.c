#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TENTATIVI 7

int main(void)
{
	int num_tentativi = 1, t;
	// Genera un numero pseudo-casuale tra 0 (incluso) e 100 (escluso)
	srand(time(0));
	int numero = rand() % 100;

	// VARIANTE 1:
	// Chiedi all'utente di indovinare il numero.
	// L'utente inserisce un intero t come tentativo
	// - Se t è il numero da indovinare, stampa un messaggio e termina
	// - Se t è maggiore del numero da indovinare, stampa un messaggio
	//   appropriato e procedi con un nuovo tentativo
	// - Procedi similmente se t è minore, con un diverso messaggio.

	// COMPLETA IL CODICE

	// VARIANTE 2:
	// memorizza in una variabile num_tentativi il numero
	// di tentativi che l'utente ha fatto. Quando il numero da indovinare
	// viene trovato, stampa a video il numero di tentativi effettuati.

	// VARIANTE 3:
	// Se l'utente supera MAX_TENTATIVI, termina il ciclo e stampa 
	// un messaggio di sconfitta, svelando anche il numero da indovinare.

	while(num_tentativi <= MAX_TENTATIVI){
		printf("Inserisci un numero: ");
		scanf("%d", &t);

		if(t == numero){
			printf("Hai indovinato in %d tentativi! :)\n", num_tentativi);
			return 0;
		} else if (t < numero){
			printf("Il numero da indovinare e' piu' grande!\n");
		} else {
			printf("Il numero da indovinare e' piu' piccolo!\n");
		}

		num_tentativi++;
	}

	printf("Hai esaurito i tentativi :(");

	return 0;
}
