/*
	LABORATORIO DI INFORMATICA - Caso di Studio Carpooling
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

/**
 * @file main.h
 * @author Vincenzo Susso
 * @date 2019 Sep 10
 * @version 1.0
 * @brief This library was developed in order to manage menu and files.
 *
 * This library is used to define files that are used to store drivers, travels, ratings and IDs.
 * This library also provide procedure to show menu and an introduction during the starting of the program.
 */

// -- Libraries --
#include <stdio.h>
#include <stdlib.h>

#include "CUnit/Basic.h"
#include "Carpool.h"

// -- Constant --
/**
 * @def DRIVERS_FILE_PATH
 * This string indicates the relative path of the file that will store the drivers.
 */
#define DRIVERS_FILE_PATH "../Files/Drivers.dat"


/**
 * @def TRAVELS_FILE_PATH
 * This string indicates the relative path of the file that will store the travels.
 */
#define TRAVELS_FILE_PATH "../Files/Travels.dat"


/**
 * @def RATINGS_FILE_PATH
 * This string indicates the relative path of the file that will store the ratings.
 */
#define RATINGS_FILE_PATH "../Files/Ratings.dat"


/**
 * @def DRIVERS_FILE_PATH
 * This string indicates the relative path of the file that will store the IDs for drivers and travels.
 */
#define ID_FILE_PATH "../Files/ID.dat"

// -- User-Defined types --
/**
 * @enum Menu_choice_t
 * This user-defined type is used in order to define the option of the menu, this user-defined type was also created in
 * order to improve the readability.
 */
typedef enum
{
	add_driver, /**< This member allow the user to add a driver to the system */
	edit_driver, /**< This member allow the user to edit a member of a driver*/
	delete_driver, /**< This member allow the user to delete a driver to the system */
	show_all_drivers, /**< This member allow the user to show all the drivers */
	add_travel, /**< This member allow the user to add a travel to the system */
	edit_travel, /**< This member allow the user to edit a member of a travel*/
	delete_travel, /**< This member allow the user to delete a travel to the system */
	show_all_travels, /**< This member allow the user to show all the travels */
	book_travel, /**< This member allow the user to book a travel */
	evaluate_driver, /**< This member allow the user to evaluate a the driver */
	sort_drivers, /**< This member allow the user to sort all the drivers */
	sort_travels, /**< This member allow the user to sort all the travels */
	exit_menu, /**< This member allow the user to exit from the program */
	not_valid_choice /**< This member is used to set a not valid choice to the menu option */
} Menu_choice_t;

// -- Procedure & Functions Prototypes --
/**
 * @fn introduction(void)
 * This procedure is used in order to show an introduction during the starting of the program.
 */
void introduction(void);


/**
 * @fn showMenu(void)
 * This procedure is used to show the menu to the user.
 */
void showMenu(void);
