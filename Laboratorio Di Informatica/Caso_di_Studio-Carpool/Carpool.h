/*
	LABORATORIO DI INFORMATICA - Caso di Studio Carpooling
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

// -- Libraries --
#ifndef Carpool_h
	#define Carpool_h

#include <stdbool.h>
#include <stdio.h>
#include "Date.h"
#include "Utilities.h"
#include "File.h"

// -- Constant --
#define MAX_LENGHT_STRINGS 24
#define MIN_LENGHT_STRINGS 2

#define MAX_LENGHT_EMAIL 60

#define MIN_LENGHT_PASSWORD 8

#define MIN_LENGHT_PHONE_NUMBER 8 // For more information, please visit here: https://stackoverflow.com/questions/14894899/what-is-the-minimum-length-of-a-valid-international-phone-number
#define MAX_LENGHT_PHONE_NUMBER 18 // This constant was obtained by Country code lenght + space + subscriber number lenght + null character

#define MAX_LENGHT_DATE_STRING_INPUT 11
#define MAX_LENGHT_GENDER_STRING_INPUT 4
#define MAX_LENGHT_RATING_STRING_INPUT 4
#define MAX_LENGHT_ID_STRING_INPUT 8

#define INDEX_ID_NOT_FOUND -1 // This constant is used to check if the index of the ID has not been found

#define DRIVER_NAME_PRINTF_VALUE "driver's name"
#define DRIVER_SURNAME_PRINTF_VALUE "driver's surname"
#define DRIVER_BIRTHDAY_PRINTF_VALUE "driver's birthday"
#define DRIVER_DRIVING_CAPACITY_PRINTF_VALUE "driver's driving capacity"
#define DRIVER_COMFORT_CAPACITY_PRINTF_VALUE "driver's comfort capacity"

// Thoose constant are used in order to assign a literal output of the gender
#define LENGHT_ARRAY_GENDER 3
#define READ_GENDER_MALE "Male"
#define READ_GENDER_FEMALE "Female"
#define READ_GENDER_CUSTOM "Custom"

// Those constant are used in order to assign a graphic output of the rating
#define LENGHT_ARRAY_RATING 5
#define READ_RATING_ONE_STAR "*"
#define READ_RATING_TWO_STAR "**"
#define READ_RATING_THREE_STAR "***"
#define READ_RATING_FOUR_STAR "****"
#define READ_RATING_FIVE_STAR "*****"

// -- User-Defined types --
typedef enum {one_star = 1, two_star, three_star, four_star, five_star} Rating_t;

typedef enum {male, female, custom} Gender_t;

typedef enum {id = -1, name, surname, email, password, phone_number, birthday, gender, driving_capacity,
			 comfort_capacity, average_rate, deleted} Driver_members_t;

typedef struct
{
	unsigned long id;
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
	bool deleted; // True mean that the record is deleted
} Driver_t;

// -- Procedure & Functions Prototypes --

// For more information about those two function, please visit here: https://stackoverflow.com/questions/1496313/returning-c-string-from-a-function
const char *readGender(const Gender_t *gender);
const char *readRating(const Rating_t *rating);

void setWord(char word[], const char printf_value[]); // The procedure set a valid value to the word passed by pointer
void setEmail(char email[]);
void setPassword(char password[]);
void setNumberPhone(char number_phone[]);
void setDate(Date_t *date, const char printf_value[]); // The procedure set a valid value to the date passed by pointer
void setGender(Gender_t *gender);
void setRating(Rating_t *rating, char printf_value[]); // The procedure set a valid value to the rating passed by pointer

void resetDriver(Driver_t *driver);
void setDriver(Driver_t *driver, unsigned long id);
void readDriver(const Driver_t *driver);
bool isIdDriverEqual(const Driver_t *driver, const unsigned long *id);



// Those function uses files
File_status_t addDriver(char path[], const unsigned long *id_driver); // This function returns true if the driver has been added to the system
//File_status_t editDriver(char path[], const unsigned long *id_driver);
File_status_t deleteDriver(char path[]); // This function returns true if the driver has been deleted to the system
File_status_t showAllDrivers(char path[]); // This function returns true if has read all records of the file, "path" is the path of the file that stores the drivers


File_status_t updateID(char path[], const long int offset, unsigned long *id); // This function returns true if the ID is update
long int getIndexDriver(char path[], const unsigned long *id);
#endif
