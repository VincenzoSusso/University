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
*  Purpose : The purpose of this header is to manage the introduction of the program "ExamsManagement.c".                                             *                     
*  Date : 04/01/2019                                                                                                                                 *
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
        "*  Name : ExamsManagement.c                                                                             *\n"
        "*  Purpose : The purpose of this program is to manage the exams of two degree courses (Computer Science *\n"
        "*            / Digital Comunication). To each candidates the program should store informations about    *\n"
        "*            name, surname, course, the grade of the exam and the year when the candidate has done the  *\n"
        "*            exam than the program should sort the students using the grade. The program should store   *\n"
        "*            informations into a file and should give the possibility to the user to search the         *\n"
        "*            candidates that has get a grade specified in input or to search the candidates that has    *\n"
        "*            get a grade lower than a grade specified in input.                                         *\n"
        "*  Date : 04/01/2019                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("ExamsManagement\n\n");
    //--------------------------------------
}