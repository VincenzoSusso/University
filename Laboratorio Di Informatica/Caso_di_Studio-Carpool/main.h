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
#define RATINGS_FILE_PATH "../Files/Ratings.dat"
#define ID_FILE_PATH "../Files/ID.dat" // This file is used in order to manage unique ID for drivers and for travel

// -- User-Defined types --
typedef enum
{
	add_driver,
	edit_driver,
	delete_driver,
	show_all_drivers,
	add_travel,
	edit_travel,
	delete_travel,
	show_all_travels,
	book_travel,
	evaluate_driver,
	sort_drivers,
	sort_travels,
	exit_menu,
	not_valid_choice
} Menu_choice_t;

// -- Procedure & Functions Prototypes --
void introduction(void);
void showMenu(void);
