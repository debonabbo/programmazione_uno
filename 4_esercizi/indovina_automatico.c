#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main(void) {
    int t = 50, delta = 50, tentativi = 20;
    srand(time(0));
	int numero = rand() % 100;
    printf("Devo indovinare il numero %d.\n", numero);

    while(tentativi > 0){
        printf("Il numero e' %d? ", t);
        delta = (int)ceil((double)delta / 2.0);
        if(numero == t){
            printf("Si, indovinato!\n");
            return 0;
        } else if(numero > t){
            printf("No, era piu' grande.\n");
            t += delta;
        } else{
            printf("No, era piu' piccolo.\n");
            t -= delta;
        }
        tentativi--;
    }
}