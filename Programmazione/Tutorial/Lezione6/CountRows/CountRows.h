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
*  Name : CountRows.h                                                                                                                                *
*  Purpose : The purpose of this header is to store function prototypes of the program "CountRows.c".                                                *                         
*  Date : 18/12/2018                                                                                                                                 *
*                                                                                                                                                    *
*****************************************************************************************************************************************************/

// -- Macros --
#include <stdio.h>

// -- Constants --
#define MAXSTRING 1000

// -- Functions Prototypes --
void read_path(char path[]); //Used to read the path of the file
int count_rows(const char path[]); //Used to count the rows of the file