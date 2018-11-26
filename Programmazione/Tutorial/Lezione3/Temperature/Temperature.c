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
*  Name : Temperature.c                                                                                                                              *
*  Purpose : The purpose of this program is to take as input the days' temperature in a week and to calculate the average.                           *
*  Date : 26/11/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define N_WEEK 7 //Number of the days in a week

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
        "*  Name : Temperature.c                                                                                 *\n"
        "*  Purpose : The purpose of this program is to take as input the days' temperature in a week and to     *\n"
        "*            calculate the average.                                                                     *\n"
        "*  Date : 26/11/2018                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("Temperature\n\n");
    //--------------------------------------

    //--------------------------------------
    typedef enum {Sun, Mon, Tue, Wed, Thu, Fri, Sat} Week; //Used to compare days

    float temperature[N_WEEK] = {0.0}, average = 0.00; /* 1 --> Used to store the temperature of the days
                                                          2 --> Used to store the average of the temperature */

    for(Week day = Sun; day <= Sat; day++)
    {
        printf("Insert the temperature (°) of %d^ day : ", day + 1); //Used to take the input of the temperature
        scanf("%f", &temperature[day]);
        average += temperature[day]; //Used to sum the number of the average
    }

    average /= N_WEEK; //Used to calculate the average

    printf("\nThe average of the temperature is %.2f°.\n", average); //Output of the average

    exit(EXIT_SUCCESS);
}