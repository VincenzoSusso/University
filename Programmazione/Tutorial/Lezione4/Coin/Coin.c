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
*  Name : Coin.c                                                                                                                                     *
*  Purpose : The purpose of this program is to simulate the throws of a coin and gives informations about the results (Heads or Tails) and           *
*            about percent of the results, the program should take the number of throws as input.                                                    *
*  Date : 07/12/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 2 //Sides of the coin

//Custom type
typedef enum {head, tails} Coins; //Used to specify the side of the coin

//Function Prototypes
void introduction(void); //Used to show the intro of the program
int get_n_throws(void); //Used to take the number of the throws
Coins throw(void); //Used to simulate the throw of the coin
float calc_percent(float n, int n_throws); //Used to calculate the percent

//Main
int main(void)
{
    int n_throws = 0, n_head = 0, n_tails = 0; /* 1 --> Used to store the number of throws
                                                  2 --> Used to count the times that head occurs
                                                  3 --> Used to count the times that tails occurs */

    introduction(); //Introduction of the program
    srand((unsigned) time(NULL)); //Used to randomize the throws of the coin

    n_throws = get_n_throws(); //Used to take the input
    
    for(int i = 0; i < n_throws; i++) //Throw the coin n_throws
    {
        if(throw() == head) //If the coin is head
        {
            printf("\nThe %d^ throw is: HEAD", i+1); //Print and adds 1 to the counter head
            n_head++;
        }
        else
        {
            printf("\nThe %d^ throw is: TAILS", i+1); //Print and adds 1 to the counter tails
            n_tails++;
        }
    }

    //Output
    printf("\n\nHead has occured %d times", n_head);
    printf("\nTails has occured %d times", n_tails);
    printf("\nThe percent of head is %.2f%% and the percent of tails is %.2f%% \n",calc_percent(n_head,n_throws), calc_percent(n_tails,n_throws));

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
        "*  Name : Coin.c                                                                                        *\n"
        "*  Purpose : The purpose of this program is to simulate the throws of a coin and gives informations     *\n"
        "*            about the results (Heads or Tails) and about percent of the results, the program should    *\n"
        "*            take the number of throws as input.                                                        *\n"
        "*  Date : 07/12/2018                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("Coin\n\n");
    //--------------------------------------
}

int get_n_throws(void)
{
    int n_throws = 0;

    do //Check the input
    {
        printf("Insert the number of the times that you want to throw the coin: ");
        scanf("%d", &n_throws);
    }
    while(n_throws < 0);

    return n_throws;
}

Coins throw(void) //Used to simulate the throw of the coin
{
    int side; //Used to store the result of the casual throw

    side = rand() % SIDES; /* if(rand() % SIDES) can also be used */
    if(side == 1)
    {
        return head;
    }
    else
    {
        return tails;
    }
}

float calc_percent(float part, int total) //Used to calculate the percent
{
    return part * 100 / total;
}