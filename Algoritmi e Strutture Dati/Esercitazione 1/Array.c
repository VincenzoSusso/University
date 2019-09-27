/*
	Algoritmi e Strutture Dati - Esercitazione 1
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

// -- Libraries --
#include "Array.h"

// -- Procedures & Functions Prototypes --
char *readOrder(Order_t order)
{
	static char *order_array[N_ELEMENT_ARRAY_ORDER] = {RANDOM, INCREASING, DECREASING, CONSTANT};

	return order_array[order];
}

void randomize(int array[], int n_elements, int min, int max)
{
	int i = 0;

	for(i = 0; i < n_elements; i++)
	{
		array[i] = rand() % (max - min + 1) + min;
	}
}

void showArray(int array[], int n_elements)
{
	int i = 0;

	printf("\n--------------------- Array ------------------------");
	for(i = 0; i < n_elements; i++)
	{
		printf("\nArray[%d]: %d", i, array[i]);
	}
	printf("\n----------------------------------------------------");
}

int greaterThan(int array[], int n_elements, int k)
{
	int counter_k = 0;
	int i = 0;

	for(i = 0; i < n_elements; i++)
	{
		if(array[i] > k)
		{
			counter_k++;
		}
	}

	return counter_k;
}

bool member(int array[], int n_elements, int k)
{
	bool k_presence = false;
	int i = 0;

	while(i < n_elements && !k_presence)
	{
		if(array[i] == k)
		{
			k_presence = true;
		}

		i++;
	}

	return k_presence;
}

int largest(int array[], int n_elements, int *pointer_index_largest)
{
	int largest_number = 0;
	int i = 0;
	*pointer_index_largest = 0;

	if(n_elements)
	{
		largest_number = array[0];
		*pointer_index_largest = 0;

		for(i = 1; i < n_elements; i++)
		{
			if(array[i] > largest_number)
			{
				largest_number = array[i];
				*pointer_index_largest = i;
			}
		}
	}

	return largest_number;
}

bool _remove(int array[], int n_elements, int k)
{
	int i = 0;
	int j = 0;
	bool remove_done = false;

	while(i < n_elements && !remove_done)
	{
		if(array[i] == k)
		{
			for(j = i; j < n_elements - 1; j++)
			{
				array[j] = array[j + 1];
			}

			array[n_elements - 1] = REPLACE_ELEMENT;
			remove_done = true;
		}
		i++;
	}

	return remove_done;
}

Order_t ordering(int array[], int n_elements)
{
	Order_t ordering = constant;
	int i = 0;

	while((i < n_elements - 1) && (ordering == constant))
	{
		if(array[i] != array[i + 1])
		{
			ordering = increasing;
		}

		i++;
	}

	while((i < n_elements - 1) && (ordering == increasing))
	{
		if(array[i] > array[i + 1])
		{
			ordering = decreasing;
		}

		i++;
	}

	i = 0;
	while((i < n_elements - 1) && (ordering == decreasing))
	{
		if(array[i] < array[i + 1])
		{
			ordering = random;
		}

		i++;
	}

	return ordering;
}


void reverse(int array[], int n_elements)
{
	int i = 0;
	int temp = 0;

	while(i < (n_elements / 2))
	{
		temp = array[i];
		array[i] = array[n_elements - i - 1];
		array[n_elements - i - 1] = temp;
		i++;
	}

}
