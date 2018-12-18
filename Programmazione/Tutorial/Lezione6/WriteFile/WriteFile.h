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
*  Name : WriteFile.h                                                                                                                                *
*  Purpose : The purpose of this header is to store the function prototypes and costants of the program "WriteFile.c".                               *                         
*  Date : 18/12/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

// -- Macros --
#include <stdio.h>

// -- Constants --
#define MAXSTRING 1000
#define PATH "HelloFile.txt"

// -- Function Prototypes --
void get_string(char stringa[]); //Used to get the value of the string
void set_file(FILE *file, const char stringa[]); //Used to create and write a string into the file