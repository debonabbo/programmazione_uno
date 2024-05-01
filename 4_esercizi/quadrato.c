#include <stdio.h>

int main(){
    int n;

    printf("Inserisci un numero: ");
    scanf("%d", &n);

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++){
            if(r == c)
                printf("\\");
            else if(r < c)
                printf(":");
            else
                printf("*");
        }

        printf("\n");
    }

    return 0;
}