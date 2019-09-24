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
#include "Ricerca.h"

// -- Procedure & Functions --
int ricercaEsaustiva(const int const array[], const int n_elementi, const int const *ricerca_elemento)
{
	/*
	 	-------------------------------------------
	 	Pseudo codice
	 	-------------------------------------------
	    indice_elemento = -1;
	    i = 0;

	    while(i < n_elementi) do
	    {
	    	if(array[i] == ricerca_elemento)
	    	{
	    		indice_elemento = i;
	    	}
	    	i = i + 1;
	    }
	 */

	int indice_elemento = INDICE_NON_TROVATO;
	int i = 0;

	for(i = 0; i < n_elementi; i++)
	{
		if(array[i] == *ricerca_elemento)
		{
			indice_elemento = i;
		}
	}

	return indice_elemento;
}

int ricercaConSentinella(const int const array[], const int n_elementi,const int const *ricerca_elemento)
{
	/*
	 	-------------------------------------------
	 	Pseudo codice
	 	-------------------------------------------
	    indice_elemento = -1;
	    trovato = false;
	    i = 0;

	    while(i < n_elementi AND !trovato) do
	    {
	    	if(array[i] == ricerca_elemento)
	    	{
	    		trovato = true;
	    		indice_elemento = i;
	    	}

	    	i = i + 1;
	    }
	 */

	int indice_elemento = INDICE_NON_TROVATO;
	int i = 0;
	bool trovato = false;

	while(i < n_elementi && !trovato)
	{
		if(array[i] == *ricerca_elemento)
		{
			trovato = true;
			indice_elemento = i;
		}
		i++;
	}

	return indice_elemento;
}

int ricercaBinaria(const int const array[],const int n_elementi,const int const *ricerca_elemento)
{
	/*
	 	-------------------------------------------
	 	Pseudo codice
	 	-------------------------------------------
	    indice_elemento = -1;

	    sinistra = 0;
	    destra = n_elementi - 1;
	    medio = 0;

	    while(indice_elemento == -1 AND sinistra <= destra) do
	    {
			medio = (sinistra + destra) / 2;
			if(array[medio] == ricerca_elemento)
			{
				indice_elemento = medio;
			}
			else
			{
				if(array[medio] > ricerca_elemento)
				{
					destra = medio - 1;
				}
				else
				{
					sinistra = medio + 1;
				}
	    }
	 */

	int indice_elemento = INDICE_NON_TROVATO;

	int sinistra = 0;
	int destra = n_elementi - 1;
	int medio = 0;

	while(indice_elemento == INDICE_NON_TROVATO && sinistra <= destra)
	{
		medio = (sinistra + destra) / 2;

		if(array[medio] == *ricerca_elemento)
		{
			indice_elemento = medio;
		}
		else
		{
			if(*ricerca_elemento > array[sinistra])
			{
				sinistra = medio + 1;
			}
			else
			{
				destra = medio - 1;
			}
		}
	}

	return indice_elemento;
}
