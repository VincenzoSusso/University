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
*  Name : SearchAlgorithms.h                                                                                                                         *
*  Purpose : The purpose of this header is to store function prototypes, fuctions and constants of the program "SearchAlgorithms.c".                 *
*  Date : 21/12/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

// -- Libraries --
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// -- Constants --
#define SIZE 1500
#define VALUE_ARRAY 10000

// -- Functions Prototypes --
int set_element_search(void); //Used to set the element to search
void set_array(int array[],const int size); //Used to set values of array
void get_array(const int array[],const int size); //Used to get the values of array

int linear_search_no_sentinel(const int array[],const int size, const int element); //Used to search element using linear search algorithm without sentinel
int linear_search_sentinel(const int array[],const int size, const int element); //Used to search element using linear search algorithm with sentinel
int binary_search(const int array[],const int size, const int element); //Used to search element using binary search algorithm

void bubble_sort(int array[], const int n); //Used to sort the array

double get_second_search(const time_t start, const time_t end); //Used to calculate the number of second that the search has taken

// -- Functions --
int set_element_search(void) //Used to set the element to search
{
     int element = 0;

     do //Used to check the value of the element (> 0)
     {
          printf("Insert the element that you want to search (positive number): ");
          scanf("%d", &element);
     }
     while(element < 0);

     return element;
}

void set_array(int array[],const int size) //Used to set values of array
{
     srand((unsigned int) time(NULL)); //Used to randomize numbers
     for(int i = 0; i < size; i++)
     {
          array[i] = rand() % (VALUE_ARRAY + 1);
     }
}

void get_array(const int array[],const int size) //Used to get the values of array
{    
     printf("-------------------------------------------------------\n");
     for(int i = 0; i < size; i++) //Output of values
     {
          printf("array[%d] = %d\n", i, array[i]);
     }
     printf("-------------------------------------------------------\n");
}

int linear_search_no_sentinel(const int array[],const int size, const int element) //Used to search element using linear search algorithm without sentinel
{
     int position = -1; //Used to store the position of the element

     for(int i = 0; i < size; i++) //Used to check the position of the element
     {
          if(array[i] == element)
          {
               position = i;
          }
     }

     if(position == -1)
     {
          printf("\n+++ ELEMENT NOT FOUND. +++");
     }

     return position;
}

int linear_search_sentinel(const int array[],const int size, const int element) //Used to search element using linear search algorithm with sentinel
{
     int position = -1, i = 0; /* 1 --> Used to store the position of the element
                                  2 --> Used as index of the array */
     bool sentinel = true; //Used to break the cycle when the element has been found

     while ((i < size) && (sentinel)) //Used to check the position of the element
     {
          if(array[i] == element)
          {
               sentinel = false;
               position = i;
          }
          i++;
     } 

     if(position == -1)
     {
          printf("\n+++ ELEMENT NOT FOUND. +++");
     }

     return position;
}

int binary_search(const int array[],const int size, const int element) //Used to search element using binary search algorithm
{
     int position = -1, first = 0, middle = 0, last = 0; /* 1 --> Used to store the position of the element 
                                                            2 --> Used to store the position of the first one element 
                                                            3 --> Used to store the position of the middle element
                                                            4 --> Used to store the position of the last one element */
     bool sentinel = true; //Used to break the cycle when the element has been found


     last = size - 1;
     middle = (first + last) / 2;

     while((first <= last) && (sentinel))
     {
          if(array[middle] > element)
          {
               last = middle - 1;     
          }
          else if (array[middle] < element)
          {
               first = middle + 1;
          }
          else
          {
               position = middle;
               sentinel = false;
          }
          middle = (first + last) / 2;
     }

     if(position == -1)
     {
          printf("\n+++ ELEMENT NOT FOUND. +++");
     }

     return position;
}

void bubble_sort(int array[], const int size) //Used to sort the array
{
     int i = 0; //Used as index of the array
     bool sorted = true; //Used to break the cycle when the array is sorted

     while((i < size) && (sorted))
     {
          sorted = false;
          i++;
          for (int j = 0; j < size - i; j++) //Used to move bigger elements to the end of the array
          {
               if(array[j] > array[j+1]) //If the first one element is bigger than the second one element, invert them
               {
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                    sorted = true;
               }
          }
     }
}

double get_second_search(const time_t start, const time_t end) //Used to calculate the number of second that the search has taken
{
     return  ((double) (end - start)) / CLOCKS_PER_SEC;
}