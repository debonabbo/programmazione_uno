#include <stdio.h>

int main(){
    int numero;
    printf("Scrivi un numero intero che vuoi tu:\n");

    //leggi il numero inserito
    scanf("%d", &numero);

    //mostra il numero a video
    printf("Hai scritto: %d\n", numero);
    printf("L'indirizzo di memoria della variabile e' %p\n",  &numero);
    return 0;
}