#include <stdio.h>

int main(){
    int n, c = 0, somma = 0;

    do{
        printf("Inserisci un numero: ");
        scanf("%d", &n);

        if(n != 0){
            somma += n;
            c++;
        }
    } while (n != 0);

    printf("La media dei %d valori inseriti e' %d.", c, (somma/c));

    return 0;
}