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
*  Name : FibonacciSequence.c                                                                                                                        *
*  Purpose : The purpose of this program is to take as input the number of sequences (>=1) and show the Fibonacci sequences.                         *
*  Date : 26/11/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MIN 1 /* The minimum value that the sequence can be (>=1) 
                 (Don't change this value or the program will not work) */
#define MINARRAY 2 //The minimum size of the array (Don't change this value or the program will not work)
#define N 2 //Number of array's element (You can change this value)



int main(void)
{
    //--------------------------------------
    printf(
        " __          __  _____           ______\n"
        " \\ \\        / / |_   _|         |  ____|\n"
        "  \\ \\  /\\  / /    | |    _ __   | |__     _ __    ____   ___\n"
        "   \\ \\/  \\/ /     | |   | '_ \\  |  __|   | '_ \\  |_  /  / _ \\\n"
        "    \\  /\\  /     _| |_  | | | | | |____  | | | |  / /  | (_) |\n"
        "     \\/  \\/     |_____| |_| |_| |______| |_| |_| /___|  \\___/\n\n"
    );

    printf(
        "/********************************************************************************************************\n"
        "*  Author : WinEnzo                                                                                     *\n"
        "*  Name : FibonacciSequence.c                                                                           *\n"
        "*  Purpose : The purpose of this program is to take as input the number of sequences (>=1) and show     *\n"
        "*            the Fibonacci sequences.                                                                   *\n"
        "*  Date : 26/11/2018                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("FibonacciSequence - Using an array of %d element\n\n", N);
    //--------------------------------------

    //--------------------------------------
    int fibonacci[N] = {0, 1}, sequence = MIN, index = 0; /* 1 --> Used to calculate the fibonacci sequence
                                                             2 --> Used to take as input the number of sequences 
                                                             3 --> Used as index of the array */
        
    for(int i = MINARRAY; i < N; i++) //Used to fill the array
    {
        fibonacci[i] = fibonacci[i - MINARRAY] + fibonacci[i - 1];
    }

    do //Check the value of the sequence (>= 1)
    {
        printf("Insert the number of sequence: ");
        scanf("%d", &sequence);
    }
    while(sequence < MIN);

    printf("\nThe fibonacci sequence is: %d", fibonacci[0]); //Used to print the first number

    for(int i = 1; i < sequence; i++) //Used to calculate the elements and show them
    {
        index = i % N; //Used to re-start the position of the array and re-set elements
        if(index == 0)
        {        
            fibonacci[index] = fibonacci[N - MINARRAY] + fibonacci[N - 1]; //Used to re-set the first one element of the array
            index++; //Point to the second one element
            fibonacci[index] = fibonacci[index - 1] + fibonacci[N - 1]; //Used to re-set the second one element of the array

            for(int j = MINARRAY; j < N; j++) //Used to re-set all the remaining elements of the array
            {  
                fibonacci[j] = fibonacci[j - 1] + fibonacci[j - 2]; //Used to fill the array  
            }

            index = i % N; //Used to restore the index of the array
        }
        printf(", %d", fibonacci[index]); //Output of the array
    }    
    
    printf("\n");

    exit(EXIT_SUCCESS);
}