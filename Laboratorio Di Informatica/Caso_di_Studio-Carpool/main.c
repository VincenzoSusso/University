/*
	LABORATORIO DI INFORMATICA - Caso di Studio Carpooling
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
    P.S -- For a better visualization of the output it is preferable to put the window in full screen  --
*/

// -- Libraries --
#include <stdio.h>
#include <stdlib.h>

#include "Carpool.h"
#include "File.h"

// -- Constant --
//#define ID_FILE_PATH "../Files/ID.dat" // This file is used in order to generate unique ID for drivers
#define DRIVERS_FILE_PATH "../Files/Drivers.dat"
#define TRAVELS_FILE_PATH "../Files/Travels.dat"

#define MAX_LENGHT_CHOOSE_INPUT 3

// -- Main --
int main(void)
{
	bool flag = true; // This flag is used in order to repeat the do-while cycle
	char choose_input[MAX_LENGHT_CHOOSE_INPUT] = NULL_STRING;
	Menu_choose_t choose_menu = not_valid_choice;
	short operation = false; // This flag is used in order to comunicate to the user if an operation has failed
	unsigned short i = 0; // Used to manage the cycle
	Driver_t driver;

	initializeCMD();

	if(!isValidFile(DRIVERS_FILE_PATH))
	{
		printfError("\nAn error has occured during the opening of the driver's file!");
		flag = false;
	}
	if(!isValidFile(TRAVELS_FILE_PATH))
	{
		printfError("\nAn error has occured during the opening of the travel's file!");
		flag = false;
	}
	/*if(!isValidFile(ID_FILE_PATH))
	{
		printfError("\nAn error has occured during the opening of the ID's file");
		flag = false;
	}*/

	while(flag)
	{
		// Reset variable
		operation = false;
		strcpy(choose_input, NULL_STRING);
		choose_menu = not_valid_choice;
		i = 0;
		resetDriver(&driver);
		// End reset variable

		showMenu();

		printf("\n\nEnter a choice: ");
		scanf("%2[^\n]s", choose_input);
		addNullCharacterString(choose_input);
		clearBuffer();
		if(isdigit(*choose_input))
		{
			choose_menu = (Menu_choose_t) strtol(choose_input, NULL, 10);
		}
		else
		{
			printfError("\n\nThe choice that you have made is not valid!");
			printf("\n\n");
			system("PAUSE");
		}

		switch(choose_menu)
		{
			case add_driver:
				addDriver(&driver);
				operation = (short) writeFile(DRIVERS_FILE_PATH, &driver, sizeof(driver));
				if(operation)
				{
					printf("\n\nThe driver has been added to the system");
				}
				else
				{
					printfError("\n\nAn error has occurred during the adding of the driver");
				}
				printf("\n\n");
				system("PAUSE");
				break;
			case edit_driver:
				break;
			case delete_driver:
				break;
			case show_all_driver:
				i = 0;
				printf("\n+----+--------------+---------------+-------------------------------+--------------+----------------+----------+--------+---------------+---------------+-------------+");
				printf("\n| ID |     Name     |    Surname    |             Email             |   Password   |  Phone Number  | Birthday | Gender | Drv. Capacity | Cmf. Capacity | Avg. Rating |");
				printf("\n+----+--------------+---------------+-------------------------------+--------------+----------------+----------+--------+---------------+---------------+-------------+");
				do
				{
					operation = (short) readFile(DRIVERS_FILE_PATH, &driver, sizeof(driver), i);
					if(operation == done)
					{
						readDriver(&driver);
					}
					i++;
				}
				while(operation == done);
				if(operation)
				{
					printf("\n\nThe drivers have been read");
				}
				else
				{
					printfError("\n\nAn error has occurred during the reading of the drivers");
				}
				printf("\n\n");
				system("PAUSE");
				break;
			case add_travel:
				break;
			case edit_travel:
				break;
			case delete_travel:
				break;
			case show_all_travel:
				break;
			case book_travel:
				break;
			case sort_driver:
				break;
			case sort_travel:
				break;
			case exit_menu:
				flag = false;
				break;
			default:
				break;
		}



		/*
		int a = readDriverFile(DRIVERS_FILE_PATH);
		printf("\n%d\n", a);*/
	}

	printf("\n\n");
	system("PAUSE");
    exit(EXIT_SUCCESS);
}
