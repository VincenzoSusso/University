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
#include <stdbool.h>

// -- Constant --
#define N_DISTANZE 5

// -- Procedure & Functions Prototypes --
void swap(int *a, int *b);

void selectionSort(int array[], const int n_elementi);

void bubbleSort(int array[], const int n_elementi);

void insertionSort(int array[], const int n_elementi);

void shellSort(int array[], const int n_elementi);

void quickSort(int array[], int sinistra, int destra);
int partition(int array[], int sinistra, int destra);

void mergeSort(int array[], int sinistra, int destra);
void merge(int array[], int sinistra, int medio, int destra);
