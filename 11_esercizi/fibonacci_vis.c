#include <stdio.h>

//------------------------------------------------------------------

// calcola l'n-esimo termine della serie di Fibonacci.
// codice come visto a lezione.
int fibonacci(int n) {
	// caso base: n<=1 -> n
	if (n<=1)
		return n;

	// passo induttivo: fib(n) = fib(n-1) + fib(n-2)
	return fibonacci(n - 1) + fibonacci(n - 2);
}

//------------------------------------------------------------------

// calcola l'n-esimo termine della serie di Fibonacci,
// visualizzando la computazione non lineare.
int fibonacci_vis(int n, size_t level) {
	// caso base: n<=1 -> n
	if (n<=1) {
		for (size_t i=0; i<level; i++)
			printf("  ");
		printf("fib(%d): caso base\n", n);

		return n;
	}
	// passo induttivo: fib(n) = fib(n-1) + fib(n-2)
	else {
		for (size_t i=0; i<level; i++)
			printf("  ");
		printf("fib(%d) = fib(%d) + fib(%d)\n", n, n-1, n-2);

		return fibonacci_vis(n-1, level+1) + fibonacci_vis(n-2, level+1);
	}
}

//------------------------------------------------------------------

int main(void) {
	int n = 6;

	// calcola l'n-esimo numero della serie di Fibonacci
	printf("FIBONACCI(%d) = %d\n\n", n, fibonacci(n));

	// calcola l'n-esimo numero della serie di Fibonacci,
	// fornendo una visualizzazione delle chiamate ricorsive effettuate.
	// NOTA: la ricorsione non è lineare, e non forma una catena lineare.
	printf("\nFIBONACCI(%d) = %d\n\n", n, fibonacci_vis(n, 0));
}

//------------------------------------------------------------------

