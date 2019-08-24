// -- Libraries --
#include "Carpool.h"

// -- Procedure & Functions --
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
	printf("\n|         %d          | Show All Drivers |", show_all_driver);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |    Add Travel    |", add_travel);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |    Edit Travel   |", edit_travel);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |   Delete Travel  |", delete_travel);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          | Show All Travels |", show_all_travel);
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

void setWord(char word[], const char printf_value[]) // The procedure set a valid value to the word passed by pointer
{
	bool flag = false;

	do
	{
		flag = false;

		printf("\nEnter the %s: ", printf_value);
		scanf("%23[^\n]s", word);
		addNullCharacterString(word);
		clearBuffer();

		flag = isVoidString(word) || !isLatinString(word) || !isIncluded(MIN_LENGHT_STRINGS, MAX_LENGHT_STRINGS, (int) strlen(word));
		if(flag)
		{
			printf("\nThe %s that you have entered is not valid (the %s is a void string or it has a wrong size or it has a number, a space or a special character)", printf_value, printf_value);
		}

	}
	while(flag);
}

void setEmail(char email[])
{
	bool flag = false;

	do
	{
		flag = false;

		printf("\nEnter the email (local-part@domain): ");
		scanf("%59[^\n]s", email);
		addNullCharacterString(email);
		clearBuffer();

		flag = isVoidString(email) || !isEmail(email) || !isIncluded(MIN_LENGHT_STRINGS, MAX_LENGHT_EMAIL, (int) strlen(email));
		if(flag)
		{
			printf("\nThe email that you have entered is not valid (the format should be \"local-part@domain\")");
		}

	}
	while(flag);
}

void setNumberPhone(char phone_number[])
{
	bool flag = false;

	do
	{
		flag = false;

		printf("\nEnter the phone number (+xxx xxxxxxxxxx): ");
		scanf("%17[^\n]s", phone_number);
		addNullCharacterString(phone_number);
		clearBuffer();

		flag = isVoidString(phone_number) || !isNumberPhone(phone_number) || !isIncluded(MIN_LENGHT_PHONE_NUMBER, MAX_LENGHT_PHONE_NUMBER, (int) strlen(phone_number));
		if(flag)
		{
			printf("\nThe phone number that you have entered is not valid (the format should be \"+xxx xxxxxxxxxx\")");
		}

	}
	while(flag);
}

void setDate(Date_t *date, const char printf_value[]) // The procedure set a valid value to the date passed by pointer
{
	bool flag = false;
	char date_input[MAX_LENGHT_DATE_STRING] = NULL_STRING; // This string is used in order to take the input

	// Thoose pointer are used to point to the part of the date
	char *year = NULL;
	char *month = NULL;
	char *day = NULL;

	do
	{
		flag = false;

		printf("\nEnter the %s (yyyy%smm%sdd): ", printf_value, DATE_DELIMITER, DATE_DELIMITER);
		scanf("%10[^\n]s", date_input);
		addNullCharacterString(date_input);
		clearBuffer();

		year = strtok(date_input, DATE_DELIMITER);
		month = strtok(NULL, DATE_DELIMITER);
		day = strtok(NULL, NULL_STRING);

		if(month != NULL && day != NULL)
		{
			// The string that the user has entered has a valid format
			date -> year = (unsigned short) strtoul(year, NULL, 10);
			date -> month = (unsigned short) strtoul(month, NULL, 10);
			date -> day = (unsigned short) strtoul(day, NULL, 10);
		}

		flag = !isValidDate(*date);
		if(flag)
		{
			printf("\nThe %s that you have entered is not valid", printf_value);
		}

	}
	while(flag);
}

void setRating(Rating_t *rating, char printf_value[])
{
	bool flag = false;
	char rating_input[MAX_LENGHT_RATING_STRING] = NULL_STRING; // This string is used in order to take the input

	do
	{
		flag = false;

		printf("\nEnter the %s (between %d and %d): ", printf_value, one_star, five_star);
		scanf("%3[^\n]s", rating_input);
		addNullCharacterString(rating_input);
		clearBuffer();

		*rating = (int) strtol(rating_input, NULL, 10);

		flag = !isIncluded(one_star, five_star, *rating);
		if(flag)
		{
			printf("\nThe %s that you have entered is not valid (it should be between %d and %d)", printf_value, one_star, five_star);
		}

	}
	while(flag);
}

Driver_t addDriver(void)
{
	Driver_t driver = {0, NULL_STRING, NULL_STRING, NULL_STRING, NULL_STRING, NULL_STRING, {MIN_YEAR, january, MIN_DAY - 1}, male - 1 ,one_star -1, one_star - 1, one_star - 1};

	setWord(driver.name, DRIVER_NAME_PRINTF_VALUE);
	setWord(driver.surname, DRIVER_SURNAME_PRINTF_VALUE);
	setEmail(driver.email);
	setNumberPhone(driver.phone_number);
	setDate(&driver.birthday, DRIVER_BIRTHDAY_PRINTF_VALUE);
	setRating(&driver.driving_capacity, DRIVER_DRIVING_CAPACITY_PRINTF_VALUE);
	setRating(&driver.comfort_capacity, DRIVER_COMFORT_CAPACITY_PRINTF_VALUE);

	driver.average_rate = (driver.driving_capacity + driver.comfort_capacity) / 2;

	return driver;
}

void readDriver(const Driver_t *driver)
{
	printf("\nName: %s", driver -> name);
	printf("\nSurname: %s", driver -> surname);
	printf("\nEmail: %s", driver -> email);
	printf("\nBirthday (yyyy/mm/dd): %hu/%hu/%hu", driver -> birthday.year, driver -> birthday.month, driver -> birthday.day);
	printf("\nDriving capacity: %d", driver -> driving_capacity);
	printf("\nComfort capacity: %d", driver -> comfort_capacity);
	printf("\nAverage Rate: %d", driver -> average_rate);
}
