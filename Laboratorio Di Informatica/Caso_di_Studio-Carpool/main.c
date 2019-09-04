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
		if(!readFile(ID_FILE_PATH, &id_drivers, sizeof(id_drivers), OFFSET_ID_DRIVER, SEEK_SET))
		{
			// The driver's ID has not been read
			flag = false;
		}
		if(!readFile(ID_FILE_PATH, &id_travels, sizeof(id_travels), OFFSET_ID_TRAVEL, SEEK_SET) && flag)
		{
			// The travel's ID has not been read
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
				if(addStruct(DRIVERS_FILE_PATH, TRAVELS_FILE_PATH, &id_drivers, DRIVER))
				{
					printf("\n\nThe driver has been added to the system");

					// Updating ID
					if(!updateID(ID_FILE_PATH, OFFSET_ID_DRIVER, &id_drivers))
					{
						printfError("\n\nAn error has occurred during the updating of the driver's ID");
						flag = false;
					}
				}
				else
				{
					printfError("\n\nAn error has occurred during the adding of the driver");
				}

				printf("\n\n");
				system("PAUSE");
				break;
			case edit_driver:
				// Editing driver
				if(editStruct(DRIVERS_FILE_PATH, TRAVELS_FILE_PATH, DRIVER))
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
				// Deleting driver
				if(deleteStruct(DRIVERS_FILE_PATH, TRAVELS_FILE_PATH, DRIVER))
				{
					printf("\n\nThe driver has been deleted to the system");
				}
				else
				{
					printfError("\n\nAn error has occurred during the deleting of the driver");
				}

				printf("\n\n");
				system("PAUSE");
				break;
			case show_all_drivers:
				// Showing drivers
				if(showAllStructs(DRIVERS_FILE_PATH, TRAVELS_FILE_PATH, DRIVER))
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
				// Adding Travel
				if(addStruct(DRIVERS_FILE_PATH, TRAVELS_FILE_PATH, &id_travels, TRAVEL))
				{
					printf("\n\nThe travel has been added to the system");

					// Updating ID
					if(!updateID(ID_FILE_PATH, OFFSET_ID_TRAVEL, &id_travels))
					{
						printfError("\n\nAn error has occurred during the updating of the travel's ID");
						flag = false;
					}
				}
				else
				{
					printfError("\n\nAn error has occurred during the adding of the travel");
				}

				printf("\n\n");
				system("PAUSE");
				break;
			case edit_travel:
				// Editing driver
				if(editStruct(DRIVERS_FILE_PATH, TRAVELS_FILE_PATH, TRAVEL))
				{
					printf("\nThe travel has been edited");
				}
				else
				{
					printfError("\n\nAn error has occurred during the editing of the travel");
				}

				printf("\n\n");
				system("PAUSE");
				break;
			case delete_travel:
				// Deleting travel
				if(deleteStruct(DRIVERS_FILE_PATH, TRAVELS_FILE_PATH, TRAVEL))
				{
					printf("\n\nThe travel has been deleted to the system");
				}
				else
				{
					printfError("\n\nAn error has occurred during the deleting of the travel");
				}

				printf("\n\n");
				system("PAUSE");
				break;
			case show_all_travels:
				// Showing travel
				if(showAllStructs(DRIVERS_FILE_PATH, TRAVELS_FILE_PATH, TRAVEL))
				{
					printf("\n\nThe travels have been read");
				}
				else
				{
					printfError("\n\nAn error has occurred during the reading of the travels");
				}

				printf("\n\n");
				system("PAUSE");
				break;
			case book_travel:
				break;
			case sort_driver:
				mergeSort(DRIVERS_FILE_PATH, 0, (getNumberRecord(DRIVERS_FILE_PATH, sizeof(Driver_t)) - 1));

				printf("\n\n");
				system("PAUSE");
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
	printf("\n|         %d          | Show All Drivers |", show_all_drivers);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |    Add Travel    |", add_travel);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |    Edit Travel   |", edit_travel);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |   Delete Travel  |", delete_travel);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          | Show All Travels |", show_all_travels);
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
