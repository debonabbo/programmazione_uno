#include <stdio.h>

void swap_mia(int *v1, int *v2){
    int app = *v1;
    *v1 = *v2;
    *v2 = app;
    return;
}

int main(){
    int v1 = 1, v2 = 2, v3 = 3, v4 = 4;

    swap_mia(&v1, &v2);
    swap_mia(&v2, &v3);
    swap_mia(&v3, &v4);

    printf("v1: %d, v2: %d, v3: %d, v4: %d", v1, v2, v3, v4);

    return 0;
}