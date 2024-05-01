#include <stdio.h>

int main(){
    int n = 0, a = 0, b = 1, old_a;

    while(n < 2){
        printf("Inserisci il numero (>=2): ");
        scanf("%d", &n);
    }

    printf("%d %d ", a, b);

    for(int i = 0; i < (n-2); i++){
        old_a = a;
        a = b;
        b += old_a;
        printf("%d ", b);
    }

    return 0;
}