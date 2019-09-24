/*



 __          __  _____           ______
 \ \        / / |_   _|         |  ____|
  \ \  /\  / /    | |    _ __   | |__     _ __    ____   ___
   \ \/  \/ /     | |   | '_ \  |  __|   | '_ \  |_  /  / _ \
    \  /\  /     _| |_  | | | | | |____  | | | |  / /  | (_) |
     \/  \/     |_____| |_| |_| |______| |_| |_| /___|  \___/




*/

/*****************************************************************************************************************************************************
*                                                                                                                                                    *
*  Author : WinEnzo                                                                                                                                  *
*  Name : Ricerca                                                                                                                                    *
*  Purpose : Implementazione di alcune funzioni di ricerca.                                                                                       *
*  Date : 21/09/2019                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

// -- Libraries --
#include <stdbool.h>

// -- Constant --
#define INDICE_NON_TROVATO -1

// -- Procedure & Functions Prototypes --
int ricercaEsaustiva(const int const array[], const int n_elementi, const int const *ricerca_elemento);
int ricercaConSentinella(const int const array[], const int n_elementi, const int const *ricerca_elemento);
int ricercaBinaria(const int const array[], const int n_elementi, const int const *ricerca_elemento);
