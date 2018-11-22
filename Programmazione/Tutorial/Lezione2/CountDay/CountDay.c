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
*  Name : CountDay.c                                                                                                                                 *
*  Purpose : The purpose of this program is to count how many days have been passed since the start of this year.                                    *
*            This program doesn't work with bissextile years.                                                                                        *
*  Date : 22/11/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>

#define D31 31 //Used by month of 31 days
#define D30 30 //Used by month of 30 days
#define D28 28 //Used by month of 28 days

int main (void)
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
        "*  Name : CountDay.c                                                                                    *\n"
        "*  Purpose : The purpose of this program is to count how many days have been passed since the start     *\n"
        "*            of this year. This program doesn't work with bissextile years.                             *\n"
        "*  Date : 22/11/2018                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("CountDay\n\n");
    //--------------------------------------

    //--------------------------------------
    int day = 0, month = 0, total = 0;

    printf("Insert a date (dd/mm): ");
    scanf("%2d/%2d", &day, &month);

    switch(month)
    {
        case 1:
            break; //If it is January do nothing
        case 2:
            total = D31; //If it is February adds the days of January
            break;
        case 3: 
            total = D31 + D28; //If it is March adds the days of January and February
            break;
        case 4:
            total = (D31 * 2) + D28; //If it is April adds the days of January, February and March
            break;
        case 5:
            total = (D31 * 2) + D30 + D28; //If it is May adds the days of January, February, March and April
            break;
        case 6:
            total = (D31 * 3) + D30 + D28; //If it is June adds the days of January, February, March, April and May
            break;
        case 7:
            total = (D31 * 3) + (D30 * 2) + D28; //If it is July adds the days of January, February, March,
            break;                               //April, May and June
        case 8:
            total = (D31 * 4) + (D30 * 2)+ D28; //If it is August adds the days of January, February, March,
            break;                              //April, May, June and July
        case 9:
            total = (D31 * 5) + (D30 * 2)+ D28; //If it is September adds the days of January, February, March,
            break;                              //April, May, June, July and August
        case 10:
            total = (D31 * 5) + (D30 * 3)+ D28; //If it is October adds the days of January, February, March,
            break;                              //April, May, June, July, August and September
        case 11:
            total = (D31 * 6) + (D30 * 3)+ D28; //If it is November adds the days of January, February, March,
            break;                              //April, May, June, July, August, September and October 
        case 12:
            total = (D31 * 6) + (D30 * 4)+ D28; // If it is December adds the days of January, February, March,
            break;                              // April, May, June, July, August, September, October and November 
        default:
            printf("Error --> Wrong month\n"); //If the month is different to a month between 1/12 close the program 
            exit(EXIT_FAILURE);                //with an error
            break; 
    }

    total = total + day;

    printf("The number of the day since this year started is : %d", total); //Output with the total of the days that have
    printf("\n");                                                           //been passed since the start of the year

    exit(EXIT_SUCCESS);
}