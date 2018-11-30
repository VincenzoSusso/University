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
*  Name : PythagoreanTable.c                                                                                                                         *
*  Purpose : The purpose of this program is to write a program that stores and show the Pythagorean table of n (0 <= n <= 20) natural number.        *
*  Date : 30/11/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MIN 1 //Min input
#define MAX 20 //Max input
#define N_MULTIPLICATIONS 10 //Number of the moltiplication

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
        "*  Name : PythagoreanTable.c                                                                            *\n"
        "*  Purpose : The purpose of this program is to write a program that stores and show the Pythagorean     *\n"
        "*            table of n (1 <= n <= 20) natural number.                                                  *\n"
        "*  Date : 30/11/2018                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("PythagoreanTable\n\n");
    //--------------------------------------

    //--------------------------------------
    int n = 1; /* 1 --> Used to take the input of the n natural number */

    do //Used to check the input
    {
        printf("Insert the numbers that you wanna see in the Pythagorean Table: ");
        scanf("%d", &n);
    }
    while((n < MIN) || (n > MAX));

    int Pythagorean[n][N_MULTIPLICATIONS]; //Create the matrix

    printf("\n");

    for(int i = 0; i < n; i++) //Create and show the pythagoream table without the multiplication table of 0
    {
        printf("Multiplication table of: %d\n", i+1); //Start from the multiplication table of 1
        for(int j = 0; j < N_MULTIPLICATIONS; j++)
        {
            Pythagorean[i][j] = (i+1) * (j+1); //Store the result of the multiplication in the matrix
            printf("\n%d x %d = %d", i+1, j+1, Pythagorean[i][j]); //Show the multiplication
        }
        printf("\n-----------------------------\n");
    }

    exit(EXIT_SUCCESS);
}