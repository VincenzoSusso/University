/*
	LABORATORIO DI INFORMATICA - Caso di Studio Carpooling
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
   This library was created in order to provide some procedures and functions to manage the dates, this library was created following the standard ISO-8601.
   For more information visit: https://en.wikipedia.org/wiki/ISO_8601
*/

// -- Libraries --
#ifndef Date_h
	#define Date_h

#include <stdbool.h>

#include "Utilities.h"

// -- Constant --
#define MIN_DAY 1
#define MAX_DAY 31
#define MAX_DAY_FEBRUARY 29

#define MIN_YEAR 1900
#define MAX_YEAR 2001

/*
	In the Gregorian calendar, every year that is exactly divisible by four is a leap year, except for years that are exactly divisible by 100,
	but these centurial years are leap years if they are exactly divisible by 400.
*/
#define CENTURY_YEAR 100 // A century year means that the year is divisible by 100
#define CENTURY_LEAP_YEAR 400 // A century leap year means that the year is divisible by 400
#define LEAP_YEAR 4 // A not century leap year means that the year is divisible by 4

/*
	The time is shown in 24-hour format
*/
#define MIN_HOUR 0
#define MAX_HOUR 24

#define MIN_MINUTE 0
#define MAX_MINUTE 59

#define DATE_DELIMITER "/"

// -- User-Defined types --
typedef enum {january = 1, february, march, april, may, june, july, august, september, october, november, december} Month_t;

typedef struct
{
	unsigned short year;
	Month_t month;
	unsigned short day;
} Date_t;

typedef struct
{
	unsigned short hour;
	unsigned short minute;
} Time_t;

// -- Procedure & Functions Prototypes --
/*Date_t createRandomDate(void);
Time_t createRandomTime(void);*/
bool isLeapYear(const unsigned short year);
bool isValidDate(const Date_t date);
bool isValidTime(const Time_t time);
/*bool areDatesEquals(Date_t first_date, Date_t second_date);
Date_t dataPiuRecente(Date_t first_date, Date_t second_date);
Date_t dataMenoRecente(Date_t first_date, Date_t second_date); */

#endif
