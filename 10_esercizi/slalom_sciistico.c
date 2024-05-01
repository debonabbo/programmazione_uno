#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

// calcola il massimo comun divisore di a e b
// assieme ai coefficienti dell'identità di Bézout x e y 
// tali che: ax+by = gcd(a,b)
int mcd_euclide_extR(int a, int b, int* pX, int* pY) {
    int mcd;

    if(b == 0){
        mcd = a;
        *pX = 1;
        *pY = 0;
    } else {
        int x, y;
        mcd = mcd_euclide_extR(b, a % b, &x, &y);
        *pX = y;
        *pY = x - (a/b)*y;
    }

    return mcd;
}

int main() {
    int a, b, c, d1, d2;
    scanf("%d%d%d%d%d", &a, &b, &c, &d1, &d2);
    
    // int x,y;
    // int delta = a-b;
    // // int offset = mcd_euclide_extR(a,b,&x,&y);
    // x = c/2;
    // y = c-x;
    // int offset = a*x+b*y;

    // // printf("delta: %d, offset: %d;   ", delta, offset);

    // for (size_t i = (d1-(d1%delta)+offset); i < d2; i += delta)
    // {
    //     mcd_euclide_extR(i,i*2,&x,&y);
    //     printf("d=%d x=%d y=%d\n", i, x, y);
    //     // x++;
    //     // y--;
    // }

    // int x,y;
    // int mcd = mcd_euclide_extR(a,b,&x,&y);
    // printf("mcd: %d, x: %d; y: %d", mcd, x, y);
    // int xo, yo;

    // for (size_t d = d1; d < d2; d++)
    // {
    //     printf("d mod mcd: %d \t", d, d%abs(mcd));
    //     if(d%abs(mcd) == 0){
    //         //Procedo
    //         xo = (d*x)/mcd;
    //         yo = (d*y)/mcd;
    //         printf("d=%d x=%d y=%d\n", d, xo, yo);
    //     }
    // }
    
}