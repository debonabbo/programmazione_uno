#include <stdio.h>

int main(void) {
	int x = 5;
	int y = 8;
	printf("x: %d, y: %d\n", x, y);

	// scambio x con y usando una variabile intermedia
	int temp = x;
	x = y;
	y = temp;

	printf("x: %d, y: %d\n", x, y);
}