/*
	Algoritmi e Strutture Dati - Esercitazione 1
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

#ifndef ARRAY_H
	#define ARRAY_H

// -- Libraries --
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// -- Constants --
#define REPLACE_ELEMENT 0

#define N_ELEMENT_ARRAY_ORDER 4
#define RANDOM "random"
#define INCREASING "increasing"
#define DECREASING "decreasing"
#define CONSTANT "constant"

// -- User-Defined types --
typedef enum {random, increasing, decreasing, constant} Order_t;

// -- Procedures & Functions Prototypes --
char *readOrder(Order_t order);
void randomize(int array[], int n_elements, int min, int max);
void showArray(int array[], int n_elements);
int greaterThan(int array[], int n_elements, int k);
bool member(int array[], int n_elements, int k);
int largest(int array[], int n_elements, int *pointer_index_largest);
bool _remove(int array[], int n_elements, int k);
Order_t ordering(int array[], int n_elements);
void reverse(int array[], int n_elements);

#endif
