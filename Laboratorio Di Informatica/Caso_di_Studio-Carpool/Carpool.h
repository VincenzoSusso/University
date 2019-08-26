/*
	LABORATORIO DI INFORMATICA - Caso di Studio Carpooling
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

// -- Libraries --
#include <stdbool.h>
#include <stdio.h>
#include "Date.h"
#include "Utilities.h"

// -- Constant --
#define MAX_LENGHT_STRINGS 24
#define MIN_LENGHT_STRINGS 2

#define MAX_LENGHT_EMAIL 60

#define MIN_LENGHT_PHONE_NUMBER 8 // For more information, please visit here: https://stackoverflow.com/questions/14894899/what-is-the-minimum-length-of-a-valid-international-phone-number
#define MAX_LENGHT_PHONE_NUMBER 18 // This constant was obtained by Country code lenght + space + subscriber number lenght + null character

#define MAX_LENGHT_DATE_STRING 11
#define MAX_LENGHT_RATING_STRING 4

#define DRIVER_NAME_PRINTF_VALUE "driver's name"
#define DRIVER_SURNAME_PRINTF_VALUE "driver's surname"
#define DRIVER_BIRTHDAY_PRINTF_VALUE "driver's birthday"
#define DRIVER_DRIVING_CAPACITY_PRINTF_VALUE "driver's driving capacity"
#define DRIVER_COMFORT_CAPACITY_PRINTF_VALUE "driver's comfort capacity"

// Thoose constant are used in order to assign a literal output of the gender
#define LENGHT_ARRAY_GENDER 7 // Lenght of the word "Custom" + null character
#define READ_GENDER_MALE "Male"
#define READ_GENDER_FEMALE "Female"
#define READ_GENDER_CUSTOM "Custom"

// Those constant are used in order to assign a graphic output of the rating
#define LENGHT_ARRAY_RATING 6 // Five star + null character
#define STAR_CHARACTER "*"

// -- User-Defined types --
typedef enum {one_star = 1, two_star, three_star, four_star, five_star} Rating_t;

typedef enum {male, female, custom} Gender_t;

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
} Menu_choose_t;

typedef struct
{
	unsigned int id;
	char name[MAX_LENGHT_STRINGS];
	char surname[MAX_LENGHT_STRINGS];
	char email[MAX_LENGHT_EMAIL];
	char password[MAX_LENGHT_STRINGS];
	char phone_number[MAX_LENGHT_PHONE_NUMBER];
	Date_t birthday;
	Gender_t gender;
	Rating_t driving_capacity;
	Rating_t comfort_capacity;
	Rating_t average_rating;
} Driver_t;

// -- Procedure & Functions Prototypes --
void showMenu(void);
const char *readGender(const Gender_t *gender);
const char *readRating(const Rating_t *rating);
void setWord(char word[], const char printf_value[]); // The procedure set a valid value to the word passed by pointer
void setEmail(char email[]);
void setNumberPhone(char number_phone[]);
void setDate(Date_t *date, const char printf_value[]); // The procedure set a valid value to the date passed by pointer
void setRating(Rating_t *rating, char printf_value[]); // The procedure set a valid value to the rating passed by pointer
void resetDriver(Driver_t *driver);
void addDriver(Driver_t *driver);
void readDriver(const Driver_t *driver);
/*void readAllDrivers(char path[]);*/
