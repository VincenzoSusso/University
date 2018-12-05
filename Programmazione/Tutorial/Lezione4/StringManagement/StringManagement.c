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
*  Name : StringManagement.c                                                                                                                         *
*  Purpose : The purpose of this program is to take as input a string (max 100 characters) and the program should give informations about the        *
*            size of the string, the number of alphabetic character, the number of capital letters, the number of lowercase letters,                 *
*            the number of digits, the number of punctuation.                                                                                        *
*  Date : 05/12/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Used to manage the string
#include <ctype.h> //Used to manage the single character

#define MAX 100 //Max size of the string

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
        "*  Name : StringManagement.c                                                                            *\n"
        "*  Purpose : The purpose of this program is to take as input a string (max 100 characters) and the      *\n"
        "*            program should give informations about the size of the string, the number of alphabetic    *\n"
        "*            character, the number of capital letters, the number of lowercase letters, the number      *\n"
        "*            of digits, the number of punctuation.                                                      *\n"
        "*  Date : 05/12/2018                                                                                    *\n"
        "********************************************************************************************************/\n\n"
    );
    //--------------------------------------

    //--------------------------------------
    printf("StringManagement\n\n");
    //--------------------------------------

    //--------------------------------------
    char string[MAX] = ""; //Used to take the string
    int alphabetic = 0, capital = 0, lowercase = 0, digit = 0, punctuation = 0; /* 1 --> Used to count alphabetic characters
                                                                                   2 --> Used to count capital characters
                                                                                   3 --> Used to count lowercase characters 
                                                                                   4 --> Used to count numbers characters
                                                                                   5 --> Used to count punctuation characters */

    printf("Insert a string (Max %d character without space): ", MAX); //Used to take the input
    scanf("%s", string);

    for(int i = 0; i < strlen(string); i++) //Used to scan the string
    {
        if(isalpha(string[i])) //Check if the character is an alfabethic character
        {
            alphabetic++; 

            if(isupper(string[i])) //Check if the character is a capital character
            {
                capital++;
            }
            else //Check if the character is a lowercase caracter
            {
                lowercase++;
            }
        }
        else if(isdigit(string[i])) //Check if the character is a digit
        {
            digit++;
        }
        else //Check if the character is a punctuation
        {
            punctuation++;
        }
    }

    //Output
    printf("The string is %s and its length is %d.\n", string, strlen(string));
    printf("The string has %d alphabetic characters.\n", alphabetic);
    printf("The string has %d capital characters.\n", capital);
    printf("The string has %d lowercase characters.\n", lowercase);
    printf("The string has %d digit characters.\n", digit);
    printf("The string has %d punctuation characters.\n", punctuation);

    exit(EXIT_SUCCESS);
}