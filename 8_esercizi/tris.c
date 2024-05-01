#include <stdio.h>
#include <stdbool.h>

#define DIM 3

char vincitore(char tavola[DIM][DIM]);

int main(){
    char tavola[DIM][DIM] = {0};

    for (size_t r = 0; r < DIM; r++){
        for (size_t c = 0; c < DIM; c++){
            scanf(" %c", &tavola[r][c]);
        }
    }

    printf("%c", vincitore(tavola));

    return 0;
}

bool vince_riga(char tavola[DIM][DIM], char *vincitore){
    *vincitore = '-';

    for(size_t r = 0; r < DIM && *vincitore == '-'; r++){
        int X = 0, O = 0;

        for (size_t c = 0; c < DIM; c++){
            if(tavola[r][c] == 'X')
                X++;
            else if (tavola[r][c] == 'O')
                O++;
        }
        if(O == DIM)
            *vincitore = 'O';
        else if (X == DIM)
            *vincitore = 'X';
    }

    return !(*vincitore == '-');
}

bool vince_colonna(char tavola[DIM][DIM], char *vincitore){
    *vincitore = '-';

    for(size_t c = 0; c < DIM && *vincitore == '-'; c++){
        int X = 0, O = 0;

        for (size_t r = 0; r < DIM; r++){
            if(tavola[r][c] == 'X')
                X++;
            else if (tavola[r][c] == 'O')
                O++;
        }
        if(O == DIM)
            *vincitore = 'O';
        else if (X == DIM)
            *vincitore = 'X';
    }

    return !(*vincitore == '-');
}

bool vince_diagonale(char tavola[DIM][DIM], char *vincitore){
    int X = 0, O = 0;
    for (size_t i = 0; i < DIM; i++)
    {
        if(tavola[i][i] == 'X')
            X++;
        else if (tavola[i][i] == 'O')
            O++;
    }
    
    if(O == DIM)
        *vincitore = 'O';
    else if(X == DIM)
        *vincitore = 'X';

    if(*vincitore == '-'){
        X = 0;
        O = 0;
        for (int i = DIM-1; i >= 0; i--)
        {
            if(tavola[DIM-i-1][i] == 'X')
                X++;
            else if (tavola[DIM-i-1][i] == 'O')
                O++;
        }
        
        if(O == DIM)
            *vincitore = 'O';
        else if(X == DIM)
            *vincitore = 'X';
    }

    return !(*vincitore == '-');
}

char vincitore(char tavola[DIM][DIM]){
    char vincitore = '-';

    if(vince_riga(tavola, &vincitore)){}
    else if (vince_colonna(tavola, &vincitore)){}
    else vince_diagonale(tavola, &vincitore);

    return vincitore;
}