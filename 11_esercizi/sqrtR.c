#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
// Su Linux potrebbe essere necessario compilare come:
//  gcc -Wall sqrtR.c -o sqrtR -lm
//   -lm significa: aggiungi le funzioni matematiche di math.h

//------------------------------------------------------------------
// Prototipi delle funzioni
//------------------------------------------------------------------

// calcola la radice quadrata di n tramite approssimazioni dicotomiche
// di un intervallo. L'algoritmo si ferma quando l'intervallo di 
// approssimazione ha ampiezza inferiore ad epsilon.
double radice_quadrata(const double n, const double epsilon);

//------------------------------------------------------------------

int main(void) {
	#define NUM 14
	const double a[NUM] = { 0, 0.32, 0.5, 1, 2, 3, 4, 5, 10, 16, 21, 55, 98, 125 };

	#define EPSILON  0.00001

	puts("\nRadice quadrata dicotomica");
	for (size_t i=0; i<NUM; i++) {
		double sq = sqrt(a[i]);
		double sqR = radice_quadrata(a[i], EPSILON);

		double diff = fabs(sq - sqR);
		printf("[%s]  n=%6.2lf sqrt=%7.4lf  radice_quadrata=%7.4lf\n",
			   diff < EPSILON ? "ok" : "NO", a[i], sq, sqR);
	}
	puts("");
}

//------------------------------------------------------------------

// Cerca la radice di n per aprossimazioni dicotomiche successive
// dell'intervallo [left, right). La ricerca procede finchè la 
// dimensione dell'intervallo (right-left) è maggiore di epsilon.
// Ad ogni passo induttivo, calcolare il valore medio mid, verificare
// se mid*mid é maggiore o minore di n, e continuare la ricorsione
// sull'intervallo che contiene sqrt(n).
double radice_quadrata_dicR(const double n, const double epsilon,
						    const double left, const double right)
{
	// printf("   radice_quadrata_dicR(n=%lf, left=%lf, right=%lf)\n", n, left, right);
	
	// COMPLETARE
	if(left >= right){
		return 0.0;
	} else {
		double mid = (double)(left+((right-left)/2));

		if (right-left < epsilon)	//Precisione di epsilon
			return mid;
		
		if(mid*mid > n)
			return radice_quadrata_dicR(n, epsilon, left, mid);
		
		return radice_quadrata_dicR(n, epsilon, mid, right);
	}
}

//------------------------------------------------------------------

// involucro per radice_quadrata_dicR
double radice_quadrata(const double n, const double epsilon) {
	assert(n >= 0);

	// Stima l'intervallo iniziale dove si trova sqrt(n)
	if (n >= 1)
		return radice_quadrata_dicR(n, epsilon, 0, n);
	else
		return radice_quadrata_dicR(n, epsilon, n, 1);
}

//------------------------------------------------------------------
