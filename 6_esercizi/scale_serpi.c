#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const int tabellone[100] = {
    38, 0, 0, 14, 0, 0, 0, 30, 0, 0,    //01 - 10
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,       //11 - 20
    42, 0, 0, 0, 0, 0, 0, 76, 0, 0,     //21 - 30
    0, 10, 0, 0, 0, 6, 0, 0, 0, 0,      //31 - 40
    0, 0, 0, 0, 0, 0, 0, 26, 0, 67,     //41 - 50
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,       //51 - 60
    0, 18, 0, 0, 0, 0, 0, 0, 0, 0,      //61 - 70
    92, 0, 0, 0, 0, 0, 0, 0, 0, 99,     //71 - 80
    0, 0, 0, 0, 0, 0, 0, 24, 0, 0,      //81 - 90 
    0, 0, 0, 0, 56, 0, 78, 0, 0, 0      //91 - 100
};

// Avanza la posizione del giocatore nella casella *pos
// in funzione del lancio del dado.
// Parametri:
//   dado   La quantità ottenuta dal lancio del dado (compresa tra 1 e 6)
//  *pos    La cella del giocatore che muove
// Ritorna true se il giocatore gioca ancora il prossimo turno, false altrimenti.
// Al ritorno, il valore di *pos è stato modificato aggiungendo il lancio 
// del dado, ed applicando tutte le rimanenti reole sulle scale e sulle serpi
bool muovi_giocatore(int dado, int* pos) {
	bool giocaAncora = (dado == 6);
	
    *pos += dado;

    if(*pos < 100){
        if(tabellone[((*pos)-1)] != 0)
            *pos = tabellone[((*pos)-1)];
    }

    return giocaAncora;
}

//------------------------------------------------------------------------------
// LEGGERE MA NON MODIFICARE IL CODICE SEGUENTE

// Simula il lancio di un dado a 6 facce
int lancia_dado() {
	return (rand() % 6) + 1;
}

// Realizza i turni del gioco delle scale e delle serpi
void scale_e_serpi(void) {
	int pos1 = 1, pos2 = 1; // la posizione dei due giocatori, inizialmente 1
	int turno = 1; 			// puo' valere 1 o 2

	// Esegui i turni
	while (pos1<100 && pos2<100) {
		// il giocatore lancia il dado
		int dado = lancia_dado();
		// muovi il giocatore attivo, e determina chi gioca il prossimo turno
		if (turno == 1) { 
			// muove il giocatore 1
			if (muovi_giocatore(dado, &pos1) == false)
				turno = 2; // passa il turno al giocatore 2
		}
		else { 
			// muove il giocatore 2
			if (muovi_giocatore(dado, &pos2) == false)
				turno = 1; // passa il turno al giocatore 1
		}
	}
	// Stampa il vincitore e le posizioni finali dei due giocatori
	printf("%d %d %d\n", turno, pos1, pos2);
}

int main(){
    srand(1);
    scale_e_serpi();
    srand(2);
    scale_e_serpi();
    srand(3);
    scale_e_serpi();
    srand(4);
    scale_e_serpi();
    srand(5);
    scale_e_serpi();
    srand(6);
    scale_e_serpi();
    srand(7);
    scale_e_serpi();
    srand(8);
    scale_e_serpi();
    srand(9);
    scale_e_serpi();
    return 0;
}