#include <stdio.h>

int main(){
    int n, i = 0;
    printf("Inserisci un numero: ");
    scanf("%d", &n);

    while(i < n){
        printf("%d\n", i);
        i++;
    }

    printf("\n\n");

    while(i >= 0){
        printf("%d\n", i);
        i--;
    }

    return 0;
}