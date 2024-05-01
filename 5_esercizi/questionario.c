#include <stdio.h>

#define NUM_RISP 20

int main(){

    int risposte[] = {
        1, 2, 5, 4, 3, 5, 2, 1, 3, 1,
        4, 3, 3, 3, 2, 3, 3, 2, 2, 5
    };

    int frequenze[] = { 0, 0, 0, 0, 0};
                //      1  2  3  4  5 stelle

    for (size_t i = 0; i < NUM_RISP; i++)
    {
        frequenze[risposte[i]-1] += 1;
    }

    printf("Stelle\tFrequenza\n");

    for (size_t i = 0; i < 5; i++)
    {
        printf("%zu\t%d\t", i+1, frequenze[i]);

        for (size_t a = 0; a < frequenze[i]; a++)
        {
            printf("#");
        }

        printf("\n");
    }
    
    return 0;
}