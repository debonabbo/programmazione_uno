#include <stdio.h>
#include <limits.h> // limiti dei tipi interi
#include <float.h>  // limiti dei tipi reali

// stampa le dimensioni dei tipi di base del linguaggio C
int main(void) {
	puts("\nTipi con segno:");

	printf("sizeof(char)     =%2lu  intervallo: %hhd, %hhd\n", 
		   sizeof(char), (char)CHAR_MIN, (char)CHAR_MAX);
	printf("sizeof(short)    =%2lu  intervallo: %hd, %hd\n", 
		   sizeof(short), (short)SHRT_MIN, (short)SHRT_MAX);
	printf("sizeof(int)      =%2lu  intervallo: %d, %d\n", 
		   sizeof(int), INT_MIN, INT_MAX);
	printf("sizeof(long)     =%2lu  intervallo: %ld, %ld\n", 
		   sizeof(long), LONG_MIN, LONG_MAX);
	printf("sizeof(long long)=%2lu  intervallo: %lld, %lld\n", 
		   sizeof(long long), LLONG_MIN, LLONG_MAX);

	puts("\nTipi senza segno:");

	printf("sizeof(unsigned char)     =%2lu  intervallo: 0, %hhu\n", 
		   sizeof(unsigned char), (unsigned char)UCHAR_MAX);
	printf("sizeof(unsigned short)    =%2lu  intervallo: 0, %hu\n", 
		   sizeof(unsigned short), (unsigned short)USHRT_MAX);
	printf("sizeof(unsigned int)      =%2lu  intervallo: 0, %u\n", 
		   sizeof(unsigned int), UINT_MAX); // oppure unsigned [senza int]
	printf("sizeof(unsigned long)     =%2lu  intervallo: 0, %lu\n", 
		   sizeof(unsigned long), ULONG_MAX);
	printf("sizeof(unsigned long long)=%2lu  intervallo: 0, %llu\n", 
		   sizeof(unsigned long long), ULLONG_MAX);

	puts("\nNumeri reali (con virgola):");

	printf("sizeof(float) =%2lu  intervallo: %e, %e\n", 
		   sizeof(float), FLT_MIN, FLT_MAX);
	printf("sizeof(double)=%2lu  intervallo: %e, %e\n", 
		   sizeof(double), DBL_MIN, DBL_MAX);

	puts("\nPuntatori a tipi elementari:");
	printf("sizeof(char*)    =%2lu\n", sizeof(char*));
	printf("sizeof(short*)   =%2lu\n", sizeof(short*));
	printf("sizeof(int*)     =%2lu\n", sizeof(int*));
	printf("sizeof(unsigned*)=%2lu\n", sizeof(unsigned*));
	printf("sizeof(long*)    =%2lu\n", sizeof(long*));
	printf("sizeof(float*)   =%2lu\n", sizeof(float*));
	printf("sizeof(double*)  =%2lu\n", sizeof(double*));

	puts("\nDimensioni dei tipi in C:");

	// Un tipo senza segno molto importante e': size_t
	// l'operatore sizeof() restituisce un valore in byte con tipo size_t
	int n = 100;
	size_t size_int = sizeof(int); // possiamo usare anche sizeof(n)
	// Quanti bytes occupano n variabili di tipo int?
	size_t size_100int = n * sizeof(int);

	printf("Lo spazio occupato da %d variabili di tipo int e' di %lu bytes.\n", n, size_100int);

}