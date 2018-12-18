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
*  Name : WriteFile.c                                                                                                                                *
*  Purpose : The purpose of this program is to create and write a string into a file called "HelloFile.txt"                                          *                         
*  Date : 18/12/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

// -- Macros --
#include <stdlib.h>
#include <stdio.h>
#include "WriteFile.h"
#include "Introduction.h"

// -- Main --
int main(void)
{
    char string[MAXSTRING] = ""; // Used to store the string that the user want to store inside the file 
    FILE *file; // Used to point to the file that the user want to create/edit

    introduction(); //Used to print the introduction

    get_string(string); //Used to get the value of the string
    set_file(file, string); //Used to create and write a string into the file

    exit(EXIT_SUCCESS);
}


// -- Functions --
void get_string(char string[]) //Used to get the value of the string
{
    printf("Insert a string that you want to add to the file: ");
    scanf("%[^\n]s", string);
}

void set_file(FILE *file, const char string[]) //Used to create and write a string into the file
{
    file = fopen(PATH, "w"); //Create or open the file "HelloFile.txt"
    if(file == NULL) //Error with the file "HelloFile.txt"
    {
        printf("\nError while using the file.\n");
        exit(EXIT_FAILURE);
    }
    
    fprintf(file, "%s", string); //Write the string into the file
    fflush(file); //Clean the buffer
    fclose(file); //Close the file

    printf("\nThe file \"%s\" has been written with the string: %s\n", PATH, string);
}