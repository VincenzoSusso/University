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
*  Name : Condominium.c                                                                                                                              *
*  Purpose : Pre-test of 16/11/2018.                                                                                                                 *
*  Date : 17/11/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXCHAR 100 //MAX lenght of strings

struct residents
{
    char surname[MAXCHAR];
    int floor;
    char home[MAXCHAR];
    float amount_payed;
    float ord_tax; //Ordinary tax
    float ext_tax; //Extraordinary tax
};

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
        "*  Name : Condominium.c                                                                                 *\n"
        "*  Purpose : Pre-test of 16/11/2018.                                                                    *\n"
        "*  Date : 17/11/2018                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("Condominium pre-test 16/11/2018");
    //--------------------------------------

    //--------------------------------------
    int n_resident, i, max, k; /* 1 --> Number of the resident of the condominium
                                  2 --> Index of array                         
                                  3 --> Used to see the resident that has paid the more
                                  4 --> Used to contain the index of the resident that has paid the more */

    char find_surname[MAXCHAR]; // 1 --> Used to find the surname

    float balance; //Used to calcolate the balance of residentes

    bool flag = false; //Used to stop the research
    //--------------------------------------

    do
    {
        printf("\nInsert the number of the resident of the condominium: "); //Used to take the input 
        scanf("%d", &n_resident);
    }
    while(n_resident <= 0);
    printf("\n");

    //--------------------------------------
    struct residents resident[n_resident]; //Used to create a table to store informations about every resident
    //--------------------------------------

    //P1 --> Insert the information about all the residents
    for(i=0; i < n_resident; i++)
    {
        printf("Insert the surname of the %d^ resident: ", i+1); //Used to insert the username of the resident
        scanf("%s", resident[i].surname);

        printf("Insert the floor where the %d^ resident live: ", i+1); //Used to insert the floor where the resident lives
        scanf("%d", &resident[i].floor);

        printf("Insert the home's ID of the %d^ resident: ", i+1); //Used to insert home's ID of the resident
        scanf("%s", resident[i].home);

        printf("Insert the amount of the tax that the %d^ resident has paid: ", i+1); //Used to insert the amount of the tax that the resident
        scanf("%f", &resident[i].amount_payed);

        printf("Insert the amount of the ordinary tax that the %d^ resident should pay (€): ", i+1); //Used to insert the ordinary tax that the resident should pay
        scanf("%f", &resident[i].ord_tax);

        printf("Insert the amount of the extraordinary tax that the %d^ resident should pay (€): ", i+1); //Used to insert the extraordinary tax that the resident should pay
        scanf("%f", &resident[i].ext_tax);

        printf("\n");
    }

    //P2 --> Insert a surname and find the amount that has been paid by the resident
    printf("Insert the surname to find: "); //Used to insert the surname to find
    scanf("%s", find_surname);

    for(i = 0; (i < n_resident) && (flag == false); i++)
    {
        if(strcmp(resident[i].surname, find_surname) == 0)
        {
            flag = true; //Stop the research because the surname has been found
        }    
    }

    if(flag == true)
    {
        i--; //This operation fix the index's value
        printf("%s has paid: %.2f€", resident[i].surname, resident[i].amount_payed);
    }
    else
    {
        printf("%s has not been found", find_surname);
    }
    printf("\n");

    //P3 --> See if residents's balance are in credit, debt or equal
    for (i = 0; i < n_resident; i++)
    {
        balance = resident[i].amount_payed - resident[i].ord_tax - resident[i].ext_tax; //Calculate the balance
        if(balance >= 0)
        {
            if(balance == 0) //Case --> balance = 0
            {
                printf("\nThe %d^ resident %s, is in equal, infact he has paid %.2f€ and he should pay %.2f€", i+1, resident[i].surname, resident[i].amount_payed, resident[i].ord_tax + resident[i].ext_tax);
            }
            else //Case --> balance > 0
            {
                printf("\nThe %d^ resident %s, is in credit, infact he has paid %.2f€ and he should pay %.2f€", i+1, resident[i].surname, resident[i].amount_payed, resident[i].ord_tax + resident[i].ext_tax);
            }
        }
        else //Case --> balance < 0
        {
            printf("\nThe %d^ resident %s, is in debt, infact he has paid %.2f€ and he should pay %.2f€", i+1, resident[i].surname, resident[i].amount_payed, resident[i].ord_tax + resident[i].ext_tax);
        }
    }
    printf("\n");

    //P4 --> See the residents who has paid the max amount
    k = 0; //Set the index of the max (first one element)
    max = resident[k].amount_payed; //Set the value of the max (first one element)
    for(i = 1; i < n_resident; i++)
    {
        if(resident[i].amount_payed > max) //If the max is not max update the max and the index
        {
            max = resident[i].amount_payed;
            k = i;
        }
    }

    printf("\nThe resident who has paid the max amount is %s who has paid %.2f€", resident[k].surname, resident[k].amount_payed); //Output max amount

    printf("\n");
    exit(EXIT_SUCCESS);
}