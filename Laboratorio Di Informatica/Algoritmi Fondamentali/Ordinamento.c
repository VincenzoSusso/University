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
*  Name : Ordinamento                                                                                                                                *
*  Purpose : Implementazione di alcune funzioni di ordinamento.                                                                                      *
*  Date : 21/09/2019                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

// -- Libraries --
#include "Ordinamento.h"

// -- Procedure & Functions --
void swap(int *a, int *b)
{
	int temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int array[], const int n_elementi)
{
	/*
	 	-------------------------------------------
	 	Pseudo codice
	 	-------------------------------------------
		minimo = 0;
		indice_minimo = 0;
		i = 0;
		j = 0;

		while(i < n_elementi - 1) do
		{
			j = i;
			minimo = array[i];
			indice_minimo = i;

			while((j + 1) < n_elementi) do
			{
				if(array[j] < min)
				{
					minimo = array[j];
				}

				j = j + 1;
			}

			swap(array[i], minimo[indice_minimo]);
			i = i + 1;
		}
	 */

	int minimo = 0;
	int indice_minimo = 0;
	int i = 0;
	int j = 0;

	for(i = 0; i < n_elementi - 1; i++)
	{
		minimo = array[i];
		indice_minimo = i;

		for(j = i + 1; j < n_elementi; j++)
		{
			if(array[j] < minimo)
			{
				minimo = array[j];
				indice_minimo = j;
			}
		}

		swap(&array[i], &array[indice_minimo]);
	}
}


void bubbleSort(int array[], const int n_elementi)
{
	/*
	 	-------------------------------------------
	 	Pseudo codice
	 	-------------------------------------------
		i = 0;
		j = 0;
		ordinato = false;

		while(!ordinato AND i < n_elementi) do
		{
			ordinato = true;
			j = n_elementi - 1;

			while(j >= i) do
			{
				if(array[j - 1] > array[j])
				{
					ordinato = false;
					swap(array[j - 1], array[j]);
				}

				j = j - 1;
			}

			i = i + 1;
		}
	 */

	int i = 0;
	int j = 0;
	bool ordinato = false;

	while(!ordinato && i < n_elementi)
	{
		ordinato = true;
		for(j = n_elementi - 1; j >= i; j--)
		{
			if(array[j-1] > array[j])
			{
				ordinato = false;
				swap(&array[j-1], &array[j]);
			}
		}
		i++;
	}
}

void insertionSort(int array[], const int n_elementi)
{
	/*
	 	-------------------------------------------
	 	Pseudo codice
	 	-------------------------------------------

	 	i = 1;
	 	j = 0;
	 	numero_ordinare = 0;

	 	while(i < n_elementi) do
	 	{
	 		numero_ordinare = array[i];
	 		j = i - 1;
	 		while(j >= 0 AND array[j] > numero_ordinare)
	 		{
	 			array[j+1] = array[j];
	 			j = j - 1;
	 		}
	 		x[j+1] = numero_ordinare;

	 		i = i + 1;
	 	}
	 */

	int i = 0;
	int j = 0;
	int numero_ordinare = 0;

	for(i = 1; i < n_elementi; i++)
	{
		numero_ordinare = array[i];
		j = i - 1;
		while(j >= 0 && array[j] > numero_ordinare)
		{
			array[j+1] = array[j];
			j--;
		}

		array[j+1] = numero_ordinare;
	}
}

void shellSort(int array[], const int n_elementi)
{
	int distanze[N_DISTANZE] = {9,5,3,2,1};
	int distanza = 0;

	int i = 0;
	int j = 0;
	int k = 0;

	int temp = 0;

	for(k = 0; k < N_DISTANZE; k++)
	{
		distanza = distanze[k];
		for(i = distanza; i < n_elementi; i++)
		{
			temp = array[i];
			for(j = i - distanza; (temp < array[j]) && (j >= 0); j -= distanza)
			{
				array[j + distanza] = array[j];
				array[j] = temp;
			}
		}
	}
}

void quickSort(int array[], int sinistra, int destra)
{
	int i = 0;
	if(sinistra < destra)
	{
		i = partition(array, sinistra, destra);
		quickSort(array, sinistra, i - 1);
		quickSort(array, i + 1, destra);
	}
}

int partition(int array[], int sinistra, int destra)
{
	int indice_pivot = (sinistra + destra) / 2;
	int pivot = array[indice_pivot];

	int i = sinistra;
	int j = destra;

	int temp = 0;

	while(i < j)
	{
		while(array[i] < pivot)
		{
			i++;
		}

		while(array[j] > pivot)
		{
			j--;
		}

		if(i < j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	return j;

}

void mergeSort(int array[], int sinistra, int destra)
{
	int medio = 0;

	if(sinistra < destra)
	{
		medio = (sinistra + destra) / 2;
		mergeSort(array, sinistra, medio);
		mergeSort(array, medio + 1, destra);
		merge(array, sinistra, medio, destra);
	}
}

void merge(int array[], int sinistra, int medio, int destra)
{
	int i = sinistra;
	int j = medio + 1;
	int k = 0;

	const int lunghezza_array = destra - sinistra + 1;
	int temp[lunghezza_array];

	while(i <= medio && j <= destra)
	{
		if(array[i] < array[j])
		{
			temp[k] = array[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = array[j];
			j++;
			k++;
		}
	}

	while(i <= medio)
	{
		temp[k] = array[i];
		i++;
		k++;
	}

	while(j <= destra)
	{
		temp[k] = array[j];
		j++;
		k++;
	}

	for(int x = sinistra, y = 0; x <= destra; x++, y++)
	{
		array[x] = temp[y];
	}
}
