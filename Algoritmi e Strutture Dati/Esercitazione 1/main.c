/*
	Algoritmi e Strutture Dati - Esercitazione 1
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "Array.h"

// -- Constants --
#define N_ELEMENTS 20
#define MAX 100
#define MIN 0

int main(void)
{
	int array[N_ELEMENTS] = {0};
	int k = 0;
	int largest_number = 0;
	int largest_index = 0;

	randomize(array, N_ELEMENTS, MIN, MAX);
	showArray(array, N_ELEMENTS);

	printf("\nEnter k: ");
	scanf("%3d", &k);

	printf("\nThe number of elements that are greater than %d are: %d", k, greaterThan(array, N_ELEMENTS, k));

	if(member(array, N_ELEMENTS, k))
	{
		printf("\n\n%d is present into the array", k);
	}
	else
	{
		printf("\n\n%d is not present into the array", k);
	}

	largest_number = largest(array, N_ELEMENTS, &largest_index);
	printf("\n\nThe grater element into the array is array[%d]: %d ", largest_index, largest_number);

	if(_remove(array, N_ELEMENTS, k))
	{
		printf("\n\n%d has been removed", k);
		showArray(array, N_ELEMENTS);
	}
	else
	{
		printf("\n\n%d has not been removed", k);
	}

	printf("\n\nThe array is ordered in: %s", readOrder(ordering(array, N_ELEMENTS)));

	reverse(array, N_ELEMENTS);
	showArray(array, N_ELEMENTS);

	printf("\n\n\n\n");
	system("PAUSE");
	exit(EXIT_SUCCESS);
}
