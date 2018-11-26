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
*  Name : HourlyWage.c                                                                                                                               *
*  Purpose : The purpose of this program is to calculate the hourly wage of number of dependent(input).                                              *
*  Date : 26/11/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

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
        "*  Name : HourlyWage.c                                                                                  *\n"
        "*  Purpose : The purpose of this program is to calculate the hourly wage of number of dependent(input). *\n"
        "*  Date : 26/11/2018                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("HourlyWage\n");
    //--------------------------------------

    //--------------------------------------
    int n_dependent = 0, hourworked = 0; /* 1 --> Used to take in input the number of dependents
                                            2 --> Used to take in input the hour that the dependent has worked */

    float wage = 0, hourlywage = 0; /* 1 --> Used to calculate the wage of a dependent
                                       2 --> Used to take in inpunt the hourlywage of the dependent */

    printf("\nInsert the number of dependents: "); //Used to take the number of dependents
    scanf("%d", &n_dependent);

    for(int i = 0; i < n_dependent; i++)
    {
        printf("\nInsert the hours that the %d^ dependent has worked: ", i + 1); //Used to take the hour that the dependent has worked
        scanf("%d", &hourworked);

        printf("Insert the hourly wage of the %d^ dependent: ", i + 1); //Used to take the hourly wage tthe dependent
        scanf("%f", &hourlywage);

        wage = hourworked * hourlywage; //Used to calculate the wage of the dipendent

        printf("The wage of the %d^ dependent is: %.2f\n", i+1, wage);
    }

    exit(EXIT_SUCCESS);
}