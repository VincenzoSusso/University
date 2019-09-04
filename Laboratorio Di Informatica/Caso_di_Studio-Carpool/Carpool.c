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
		scanf("%19[^\n]s", word);
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
		scanf("%39[^\n]s", email);
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
		scanf("%19[^\n]s", password);
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

void setAdditionalNotes(char additional_notes[])
{
	bool flag = false;
	bool user_choiche_additional_notes = false; // This variable is used in order to know if the user want or not add additional notes

	strcpy(additional_notes, NULL_STRING);


	setNumberInput((int *) &user_choiche_additional_notes, false, true, TRAVEL_ADDITIONAL_NOTES_PRINTF_VALUE_INPUT, TRAVEL_ADDITIONAL_NOTES_PRINTF_VALUE_ERROR);

	if(user_choiche_additional_notes)
	{
		do
		{
			printf("\nEnter the travel's additional notes: ");
			scanf("%39[^\n]s", additional_notes);
			addNullCharacterString(additional_notes);
			clearBuffer();

			flag = isVoidString(additional_notes) || !isIncluded(MIN_LENGHT_STRINGS, MAX_LENGHT_ADDITIONAL_NOTES, strlen(additional_notes));

			if(flag)
			{
				printf("\nThe additional notes that you have entered is not valid (you have entered a void string or a string too long)");
			}
		}
		while(flag);
	}
}

void setPrice(double *price)
{
	bool flag = false;

	char price_input[MAX_LENGHT_NUMBER_INPUT] = NULL_STRING;

	do
	{
		flag = false;

		printf("\nEnter the price (%s) of the travel (Use the period \".\" to separate the integer part to the decimal portion): ", DOLLAR_CHARACTER);
		scanf("%7[^\n]s", price_input);
		addNullCharacterString(price_input);
		clearBuffer();

			flag = !isDecimalNumber(price_input) || isVoidString(price_input);

			if(!flag)
			{
				// The input can be converted to double
				*price = (double) strtod(price_input, NULL);

				if(*price < MIN_PRICE || *price > MAX_PRICE)
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
				printf("\nThe price that you have inserted is not valid (it should be between %.2lf%s and %.2lf%s, and the integer part should be separeted to the decimal portion by a period \".\")", MIN_PRICE, DOLLAR_CHARACTER, MAX_PRICE, DOLLAR_CHARACTER);
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
			*input = (int) strtol(string_input, NULL, BASE_STRTOL);

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

void setDriver(Driver_t *driver, const int *id)
{
	resetDriver(driver);

	driver -> id = *id;

	setWord(driver -> name, DRIVER_NAME_PRINTF_VALUE);
	capitalizeString(driver -> name);

	setWord(driver -> surname, DRIVER_SURNAME_PRINTF_VALUE);
	capitalizeString(driver -> surname);

	setEmail(driver -> email);
	setPassword(driver -> password);
	setNumberPhone(driver -> phone_number);
	setDate(&driver -> birthday, MIN_YEAR_BIRTHDAY, MAX_YEAR_BIRTHDAY, DRIVER_BIRTHDAY_PRINTF_VALUE);
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
		printf("\n|%4d|%17s|%17s|%35s|%19s|%17s|%4.4hu%s%2.2d%s%2.2hu|%6s|   %5s  |   %5s  |  %5s  |", driver -> id,
				driver -> name, driver -> surname, driver -> email, driver -> password, driver -> phone_number,
				driver -> birthday.year, DATE_DELIMITER, driver -> birthday.month, DATE_DELIMITER, driver -> birthday.day,
				readGender(&driver -> gender), readRating(&driver -> driving_capacity),
				readRating(&driver -> comfort_capacity), readRating(&driver -> average_rating));
		printf("\n+----+-----------------+-----------------+-----------------------------------+-------------------+-----------------+----------+------+----------+----------+---------+");
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

void resetTravel(Travel_t *travel)
{
	travel -> id = 0;
	travel -> id_driver = 0;
	strcpy(travel -> departure_destination, NULL_STRING);
	strcpy(travel -> arrival_destination, NULL_STRING);
	strcpy(travel -> additional_notes, NULL_STRING);
	resetDate(&travel -> departure_date);
	resetTime(&travel -> departure_time);
	travel -> price = 0;
	travel -> total_seats = 0;
	travel -> free_seats = 0;
	travel -> deleted = false;
}

void setTravel(Travel_t *travel, const int *id, const char path_driver_file[])
{
	travel -> id = *id;
	do
	{
		travel -> id_driver = getIndexDriverUser(path_driver_file, TRAVEL_DRIVER_ID_PRINTF_VALUE_INPUT, TRAVEL_DRIVER_ID_PRINTF_VALUE_ERROR);
		if(travel -> id_driver == INDEX_NOT_FOUND)
		{
			printf("\nAn error has occurred during the acquisition of the driver's ID");
		}
	}
	while(travel -> id_driver == INDEX_NOT_FOUND);

	setWord(travel -> departure_destination, TRAVEL_DEPARTURE_DESTINATION_PRINTF_VALUE);
	capitalizeString(travel -> departure_destination);

	setWord(travel -> arrival_destination, TRAVEL_ARRIVAL_DESTINATION_PRINTF_VALUE);
	capitalizeString(travel -> arrival_destination);

	setDate(&travel -> departure_date, MIN_YEAR_TRAVEL, MAX_YEAR_TRAVEL, TRAVEL_DEPARTURE_DATE_PRINTF_VALUE);
	setTime(&travel -> departure_time, TRAVEL_DEPARTURE_TIME_PRINTF_VALUE);

	setNumberInput((int *) &travel -> total_seats, MIN_NUMBER_TOTAL_SEATS, MAX_NUMBER_TOTAL_SEATS, TRAVEL_TOTAL_SEAT_INPUT, TRAVEL_TOTAL_SEAT_ERROR);
	do
	{
		setNumberInput((int *) &travel -> free_seats, MIN_NUMBER_FREE_SEATS, MAX_NUMBER_FREE_SEATS, TRAVEL_FREE_SEAT_INPUT, TRAVEL_FREE_SEAT_ERROR);

		if(!isIncluded(MIN_NUMBER_FREE_SEATS + 1, travel -> total_seats - 1, travel -> free_seats))
		{
			printf("\nThe number of free seat is bigger than the total of seat in the driver's veicle or you have entered 0 free seats");
		}
	}
	while(!isIncluded(MIN_NUMBER_FREE_SEATS + 1, travel -> total_seats - 1, travel -> free_seats)); // (min number free seats + 1) was added because 0 free seat is useless, (total seat - 1) was added due to driver's seat

	setPrice(&travel -> price);
	setAdditionalNotes(travel -> additional_notes);

	travel -> deleted = false;
}

void readTravel(const Travel_t *travel, const char path_driver_file[])
{
	Driver_t driver; // Used to print name and surname of the driver's travel

	resetDriver(&driver);

	if(!travel -> deleted)
	{
		readFile(path_driver_file, &driver, sizeof(driver), getIndexDriver(path_driver_file, &travel -> id_driver), SEEK_SET);
		printf("\n|%4d|%14s %14s|%18s|%18s| %4.4hu/%2.2d/%2.2hu %2.2hu%s%2.2hu | %7.2lf%s |     %1hu    |     %1hu    |%40s|", travel -> id,
				driver.name, driver.surname, travel -> departure_destination, travel -> arrival_destination,
				travel -> departure_date.year, travel -> departure_date.month, travel -> departure_date.day,
				travel -> departure_time.hour, TIME_DELIMITER, travel -> departure_time.minute,
				travel -> price, DOLLAR_CHARACTER, travel -> total_seats, travel -> free_seats, travel -> additional_notes);
		printf("\n+----+-----------------------------+------------------+------------------+------------------+----------+----------+----------+----------------------------------------+");
	}
}

bool isIdTravelEqual(const Travel_t *travel, const int *id)
{
	bool equal_id = false;

	if(!(travel -> deleted))
	{
		// The travel is not deleted
		if(travel -> id == *id)
		{
			equal_id = true;
		}
	}

	return equal_id;
}

void showMemberTravel(void)
{
	printf("\n\n\n+--------------------+-----------------------+");
	printf("\n|  Number of Member  |         Member        |");
	printf("\n+--------------------+-----------------------+");
	printf("\n|         %d          | Departure Destination |", departure_destination);
	printf("\n+--------------------+-----------------------+");
	printf("\n|         %d          |  Arrival Destination  |", arrival_destination);
	printf("\n+--------------------+-----------------------+");
	printf("\n|         %d          |     Departure Date    |", departure_date);
	printf("\n+--------------------+-----------------------+");
	printf("\n|         %d          |     Departure Time    |", departure_time);
	printf("\n+--------------------+-----------------------+");
	printf("\n|         %d          |      Total Seats      |", total_seats);
	printf("\n+--------------------+-----------------------+");
	printf("\n|         %d          |       Free Seats      |", free_seats);
	printf("\n+--------------------+-----------------------+");
	printf("\n|         %d          |         Price         |", price);
	printf("\n+--------------------+-----------------------+");
	printf("\n|         %d          |    Additional Notes   |", additional_notes);
	printf("\n+--------------------+-----------------------+");

}

File_status_t addDriver(const char path_file_driver[], const int *id_driver) // This function return true if the driver has been added to the system
{
	File_status_t operation = error;
	Driver_t driver;

	resetDriver(&driver);

	setDriver(&driver, id_driver); // Get information of the driver
	operation = writeFile(path_file_driver, &driver, sizeof(driver), 0, SEEK_END); // Write the driver into the file
	return operation;
}

File_status_t editDriver(const char path_file_driver[])
{
	File_status_t operation = done;
	Driver_t driver;
	Driver_members_t member_input = id_driver - 1;
	long int index_id = INDEX_NOT_FOUND; // This variable is used to get the index of the ID

	resetDriver(&driver);

	// Get index of the driver that the user want to edit
	index_id = getIndexDriverUser(path_file_driver, DRIVER_ID_EDIT_PRINTF_VALUE_INPUT, DRIVER_ID_EDIT_PRINTF_VALUE_ERROR);

	if(index_id != INDEX_NOT_FOUND)
	{
		// Loads driver from file
		operation = readFile(path_file_driver, &driver, sizeof(driver), index_id, SEEK_SET);
		if(operation == done)
		{
			showMemberDriver(); // Output of the member

			// Get the member of the driver that the user wants to edit
			setNumberInput((int *) &member_input, name, comfort_capacity, MEMBER_PRINTF_VALUE_INPUT, MEMBER_PRINTF_VALUE_ERROR);

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
					setDate(&driver.birthday, MIN_YEAR_BIRTHDAY, MAX_YEAR_BIRTHDAY, DRIVER_BIRTHDAY_PRINTF_VALUE);
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
			operation = writeFile(path_file_driver, &driver, sizeof(driver), index_id, SEEK_SET);
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

File_status_t deleteDriver(const char path_file_driver[]) // This function returns true if the driver has been deleted to the system
{
	File_status_t operation = done;
	Driver_t driver;
	long int index_id = INDEX_NOT_FOUND; // Variable that will store the index of the ID

	resetDriver(&driver);

	// Get index of the driver that the user want to delete
	index_id = getIndexDriverUser(path_file_driver, DRIVER_ID_DELETE_PRINTF_VALUE_INPUT, DRIVER_ID_DELETE_PRINTF_VALUE_ERROR);

	if(index_id != INDEX_NOT_FOUND)
	{
		// The driver has been found so the system will delete him
		operation = readFile(path_file_driver, &driver, sizeof(driver), index_id, SEEK_SET);
		if(operation == done)
		{
			driver.deleted = true;
			operation = writeFile(path_file_driver, &driver, sizeof(driver), index_id, SEEK_SET);
		}
	}
	else
	{
		// The driver has non been found
		operation = error;
	}

	return operation;
}

File_status_t showAllDrivers(const char path_file_driver[]) // This function return true if has read all records of the file, "path" is the path of the file that stores the drivers
{
	File_status_t operation = error;
	Driver_t driver;
	long int i = 0;

	resetDriver(&driver);

	printf("\n+----+-----------------+-----------------+-----------------------------------+-------------------+-----------------+----------+------+----------+----------+---------+");
	printf("\n| ID |       Name      |     Surname     |               Email               |      Password     |   Phone Number  | Birthday |Gender|Drv. Cpty.|Cmf. Cpty.|Avg. Rat.|");
	printf("\n+----+-----------------+-----------------+-----------------------------------+-------------------+-----------------+----------+------+----------+----------+---------+");

	do
	{
		operation = readFile(path_file_driver, &driver, sizeof(driver), i, SEEK_CUR);
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

File_status_t addTravel(const char path_file_travel[], const char path_file_driver[], const int *id_travel) // This function returns true if the travel has been added to the system
{
	File_status_t operation = error;
	Travel_t travel;

	resetTravel(&travel);

	setTravel(&travel, id_travel, path_file_driver); // Get information of the travel
	operation = writeFile(path_file_travel, &travel, sizeof(travel), 0, SEEK_END); // Write the travel into the file
	return operation;
}

File_status_t editTravel(const char path_file_travel[], const char path_file_driver[]) // This function returns true if the driver has been edited
{
	File_status_t operation = done;
	Travel_t travel;
	Travel_members_t member_input = id_travel - 1;
	long int index_id = INDEX_NOT_FOUND; // This variable is used to get the index of the ID

	resetTravel(&travel);

	// Get index of the travel that the user want to edit
	index_id = getIndexTravelUser(path_file_travel, path_file_driver, TRAVEL_ID_EDIT_PRINTF_VALUE_INPUT, TRAVEL_ID_EDIT_PRINTF_VALUE_ERROR);

	if(index_id != INDEX_NOT_FOUND)
	{
		// Loads driver from file
		operation = readFile(path_file_travel, &travel, sizeof(travel), index_id, SEEK_SET);
		if(operation == done)
		{
			showMemberTravel(); // Output of the member

			// Get the member of the driver that the user wants to edit
			setNumberInput((int *) &member_input, name, comfort_capacity, MEMBER_PRINTF_VALUE_INPUT, MEMBER_PRINTF_VALUE_ERROR);

			switch(member_input)
			{
				case departure_destination:
					setWord(travel.departure_destination, TRAVEL_DEPARTURE_DESTINATION_PRINTF_VALUE);
					capitalizeString(travel.departure_destination);
					break;
				case arrival_destination:
					setWord(travel.arrival_destination, TRAVEL_ARRIVAL_DESTINATION_PRINTF_VALUE);
					capitalizeString(travel.arrival_destination);
					break;
				case departure_date:
					setDate(&travel.departure_date, MIN_YEAR_TRAVEL, MAX_YEAR_TRAVEL, TRAVEL_DEPARTURE_DATE_PRINTF_VALUE);
					break;
				case departure_time:
					setTime(&travel.departure_time, TRAVEL_DEPARTURE_TIME_PRINTF_VALUE);
					break;
				case total_seats:
					setNumberInput((int *) &travel.total_seats, MIN_NUMBER_TOTAL_SEATS, MAX_NUMBER_TOTAL_SEATS, TRAVEL_TOTAL_SEAT_INPUT, TRAVEL_TOTAL_SEAT_ERROR);
					break;
				case free_seats:
					do
					{
						setNumberInput((int *) &travel.free_seats, MIN_NUMBER_FREE_SEATS, MAX_NUMBER_FREE_SEATS, TRAVEL_FREE_SEAT_INPUT, TRAVEL_FREE_SEAT_ERROR);

						if(!isIncluded(MIN_NUMBER_FREE_SEATS + 1, travel.total_seats - 1, travel.free_seats))
						{
							printf("\nThe number of free seat is bigger than the total of seat in the driver's veicle or you have entered 0 free seats");
						}
					}
					while(!isIncluded(MIN_NUMBER_FREE_SEATS + 1, travel.total_seats - 1, travel.free_seats)); // (min number free seats + 1) was added because 0 free seat is useless, (total seat - 1) was added due to driver's seat
					break;
				case price:
					setPrice(&travel.price);
					break;
				case additional_notes:
					setAdditionalNotes(travel.additional_notes);
					break;
				default:
					break;
			}

			// Write the edited driver into file
			operation = writeFile(path_file_travel, &travel, sizeof(travel), index_id, SEEK_SET);
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

File_status_t deleteTravel(const char path_file_travel[], const char path_file_driver[]) // This function returns true if the travel has been deleted to the system
{
	File_status_t operation = done;
	Travel_t travel;
	long int index_id = INDEX_NOT_FOUND; // Variable that will store the index of the ID

	resetTravel(&travel);

	// Get index of the driver that the user want to delete
	index_id = getIndexTravelUser(path_file_travel, path_file_driver, TRAVEL_ID_DELETE_PRINTF_VALUE_INPUT, TRAVEL_ID_DELETE_PRINTF_VALUE_ERROR);

	if(index_id != INDEX_NOT_FOUND)
	{
		// The driver has been found so the system will delete him
		operation = readFile(path_file_travel, &travel, sizeof(travel), index_id, SEEK_SET);
		if(operation == done)
		{
			travel.deleted = true;
			operation = writeFile(path_file_travel, &travel, sizeof(travel), index_id, SEEK_SET);
		}
	}
	else
	{
		// The driver has non been found
		operation = error;
	}

	return operation;
}

File_status_t ShowAllTravels(const char path_file_travel[], const char path_file_driver[]) // This function returns true if it has read all records of the file
{
	File_status_t operation = error;
	Travel_t travel;
	long int i = 0;

	resetTravel(&travel);

	printf("\n+----+-----------------------------+------------------+------------------+------------------+----------+----------+----------+----------------------------------------+");
	printf("\n| ID |  Driver's Name and Surname  | Dep. Destination | Arr. Destination |Dep. Date and Time|   Price  |Tot. Seats|Free Seats|            Additional Notes            |");
	printf("\n+----+-----------------------------+------------------+------------------+------------------+----------+----------+----------+----------------------------------------+");

	do
	{
		operation = readFile(path_file_travel, &travel, sizeof(travel), i, SEEK_CUR);
		if(operation == done)
		{
			// The travel has been read
			readTravel(&travel, path_file_driver);
		}
		i++;
	}
	while(operation == done);

	return operation;
}

File_status_t updateID(const char path_file[], const long int offset, int *id)
{
	File_status_t operation = error;

	(*id)++;
	operation = writeFile(path_file, id, sizeof(*id), offset, SEEK_SET);

	return operation;
}

// This function return the index of the driver's ID, the driver's ID is entered by the user using keyboard
long int getIndexDriverUser(const char path_file_driver[], const char printf_value_input[], const char printf_value_error[])
{
	File_status_t operation = error;
	Driver_t driver;
	unsigned long i = 0;
	int id_input = 0; // Variable that will store the input of the ID
	unsigned long index_id = INDEX_NOT_FOUND;

	resetDriver(&driver);

	if(showAllDrivers(path_file_driver))
	{
		// Get the ID of the driver
		setNumberInput(&id_input, INT_MIN, INT_MAX, printf_value_input, printf_value_error);
		do
		{
			operation = readFile(path_file_driver, &driver, sizeof(driver), i, SEEK_CUR);
			if(operation == done)
			{
				// The driver has been read
				if(isIdDriverEqual(&driver, &id_input))
				{
					index_id = i;
				}
			}
				i++;
		}
		while(operation == done);
	}

	return index_id;
}

long int getIndexTravelUser(const char path_file_travel[], const char path_file_driver[] ,const char printf_value_input[], const char printf_value_error[])
{
	File_status_t operation = error;
	Travel_t travel;
	unsigned long i = 0;
	int id_input = 0; // Variable that will store the input of the ID
	unsigned long index_id = INDEX_NOT_FOUND;

	resetTravel(&travel);

	if(ShowAllTravels(path_file_travel, path_file_driver))
	{
		// Get the ID of the driver
		setNumberInput(&id_input, INT_MIN, INT_MAX, printf_value_input, printf_value_error);
		do
		{
			operation = readFile(path_file_travel, &travel, sizeof(travel), i, SEEK_CUR);
			if(operation == done)
			{
				// The driver has been read
				if(isIdTravelEqual(&travel, &id_input))
				{
					index_id = i;
				}
			}
				i++;
		}
		while(operation == done);
	}

	return index_id;
}

// This function return the index of the driver's ID, the driver's ID is passed by pointer
long int getIndexDriver(const char path_file_driver[], const int *id)
{
	File_status_t operation = error;
	Driver_t driver;
	unsigned long i = 0;
	unsigned long index_id = INDEX_NOT_FOUND;

	resetDriver(&driver);

	do
	{
		operation = readFile(path_file_driver, &driver, sizeof(driver), i, SEEK_CUR);
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

long int getIndexTravel(const char path_file_travel[], const char path_file_driver[], const int *id)
{
	File_status_t operation = error;
	Travel_t travel;
	unsigned long i = 0;
	int id_input = 0; // Variable that will store the input of the ID
	unsigned long index_id = INDEX_NOT_FOUND;

	resetTravel(&travel);

	do
	{
		operation = readFile(path_file_travel, &travel, sizeof(travel), i, SEEK_CUR);
		if(operation == done)
		{
			// The driver has been read
			if(isIdTravelEqual(&travel, &id_input))
			{
				index_id = i;
			}
		}
			i++;
	}
	while(operation == done);


	return index_id;
}

void mergeSort(const char path_file[], long int start, long int end)
{
	long int middle = 0;

	if(start < end)
	{
		middle = (start + end) / 2;
		mergeSort(path_file, start, middle);
		mergeSort(path_file, middle + 1, end);

		merge(path_file, start, middle, end);
	}
}

void merge(const char path_file[], long int start, long int middle, long int end)
{
	Driver_t driver1;
	Driver_t driver2;

	long int i = start;
	long int j = middle + 1;
	long int k = 0;

	isValidFile(MERGE_TEMP_FILE_PATH);

	resetDriver(&driver1);
	resetDriver(&driver2);

	while(i <= middle && j <= end)
	{
		readFile(path_file, &driver1, sizeof(Driver_t), i, SEEK_SET);
		readFile(path_file, &driver2, sizeof(Driver_t), j, SEEK_SET);

		if(driver1.driving_capacity <= driver2.driving_capacity)
		{
			writeFile(MERGE_TEMP_FILE_PATH, &driver1, sizeof(Driver_t), k, SEEK_SET);
			i++;
		}
		else
		{
			writeFile(MERGE_TEMP_FILE_PATH, &driver2, sizeof(Driver_t), k, SEEK_SET);
			j++;
		}
		k++;
	}

	while(i <= middle)
	{
		readFile(path_file, &driver1, sizeof(Driver_t), i, SEEK_SET);
		writeFile(MERGE_TEMP_FILE_PATH, &driver1, sizeof(Driver_t), k, SEEK_SET);
		i++;
		k++;
	}

	while(j <= end)
	{
		readFile(path_file, &driver1, sizeof(Driver_t), j, SEEK_SET);
		writeFile(MERGE_TEMP_FILE_PATH, &driver1, sizeof(Driver_t), k, SEEK_SET);
		j++;
		k++;
	}

	for(i = start, j = 0; i <= end; i++, j++)
	{
		readFile(MERGE_TEMP_FILE_PATH, &driver1, sizeof(Driver_t), j, SEEK_SET);
		writeFile(path_file, &driver1, sizeof(Driver_t), i, SEEK_SET);
	}

	deleteFile(MERGE_TEMP_FILE_PATH);
}
