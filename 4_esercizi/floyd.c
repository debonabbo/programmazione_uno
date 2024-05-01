#include <stdio.h>

int main(){
    int n, x = 1;
    
    printf("Inserisci un numero: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        for(int c = 0; c <= i; c++){
            printf("%d ", x);
            x++;
        }

        printf("\n");
    }

    return 0;
}