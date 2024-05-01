#include <stdio.h>

#define MAX_N 20

int main(){
    size_t N;

    // printf("Quanto deve essere lungo l'array?: ");
    scanf("%zu", &N);

    if(N < 0 || N > MAX_N){
        printf("Errore: numero di elementi non valido.");
    } else {
        int sequenza[N]; 

        for (size_t i = 0; i < N; i++)
        {
            int numerino; 
            scanf("%d", &numerino);

            sequenza[i] = numerino;
        }

        if(N == 0){
            printf("Vuoto.");
        } else {
            int somma = 0;
            int minimo = sequenza[0];

            for (size_t i = 1; i < N; i++)
            {
                if(sequenza[i] < minimo)
                    minimo = sequenza[i];
            }

            for (size_t i = 0; i < N; i++)
            {
                if(sequenza[i] >= (minimo*minimo))
                    somma += sequenza[i];
            }
            
            // printf("La somma e' %d.", somma);
            printf("%d", somma);
        }
    }
    
    

    return 0;
}