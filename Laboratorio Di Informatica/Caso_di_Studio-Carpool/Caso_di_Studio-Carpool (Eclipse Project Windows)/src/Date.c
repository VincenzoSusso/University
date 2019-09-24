// -- Libraries --
#include "Date.h"

/**
 * @file Date.c
 * @author Vincenzo Susso
 * @date 2019 Sep 09
 * @version 1.0
 * @brief This file is the implementation file of Date.h
 */

// -- Procedure & Functions --
/**
 * In the Gregorian calendar, every year that is exactly divisible by four is a leap year, except for
 * years that are exactly divisible by 100, but these centurial years are leap years if they are exactly
 * divisible by 400.
*/
bool isLeapYear(const unsigned short year)
{
	bool leap_year = false;

	// A year is a leap year if it is divisible by four and not by one-hundred or if it is divisible by four-hundred
	if((!(year % LEAP_YEAR) && (year % CENTURY_YEAR)) || !(year % CENTURY_LEAP_YEAR))
	{
		leap_year = true;
	}
	else
	{
		leap_year = false;
	}

	return leap_year;
}

bool isValidDate(const Date_t *date, const unsigned short min_year, const unsigned short max_year)
{
	bool valid_date = false;

	// If the year or the month is not valid, all the date is wrong
	if(isIncluded(january, december, date -> month) && isIncluded(min_year, max_year, date -> year))
	{
		if(date -> month == february)
		{
			if(isLeapYear(date -> year))
			{
				// The year is a lap year so the month has twenty-nine days
				valid_date = isIncluded(MIN_DAY, MAX_DAY_FEBRUARY, date -> day);
			}
			else
			{
				// The year is not a lap year so the month has twenty-eight days
				valid_date = isIncluded(MIN_DAY, MAX_DAY_FEBRUARY - 1, date -> day);
			}
		}
		else if(date -> month == april || date -> month == june || date -> month == september || date -> month == november)
		{
			// The month has thirty days
			valid_date = isIncluded(MIN_DAY, MAX_DAY - 1, date -> day);
		}
		else
		{
			// The month has thirty-one days
			valid_date = isIncluded(MIN_DAY, MAX_DAY, date -> day);
		}
	}

	return valid_date;
}

void resetDate(Date_t *date)
{
	date -> year = 0;
	date -> month = january - 1;
	date -> day = MIN_DAY - 1;
}

void setDate(Date_t *date, const unsigned short min_year, const unsigned short max_year, const char printf_value[])
{
	bool flag = false;
	char date_input[MAX_LENGHT_DATE_STRING_INPUT] = NULL_STRING; // This string is used in order to take the input

	// Thoose pointer are used to point to the part of the date
	char *year = NULL;
	char *month = NULL;
	char *day = NULL;

	resetDate(date);

	do
	{
		flag = false;

		printf("\nEnter the %s (yyyy%smm%sdd): ", printf_value, DATE_DELIMITER, DATE_DELIMITER);
		scanf("%10[^\n]s", date_input);
		addNullCharacterString(date_input);
		clearBuffer();

		// Splitting the date
		year = strtok(date_input, DATE_DELIMITER);
		month = strtok(NULL, DATE_DELIMITER);
		day = strtok(NULL, NULL_STRING);

		if(month && day)
		{
			// The string that the user has entered has a valid format
			if(isNumberString(year) && isNumberString(month) && isNumberString(day))
			{
				// The string has the correct characters
				date -> year = (unsigned short) strtoul(year, NULL, BASE_STRTOL);
				date -> month = (unsigned short) strtoul(month, NULL, BASE_STRTOL);
				date -> day = (unsigned short) strtoul(day, NULL, BASE_STRTOL);
			}
		}

		flag = !isValidDate(date, min_year, max_year);
		if(flag)
		{
			printf("\nThe %s that you have entered is not valid", printf_value);
		}

	}
	while(flag);
}

bool isValidTime(const Time_t *time)
{
	bool valid_time = false;

	if(isIncluded(MIN_HOUR, MAX_HOUR, time -> hour) && isIncluded(MIN_MINUTE, MAX_MINUTE, time -> minute))
	{
		valid_time = true;
	}

	return valid_time;
}

void resetTime(Time_t *time)
{
	time -> hour = MIN_HOUR - 1;
	time -> minute = MIN_MINUTE - 1;
}

void setTime(Time_t *time, const char printf_value[]) // The procedure set a valid value to the time passed by pointer
{
	bool flag = false;
	char time_input[MAX_LENGHT_TIME_STRING_INPUT] = NULL_STRING; // This string is used in order to take the input

	// Thoose pointer are used to point to the part of the date
	char *hour = NULL;
	char *minute = NULL;

	resetTime(time);

	do
	{
		flag = false;

		printf("\nEnter the %s (hh%smm): ", printf_value, TIME_DELIMITER);
		scanf("%5[^\n]s", time_input);
		addNullCharacterString(time_input);
		clearBuffer();

		// Splitting time
		hour = strtok(time_input, TIME_DELIMITER);
		minute = strtok(NULL, NULL_STRING);

		if(minute)
		{
			// The string that the user has entered has a valid format
			if(isNumberString(hour) && isNumberString(minute))
			{
				// The string has the correct characters
				time -> hour = (unsigned short) strtoul(hour, NULL, BASE_STRTOL);
				time -> minute = (unsigned short) strtoul(minute, NULL, BASE_STRTOL);
			}
		}

		flag = !isValidTime(time);
		if(flag)
		{
			printf("\nThe %s that you have entered is not valid", printf_value);
		}

	}
	while(flag);
}

Date_order_t cmpDate(const Date_t *first_date, const Date_t *second_date)
{
	Date_order_t comparison_dates = equal;

	if((first_date -> year) < (second_date -> year))
	{
		// The first date is older than the second one due to the year
		comparison_dates = older;
	}
	else if((first_date -> year) > (second_date -> year))
	{
		// The first date is later than the second one due to the year
		comparison_dates = later;
	}
	else
	{
		if((first_date -> month) < (second_date -> month))
		{
			// The first date is older than the second one due to the month
			comparison_dates = older;
		}
		else if((first_date -> month) > (second_date -> month))
		{
			// The first date is later than the second one due to the month
			comparison_dates = later;
		}
		else
		{
			if((first_date -> day) < (second_date -> day))
			{
				// The first date is older than the second one due to the day
				comparison_dates = older;
			}
			else if(first_date -> day > second_date -> day)
			{
				// The first date is later than the second one due to the day
				comparison_dates = later;
			}
			else
			{
				// Both dates are equals
				comparison_dates = equal;
			}
		}
	}

	return comparison_dates;
}

Date_order_t cmpTime(const Time_t *first_time, const Time_t *second_time)
{
	int comparison_times = equal;

	if((first_time -> hour) < (second_time -> hour))
	{
		// The first time is older that the second one due to hour
		comparison_times = older;
	}
	else if((first_time -> hour) > (second_time -> hour))
	{
		// The first time is latest that the second one due to hour
		comparison_times = later;
	}
	else
	{
		if((first_time -> minute) < (second_time -> minute))
		{
			// The first time is older that the second one due to minute
			comparison_times = older;
		}
		else if((first_time -> minute) > (second_time -> minute))
		{
			// The first time is latest that the second one due to hour
			comparison_times = later;
		}
		else
		{
			// The two times are equals
			comparison_times = equal;
		}
	}

	return comparison_times;
}
