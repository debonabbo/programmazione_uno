#include <stdio.h>

#define DIMENSIONE 27

int main(){
    char alfabeto[DIMENSIONE];

    for (size_t i = 0; i < DIMENSIONE-1; i++)
    {
        alfabeto[i] = i + 48;
    }
    
    alfabeto[DIMENSIONE-1] = 0;

    printf("%27s", alfabeto);
}