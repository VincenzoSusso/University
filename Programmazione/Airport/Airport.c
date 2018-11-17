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
*  Name : Airport.c                                                                                                                                  *
*  Purpose : Pre-test of 15/11/2011                                                                                                                  *
*  Date : 13/11/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXCHAR 100 //MAX lenght of strings

// Struct used to store the information about flies
struct flies
{
    int id_fly;
    char start_city[MAXCHAR];
    char end_city[MAXCHAR];
    int all_seat;
    int occ_seat;
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
        "*  Name : Airport.c                                                                                     *\n"
        "*  Purpose : Pre-test of 15/11/2011                                                                     *\n"
        "*  Date : 13/11/2018                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("Airport \"Vattelapesca\" pre-test 15/11/2011");
    //--------------------------------------

    //--------------------------------------
    int n_flies = 0, avaible_seat = 0, i = 0; /* 1 --> Used to store the number of flies
                                                 2 --> Used to store the number of avaible seat
                                                 3 --> Index of array  */

    int n_booking = 0, res_id_fly = 0, required_seat = 0; /* 1 --> Used to store the number of booking
                                                                2 --> Used to search the id of the fly
                                                                3 --> Used to take the input of the seat that are required */

    bool flag = false; // Used to stop the research
    //--------------------------------------
    do
    {
        printf("\nInsert the number of flies : "); //Used to get the number of the flies
        scanf("%d", &n_flies);
    }
    while(n_flies <= 0);

    //--------------------------------------
    struct flies fly[n_flies]; //Used to store all the flies
    //--------------------------------------

    //P1
    for(i = 0; i < n_flies; i++)
    {
        printf("Insert the ID of the %d^ fly : ", i+1); //Used to insert the ID of the fly
        scanf("%d", &fly[i].id_fly);
        
        printf("Insert the departue city of the %d^ fly : ", i+1); //Used to insert the departure city of the fly
        scanf("%s", fly[i].start_city);

        printf("Insert the arrival city of the %d^ fly : ", i+1); //Used to insert the arrival city of the fly
        scanf("%s", fly[i].end_city);

        printf("Insert all the seat of the %d^ fly : ", i+1); //Used to insert all the seat of the fly
        scanf("%d", &fly[i].all_seat);

        do
        {
            printf("Insert the number of the occupied seats of the %d^ fly : ", i+1); //Used to insert the number of the occupied seats
            scanf("%d", &fly[i].occ_seat);
        }
        while(fly[i].occ_seat > fly[i].all_seat);
        printf("\n");
    }

    //P2
    do
    {
        printf("\nInsert the number of bookings : "); //Used to insert the number of bookings
        scanf("%d", &n_booking);
    }
    while(n_booking <= 0);

    for(int j = 0; j < n_booking; j++)
    {
        printf("\nInsert the ID of the fly to search : "); //Used to insert the ID of the fly to search 
        scanf("%d", &res_id_fly);

        printf("Insert the number of the required seat : "); //Used to get the number of the seat of the fly
        scanf("%d", &required_seat);

        flag = false; //Reset of the flag
        
        
        for(i = 0; (i < n_flies) && (flag == false); i++)
        {
            if(res_id_fly == fly[i].id_fly)
            {
                flag = true; //Stop the search
            }
        }
        
        i--; //Adjust of the counter!

        if(flag == true)
        {
            avaible_seat = fly[i].all_seat-fly[i].occ_seat; //Calculation of the avaible seat
            if(avaible_seat >= required_seat) 
            {
                printf("\nThe booking %d has been done!", res_id_fly); //Output booked fly
                fly[i].occ_seat = fly[i].occ_seat + required_seat; //Update occupied seat
            }
            else
            {
                printf("\nThe booking %d cannot be done, ", res_id_fly); //Output not booked fly
                printf("the avaible seat are : %d and the required seat are : %d", avaible_seat, required_seat);
            }
        }
        else
        {
            printf("\nThe fly %d does not exist", res_id_fly); //Output fly doesn't found
        }
        printf("\n");
    }

    //P3
    printf("\n\nUpdated table : ");
    for(i = 0; i < n_flies; i++)
    {
        printf("\n---------------------------------------------------------------------------------");
        printf("\nInformation about the %d^ fly :", i+1);

        printf("\nID %d^ fly --> %d", i+1, fly[i].id_fly); //Output ID fly
        printf("\nDeparture city of the %d^ fly --> %s", i+1, fly[i].start_city); //Output departure city
        printf("\nArrival city of the %d^ fly --> %s", i+1, fly[i].end_city); //Output arrival city
        printf("\nSeat of the %d^ fly --> %d", i+1, fly[i].all_seat); //Output seat
        printf("\nOccupied seat of the %d^ fly --> %d", i+1, fly[i].occ_seat); //Output occupied seat
        printf("\n---------------------------------------------------------------------------------");
    }
    printf("\n");

    exit(EXIT_SUCCESS);
}