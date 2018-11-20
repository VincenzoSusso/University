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
*  Purpose : The purpose of this program is to determine the max between two integers value                                                          *
*  Date : 20/11/2018                                                                                                                                 *
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
        "*  Name : Max.c                                                                                         *\n"
        "*  Purpose : The purpose of this program is to determine the max between two integers value             *\n"
        "*  Date : 20/11/2018                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("Max\n\n");
    //--------------------------------------

    //--------------------------------------
    int first_num = 0, second_num = 0;

    printf("Insert the first number: ");
    scanf("%d", &first_num);

    printf("Insert the second number: ");
    scanf("%d", &second_num);

    if(first_num >= second_num) //Compare two number
    {
        if(first_num > second_num) //If the first one is bigger than the second one
        {
            printf("The first one number (%d) is bigger than the second one (%d).", first_num, second_num);
        }
        else //If the value of the first one is the same value of the second one
        {
            printf("Those two number are the same, indeed the fist one is %d and the second one is %d.", first_num, second_num);
        }
    }
    else //If the second one is bigger than the first one
    {
        printf("The second one number (%d) is bigger than the first one (%d).", second_num, first_num);
    }

    printf("\n");

    exit(EXIT_SUCCESS);
}