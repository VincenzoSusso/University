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
*  Name : Area.c                                                                                                                                     *
*  Purpose : The purpose of this program is to calculate the area of the rectangle or the area of the triangle by giving the possibility to the      *
*            user to choose what to do.                                                                                                              *
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
        "*  Name : Area.c                                                                                        *\n"
        "*  Purpose : The purpose of this program is to calculate the area of the rectangle or the area of the   *\n"
        "*            the triangle by giving the possibility to the user to choose what to do.                   *\n"
        "*  Date : 20/11/2018                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("Area\n\n");
    //--------------------------------------

    //--------------------------------------
    float base = 0, height = 0, area = 0; 
    char choose = 'R';

    printf("R or r --> To calculate the area of the rectangle"); //Menu
    printf("\nT or t --> To calculate the area of the triangle");

    printf("\n\nInsert what you want to do: "); //INput of the choose
    scanf("%c", &choose);

    if(choose == 'R' || choose == 'r') //Rectangle
    {
        printf("Insert the base of the rectangle: "); //Input base of the rectangle
        scanf("%f", &base);

        printf("Insert the height of the rectangle: "); //Input height of the rectangle
        scanf("%f", &height);

        area = base * height; //Calculate the area of the rectangle
        printf("The area of the rectangle is: %f",area);
    }
    else if (choose == 'T' || choose == 't') //Triangle
    {
        printf("Insert the base of the triangle: "); //Input base of the triangle
        scanf("%f", &base);

        printf("Insert the height of the triangle: "); //Input height of the triangle
        scanf("%f", &height);

        area = (base * height) / 2;
        printf("The area of the triangle is: %f",area);
    }
    else
    {
        printf("%c is not a correct letter", choose);
    }

    printf("\n");

    exit(EXIT_SUCCESS);
}