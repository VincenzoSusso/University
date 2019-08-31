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

	strcpy(word, NULL_STRING); // Reset word

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

	strcpy(email, NULL_STRING); // Reset email

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

	strcpy(password, NULL_STRING); // Reset password

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

	strcpy(phone_number, NULL_STRING); // Reset phone number

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

void setNumberInput(int *input, const int min, const int max, const char printf_value_input[], const char printf_value_error[])
{
	bool flag = false;
	char string_input[MAX_LENGHT_NUMBER_INPUT] = NULL_STRING;

	do
	{
		flag = false;

		printf("\n%s", printf_value_input);
		scanf("%7[^\n]s", string_input);
		addNullCharacterString(string_input);
		clearBuffer();

		flag = !isNumberString(string_input) || isVoidString(string_input);

		if(!flag)
		{
			// The input can be converted to Gender_t
			*input = (int) strtol(string_input, NULL, 10);

			if(!isIncluded(min, max, *input))
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
			printf("\n%s", printf_value_error);
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
	resetDate(&driver -> birthday);
	driver -> gender = male - 1;
	driver -> driving_capacity = one_star - 1;
	driver -> comfort_capacity = one_star - 1;
	driver -> average_rating = one_star - 1;
	driver -> deleted = false;
}

void setDriver(Driver_t *driver, int id)
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
	setNumberInput((int *) &driver -> gender, male, custom, DRIVER_GENDER_PRINTF_VALUE_INPUT, DRIVER_GENDER_PRINTF_VALUE_ERROR);
	setNumberInput((int *) &driver -> driving_capacity, one_star, five_star, DRIVER_DRIVING_CAPACITY_PRINTF_VALUE_INPUT, DRIVER_DRIVING_CAPACITY_PRINTF_VALUE_ERROR);
	setNumberInput((int *) &driver -> comfort_capacity, one_star, five_star, DRIVER_COMFORT_CAPACITY_PRINTF_VALUE_INPUT, DRIVER_COMFORT_CAPACITY_PRINTF_VALUE_ERROR);

	driver -> average_rating = (driver -> driving_capacity + driver -> comfort_capacity) / NUMBER_OF_RATING;

	driver -> deleted = false;
}

void readDriver(const Driver_t *driver)
{
	if(!driver -> deleted)
	{
		printf("\n|%4d|%14s|%15s|%31s|%14s|%16s|%4.4hu/%2.2d/%2.2hu| %6s |%5s|%5s|%5s|", driver -> id,
				driver -> name, driver -> surname, driver -> email, driver -> password, driver -> phone_number,
				driver -> birthday.year, driver -> birthday.month, driver -> birthday.day,
				readGender(&driver -> gender), readRating(&driver -> driving_capacity),
				readRating(&driver -> comfort_capacity), readRating(&driver -> average_rating));
		printf("\n+----+--------------+---------------+-------------------------------+--------------+----------------+----------+--------+---------------+---------------+-------------+");
	}
}

bool isIdDriverEqual(const Driver_t *driver, const int *id)
{
	bool equal_id = false;

	if(!(driver -> deleted))
	{
		// The driver is not deleted
		if(driver -> id == *id)
		{
			equal_id = true;
		}
	}

	return equal_id;
}

void showMemberDriver(void)
{
	printf("\n\n\n+--------------------+------------------+");
	printf("\n|  Number of Member  |      Member      |");
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |       Name       |", name);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |      Surname     |", surname);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |       Email      |", email);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |     Password     |", password);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |   Phone Number   |", phone_number);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |     Birthday     |", birthday);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          |      Gender      |", gender);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          | Driving Capacity |", driving_capacity);
	printf("\n+--------------------+------------------+");
	printf("\n|         %d          | Comfort Capacity |", comfort_capacity);
	printf("\n+--------------------+------------------+");
}

File_status_t addDriver(char path[], const int *id_driver) // This function return true if the driver has been added to the system
{
	File_status_t operation = error;
	Driver_t driver;

	resetDriver(&driver);

	setDriver(&driver, *id_driver); // Get information of the driver
	operation = writeFile(path, &driver, sizeof(driver), 0, SEEK_END); // Write the driver into the file
	return operation;
}

File_status_t editDriver(char path[])
{
	File_status_t operation = done;
	Driver_t driver;
	int id_input = 0; // This variable is used to get the input of the ID
	Driver_members_t member_input = id - 1;
	long int index_id = INDEX_ID_NOT_FOUND; // This variable is used to get the index of the ID

	resetDriver(&driver);

	// Get the ID of the driver that the user wants to edit
	setNumberInput(&id_input, INT_MIN, INT_MAX, DRIVER_ID_EDIT_PRINTF_VALUE_INPUT, DRIVER_ID_EDIT_PRINTF_VALUE_ERROR);
	index_id = getIndexDriver(path, &id_input);

	if(index_id != INDEX_ID_NOT_FOUND)
	{
		// Loads driver from file
		operation = readFile(path, &driver, sizeof(driver), index_id, SEEK_SET);
		if(operation == done)
		{
			showMemberDriver(); // Output of the member

			// Get the member of the driver that the user wants to edit
			setNumberInput((int *) &member_input, name, comfort_capacity, DRIVER_MEMBER_PRINTF_VALUE_INPUT, DRIVER_MEMBER_PRINTF_VALUE_ERROR);

			switch(member_input)
			{
				case name:
					setWord(driver.name, DRIVER_NAME_PRINTF_VALUE);
					capitalizeString(driver.name);
					break;
				case surname:
					setWord(driver.surname, DRIVER_SURNAME_PRINTF_VALUE);
					capitalizeString(driver.surname);
					break;
				case email:
					setEmail(driver.email);
					break;
				case password:
					setPassword(driver.password);
					break;
				case phone_number:
					setNumberPhone(driver.phone_number);
					break;
				case birthday:
					setDate(&driver.birthday, DRIVER_BIRTHDAY_PRINTF_VALUE);
					break;
				case gender:
					setNumberInput((int *) &driver.gender, male, custom, DRIVER_GENDER_PRINTF_VALUE_INPUT, DRIVER_GENDER_PRINTF_VALUE_ERROR);
					break;
				case driving_capacity:
					setNumberInput((int *) &driver.driving_capacity, one_star, five_star, DRIVER_DRIVING_CAPACITY_PRINTF_VALUE_INPUT, DRIVER_DRIVING_CAPACITY_PRINTF_VALUE_ERROR);
					driver.average_rating = (driver.driving_capacity + driver.comfort_capacity) / NUMBER_OF_RATING;
					break;
				case comfort_capacity:
					setNumberInput((int *) &driver.comfort_capacity, one_star, five_star, DRIVER_COMFORT_CAPACITY_PRINTF_VALUE_INPUT, DRIVER_COMFORT_CAPACITY_PRINTF_VALUE_ERROR);
					driver.average_rating = (driver.driving_capacity + driver.comfort_capacity) / NUMBER_OF_RATING;
					break;
				default:
					break;
			}

			// Write the edited driver into file
			operation = writeFile(path, &driver, sizeof(driver), index_id, SEEK_SET);
		}
		else
		{
			// Force the operation to error in order to report the error
			operation = error;
		}
	}
	else
	{
		// The driver has non been found
		operation = error;
	}

	return operation;
}

File_status_t deleteDriver(char path[]) // This function returns true if the driver has been deleted to the system
{
	File_status_t operation = done;
	Driver_t driver;
	int id_input = 0; // Variable that will store the input of the ID
	long int index_id = INDEX_ID_NOT_FOUND; // Variable that will store the index of the ID

	resetDriver(&driver);

	// Get the ID of the driver that the user wants to delete
	setNumberInput(&id_input, INT_MIN, INT_MAX, DRIVER_ID_DELETE_PRINTF_VALUE_INPUT, DRIVER_ID_DELETE_PRINTF_VALUE_ERROR);
	index_id = getIndexDriver(path, &id_input); // Get index of the driver that the user wanna delete

	if(index_id != INDEX_ID_NOT_FOUND)
	{
		// The driver has been found so the system will delete him
		operation = readFile(path, &driver, sizeof(driver), index_id, SEEK_SET);
		if(operation == done)
		{
			driver.deleted = true;
			operation = writeFile(path, &driver, sizeof(driver), index_id, SEEK_SET);
		}
	}
	else
	{
		// The driver has non been found
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
			// The driver has been read
			readDriver(&driver);
		}
		i++;
	}
	while(operation == done);

	return operation;
}

File_status_t updateID(char path[], const long int offset, int *id)
{
	File_status_t operation = error;

	(*id)++;
	operation = writeFile(path, id, sizeof(*id), offset, SEEK_SET);

	return operation;
}

long int getIndexDriver(char path[], const int *id)
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
			// The driver has been read
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
