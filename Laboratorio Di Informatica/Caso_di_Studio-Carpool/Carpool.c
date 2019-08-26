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

const char *readGender(const Gender_t *gender)
{
	static char gender_name[LENGHT_ARRAY_GENDER] = NULL_STRING;

	strcpy(gender_name, NULL_STRING);

	if(*gender == male)
	{
		strcpy(gender_name, READ_GENDER_MALE);
	}
	else if(*gender == female)
	{
		strcpy(gender_name, READ_GENDER_FEMALE);
	}
	else
	{
		strcpy(gender_name, READ_GENDER_CUSTOM);
	}

	return gender_name;
}

const char *readRating(const Rating_t *rating)
{
	unsigned short i = 0;
	static char rating_star[LENGHT_ARRAY_RATING] = NULL_STRING;

	strcpy(rating_star, NULL_STRING);
	for(i = 0; i < *rating; i++)
	{
		strcat(rating_star, STAR_CHARACTER);
	}

	addNullCharacterString(rating_star);

	return rating_star;
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

void resetDriver(Driver_t *driver)
{
	driver -> id = 0;
	strcpy(driver -> name, NULL_STRING);
	strcpy(driver -> surname, NULL_STRING);
	strcpy(driver -> email, NULL_STRING);
	strcpy(driver -> password, NULL_STRING);
	strcpy(driver -> phone_number, NULL_STRING);
	driver -> birthday.year = MIN_YEAR - 1;
	driver -> birthday.month = january - 1;
	driver -> birthday.day = MIN_DAY - 1;
	driver -> gender = male - 1;
	driver -> driving_capacity = one_star - 1;
	driver -> comfort_capacity = one_star - 1;
	driver -> average_rating = one_star - 1;
}

void addDriver(Driver_t *driver)
{
	resetDriver(driver);

	setWord(driver -> name, DRIVER_NAME_PRINTF_VALUE);
	capitalizeString(driver -> name);

	setWord(driver -> surname, DRIVER_SURNAME_PRINTF_VALUE);
	capitalizeString(driver -> surname);

	setEmail(driver -> email);
	setNumberPhone(driver -> phone_number);
	setDate(&driver -> birthday, DRIVER_BIRTHDAY_PRINTF_VALUE);
	setRating(&driver -> driving_capacity, DRIVER_DRIVING_CAPACITY_PRINTF_VALUE);
	setRating(&driver -> comfort_capacity, DRIVER_COMFORT_CAPACITY_PRINTF_VALUE);

	driver -> average_rating = (driver -> driving_capacity + driver -> comfort_capacity) / 2;
}

void readDriver(const Driver_t *driver)
{
	printf("\n|%4d|%14s|%15s|%31s|%14s|%16s|%4.4hu/%2.2d/%2.2hu| %6s |%5s|%5s|%5s", driver -> id,
			driver -> name, driver -> surname, driver -> email, driver -> password, driver -> phone_number,
			driver -> birthday.year, driver -> birthday.month, driver -> birthday.day,
			readGender(&driver -> gender), readRating(&driver -> driving_capacity),
			readRating(&driver -> comfort_capacity), readRating(&driver -> average_rating));
	printf("\n+----+--------------+---------------+-------------------------------+--------------+----------------+----------+--------+---------------+---------------+-------------+");
}

/*void readAllDrivers(char path[])
{
	Driver_t *driver;
	short i = 0;

	do
	{
		readFile(path, driver, sizeof(*driver), i);
		readDriver(driver);
		i++;
	}
	while(driver)
}*/
