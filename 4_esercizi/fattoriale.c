#include <stdio.h>

int main(){
    int n, f = 1;
    printf("Inserisci un numero: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        f *= i;
    }

    printf("Il fattoriale di %d e' %d.", n, f);

    return 0;
}