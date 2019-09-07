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
	const static char *rating_star[LENGHT_ARRAY_RATING] = {READ_RATING_NONE,READ_RATING_ONE_STAR, READ_RATING_TWO_STAR,
														  READ_RATING_THREE_STAR, READ_RATING_FOUR_STAR,
														  READ_RATING_FIVE_STAR};

	return rating_star[*rating];
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
	driver -> driving_capacity = none;
	driver -> comfort_capacity = none;
	driver -> average_rating = none;
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

	/*
	setNumberInput((int *) &driver -> driving_capacity, one_star, five_star, DRIVER_DRIVING_CAPACITY_PRINTF_VALUE_INPUT, DRIVER_DRIVING_CAPACITY_PRINTF_VALUE_ERROR);
	setNumberInput((int *) &driver -> comfort_capacity, one_star, five_star, DRIVER_COMFORT_CAPACITY_PRINTF_VALUE_INPUT, DRIVER_COMFORT_CAPACITY_PRINTF_VALUE_ERROR);

	driver -> average_rating = (driver -> driving_capacity + driver -> comfort_capacity) / NUMBER_OF_RATING;
	*/

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
}

void showSortingDriver(void)
{
	printf("\n\n\n+---------------------+-----------------------------+");
	printf("\n|  Number of Sorting  |           Sorting           |");
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |        Increasing ID        |", increasing_id_driver);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |        Decreasing ID        |", decreasing_id_driver);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |       Increasing Name       |", increasing_name);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |       Decreasing Name       |", decreasing_name);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |      Increasing Surname     |", increasing_surname);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |      Decreasing Surname     |", decreasing_surname);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |     Increasing Birthday     |", increasing_birthday);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |     Decreasing Birthday     |", decreasing_birthday);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |      Increasing Gender      |", increasing_gender);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |      Decreasing Gender      |", decreasing_gender);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d         | Increasing Driving Capacity |", increasing_driving_capacity);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d         | Decreasing Driving Capacity |", decreasing_driving_capacity);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d         | Increasing Comfort Capacity |", increasing_comfort_capacity);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d         | Decreasing Comfort Capacity |", decreasing_comfort_capacity);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d         |  Increasing Average Rating  |", increasing_average_rating);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d         |  Decreasing Average Rating  |", decreasing_average_rating);
	printf("\n+---------------------+-----------------------------+\n");
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

void setTravel(Travel_t *travel, const int *id, const char path_file_travel[], const char path_file_driver[])
{
	travel -> id = *id;
	do
	{
		travel -> id_driver = getIndexUser(path_file_driver, path_file_travel, TRAVEL_DRIVER_ID_PRINTF_VALUE_INPUT, TRAVEL_DRIVER_ID_PRINTF_VALUE_ERROR, DRIVER);
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
		readFile(path_driver_file, &driver, sizeof(driver), getIndex(path_driver_file, &travel -> id_driver, DRIVER), SEEK_SET);
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

void showSortingTravel(void)
{
	printf("\n\n\n+---------------------+-----------------------------------+");
	printf("\n|  Number of Sorting  |              Sorting              |");
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |           Increasing ID           |", increasing_id_travel);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |           Decreasing ID           |", decreasing_id_travel);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |  Increasing Departure Destination |", increasing_departure_destination);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |  Decreasing Departure Destination |", decreasing_departure_destination);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |   Increasing Arrival Destination  |", increasing_arrival_destination);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |   Decreasing Arrival Destination  |", decreasing_arrival_destination);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |     Increasing Departure Date     |", increasing_departure_date);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |     Decreasing Departure Date     |", decreasing_departure_date);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |          Increasing Price         |", increasing_price);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |          Decreasing Price         |", decreasing_price);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d         |       Increasing Total Seats      |", increasing_total_seats);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d         |       Decreasing Total Seats      |", decreasing_total_seats);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d         |       Increasing Free Seats       |", increasing_driving_capacity);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d         |       Decreasing Free Seats       |", decreasing_driving_capacity);
	printf("\n+---------------------+-----------------------------------+\n");
}

void resetBookingTravel(Booking_travel_t *booking_travel)
{
	strcpy(booking_travel -> departure_destination, NULL_STRING);
	strcpy(booking_travel -> arrival_destination, NULL_STRING);
	resetDate(&booking_travel -> departure_date);
	resetTime(&booking_travel -> departure_time);
	booking_travel -> number_seats = -1;
}

File_status_t addStruct(const char path_file_driver[], const char path_file_travel[], const int *id, bool select_struct) // This function returns true if the struct has been added to the system
{
	File_status_t operation = error;
	Driver_t driver;
	Travel_t travel;

	resetDriver(&driver);
	resetTravel(&travel);

	if(select_struct)
	{
		setDriver(&driver, id); // Get information of the driver
		operation = writeFile(path_file_driver, &driver, sizeof(Driver_t), 0, SEEK_END); // Write the driver into the file
	}
	else
	{
		setTravel(&travel, id, path_file_travel, path_file_driver); // Get information of the travel
		operation = writeFile(path_file_travel, &travel, sizeof(Travel_t), 0, SEEK_END); // Write the travel into the file
	}

	return operation;
}

File_status_t editStruct(const char path_file_driver[], const char path_file_travel[], bool select_struct) // This function returns true if the struct has been edited
{
	File_status_t operation = done;
	Driver_t driver;
	Travel_t travel;
	Driver_members_t member_input_driver = id_driver - 1;
	Travel_members_t member_input_travel = id_travel - 1;
	long int index_id = INDEX_NOT_FOUND; // This variable is used to get the index of the ID

	resetDriver(&driver);
	resetTravel(&travel);

	if(select_struct)
	{

		// Get index of the driver that the user want to edit
		index_id = getIndexUser(path_file_driver, path_file_travel, DRIVER_ID_EDIT_PRINTF_VALUE_INPUT, DRIVER_ID_EDIT_PRINTF_VALUE_ERROR, DRIVER);

		if(index_id != INDEX_NOT_FOUND)
		{
			// Loads driver from file
			operation = readFile(path_file_driver, &driver, sizeof(Driver_t), index_id, SEEK_SET);
			if(operation == done)
			{
				showMemberDriver(); // Output of the member

				// Get the member of the driver that the user wants to edit
				setNumberInput((int *) &member_input_driver, name, gender, MEMBER_PRINTF_VALUE_INPUT, MEMBER_PRINTF_VALUE_ERROR);

				switch(member_input_driver)
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
					default:
						break;
				}

				// Write the edited driver into file
				operation = writeFile(path_file_driver, &driver, sizeof(Driver_t), index_id, SEEK_SET);
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
	}
	else
	{
		// Get index of the travel that the user want to edit
		index_id = getIndexUser(path_file_driver, path_file_travel, TRAVEL_ID_EDIT_PRINTF_VALUE_INPUT, TRAVEL_ID_EDIT_PRINTF_VALUE_ERROR, TRAVEL);

		if(index_id != INDEX_NOT_FOUND)
		{
			// Loads travel from file
			operation = readFile(path_file_travel, &travel, sizeof(Travel_t), index_id, SEEK_SET);
			if(operation == done)
			{
				showMemberTravel(); // Output of the member

				// Get the member of the travel that the user wants to edit
				setNumberInput((int *) &member_input_travel, departure_destination, additional_notes, MEMBER_PRINTF_VALUE_INPUT, MEMBER_PRINTF_VALUE_ERROR);

				switch(member_input_travel)
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

				// Write the edited travel into file
				operation = writeFile(path_file_travel, &travel, sizeof(Travel_t), index_id, SEEK_SET);
			}
			else
			{
				// Force the operation to error in order to report the error
				operation = error;
			}
		}
		else
		{
			// The travel has non been found
			operation = error;
		}
	}

	return operation;
}

File_status_t deleteStruct(const char path_file_driver[], const char path_file_travel[], bool select_struct) // This function returns true if the struct has been deleted to the system
{
	File_status_t operation = done;
	Driver_t driver;
	Travel_t travel;
	int id = -1;
	long int index_id = INDEX_NOT_FOUND; // Variable that will store the index of the ID
	long int i = 0; // Used to search travel to delete after the delete of the driver

	resetDriver(&driver);
	resetTravel(&travel);

	if(select_struct)
	{

		// Get index of the driver that the user want to delete
		index_id = getIndexUser(path_file_driver, path_file_travel, DRIVER_ID_DELETE_PRINTF_VALUE_INPUT, DRIVER_ID_DELETE_PRINTF_VALUE_ERROR, DRIVER);

		if(index_id != INDEX_NOT_FOUND)
		{
			// The driver has been found so the system will delete him
			operation = readFile(path_file_driver, &driver, sizeof(Driver_t), index_id, SEEK_SET);
			if(operation == done)
			{
				id = driver.id; // Get the ID in order to search the travel to delete
				driver.deleted = true;
				operation = writeFile(path_file_driver, &driver, sizeof(Driver_t), index_id, SEEK_SET);
			}

			if(operation == done)
			{
				i = 0;
				do
				{
					operation = readFile(path_file_travel, &travel, sizeof(Travel_t), i, SEEK_SET);
					if(operation == done && travel.id_driver == id)
					{
						travel.deleted = true;
						operation = writeFile(path_file_travel, &travel, sizeof(Travel_t), i, SEEK_SET);
					}
					i++;
				}
				while(operation == done);
			}
		}
		else
		{
			// The driver has not been found
			operation = error;
		}
	}
	else
	{
		// Get index of the driver that the user want to delete
		index_id = getIndexUser(path_file_driver, path_file_travel, TRAVEL_ID_DELETE_PRINTF_VALUE_INPUT, TRAVEL_ID_DELETE_PRINTF_VALUE_ERROR, TRAVEL);

		if(index_id != INDEX_NOT_FOUND)
		{
			// The driver has been found so the system will delete him
			operation = readFile(path_file_travel, &travel, sizeof(Travel_t), index_id, SEEK_SET);
			if(operation == done)
			{
				travel.deleted = true;
				operation = writeFile(path_file_travel, &travel, sizeof(Travel_t), index_id, SEEK_SET);
			}
		}
		else
		{
			// The driver has non been found
			operation = error;
		}
	}

	return operation;
}

File_status_t showAllStructs(const char path_file_driver[], const char path_file_travel[], bool select_struct) // This function returns if it has read all records of the file
{
	File_status_t operation = error;
	Driver_t driver;
	Travel_t travel;
	long int i = 0;

	resetDriver(&driver);
	resetTravel(&travel);

	if(select_struct)
	{

		printf("\n+----+-----------------+-----------------+-----------------------------------+-------------------+-----------------+----------+------+----------+----------+---------+");
		printf("\n| ID |       Name      |     Surname     |               Email               |      Password     |   Phone Number  | Birthday |Gender|Drv. Cpty.|Cmf. Cpty.|Avg. Rat.|");
		printf("\n+----+-----------------+-----------------+-----------------------------------+-------------------+-----------------+----------+------+----------+----------+---------+");

		do
		{
			operation = readFile(path_file_driver, &driver, sizeof(Driver_t), i, SEEK_SET);
			if(operation == done)
			{
				// The driver has been read
				readDriver(&driver);
			}
			i++;
		}
		while(operation == done);
	}
	else
	{
		printf("\n+----+-----------------------------+------------------+------------------+------------------+----------+----------+----------+----------------------------------------+");
		printf("\n| ID |  Driver's Name and Surname  | Dep. Destination | Arr. Destination |Dep. Date and Time|   Price  |Tot. Seats|Free Seats|            Additional Notes            |");
		printf("\n+----+-----------------------------+------------------+------------------+------------------+----------+----------+----------+----------------------------------------+");

		do
		{
			operation = readFile(path_file_travel, &travel, sizeof(Travel_t), i, SEEK_SET);
			if(operation == done)
			{
				// The travel has been read
				readTravel(&travel, path_file_driver);
			}
			i++;
		}
		while(operation == done);
	}

	return operation;
}

bool bookTravel(const char path_file_driver[], const char path_file_travel[])
{
	bool travel_booked = true;
	File_status_t reading_operation = error;
	File_status_t writing_operation = error;
	Travel_t travel;
	Booking_travel_t booking_travel;


	int id_input_travel = -1; // This variable is used to take the input of the ID

	int id_travel = -1; // Used to check if the ID that the user has choosen is valid
	bool valid_id_travel = false;
	long int i = 0; // Index of the travel's file
	long int j = 0; // Index of the temporary file

	resetTravel(&travel);
	resetBookingTravel(&booking_travel);

	if(isValidFile(BOOK_TRAVEL_TEMP_FILE_PATH))
	{
		// Take input
		setWord(booking_travel.departure_destination, TRAVEL_DEPARTURE_DESTINATION_PRINTF_VALUE);
		capitalizeString(booking_travel.departure_destination);

		setWord(booking_travel.arrival_destination, TRAVEL_ARRIVAL_DESTINATION_PRINTF_VALUE);
		capitalizeString(booking_travel.arrival_destination);

		setDate(&booking_travel.departure_date, MIN_YEAR_TRAVEL, MAX_YEAR_TRAVEL, TRAVEL_DEPARTURE_DATE_PRINTF_VALUE);
		setTime(&booking_travel.departure_time, TRAVEL_DEPARTURE_TIME_PRINTF_VALUE);

		setNumberInput((int *) &booking_travel.number_seats, MIN_NUMBER_FREE_SEATS + 1, MAX_NUMBER_FREE_SEATS, BOOK_TRAVEL_SEATS_PRINTF_VALUE_INPUT, BOOK_TRAVEL_SEATS_PRINTF_VALUE_ERROR);

		i = 0;
		j = 0;

		// Save valid travel to temporary file
		do
		{
			reading_operation = readFile(path_file_travel, &travel, sizeof(Travel_t), i, SEEK_SET);
			if(reading_operation == done)
			{
				if((strcmp(booking_travel.departure_destination, travel.departure_destination) == 0) && (strcmp(booking_travel.arrival_destination, travel.arrival_destination) == 0) && (cmpDate(&booking_travel.departure_date, &travel.departure_date) == equal) && (cmpTime(&booking_travel.departure_time, &travel.departure_time) <= equal) && (booking_travel.number_seats <= travel.free_seats))
				{
					writing_operation = writeFile(BOOK_TRAVEL_TEMP_FILE_PATH, &travel.id , sizeof(int), j, SEEK_SET);
					if(!writing_operation)
					{
						reading_operation = error;
						writing_operation = error;
						travel_booked = false;
					}
					j++;
				}
			}
			i++;
		}
		while(reading_operation == done);

		if(j <= 0 && travel_booked)
		{
			// There's no travel
			printf("\nThere's no travel that matches your research");
			travel_booked = false;
		}

		if(travel_booked)
		{
			printf("\n+----+-----------------------------+------------------+------------------+------------------+----------+----------+----------+----------------------------------------+");
			printf("\n| ID |  Driver's Name and Surname  | Dep. Destination | Arr. Destination |Dep. Date and Time|   Price  |Tot. Seats|Free Seats|            Additional Notes            |");
			printf("\n+----+-----------------------------+------------------+------------------+------------------+----------+----------+----------+----------------------------------------+");

			reading_operation = done;
			i = 0;

			// Printing valid travel
			while(i < j && reading_operation == done)
			{
				reading_operation = readFile(BOOK_TRAVEL_TEMP_FILE_PATH, &id_travel, sizeof(int), i, SEEK_SET);
				if(reading_operation == done)
				{
					reading_operation = readFile(path_file_travel, &travel, sizeof(Travel_t), getIndex(path_file_travel, &id_travel, TRAVEL), SEEK_SET);
					readTravel(&travel, path_file_driver);
				}
				i++;
			}

			// Compare ID to the travel
			do
			{
				// Get the number of the ID of the travel that the user wants to book
				setNumberInput(&id_input_travel, INT_MIN, INT_MAX, BOOK_TRAVEL_ID_PRINTF_VALUE_INPUT, BOOK_TRAVEL_ID_PRINTF_VALUE_ERROR);
				reading_operation = done;
				i = 0;

				while(i < j && reading_operation == done && travel_booked)
				{
					reading_operation = readFile(BOOK_TRAVEL_TEMP_FILE_PATH, &id_travel, sizeof(int), i, SEEK_SET);
					if(id_input_travel == id_travel)
					{
						travel_booked = true;
						valid_id_travel = true;
						readFile(path_file_travel, &travel, sizeof(Travel_t), getIndex(path_file_travel, &id_travel, TRAVEL), SEEK_SET);
						travel.free_seats -= booking_travel.number_seats;
						writeFile(path_file_travel, &travel, sizeof(Travel_t), getIndex(path_file_travel, &id_travel, TRAVEL), SEEK_SET);
					}
					i++;
				}

				if(!valid_id_travel)
				{
					printf("\nThe ID that you have entered doesn't belong to the list");
				}
			}
			while(!valid_id_travel);
		}

		deleteFile(BOOK_TRAVEL_TEMP_FILE_PATH);
	}
	else
	{
		printf("There was no travel that matched your research");
	}

	return travel_booked;
}

File_status_t manageRating(const char path_file_driver[], const char path_file_rating[])
{
	File_status_t operation = error;
	Driver_t driver;
	Rating_operation_t rating;

	int number_rating_driving_capacity = 0;
	int sum_rating_driving_capacity = 0;
	int number_rating_comfort_capacity = 0;
	int sum_rating_comfort_capacity = 0;
	int number_total_rating = 0;
	int sum_total_rating = 0;

	long int i = 0;
	long int j = 0;

	resetDriver(&driver);

	while(i < getNumberRecord(path_file_driver, sizeof(Driver_t)))
	{
		// Reset variable
		j = 0;
		number_rating_driving_capacity = 0;
		sum_rating_driving_capacity = 0;
		number_rating_comfort_capacity = 0;
		sum_rating_comfort_capacity = 0;
		number_total_rating = 0;
		sum_total_rating = 0;

		operation = readFile(path_file_driver, &driver, sizeof(Driver_t), i, SEEK_SET);
		while(operation == done)
		{
			operation = readFile(path_file_rating, &rating, sizeof(Rating_operation_t), j, SEEK_SET);
			if(isIdDriverEqual(&driver, &rating.id_driver))
			{
				number_total_rating++;
				sum_total_rating += rating.rating;
				if(rating.option_rating)
				{
					number_rating_comfort_capacity++;
					sum_rating_comfort_capacity += rating.rating;
				}
				else
				{
					number_rating_driving_capacity++;
					sum_rating_driving_capacity += rating.rating;
				}
			}
			j++;
		}

		if(number_total_rating)
		{
			driver.average_rating = sum_total_rating / number_total_rating;

			if(number_rating_comfort_capacity)
			{
				driver.comfort_capacity = sum_rating_comfort_capacity / number_rating_comfort_capacity;
			}

			if(number_rating_driving_capacity)
			{
				driver.driving_capacity = sum_rating_driving_capacity / number_rating_driving_capacity;
			}

			operation = writeFile(path_file_driver, &driver, sizeof(Driver_t), i, SEEK_SET);
		}

		i++;
	}

	return operation;
}

File_status_t evaluateDriver(const char path_file_driver[], const char path_file_rating[])
{
	File_status_t operation = error;
	Rating_operation_t rating;
	Driver_t driver;
	bool id_driver_not_valid = true;

	long int i = 0;

	resetDriver(&driver);

	showAllStructs(path_file_driver, NULL, DRIVER);

	do
	{
		setNumberInput(&rating.id_driver, INT_MIN, INT_MAX, EVALUATE_ID_DRIVER_PRINTF_VALUE_INPUT, EVALUATE_ID_DRIVER_PRINTF_VALUE_ERROR);
		i = 0;
		do
		{
			operation = readFile(path_file_driver, &driver, sizeof(Driver_t), i, SEEK_SET);
			if(isIdDriverEqual(&driver, &rating.id_driver))
			{
				id_driver_not_valid = false;
			}
			i++;
		}
		while(operation == done && id_driver_not_valid);

		if(id_driver_not_valid)
		{
			printf("\nThe ID that you have entered doesn't belong to the system");
		}
	}
	while(id_driver_not_valid);

	setNumberInput((int *) &rating.option_rating, false, true, EVALUATE_CHOICHE_RATING_PRINTF_VALUE_INPUT, EVALUATE_CHOICHE_RATING_PRINTF_VALUE_ERROR);

	if(rating.option_rating)
	{
		setNumberInput((int *) &rating.rating,one_star, five_star, EVALUATE_COMFORT_CAPACITY_PRINTF_VALUE_INPUT, EVALUATE_COMFORT_CAPACITY_PRINTF_VALUE_ERROR);
	}
	else
	{
		setNumberInput((int *) &rating.rating, one_star, five_star, EVALUATE_DRIVING_CAPACITY_PRINTF_VALUE_INPUT, EVALUATE_DRIVING_CAPACITY_PRINTF_VALUE_ERROR);
	}

	operation = writeFile(path_file_rating, &rating, sizeof(Rating_operation_t), 0, SEEK_END);

	if(operation)
	{
		operation = manageRating(path_file_driver, path_file_rating);
	}

	return operation;
}

File_status_t updateID(const char path_file[], const long int offset, int *id)
{
	File_status_t operation = error;

	(*id)++;
	operation = writeFile(path_file, id, sizeof(int), offset, SEEK_SET);

	return operation;
}

// This function return the index of the driver's ID, the driver's ID is entered by the user using keyboard
long int getIndexUser(const char path_file_driver[], const char path_file_travel[], const char printf_value_input[], const char printf_value_error[], bool select_struct)
{
	File_status_t operation = error;
	Driver_t driver;
	Travel_t travel;
	unsigned long i = 0;
	int id_input = 0; // Variable that will store the input of the ID
	unsigned long index_id = INDEX_NOT_FOUND;

	resetDriver(&driver);
	resetTravel(&travel);

	if(select_struct)
	{
		if(showAllStructs(path_file_driver, path_file_travel, DRIVER))
		{
			// Get the ID of the driver
			setNumberInput(&id_input, INT_MIN, INT_MAX, printf_value_input, printf_value_error);
			do
			{
				operation = readFile(path_file_driver, &driver, sizeof(Driver_t), i, SEEK_SET);
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
	}
	else
	{
		if(showAllStructs(path_file_driver, path_file_travel, TRAVEL))
		{
			// Get the ID of the travel
			setNumberInput(&id_input, INT_MIN, INT_MAX, printf_value_input, printf_value_error);
			do
			{
				operation = readFile(path_file_travel, &travel, sizeof(Travel_t), i, SEEK_SET);
				if(operation == done)
				{
					// The travel has been read
					if(isIdTravelEqual(&travel, &id_input))
					{
						index_id = i;
					}
				}
				i++;
			}
			while(operation == done);
		}
	}

	return index_id;
}

// This function return the index of the driver's ID, the driver's ID is passed by pointer
long int getIndex(const char path_file[], const int *id, bool select_struct)
{
	File_status_t operation = error;
	Driver_t driver;
	Travel_t travel;
	unsigned long i = 0;
	unsigned long index_id = INDEX_NOT_FOUND;

	resetDriver(&driver);
	resetTravel(&travel);

	if(select_struct)
	{
		do
		{
			operation = readFile(path_file, &driver, sizeof(driver), i, SEEK_SET);
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
	}
	else
	{
		do
		{
			operation = readFile(path_file, &travel, sizeof(travel), i, SEEK_SET);
			if(operation == done)
			{
				// The travel has been read
				if(isIdTravelEqual(&travel, id))
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

double setSort(const char path_file[], long int start, long int end, bool select_struct) // It returns the seconds that the sort has spent
{
	double sorting_seconds = 0;
	time_t sorting_start = 0;
	time_t sorting_end = 0;
	int sorting_input = -1;

	if(select_struct)
	{
		showSortingDriver();
		setNumberInput(&sorting_input, increasing_id_driver, decreasing_average_rating, SORTING_DRIVER_PRINTF_VALUE_INPUT, SORTING_DRIVER_PRINTF_VALUE_ERROR);
		sorting_start = clock();
		mergeSort(path_file, start, end, select_struct, sorting_input);
		sorting_end = clock();
	}
	else
	{
		showSortingTravel();
		setNumberInput(&sorting_input, increasing_id_travel, decreasing_free_seats, SORTING_TRAVEL_PRINTF_VALUE_INPUT, SORTING_TRAVEL_PRINTF_VALUE_ERROR);
		sorting_start = clock();
		mergeSort(path_file, start, end, select_struct, sorting_input);
		sorting_end = clock();
	}

	if(sorting_start != -1 && sorting_end != -1)
	{
		// The functions clock() have not failed
		sorting_seconds = getSecondSort(sorting_start, sorting_end);
	}

	return sorting_seconds;
}

void mergeSort(const char path_file[], long int start, long int end, bool select_struct, int kind_sorting)
{
	long int middle = 0;

	if(start < end)
	{
		middle = (start + end) / 2;
		mergeSort(path_file, start, middle, select_struct, kind_sorting);
		mergeSort(path_file, middle + 1, end, select_struct, kind_sorting);

		if(select_struct)
		{
			mergeDriver(path_file, start, middle, end, kind_sorting);
		}
		else
		{
			mergeTravel(path_file, start, middle, end, kind_sorting);
		}
	}
}

void mergeDriver(const char path_file[], long int start, long int middle, long int end, int kind_sorting)
{
	Driver_t first_driver;
	Driver_t second_driver;

	long int i = start;
	long int j = middle + 1;
	long int k = 0;

	resetDriver(&first_driver);
	resetDriver(&second_driver);

	if(isValidFile(MERGE_TEMP_FILE_PATH))
	{
		while(i <= middle && j <= end)
		{
			readFile(path_file, &first_driver, sizeof(Driver_t), i, SEEK_SET);
			readFile(path_file, &second_driver, sizeof(Driver_t), j, SEEK_SET);

			switch(kind_sorting)
			{
				case increasing_id_driver:
					if(first_driver.id <= second_driver.id)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_driver, sizeof(Driver_t), k, SEEK_SET);
						j++;
					}
					break;
				case decreasing_id_driver:
					if(first_driver.id >= second_driver.id)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_driver, sizeof(Driver_t), k, SEEK_SET);
						j++;
					}
					break;
				case increasing_name:
					if(strcmp(first_driver.name, second_driver.name) <= 0)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_driver, sizeof(Driver_t), k, SEEK_SET);
						j++;
					}
					break;
				case decreasing_name:
					if(strcmp(first_driver.name, second_driver.name) >= 0)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_driver, sizeof(Driver_t), k, SEEK_SET);
						j++;
					}
					break;
				case increasing_surname:
					if(strcmp(first_driver.surname, second_driver.surname) <= 0)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_driver, sizeof(Driver_t), k, SEEK_SET);
						j++;
					}
					break;
				case decreasing_surname:
					if(strcmp(first_driver.surname, second_driver.surname) >= 0)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_driver, sizeof(Driver_t), k, SEEK_SET);
						j++;
					}
					break;
				case increasing_birthday:
					if(cmpDate(&first_driver.birthday, &second_driver.birthday) <= equal)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_driver, sizeof(Driver_t), k, SEEK_SET);
						j++;
					}
					break;
				case decreasing_birthday:
					if(cmpDate(&first_driver.birthday, &second_driver.birthday) >= equal)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_driver, sizeof(Driver_t), k, SEEK_SET);
						j++;
					}
					break;
				case increasing_gender:
					if(first_driver.gender <= second_driver.gender)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_driver, sizeof(Driver_t), k, SEEK_SET);
						j++;
					}
					break;
				case decreasing_gender:
					if(first_driver.gender >= second_driver.gender)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_driver, sizeof(Driver_t), k, SEEK_SET);
						j++;
					}
					break;
				case increasing_driving_capacity:
					if(first_driver.driving_capacity <= second_driver.driving_capacity)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_driver, sizeof(Driver_t), k, SEEK_SET);
						j++;
					}
					break;
				case decreasing_driving_capacity:
					if(first_driver.driving_capacity >= second_driver.driving_capacity)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_driver, sizeof(Driver_t), k, SEEK_SET);
						j++;
					}
					break;
				case increasing_comfort_capacity:
					if(first_driver.comfort_capacity <= second_driver.comfort_capacity)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_driver, sizeof(Driver_t), k, SEEK_SET);
						j++;
					}
					break;
				case decreasing_comfort_capacity:
					if(first_driver.comfort_capacity >= second_driver.comfort_capacity)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_driver, sizeof(Driver_t), k, SEEK_SET);
						j++;
					}
					break;
				case increasing_average_rating:
					if(first_driver.average_rating <= second_driver.average_rating)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_driver, sizeof(Driver_t), k, SEEK_SET);
						j++;
					}
					break;
				case decreasing_average_rating:
					if(first_driver.average_rating >= second_driver.average_rating)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_driver, sizeof(Driver_t), k, SEEK_SET);
						j++;
					}
					break;
				default:
					break;
			}
			k++;
		}

		while(i <= middle)
		{
			readFile(path_file, &first_driver, sizeof(Driver_t), i, SEEK_SET);
			writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
			i++;
			k++;
		}

		while(j <= end)
		{
			readFile(path_file, &first_driver, sizeof(Driver_t), j, SEEK_SET);
			writeFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), k, SEEK_SET);
			j++;
			k++;
		}

		for(i = start, j = 0; i <= end; i++, j++)
		{
			readFile(MERGE_TEMP_FILE_PATH, &first_driver, sizeof(Driver_t), j, SEEK_SET);
			writeFile(path_file, &first_driver, sizeof(Driver_t), i, SEEK_SET);
		}

		deleteFile(MERGE_TEMP_FILE_PATH);
	}
}

void mergeTravel(const char path_file[], long int start, long int middle, long int end, int kind_sorting)
{
	Travel_t first_travel;
	Travel_t second_travel;

	long int i = start;
	long int j = middle + 1;
	long int k = 0;

	resetTravel(&first_travel);
	resetTravel(&second_travel);

	if(isValidFile(MERGE_TEMP_FILE_PATH))
	{
		while(i <= middle && j <= end)
		{
			readFile(path_file, &first_travel, sizeof(Travel_t), i, SEEK_SET);
			readFile(path_file, &second_travel, sizeof(Travel_t), j, SEEK_SET);

			switch(kind_sorting)
			{
				case increasing_id_travel:
					if(first_travel.id <= second_travel.id)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_travel, sizeof(Travel_t), k, SEEK_SET);
						j++;
					}
					break;
				case decreasing_id_travel:
					if(first_travel.id >= second_travel.id)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_travel, sizeof(Travel_t), k, SEEK_SET);
						j++;
					}
					break;
				case increasing_departure_destination:
					if(strcmp(first_travel.departure_destination, second_travel.departure_destination) <= 0)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_travel, sizeof(Travel_t), k, SEEK_SET);
						j++;
					}
					break;
				case decreasing_departure_destination:
					if(strcmp(first_travel.departure_destination, second_travel.departure_destination) >= 0)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_travel, sizeof(Travel_t), k, SEEK_SET);
						j++;
					}
					break;
				case increasing_arrival_destination:
					if(strcmp(first_travel.arrival_destination, second_travel.arrival_destination) <= 0)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_travel, sizeof(Travel_t), k, SEEK_SET);
						j++;
					}
					break;
				case decreasing_arrival_destination:
					if(strcmp(first_travel.arrival_destination, second_travel.arrival_destination) >= 0)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_travel, sizeof(Travel_t), k, SEEK_SET);
						j++;
					}
					break;
				case increasing_departure_date:
					if(cmpDate(&first_travel.departure_date, &second_travel.departure_date) == equal)
					{
						if(cmpTime(&first_travel.departure_time, &second_travel.departure_time) <= equal)
						{
							writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
							i++;
						}
						else
						{
							writeFile(MERGE_TEMP_FILE_PATH, &second_travel, sizeof(Travel_t), k, SEEK_SET);
							j++;
						}
					}
					else
					{
						if(cmpDate(&first_travel.departure_date, &second_travel.departure_date) < equal)
						{
							writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
							i++;
						}
						else
						{
							writeFile(MERGE_TEMP_FILE_PATH, &second_travel, sizeof(Travel_t), k, SEEK_SET);
							j++;
						}
					}
					break;
				case decreasing_departure_date:
					if(cmpDate(&first_travel.departure_date, &second_travel.departure_date) == equal)
					{
						if(cmpTime(&first_travel.departure_time, &second_travel.departure_time) >= equal)
						{
							writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
							i++;
						}
						else
						{
							writeFile(MERGE_TEMP_FILE_PATH, &second_travel, sizeof(Travel_t), k, SEEK_SET);
							j++;
						}
					}
					else
					{
						if(cmpDate(&first_travel.departure_date, &second_travel.departure_date) > equal)
						{
							writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
							i++;
						}
						else
						{
							writeFile(MERGE_TEMP_FILE_PATH, &second_travel, sizeof(Travel_t), k, SEEK_SET);
							j++;
						}
					}
					break;
				case increasing_price:
					if(first_travel.price <= second_travel.price)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_travel, sizeof(Travel_t), k, SEEK_SET);
						j++;
					}
					break;
				case decreasing_price:
					if(first_travel.price >= second_travel.price)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_travel, sizeof(Travel_t), k, SEEK_SET);
						j++;
					}
					break;
				case increasing_total_seats:
					if(first_travel.total_seats <= second_travel.total_seats)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_travel, sizeof(Travel_t), k, SEEK_SET);
						j++;
					}
					break;
				case decreasing_total_seats:
					if(first_travel.total_seats >= second_travel.total_seats)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_travel, sizeof(Travel_t), k, SEEK_SET);
						j++;
					}
					break;
				case increasing_free_seats:
					if(first_travel.free_seats <= second_travel.free_seats)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_travel, sizeof(Travel_t), k, SEEK_SET);
						j++;
					}
					break;
				case decreasing_free_seats:
					if(first_travel.free_seats >= second_travel.free_seats)
					{
						writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
						i++;
					}
					else
					{
						writeFile(MERGE_TEMP_FILE_PATH, &second_travel, sizeof(Travel_t), k, SEEK_SET);
						j++;
					}
					break;
				default:
					break;
			}
			k++;
		}

		while(i <= middle)
		{
			readFile(path_file, &first_travel, sizeof(Travel_t), i, SEEK_SET);
			writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
			i++;
			k++;
		}

		while(j <= end)
		{
			readFile(path_file, &first_travel, sizeof(Travel_t), j, SEEK_SET);
			writeFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), k, SEEK_SET);
			j++;
			k++;
		}

		for(i = start, j = 0; i <= end; i++, j++)
		{
			readFile(MERGE_TEMP_FILE_PATH, &first_travel, sizeof(Travel_t), j, SEEK_SET);
			writeFile(path_file, &first_travel, sizeof(Travel_t), i, SEEK_SET);
		}

		deleteFile(MERGE_TEMP_FILE_PATH);
	}
}
