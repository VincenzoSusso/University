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
*  Name : Max.c                                                                                                                                      *
*  Purpose : The purpose of this program is to take 3 numbers in input and show the max using 2 times the function max which calculate the max       *
*            between 2 numbers.                                                                                                                      *
*  Date : 06/12/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

#include <stdlib.h>
#include <stdio.h>

//Function Prototypes
void introduction(void); //Used to show the intro of the program
int max(int first_number, int second_number); //Used to calculate the max between two numbers

int main(void)
{
    int first_number = 0, second_number = 0, third_number = 0, max_number = 0;; /* 1 --> Used to take the first number in input
                                                                                   2 --> Used to take the second number in input
                                                                                   3 --> Used to take the third number in input
                                                                                   4 --> Used to store the max number */

    introduction(); //Output of the introduction

    printf("Insert the first number: "); //Input of the first number
    scanf("%d", &first_number);

    printf("Insert the second number: "); //Input of the second number
    scanf("%d", &second_number);

    printf("Insert the third number: "); //Input of the third number
    scanf("%d", &third_number);

    max_number = max(first_number, second_number); //Max between the first number and the second number
    max_number = max(max_number, third_number); //Max between the max and the third number

    /*
        -- THIS SOLUTION CAN ALSO BE USED TO SAVE ONE VARIABLE --
        printf("\nThe max number between %d, %d and %d is: %d\n", first_number, second_number, third_number, max(max(first_number,second_number), third_number));
    */

    printf("\nThe max number between %d, %d and %d is: %d\n", first_number, second_number, third_number, max_number);
    
    exit(EXIT_SUCCESS);
}

void introduction(void) //Used to print the introduction
{
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
        "*  Name : Max.c                                                                                         *\n"
        "*  Purpose : The purpose of this program is to take 3 numbers in input and show the max using 2 times   *\n"
        "*            the function max which calculate the max between 2 numbers.                                *\n"
        "*  Date : 06/12/2018                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("Max\n\n");
    //--------------------------------------
}


int max(int first_number, int second_number) //Return the max between 2 numbers
{
    if(first_number > second_number) //If the first number is bigger than the second one return the first number
    {
        return first_number;
    }
    else
    {
        return second_number;
    }
}