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
*  Name : SearchAlgorithms.c                                                                                                                         *
*  Purpose : The purpose of this program is to test different search algorithm (binary search algorithm / linear search algorithm with sentinel /    *
*            linear search algorithm without sentinel).                                                                                              *
*  Date : 21/12/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

// -- Libraries --
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Introduction.h"
#include "SearchAlgorithms.h"

// -- Main --
int main(void)
{
    int element = 0, position = 0; 
    int array[SIZE] = {0}; 
    time_t start = 0, end = 0;

    introduction(); //Used to print the introduction
    set_array(array, SIZE); //Used to set values of array
    printf("Array elements:\n");
    get_array(array, SIZE); //Used to get the values of array
    printf("\n");
    element = set_element_search(); //Used to set the element to search

    //Linear search algorithm without sentinel
    start = clock();
    position = linear_search_no_sentinel(array, SIZE, element);
    end = clock();
    printf("\nThe linear search without sentinel has taken %lf seconds to find the element in %d position\n", get_second_search(start, end), position);

    //Linear search algorithm with sentinel
    start = clock();
    position = linear_search_sentinel(array, SIZE, element);
    end = clock();
    printf("\nThe linear search with sentinel has taken %lf seconds to find the element in %d position\n", get_second_search(start, end), position);

    //Binary search algorithm
    bubble_sort(array, SIZE);
    printf("\nNow the array has been sorted!\n");
    get_array(array, SIZE); //Used to get the values of array
    start = clock();
    position = binary_search(array, SIZE, element);
    end = clock();
    printf("\nThe binary search has taken %lf seconds to find the element in %d position", get_second_search(start, end), position);

    printf("\n");
    exit(EXIT_SUCCESS);
}