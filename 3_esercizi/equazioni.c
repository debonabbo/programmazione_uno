#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c;

    printf("Inserisci i coefficienti di a, b e c: ");
    scanf("%f %f %f", &a, &b, &c);

    if(a != 0.0){
        //Equazione di secondo grado
        float delta = (b*b)-(4*a*c);

        if(delta == 0.0){
            printf("La radice dell'equazione di secondo grado e': %.1f", -(b/(2.0*a)));
        } else if (delta > 0.0) {
            float x1, x2;

            x1 = (-b+sqrt(delta))/(2.0*a);
            x2 = (-b-sqrt(delta))/(2.0*a);

            printf("Le due radici dell'equazione sono %.1f e %.1f.", x1, x2);
        } else {
            printf("Le radici sono complesse coniugate.");
        }
    } else if (b != 0.0){
        //Equazione di primo grado
        printf("La radice dell'equazione di primo grado e' %.1f.", (c/b));
    } else if (c != 0.0){
        //Equazione indeterminata
        printf("L'equazione e' indeterminata.");
    } else {
        //Equazione impossibile
        printf("L'equazione e' impossibile.");
    }

    return 0;
}