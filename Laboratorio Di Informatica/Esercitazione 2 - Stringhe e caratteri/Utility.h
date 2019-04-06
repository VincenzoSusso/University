/* 
    Libreria che fornisce diverse funzioni di utility
*/

// -- Librerie --
#include <stdlib.h>
#include <stdio.h>

// -- Costanti --
#define RITORNO_A_CAPO '\n' // Carattere utilizzato per pulire il buffer

// -- Prototipi di Procedure & Funzioni --
int generaValoreCasuale(int min, int max); // Genera un valore casuale nel range min - max
void pulisciBuffer(void);