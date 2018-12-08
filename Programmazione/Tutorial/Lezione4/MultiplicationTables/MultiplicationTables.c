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
*  Name : MultiplicationTables.c                                                                                                                     *
*  Purpose : The purpose of this program is to give questions about multiplication tables to the final user of the program, the final user should    *
*            answer to those questions and then he should decide to continue or not to.                                                              *
*  Date : 08/12/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MULTIPLICATIONTABLE 11 //Used to give multiplication table from 0 to 10

//Function Prototypes
void introduction(void); //Used to show the intro of the program
bool repeat(void); //Used to repeat the program or not to
void generate_numbers(int *first_number, int *second_number); //Used to generate the number of the multiplication
int multiplication(int first_number, int second_number); //Used to do the multiplication

//Main
int main(void)
{
    bool flag = false; //Used to repeat the program
    int first_number = 0, second_number = 0, result = 0; /* 1 --> Used to store the first number 
                                                            2 --> Used to store the second number
                                                            3 --> Used to store the result of the multiplication */
    int correct = 0, wrong = 0; //Used to count the correct and the wrong answer

    srand((unsigned) time(NULL)); //Used to randomize numbers
    introduction(); //Introduction of the program

    do
    {
        generate_numbers(&first_number, &second_number); //Used to generate random numbers
        printf("\n%d x %d is equal to: ", first_number, second_number); //Output of the multiplication
        scanf("%d", &result); //Used to take the input (The result of the multiplication)
        if(multiplication(first_number, second_number) == result) //If the result is right
        {
            printf("Your answer is right, good job!\n"); //Output and adds one to the corrected answers
            correct++;
        }
        else
        {
            printf("Your answer is wrong!\n"); //Output and adds one to the wrong answers
            wrong++;
        }
        flag = repeat(); //Used to set the flag and repeat the program
    }
    while(flag);

    //Output of the stats of the final user
    printf("\nYou have answered to %d questions, your corrected answer were %d, and your wrong answer were %d\n", correct+wrong, correct, wrong);

    exit(EXIT_SUCCESS);
}

// -- Functions --
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
        "*  Name : MultiplicationTables.c                                                                        *\n"
        "*  Purpose : The purpose of this program is to give questions about multiplication tables to the final  *\n"
        "*            user of the program, the final user should answer to those questions and then he should    *\n"
        "*            decide to continue or not to.                                                              *\n"
        "*  Date : 08/12/2018                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("MultiplicationTables\n");
    //--------------------------------------
}

bool repeat(void) //Used to repeat the program or not to
{
    char answer = 'N';
    
    printf("\nInsert if you want to continue (Y/N): "); //Used to know if the user want to repeat
    scanf(" %c", &answer);

    if((answer == 'Y') || (answer == 'y'))
    {
        return true;
    }
    
    return false;
}

void generate_numbers(int *first_number, int *second_number) //Used to generate the number of the multiplication
{
    *first_number = rand() % MULTIPLICATIONTABLE;
    *second_number = rand() % MULTIPLICATIONTABLE;
}

int multiplication(int first_number, int second_number) //Used to do the multiplication
{
    return first_number * second_number;
}