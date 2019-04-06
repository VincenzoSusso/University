// -- Librerie --
#include "Utility.h"

// -- Procedure & Funzioni --
int generaValoreCasuale(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void pulisciBuffer(void)
{
    while(getchar() != RITORNO_A_CAPO){};
}