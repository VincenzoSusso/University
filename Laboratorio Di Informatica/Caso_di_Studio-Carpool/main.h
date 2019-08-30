/*
	LABORATORIO DI INFORMATICA - Caso di Studio Carpooling
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

// -- Libraries --
#include <stdio.h>
#include <stdlib.h>

#include "Carpool.h"

// -- Constant --
#define DRIVERS_FILE_PATH "../Files/Drivers.dat"
#define TRAVELS_FILE_PATH "../Files/Travels.dat"
#define ID_FILE_PATH "../Files/ID.dat" // This file is used in order to generate unique ID for drivers and for travels

#define OFFSET_ID_DRIVER 0
#define OFFSET_ID_TRAVEL 1

#define MAX_LENGHT_CHOOSE_INPUT 3

// -- User-Defined types --
typedef enum
{
	add_driver,
	edit_driver,
	delete_driver,
	show_all_driver,
	add_travel,
	edit_travel,
	delete_travel,
	show_all_travel,
	book_travel,
	sort_driver,
	sort_travel,
	exit_menu,
	not_valid_choice
} Menu_choice_t;

// -- Procedure & Functions Prototypes --
void showMenu(void);
bool setChoiceMenu(Menu_choice_t *menu_choice); // Return true if the input is valid
