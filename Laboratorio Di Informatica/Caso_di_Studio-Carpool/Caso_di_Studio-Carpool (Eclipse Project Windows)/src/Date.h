/*
	LABORATORIO DI INFORMATICA - Caso di Studio Carpooling
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
   This library was created in order to provide some procedures and functions to manage the dates and times
   this library was created following the standard ISO-8601.
   For more information visit: https://en.wikipedia.org/wiki/ISO_8601
*/

/**
 * @file Date.h
 * @author Vincenzo Susso
 * @date 2019 Sep 09
 * @version 1.0
 * @brief This library was created in order to provide some procedures and functions that are used to
 * manage dates and times.
 *
 * This library provide some procedures and functions to check if a date or time is valid, to set a valid value
 * to a date or a time, and to compare different dates or times.
 * This library was created following the standard ISO-8601,
 * for more information visit: https://en.wikipedia.org/wiki/ISO_8601
 * The time is shown is 24-hour format.
 */

// -- Libraries --
#ifndef Date_h
	#define Date_h

#include <stdbool.h>
#include <string.h>

#include "Utilities.h"

// -- Constant --
/**
 * @def MIN_DAY
 * This integer is used to indicates the minimum day that can be assigned to a valid date.
 */
#define MIN_DAY 1


/**
 * @def MAX_DAY
 * This integer is used to indicates the maximum day that can be assigned to a valid date.
 */
#define MAX_DAY 31


/**
 * @def MAX_DAY_FEBRUARY
 * This integer is used to indicates the maximum day that can be assigned to a valid date in February.
 */
#define MAX_DAY_FEBRUARY 29


/**
 * @def CENTURY_YEAR
 * This integer is used to check if a year is a leap year.
 */
#define CENTURY_YEAR 100


/**
 * @def CENTURY_LEAP_YEAR
 * This integer is used to check if a year century year is a leap year.
 */
#define CENTURY_LEAP_YEAR 400


/**
 * @def LEAP_YEAR
 * This integer is used to check if a year is a leap year.
 */
#define LEAP_YEAR 4

/**
 * @def MIN_HOUR
 * This integer is used to indicates the minimum hour of a valid time.
 */
#define MIN_HOUR 0


/**
 * @def MAX_HOUR
 * This integer is used to indicates the maximum hour of a valid time.
 */
#define MAX_HOUR 23


/**
 * @def MIN_MINUTE
 * This integer is used to indicates the minimum minute of a valid time.
 *
 */
#define MIN_MINUTE 0


/**
 * @def MAX_MINUTE
 * This integer is used to indicates the maximum minute of a valid time.
 */
#define MAX_MINUTE 59


/**
 * @def DATE_DELIMITER
 * This string is used to separate the member of a date.
 */
#define DATE_DELIMITER "/"


/**
 * @def TIME_DELIMITER
 * This string is used to separate the member of a time.
 */
#define TIME_DELIMITER ":"


/**
 * @def MAX_LENGHT_DATE_STRING_INPUT
 * This integer is used in order to indicates the maximum lenght of the string that will be used to take
 * the date in input.
 */
#define MAX_LENGHT_DATE_STRING_INPUT 11


/**
 * @def MAX_LENGHT_TIME_STRING_INPUT
 * This integer is used in order to indicates the maximum lenght of the string that will be used to take
 * the time in input.
 */
#define MAX_LENGHT_TIME_STRING_INPUT 6


// -- User-Defined types --
/**
 * @enum Month_t
 * This user-defined type is used in order to indicates the months and improve the readability.
 */
typedef enum {january = 1, /**< This member is used to indicate the month of January*/
			 february, /**< This member is used to indicate the month of February*/
			 march, /**< This member is used to indicate the month of March*/
			 april, /**< This member is used to indicate the month of April*/
			 may, /**< This member is used to indicate the month of May*/
			 june, /**< This member is used to indicate the month of June*/
			 july, /**< This member is used to indicate the month of July*/
			 august, /**< This member is used to indicate the month of August*/
			 september, /**< This member is used to indicate the month of September*/
			 october, /**< This member is used to indicate the month of October*/
			 november, /**< This member is used to indicate the month of November*/
			 december /**< This member is used to indicate the month of December*/
} Month_t;


/**
 * @enum Date_order_t
 * This user-defined type is used in order to return a value after a date/time comparision.
 */
typedef enum {older = -1, /**< The first date/time is older than the second one*/
			 equal, /**< The first date/time and the second one are equal*/
			 later /**< The first date/time is later than the second one*/
} Date_order_t;


/**
 * @struct Date_t
 * This user-defined type is used in order to manage the dates.
 */
typedef struct
{
	unsigned short year; /**< This member is used to store the year of the date */
	Month_t month; /**< This member is used to store the month of the date */
	unsigned short day; /**< This member is used to store the day of the date */
} Date_t;


/**
 * @struct Time_t
 * This user-defined type is used in order to manage the times.
 */
typedef struct
{
	unsigned short hour; /**< This member is used to store the hour of the time */
	unsigned short minute; /**< This member is used to store the minute of the time */
} Time_t;


// -- Procedure & Functions Prototypes --
/**
 * @fn isLeapYear(const unsigned short year)
 * This function checks if the year is a leap year.
 * @param year is checked in order to see if it is a leap year.
 * @return true if the year is a leap year, otherwise It will return false.
 */
bool isLeapYear(const unsigned short year);


/**
 * @fn isValidDate(const Date_t *date, const unsigned short min_year, const unsigned short max_year)
 * This function checks if the date that has been passed by pointer is a valid date and It is included between
 * min_year and max_year.
 * @param date is checked in order to see if it is valid.
 * @param min_year is the older valid year.
 * @param max_year is the later valid year.
 * @return true if the date is a valid date, otherwise It will return false.
 */
bool isValidDate(const Date_t *date, const unsigned short min_year, const unsigned short max_year);


/**
 * @fn resetDate(Date_t *date)
 * This procedure reset the date passed by pointer assigning invalid values to the date.
 * @param date is resetted by the procedure.
 */
void resetDate(Date_t *date);


/**
 * @fn setDate(Date_t *date, const unsigned short min_year, const unsigned short max_year, const char printf_value[])
 * This procedure sets a valid date to the date passed by pointer, the date must be included between min_year and
 * max_year.
 * @param date is used to assigns a valid value.
 * @param min_year is the older valid year.
 * @param max_year is the later valid_year.
 * @param printf_value says to the users what they should enter.
 */
void setDate(Date_t *date, const unsigned short min_year, const unsigned short max_year, const char printf_value[]);


/**
 * @fn isValidTime(const Time_t *time)
 * This function checks if the time that has been passed by pointer is a valid time.
 * @param time is checked in order to see if it is valid.
 * @return true if the time is a valid time, otherwise It will return false.
 */
bool isValidTime(const Time_t *time);


/**
 * @fn resetTime(Time_t *time)
 * This procedure reset the time passed by pointer assigning invalid values to the time.
 * @param time is resetted by the procedure
 */
void resetTime(Time_t *time);


/**
 * @fn setTime(Time_t *time, const char printf_value[])
 * This procedure sets a valid time to the time passed by pointer.
 * @param time is used to assigns a valid value.
 * @param printf_value says to the users what they should enter.
 */
void setTime(Time_t *time, const char printf_value[]);


/**
 * @fn cmpDate(const Date_t *first_date, const Date_t *second_date)
 * This functions is used to compare two dates.
 * @param first_date passed by pointer is used as a date to compare.
 * @param second_date passed by pointer is used as a date to compare.
 * @return -1 if the first date is older than the second one, 0 if the first date is equal to the second one,
 * 1 if the first date is later than the second one.
 */
Date_order_t cmpDate(const Date_t *first_date, const Date_t *second_date);


/**
 * @fn cmpTime(const Time_t *first_time, const Time_t *second_time)
 * @param first_time passed by pointer is used as a time to compare.
 * @param second_time passed by pointer is used as a time to compare.
 * @return -1 if the first time is older than the second one, 0 if the first time is equal to the second one,
 * 1 if the first time is later than the second one.
 */
Date_order_t cmpTime(const Time_t *first_time, const Time_t *second_time);

#endif
