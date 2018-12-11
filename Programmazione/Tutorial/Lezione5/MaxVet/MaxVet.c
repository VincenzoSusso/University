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
*  Name : MaxVet.c                                                                                                                                   *
*  Purpose : The purpose of this program is to find the max element of an array that has been taken in input.                                        *
*  Date : 11/12/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MIN 1 //Min size of the array

void introduction(void); //Used to print the introduction
void set_vet(int vet[], int n); //Used to set elements of the array
int get_max(int vet[], int n); //Used to get the max element of the array

int main(void)
{
    int numbers = 1;
    introduction();
    do
    {
        printf("Insert how many elements has your array : ");
        scanf("%d", &numbers);
    }
    while(numbers < MIN);

    int vet[numbers];

    printf("\n");
    set_vet(vet, numbers); //Used to take inputs

    printf("\nThe max element is: %d\n", get_max(vet, numbers)); //Output of the max
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
        "*  Name : MaxVet.c                                                                                      *\n"
        "*  Purpose : The purpose of this program is to find the max element of an array that has been taken     *\n"
        "*            in input.                                                                                  *\n"
        "*  Date : 11/12/2018                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("MaxVet\n\n");
    //--------------------------------------
}

void set_vet(int vet[], int n) //Used to set elements of the array
{
    for(int i = 0; i < n; i++) //Input of the element
    {
        printf("Insert the %d element: ", i+1);
        scanf("%d", &vet[i]);
    }    
}

int get_max(int vet[], int n) //Used to get the max element of the array
{
    int max = vet[0]; //The first element is the max

    for(int i = 1; i < n; i++) //Check other element
    {
        if(vet[i] > max)
        {
            max = vet[i];
        }
    }

    return max;
}