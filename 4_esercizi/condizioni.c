#include <stdio.h>
#include <stdbool.h>

int main(){
    int n;
    bool tutti_dispari = true;
    bool tutti_multipli_3 = true;
    bool esiste_r7 = false;
    bool esiste_100 = false;

    while (scanf("%d", &n) && n != 0){
        if(n % 2 == 0)
            tutti_dispari = false;
        if(n % 3 != 0)
            tutti_multipli_3 = false;
        if(n % 10 == 7)
            esiste_r7 = true;
        if(n == 100)
            esiste_100 = true;
    } 

    printf(((tutti_dispari) ? "TUTTI_DISPARI " : ""));
    printf(((tutti_multipli_3) ? "TUTTI_MULTIPLI_3 " : ""));
    printf(((esiste_r7) ? "ESISTE_R7 " : ""));
    printf(((esiste_100) ? "ESISTE_100 " : ""));

    return 0;
}