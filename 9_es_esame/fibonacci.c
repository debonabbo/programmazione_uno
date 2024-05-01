#include <stdio.h>

//Fibonacci ricorsivo

size_t fibonacci(size_t n){
    size_t res = 0;

    if(n == 0 || n == 1){
        res = n;
    } else {
        res = fibonacci(n-1) + fibonacci(n-2);
    }

    return res;
}

int main(){
    size_t numero = 1;

    do{
        printf("Inserisci un numero: ");
        scanf("%zu", &numero);
        printf("Fibonacci di %zu: %zu\n", numero, fibonacci(numero));
    } while(numero != 0);

    return 0;
}