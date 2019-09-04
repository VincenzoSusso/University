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
#include <limits.h>
#include "Date.h"
#include "Utilities.h"
#include "File.h"

// -- Constant --
#define DRIVER true
#define TRAVEL false

#define MAX_LENGHT_STRINGS 20
#define MIN_LENGHT_STRINGS 2

#define MAX_LENGHT_EMAIL 40

#define MIN_LENGHT_PASSWORD 8

#define MIN_LENGHT_PHONE_NUMBER 8 // For more information, please visit here: https://stackoverflow.com/questions/14894899/what-is-the-minimum-length-of-a-valid-international-phone-number
#define MAX_LENGHT_PHONE_NUMBER 18 // This constant was obtained by Country code lenght + space + subscriber number lenght + null character

#define MAX_LENGHT_ADDITIONAL_NOTES 40

#define MAX_LENGHT_NUMBER_INPUT 8

#define MIN_YEAR_BIRTHDAY 1900
#define MAX_YEAR_BIRTHDAY 2001

#define MIN_YEAR_TRAVEL 2010
#define MAX_YEAR_TRAVEL 2050

#define MIN_PRICE 0.01
#define MAX_PRICE 9999.99
#define DOLLAR_CHARACTER "$"

#define MAX_NUMBER_TOTAL_SEATS 9 // For more information, please visit here: https://www.moneymaxim.co.uk/faq/car-hire/maximum-occupancy
#define MIN_NUMBER_TOTAL_SEATS 2

#define MAX_NUMBER_FREE_SEATS 8 // Max Total seats - driver's seat
#define MIN_NUMBER_FREE_SEATS 0

#define NUMBER_OF_RATING 2 // Used to calculate the arithmetic mean

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

// Thoose constant are used as printf_value of the procedure setWord()
#define DRIVER_NAME_PRINTF_VALUE "driver's name"
#define DRIVER_SURNAME_PRINTF_VALUE "driver's surname"

#define TRAVEL_DEPARTURE_DESTINATION_PRINTF_VALUE "travel's departure destination"
#define TRAVEL_ARRIVAL_DESTINATION_PRINTF_VALUE "travel's arrival destination"

// Thoose constant are used ad printf_value of the procedure setDate()
#define DRIVER_BIRTHDAY_PRINTF_VALUE "driver's birthday"
#define TRAVEL_DEPARTURE_DATE_PRINTF_VALUE "travel's departure date"

// Thoose constant are used ad printf_value of the procedure setTime()
#define TRAVEL_DEPARTURE_TIME_PRINTF_VALUE "travel's departure time"

// Thoose constant are used as printf_value of the procedure setNumberInput()
#define DRIVER_GENDER_PRINTF_VALUE_INPUT "Enter the driver's gender (Male = 0, Female = 1, Custom = 2): "
#define DRIVER_GENDER_PRINTF_VALUE_ERROR "The driver's gender that you have entered is not valid"

#define DRIVER_DRIVING_CAPACITY_PRINTF_VALUE_INPUT "Enter the driver's driving capacity (It should be between 1 and 5): "
#define DRIVER_DRIVING_CAPACITY_PRINTF_VALUE_ERROR "The driver's driving capacity that you have entered is not valid"

#define DRIVER_COMFORT_CAPACITY_PRINTF_VALUE_INPUT "Enter the driver's comfort capacity (It should be between 1 and 5): "
#define DRIVER_COMFORT_CAPACITY_PRINTF_VALUE_ERROR "The driver's driving capacity that you have entered is not valid"

#define DRIVER_ID_EDIT_PRINTF_VALUE_INPUT "Enter the ID of the driver that you want to edit: "
#define DRIVER_ID_EDIT_PRINTF_VALUE_ERROR "The ID of the driver that you want to edit is not valid"

#define MEMBER_PRINTF_VALUE_INPUT "Enter the number of member that you want to edit: "
#define MEMBER_PRINTF_VALUE_ERROR "The number of member that you have entered is not valid"

#define DRIVER_ID_DELETE_PRINTF_VALUE_INPUT "Enter the ID of the driver that you want to delete: "
#define DRIVER_ID_DELETE_PRINTF_VALUE_ERROR "The ID of the driver that you want to delete is not valid"

#define TRAVEL_DRIVER_ID_PRINTF_VALUE_INPUT "Enter the ID of the driver that will offer the travel: "
#define TRAVEL_DRIVER_ID_PRINTF_VALUE_ERROR "The ID of the driver that you have entered is not valid"

#define TRAVEL_ADDITIONAL_NOTES_PRINTF_VALUE_INPUT "Do you want to add additional notes to the travel (No = 0, Yes = 1): "
#define TRAVEL_ADDITIONAL_NOTES_PRINTF_VALUE_ERROR "The ID of the driver that you have entered is not valid"

#define TRAVEL_TOTAL_SEAT_INPUT "Enter the driver's veicle total number seats (the number should be between 2 and 9, and it must include the driver's seat): "
#define TRAVEL_TOTAL_SEAT_ERROR "The driver's veicle total number seats is not valid"

#define TRAVEL_FREE_SEAT_INPUT "Enter the number of free seats of the driver's veicle (the number should be between 1 and 8): "
#define TRAVEL_FREE_SEAT_ERROR "The number of free seats of the driver's veicle is not valid"

#define TRAVEL_ID_EDIT_PRINTF_VALUE_INPUT "Enter the ID of the travel that you want to edit: "
#define TRAVEL_ID_EDIT_PRINTF_VALUE_ERROR "The ID of the travel that you want to edit is not valid"

#define TRAVEL_ID_DELETE_PRINTF_VALUE_INPUT "Enter the ID of the travel that you want to delete: "
#define TRAVEL_ID_DELETE_PRINTF_VALUE_ERROR "The ID of the driver that you want to delete is not valid"

#define MERGE_TEMP_FILE_PATH "../Files/Temp.dat"

// -- User-Defined types --
typedef enum {one_star = 1, two_star, three_star, four_star, five_star} Rating_t;

typedef enum {male, female, custom} Gender_t;

typedef enum {id_driver = -1, name, surname, email, password, phone_number, birthday, gender, driving_capacity,
			 comfort_capacity, average_rating, deleted_driver} Driver_members_t;

typedef enum {id_travel = -2, id_driver_, departure_destination, arrival_destination, departure_date, departure_time,
			 total_seats, free_seats, price, additional_notes, deleted_travel} Travel_members_t;

typedef struct
{
	int id;
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
	bool deleted; // True mean that the driver is deleted
} Driver_t;

typedef struct
{
	int id;
	int id_driver;
	char departure_destination[MAX_LENGHT_STRINGS];
	char arrival_destination[MAX_LENGHT_STRINGS];
	char additional_notes[MAX_LENGHT_ADDITIONAL_NOTES];
	Date_t departure_date;
	Time_t departure_time;
	double price;
	unsigned short total_seats;
	unsigned short free_seats;
	bool deleted; // True mean that the travel is deleted
} Travel_t;

// -- Procedure & Functions Prototypes --

// For more information about those two function, please visit here: https://stackoverflow.com/questions/1496313/returning-c-string-from-a-function
const char *readGender(const Gender_t *gender);
const char *readRating(const Rating_t *rating);

void setWord(char word[], const char printf_value[]); // The procedure set a valid value to the word passed by pointer
void setEmail(char email[]);
void setPassword(char password[]);
void setNumberPhone(char number_phone[]);
void setAdditionalNotes(char additional_notes[]);
void setPrice(double *price);
void setNumberInput(int *input, const int min, const int max, const char printf_value_input[], const char printf_value_error[]);

void resetDriver(Driver_t *driver);
void setDriver(Driver_t *driver, const int *id);
void readDriver(const Driver_t *driver);
bool isIdDriverEqual(const Driver_t *driver, const int *id);
void showMemberDriver(void);

void resetTravel(Travel_t *travel);
void setTravel(Travel_t *travel, const int *id, const char path_file_travel[], const char path_file_driver[]);
void readTravel(const Travel_t *travel, const char path_driver_file[]);
bool isIdTravelEqual(const Travel_t *travel, const int *id);
void showMemberTravel(void);

// Those function uses files
File_status_t addStruct(const char path_file_driver[], const char path_file_travel[], const int *id, bool select_struct); // This function returns true if the struct has been added to the system
File_status_t editStruct(const char path_file_driver[], const char path_file_travel[], bool select_struct); // This function returns true if the struct has been edited
File_status_t deleteStruct(const char path_file_driver[], const char path_file_travel[], bool select_struct); // This function returns true if the struct has been deleted to the system
File_status_t showAllStructs(const char path_file_driver[], const char path_file_travel[], bool select_struct); // This function returns if it has read all records of the file

File_status_t updateID(const char path_file[], const long int offset, int *id); // This function returns true if the ID is update

// This function return the index of the ID, the ID is entered by the user using keyboard
long int getIndexUser(const char path_file_driver[], const char path_file_travel[], const char printf_value_input[], const char printf_value_error[], bool select_struct);

// This function return the index of the ID, the ID is passed by pointer
long int getIndex(const char path_file[], const int *id, bool select_struct);

void mergeSort(const char path_file[], long int start, long int end);
void merge(const char path_file[], long int start, long int middle, long int end);

#endif
