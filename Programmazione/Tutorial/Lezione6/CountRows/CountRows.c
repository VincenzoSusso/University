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
*  Purpose : The purpose of this header is to manage the introduction of the program "WriteFile.c".                                                  *                     
*  Date : 18/12/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

// -- Macros --
#include <stdlib.h>
#include <stdio.h>
#include "CountRows.h"
#include "Introduction.h"

// -- Main --
int main(void)
{
    int rows = 0; //Used to store the number of rows
    char path[MAXSTRING] = ""; //Used to store the path of the file
    
    introduction(); //Used to print the introduction

    read_path(path); //Used to read the path of the file
    rows = count_rows(path);

    printf("\n\nThe file \"%s\" has %d rows\n", path, rows);

    exit(EXIT_SUCCESS);
}

//Functions
void read_path(char path[]) //Used to read the path of the file
{
    printf("Insert the path of the file that you want to count the rows: ");
    scanf("%[^\n]s", path);
}

int count_rows(const char path[]) //Used to count the rows of the file
{
    int rows = 0; //Used to store the number of rows of the file
    char character = ' '; //Used to check single characters of the file
    FILE *file; //Used to manage the file

    file = fopen(path, "r"); //Open the file in read mode
    if(file == NULL)
    {
        printf("\nError while using the file.\n");
        exit(EXIT_FAILURE);
    }

    printf("\nThe file \"%s\" contains: \n", path);
    printf("\n* * * * * * * - - - - - - - START - - - - - - - * * * * * * *\n");
    for(character = fgetc(file); character != EOF; character = fgetc(file)) //Get character and if the character is not EOF continue to repeat the cicle
    {
        printf("%c", character); 
        if(character == '\n') //If the character is '\n' adds one to rows
        {
            rows++;
        }
    }
    printf("\n* * * * * * * - - - - - - - END - - - - - - - * * * * * * *");

    fclose(file); //Close the file

    return rows;
}