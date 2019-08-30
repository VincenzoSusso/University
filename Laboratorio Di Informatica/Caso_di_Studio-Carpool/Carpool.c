// -- Libraries --
#include "Carpool.h"

// -- Procedure & Functions --
const char *readGender(const Gender_t *gender)
{
	const static char *gender_name[LENGHT_ARRAY_GENDER] = {READ_GENDER_MALE, READ_GENDER_FEMALE, READ_GENDER_CUSTOM};

	return gender_name[*gender];
}

const char *readRating(const Rating_t *rating)
{
	const static char *rating_star[LENGHT_ARRAY_RATING] = {READ_RATING_ONE_STAR, READ_RATING_TWO_STAR,
														  READ_RATING_THREE_STAR, READ_RATING_FOUR_STAR,
														  READ_RATING_FIVE_STAR};

	return rating_star[*rating - 1]; // - 1 was added because the array starts from 0 while the value one_star starts from 1
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

void setPassword(char password[])
{
	bool flag = false;

	do
	{
		flag = false;

		printf("\nEnter the password (It should contain at least %d characters, an uppercase character and an number character): ", MIN_LENGHT_PASSWORD);
		scanf("%23[^\n]s", password);
		addNullCharacterString(password);
		clearBuffer();

		flag = isVoidString(password) || !isPassword(password) || !isIncluded(MIN_LENGHT_PASSWORD, MAX_LENGHT_STRINGS, (int) strlen(password));
		if(flag)
		{
			printf("\nThe password that you have entered is not valid (the password should contain at least %d characters, an uppercase character and an number character)", MIN_LENGHT_PASSWORD);
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
	char date_input[MAX_LENGHT_DATE_STRING_INPUT] = NULL_STRING; // This string is used in order to take the input

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
			if(isNumberString(year) && isNumberString(month) && isNumberString(day))
			{
				// The string has the correct characters
				date -> year = (unsigned short) strtoul(year, NULL, 10);
				date -> month = (unsigned short) strtoul(month, NULL, 10);
				date -> day = (unsigned short) strtoul(day, NULL, 10);
			}
		}

		flag = !isValidDate(*date);
		if(flag)
		{
			printf("\nThe %s that you have entered is not valid", printf_value);
		}

	}
	while(flag);
}

void setGender(Gender_t *gender)
{
	bool flag = false;
	char gender_input[MAX_LENGHT_GENDER_STRING_INPUT] = NULL_STRING;

	do
	{
		flag = false;

		printf("\nEnter your gender (Male = 0, Female = 1, Custom = 2): ");
		scanf("%3[^\n]s", gender_input);
		addNullCharacterString(gender_input);
		clearBuffer();

		if(isNumberString(gender_input))
		{
			// The input can be converted to Gender_t
			*gender = (Gender_t) strtol(gender_input, NULL, 10);

			if(!isIncluded(male, custom, *gender))
			{
				// The string is not included
				flag = true;
			}

		}
		else
		{
			// The string is not a number
			flag = true;
		}

		if(flag)
		{
			printf("\nThe gender that you have entered is not valid");
		}

	}
	while(flag);
}

void setRating(Rating_t *rating, char printf_value[])
{
	bool flag = false;
	char rating_input[MAX_LENGHT_RATING_STRING_INPUT] = NULL_STRING; // This string is used in order to take the input

	do
	{
		flag = false;

		printf("\nEnter the %s (between %d and %d): ", printf_value, one_star, five_star);
		scanf("%3[^\n]s", rating_input);
		addNullCharacterString(rating_input);
		clearBuffer();

		if(isNumberString(rating_input))
		{
			// The input can be converted to Rating_t
			*rating = (int) strtol(rating_input, NULL, 10);
			if(!isIncluded(one_star, five_star, *rating))
			{
				flag = true;
			}
		}
		else
		{
			// The string is not a number
			flag = true;
		}

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
	driver -> deleted = false;
}

void setDriver(Driver_t *driver, unsigned long id)
{
	resetDriver(driver);

	driver -> id = id;

	setWord(driver -> name, DRIVER_NAME_PRINTF_VALUE);
	capitalizeString(driver -> name);

	setWord(driver -> surname, DRIVER_SURNAME_PRINTF_VALUE);
	capitalizeString(driver -> surname);

	setEmail(driver -> email);
	setPassword(driver -> password);
	setNumberPhone(driver -> phone_number);
	setDate(&driver -> birthday, DRIVER_BIRTHDAY_PRINTF_VALUE);
	setGender(&driver -> gender);
	setRating(&driver -> driving_capacity, DRIVER_DRIVING_CAPACITY_PRINTF_VALUE);
	setRating(&driver -> comfort_capacity, DRIVER_COMFORT_CAPACITY_PRINTF_VALUE);

	driver -> average_rating = (driver -> driving_capacity + driver -> comfort_capacity) / 2;

	driver -> deleted = false;
}

void readDriver(const Driver_t *driver)
{
	if(!driver -> deleted)
	{
		printf("\n|%4lu|%14s|%15s|%31s|%14s|%16s|%4.4hu/%2.2d/%2.2hu| %6s |%5s|%5s|%5s|", driver -> id,
				driver -> name, driver -> surname, driver -> email, driver -> password, driver -> phone_number,
				driver -> birthday.year, driver -> birthday.month, driver -> birthday.day,
				readGender(&driver -> gender), readRating(&driver -> driving_capacity),
				readRating(&driver -> comfort_capacity), readRating(&driver -> average_rating));
		printf("\n+----+--------------+---------------+-------------------------------+--------------+----------------+----------+--------+---------------+---------------+-------------+");
	}
}

bool isIdDriverEqual(const Driver_t *driver, const unsigned long *id)
{
	bool equal_id = false;

	if(!(driver -> deleted))
	{
		if(driver -> id == *id)
		{
			equal_id = true;
		}
	}

	return equal_id;
}

File_status_t addDriver(char path[], const unsigned long *id_driver) // This function return true if the driver has been added to the system
{
	File_status_t operation = error;
	Driver_t driver;

	resetDriver(&driver);

	setDriver(&driver, *id_driver);
	operation = writeFile(path, &driver, sizeof(driver), 0, SEEK_END);

	return operation;
}

File_status_t editDriver(char path[], const unsigned long *id_driver)
{
	File_status_t operation = done;

	return operation;
}

File_status_t deleteDriver(char path[]) // This function returns true if the driver has been deleted to the system
{
	File_status_t operation = done;
	Driver_t driver;
	long int index_id = INDEX_ID_NOT_FOUND;
	unsigned long id_input = 0; // Variable that will store the index
	char id_input_string[MAX_LENGHT_ID_STRING_INPUT] = NULL_STRING;

	resetDriver(&driver);

	printf("\n\nEnter the ID of the driver that you want to delete: ");
	scanf("%s", id_input_string);
	clearBuffer();

	if(isNumberString(id_input_string))
	{
		id_input = strtol(id_input_string, NULL, 10);
	}
	else
	{
		operation = error;
	}

	index_id = getIndexDriver(path, &id_input);

	if(index_id != INDEX_ID_NOT_FOUND)
	{
		driver.deleted = true;
		operation = writeFile(path, &driver, sizeof(driver), index_id, SEEK_SET);
	}
	else
	{
		operation = error;
	}

	return operation;
}

File_status_t showAllDrivers(char path[]) // This function return true if has read all records of the file, "path" is the path of the file that stores the drivers
{
	File_status_t operation = error;
	Driver_t driver;
	long int i = 0;

	resetDriver(&driver);

	printf("\n+----+--------------+---------------+-------------------------------+--------------+----------------+----------+--------+---------------+---------------+-------------+");
	printf("\n| ID |     Name     |    Surname    |             Email             |   Password   |  Phone Number  | Birthday | Gender | Drv. Capacity | Cmf. Capacity | Avg. Rating |");
	printf("\n+----+--------------+---------------+-------------------------------+--------------+----------------+----------+--------+---------------+---------------+-------------+");

	do
	{
		operation = readFile(path, &driver, sizeof(driver), i, SEEK_CUR);
		if(operation == done)
		{
			readDriver(&driver);
		}
		i++;
	}
	while(operation == done);

	return operation;
}

File_status_t updateID(char path[], const long int offset, unsigned long *id)
{
	File_status_t operation = error;

	(*id)++;
	operation = writeFile(path, id, sizeof(*id), offset, SEEK_SET);

	return operation;
}

long int getIndexDriver(char path[], const unsigned long *id)
{
	File_status_t operation = error;
	Driver_t driver;
	unsigned long i = 0;
	unsigned long index_id = INDEX_ID_NOT_FOUND;

	resetDriver(&driver);

	do
	{
		operation = readFile(path, &driver, sizeof(driver), i, SEEK_CUR);
		if(operation == done)
		{
			if(isIdDriverEqual(&driver, id))
			{
				index_id = i;
			}
		}
			i++;
	}
	while(operation == done);

	return index_id;
}
