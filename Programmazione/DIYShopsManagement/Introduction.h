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
*  Name : Introduction.h                                                                                                                             *
*  Purpose : The purpose of this header is to manage the introduction of the program "DIYShopsManagement.c".                                         *                     
*  Date : 09/01/2019                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

// -- Libraries --
#include <stdio.h>

// -- Functions Prototypes --
void introduction(void); //Used to print the introduction

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
        "*  Name : DIYShopsManagement.c                                                                          *\n"
        "*  Purpose : The purpose of this program is to manage several DIY shops that everyday refound themself  *\n"
        "*            requiring to a warehouse different materials. Every request is formed by: the id of the    *\n"
        "*            shop, the number of material required, the id of the material, a description of the        *\n"
        "*            material the number of material required. The warehouse manage the material storing using  *\n"
        "*            a table formed by: the id of the materials, the number of the materials and costs per unit.*\n"
        "*            The program should manage every request of the DIY shops and print the total cost of       *\n"
        "*            materials.                                                                                 *\n"
        "*  Date : 09/01/2019                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("DIYShopsManagement\n\n");
    //--------------------------------------
}