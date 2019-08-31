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
#include "main.h"

// -- Main --
int main(void)
{
	bool flag = true; // This flag is used in order to repeat the do-while cycle
	Menu_choice_t menu_choice = not_valid_choice;

	int id_drivers = 0;
	int id_travels = 0;

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
	if(!isValidFile(ID_FILE_PATH))
	{
		printfError("\nAn error has occured during the opening of the ID's file");
		flag = false;
	}

	if(flag)
	{
		if(!readFile(ID_FILE_PATH, &id_drivers, sizeof(id_drivers), OFFSET_ID_DRIVER, SEEK_SET) && !readFile(ID_FILE_PATH, &id_travels, sizeof(id_travels), OFFSET_ID_TRAVEL, SEEK_SET))
		{
			// The IDs have not been read
			flag = false;
		}

	}

	while(flag)
	{
		// Reset variable
		menu_choice = not_valid_choice;

		showMenu();

		// Get input
		setNumberInput((int *) &menu_choice, add_driver, exit_menu, MENU_CHOICHE_PRINTF_VALUE_INPUT, MENU_CHOICHE_PRINTF_VALUE_ERROR);

		switch(menu_choice)
		{
			case add_driver:
				// Adding Driver
				if(addDriver(DRIVERS_FILE_PATH, &id_drivers))
				{
					printf("\n\nThe driver has been added to the system");
				}
				else
				{
					printfError("\n\nAn error has occurred during the adding of the driver");
				}

				// Updating ID
				if(!updateID(ID_FILE_PATH, OFFSET_ID_DRIVER, &id_drivers))
				{
					printfError("\n\nAn error has occurred during the updating of the ID's driver");
					flag = false;
				}

				printf("\n\n");
				system("PAUSE");
				break;
			case edit_driver:
				// Showing drivers
				if(!showAllDrivers(DRIVERS_FILE_PATH))
				{
					printfError("\n\nAn error has occurred during the reading of the drivers");
				}

				// Editing driver
				if(editDriver(DRIVERS_FILE_PATH))
				{
					printf("\nThe driver has been edited");
				}
				else
				{
					printfError("\n\nAn error has occurred during the editing of the driver");
				}

				printf("\n\n");
				system("PAUSE");
				break;
			case delete_driver:
				// Showing drivers
				if(!showAllDrivers(DRIVERS_FILE_PATH))
				{
					printfError("\n\nAn error has occurred during the reading of the drivers");
				}

				// Deleting driver
				if(deleteDriver(DRIVERS_FILE_PATH))
				{
					printf("\n\nThe driver has been deleted to the system");
				}
				else
				{
					printfError("\n\nAn error has occurred during the deleting of the drivers");
				}

				printf("\n\n");
				system("PAUSE");
				break;
			case show_all_driver:
				// Showing drivers
				if(showAllDrivers(DRIVERS_FILE_PATH))
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
	}

	printf("\n\n");
	system("PAUSE");
    exit(EXIT_SUCCESS);
}

void showMenu(void)
{
	printf("\n\nMenu':");
	printf("\n+--------------------+------------------+");
	printf("\n|  Number of Choice  |      Option      |");
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |    Add Driver    |", add_driver);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |    Edit Driver   |", edit_driver);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |   Delete Driver  |", delete_driver);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          | Show All Drivers |", show_all_driver);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |    Add Travel    |", add_travel);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |    Edit Travel   |", edit_travel);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |   Delete Travel  |", delete_travel);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          | Show All Travels |", show_all_travel);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |   Book a Travel  |", book_travel);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |    Sort Drivers  |", sort_driver);
	printf("\n+--------------------+------------------+");
	printf("\n|        %d          |    Sort Travels  |", sort_travel);
	printf("\n+--------------------+------------------+");
	printf("\n|        %d          |       Exit       |", exit_menu);
	printf("\n+--------------------+------------------+");
}
