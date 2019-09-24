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
*  Name : AlgoritmiFondamentali                                                                                                                      *
*  Purpose : Implementazione di alcuni algoritmi fondamentali.                                                                                       *
*  Date : 21/09/2019                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

// -- Libraries --
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Ricerca.h"
#include "Ordinamento.h"

// -- Constant --
#define N 10//50000
#define MIN -100
#define MAX 100

void randomizzaArray(int array[], const int n_elementi)
{
	for(unsigned short i = 0; i < n_elementi; i++)
	{
		array[i] = rand() % (MAX - MIN + 1) + MIN;
	}
}

void mostraArray(int array[], const int n_elementi)
{
	printf("\n--------------------------------------------------\nArray:");
	for(unsigned short i = 0; i < n_elementi; i++)
	{
		printf("\narray[%d]: %d", i, array[i]);
	}
}

double secondiOperazione(const time_t inizio, const time_t fine)
{
     return  ((double) (fine - inizio)) / CLOCKS_PER_SEC;
}


int main(void)
{
	int array[N] = {0};
	int input_elemento_ricerca = MAX + 1;
	int indice_elemento_ricercato = INDICE_NON_TROVATO;

	time_t inizio = 0;
	time_t fine = 0;

	srand(time(NULL));

	randomizzaArray(array, N);

	do
	{
		// Inserimento input
		printf("\nInserisci il numero da cercare compreso tra (%d e %d): ", MIN, MAX);
		scanf("%d", &input_elemento_ricerca);
	} while(input_elemento_ricerca < MIN || input_elemento_ricerca > MAX);

	// Ricerca lineare esaustiva
	inizio = clock();
	indice_elemento_ricercato = ricercaEsaustiva(array, N, &input_elemento_ricerca);
	fine = clock();
	if(indice_elemento_ricercato != INDICE_NON_TROVATO)
	{
		printf("\nL'elemento %d si trova nella posizione %d", array[indice_elemento_ricercato], indice_elemento_ricercato);
		printf("\nLa ricerca lineare esaustiva ha impiegato %.2lf secondi", secondiOperazione(inizio, fine));
	}
	else
	{
		printf("\nL'elemento %d non appartiene all'array", input_elemento_ricerca);
		printf("\nLa ricerca lineare esaustiva ha comunque impiegato %.2lf secondi", secondiOperazione(inizio, fine));
	}

	// Ricerca lineare con sentinella
	printf("\n\n");
	indice_elemento_ricercato = INDICE_NON_TROVATO;
	inizio = clock();
	indice_elemento_ricercato = ricercaConSentinella(array, N, &input_elemento_ricerca);
	fine = clock();
	if(indice_elemento_ricercato != INDICE_NON_TROVATO)
	{
		printf("\nL'elemento %d si trova nella posizione %d", array[indice_elemento_ricercato], indice_elemento_ricercato);
		printf("\nLa ricerca lineare con sentinella ha impiegato %.2lf secondi", secondiOperazione(inizio, fine));
	}
	else
	{
		printf("\nL'elemento %d non appartiene all'array", input_elemento_ricerca);
		printf("\nLa ricerca lineare con sentinella ha comunque impiegato %.2lf secondi", secondiOperazione(inizio, fine));
	}

	// Ricerca binaria
	printf("\n\n");
	quickSort(array, 0, N - 1);
	indice_elemento_ricercato = INDICE_NON_TROVATO;
	inizio = clock();
	indice_elemento_ricercato = ricercaBinaria(array, N, &input_elemento_ricerca);
	fine = clock();
	if(indice_elemento_ricercato != INDICE_NON_TROVATO)
	{
		printf("\nL'elemento %d si trova nella posizione %d", array[indice_elemento_ricercato], indice_elemento_ricercato);
		printf("\nLa ricerca binaria ha impiegato %.2lf secondi", secondiOperazione(inizio, fine));
	}
	else
	{
		printf("\nL'elemento %d non appartiene all'array", input_elemento_ricerca);
		printf("\nLa ricerca binaria ha comunque impiegato %.2lf secondi", secondiOperazione(inizio, fine));
	}

	randomizzaArray(array, N);

	// Insertion Sort
	printf("\n\n");
	inizio = clock();
	selectionSort(array, N);
	fine = clock();
	printf("\nL'insertion sort ha impiegato %.2lf secondi per ordinare l'array", secondiOperazione(inizio, fine));

	randomizzaArray(array, N);

	// Bubble Sort
	printf("\n\n");
	inizio = clock();
	bubbleSort(array, N);
	fine = clock();
	printf("\nIl bubble sort ha impiegato %.2lf secondi per ordinare l'array", secondiOperazione(inizio, fine));

	randomizzaArray(array, N);

	// Shell Sort
	printf("\n\n");
	inizio = clock();
	shellSort(array, N);
	fine = clock();
	printf("\nLo shell sort ha impiegato %.2lf secondi per ordinare l'array", secondiOperazione(inizio, fine));

	randomizzaArray(array, N);

	// Quick Sort
	printf("\n\n");
	inizio = clock();
	quickSort(array, 0, N - 1);
	fine = clock();
	printf("\nIl quick sort ha impiegato %.2lf secondi per ordinare l'array", secondiOperazione(inizio, fine));

	randomizzaArray(array, N);

	// Merge Sort
	printf("\n\n");
	inizio = clock();
	mergeSort(array, 0, N - 1);
	fine = clock();
	printf("\nIl merge sort ha impiegato %.2lf secondi per ordinare l'array", secondiOperazione(inizio, fine));

	printf("\n\n");
	system("PAUSE");
	exit(EXIT_SUCCESS);
}
