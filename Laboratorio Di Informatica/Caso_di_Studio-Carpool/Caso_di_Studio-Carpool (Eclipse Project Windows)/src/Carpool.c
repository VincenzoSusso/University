// -- Libraries --
#include "Carpool.h"

/**
 * @file Carpool.c
 * @author Vincenzo Susso
 * @date 2019 Sep 10
 * @version 1.0
 * @brief This file is the implementation file of Carpool.h
 */

// -- Procedure & Functions --
const char *readGender(const Gender_t *gender)
{
	const static char *gender_name[LENGHT_ARRAY_GENDER] = {READ_GENDER_MALE, READ_GENDER_FEMALE, READ_GENDER_CUSTOM};

	// Using the value of the pointer (*gender) as index of the array
	return gender_name[*gender];
}

const char *readRating(const Rating_t *rating)
{
	const static char *rating_star[LENGHT_ARRAY_RATING] = {READ_RATING_NONE,READ_RATING_ONE_STAR, READ_RATING_TWO_STAR,
														  READ_RATING_THREE_STAR, READ_RATING_FOUR_STAR,
														  READ_RATING_FIVE_STAR};

	// Using the value of the pointer (*rating) as index of the array
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

		// Testing the input
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

		// Testing input
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

		// Testing input
		flag = isVoidString(password) || !isPassword(password) || !isIncluded(MIN_LENGHT_PASSWORD, MAX_LENGHT_STRINGS, (int) strlen(password));
		if(flag)
		{
			printf("\nThe password that you have entered is not valid (the password should contain at least %d characters, an uppercase character and an number character)", MIN_LENGHT_PASSWORD);
		}

	}
	while(flag);
}

void setPhoneNumber(char phone_number[])
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

		// Testing input
		flag = isVoidString(phone_number) || !isPhoneNumber(phone_number) || !isIncluded(MIN_LENGHT_PHONE_NUMBER, MAX_LENGHT_PHONE_NUMBER, (int) strlen(phone_number));
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

	// This variable is used in order to know if the user want or not add additional notes
	bool user_choice_additional_notes = false;

	strcpy(additional_notes, NULL_STRING); // Reset additional notes


	setNumberInput((int *) &user_choice_additional_notes, false, true, "Do you want to add additional notes to the travel (No = 0, Yes = 1): ", "The choice that you have entered is not valid");

	if(user_choice_additional_notes)
	{
		do
		{
			printf("\nEnter the travel's additional notes: ");
			scanf("%39[^\n]s", additional_notes);
			addNullCharacterString(additional_notes);
			clearBuffer();

			// Testing input
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

		printf("\nEnter the price (%s) of the travel (Use the period \".\" to separate the integer part to the decimal portion): ", DOLLAR_STRING);
		scanf("%7[^\n]s", price_input);
		addNullCharacterString(price_input);
		clearBuffer();

		// Testing input
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
			printf("\nThe price that you have inserted is not valid (it should be between %.2lf%s and %.2lf%s, and the integer part should be separeted to the decimal portion by a period \".\")", MIN_PRICE, DOLLAR_STRING, MAX_PRICE, DOLLAR_STRING);
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

		// Testing input
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

	setWord(driver -> name, "driver's name");
	capitalizeString(driver -> name);

	setWord(driver -> surname, "driver's surname");
	capitalizeString(driver -> surname);

	setEmail(driver -> email);
	setPassword(driver -> password);
	setPhoneNumber(driver -> phone_number);
	setDate(&driver -> birthday, MIN_YEAR_BIRTHDAY, MAX_YEAR_BIRTHDAY, "driver's birthday");
	setNumberInput((int *) &driver -> gender, male, custom, "Enter the driver's gender (Male = 0, Female = 1, Custom = 2): ", "The driver's gender that you have entered is not valid");

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

void showSortKeyDriver(void)
{
	printf("\n\n\n+---------------------+-----------------------------+");
	printf("\n|  Number of Sorting  |           Sorting           |");
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |        Increasing ID        |", inc_id_driver);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |        Decreasing ID        |", dec_id_driver);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |       Increasing Name       |", inc_name);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |       Decreasing Name       |", dec_name);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |      Increasing Surname     |", inc_surname);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |      Decreasing Surname     |", dec_surname);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |     Increasing Birthday     |", inc_birthday);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |     Decreasing Birthday     |", dec_birthday);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |      Increasing Gender      |", inc_gender);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d          |      Decreasing Gender      |", dec_gender);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d         | Increasing Driving Capacity |", inc_driving_capacity);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d         | Decreasing Driving Capacity |", dec_driving_capacity);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d         | Increasing Comfort Capacity |", inc_comfort_capacity);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d         | Decreasing Comfort Capacity |", dec_comfort_capacity);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d         |  Increasing Average Rating  |", inc_average_rating);
	printf("\n+---------------------+-----------------------------+");
	printf("\n|          %d         |  Decreasing Average Rating  |", dec_average_rating);
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

void setTravel(Travel_t *travel, const int *id, const char path_file_driver[])
{
	travel -> id = *id;
	do
	{
		travel -> id_driver = getIndexUser(path_file_driver, NULL, "Enter the ID of the driver that will offer the travel: ", "The ID of the driver that you have entered is not valid", DRIVER);
		if(travel -> id_driver == INDEX_NOT_FOUND)
		{
			printf("\nAn error has occurred during the acquisition of the driver's ID");
		}
	}
	while(travel -> id_driver == INDEX_NOT_FOUND);

	setWord(travel -> departure_destination, "travel's departure destination");
	capitalizeString(travel -> departure_destination);

	setWord(travel -> arrival_destination, "travel's arrival destination");
	capitalizeString(travel -> arrival_destination);

	setDate(&travel -> departure_date, MIN_YEAR_TRAVEL, MAX_YEAR_TRAVEL, "travel's departure date");
	setTime(&travel -> departure_time, "travel's departure time");

	setNumberInput((int *) &travel -> total_seats, MIN_NUMBER_TOTAL_SEATS, MAX_NUMBER_TOTAL_SEATS, "Enter the driver's veicle total number seats (the number should be between 2 and 9, and it must include the driver's seat): ", "The driver's veicle total number seats is not valid");
	do
	{
		setNumberInput((int *) &travel -> free_seats, MIN_NUMBER_FREE_SEATS, MAX_NUMBER_FREE_SEATS, "Enter the number of free seats of the driver's veicle (the number should be between 1 and 8): ", "The number of free seats of the driver's veicle is not valid");

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
				travel -> price, DOLLAR_STRING, travel -> total_seats, travel -> free_seats, travel -> additional_notes);
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

void showSortKeyTravel(void)
{
	printf("\n\n\n+---------------------+-----------------------------------+");
	printf("\n|  Number of Sorting  |              Sorting              |");
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |           Increasing ID           |", inc_id_travel);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |           Decreasing ID           |", dec_id_travel);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |  Increasing Departure Destination |", inc_departure_destination);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |  Decreasing Departure Destination |", dec_departure_destination);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |   Increasing Arrival Destination  |", inc_arrival_destination);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |   Decreasing Arrival Destination  |", dec_arrival_destination);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |     Increasing Departure Date     |", inc_departure_date);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |     Decreasing Departure Date     |", dec_departure_date);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |          Increasing Price         |", inc_price);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d          |          Decreasing Price         |", dec_price);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d         |       Increasing Total Seats      |", inc_total_seats);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d         |       Decreasing Total Seats      |", dec_total_seats);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d         |       Increasing Free Seats       |", inc_free_seats);
	printf("\n+---------------------+-----------------------------------+");
	printf("\n|          %d         |       Decreasing Free Seats       |", dec_free_seats);
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

File_status_t addStruct(const char path_file_driver[], const char path_file_travel[], const int *id, bool select_struct)
{
	File_status_t operation = error_file;
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
		setTravel(&travel, id, path_file_driver); // Get information of the travel
		operation = writeFile(path_file_travel, &travel, sizeof(Travel_t), 0, SEEK_END); // Write the travel into the file
	}

	return operation;
}

File_status_t editStruct(const char path_file_driver[], const char path_file_travel[], bool select_struct)
{
	File_status_t operation = done;
	Driver_t driver;
	Travel_t travel;
	Driver_members_t member_input_driver = id_driver - 1;
	Travel_members_t member_input_travel = id_travel - 1;
	long int index_record = INDEX_NOT_FOUND; // This variable is used to get the index of the record

	resetDriver(&driver);
	resetTravel(&travel);

	if(select_struct)
	{

		// Get index of the driver that the user want to edit
		index_record = getIndexUser(path_file_driver, path_file_travel, "Enter the ID of the driver that you want to edit: ", "The ID of the driver that you want to edit is not valid", DRIVER);

		if(index_record != INDEX_NOT_FOUND)
		{
			// Index has been found

			// Loads driver from file
			operation = readFile(path_file_driver, &driver, sizeof(Driver_t), index_record, SEEK_SET);
			if(operation == done)
			{
				showMemberDriver(); // Output of the member

				// Get the member of the driver that the user wants to edit
				setNumberInput((int *) &member_input_driver, name, gender, "Enter the number of member that you want to edit: ", "The number of member that you have entered is not valid");

				switch(member_input_driver)
				{
					case name:
						setWord(driver.name, "driver's name");
						capitalizeString(driver.name);
						break;
					case surname:
						setWord(driver.surname, "driver's surname");
						capitalizeString(driver.surname);
						break;
					case email:
						setEmail(driver.email);
						break;
					case password:
						setPassword(driver.password);
						break;
					case phone_number:
						setPhoneNumber(driver.phone_number);
						break;
					case birthday:
						setDate(&driver.birthday, MIN_YEAR_BIRTHDAY, MAX_YEAR_BIRTHDAY, "driver's birthday");
						break;
					case gender:
						setNumberInput((int *) &driver.gender, male, custom, "Enter the driver's gender (Male = 0, Female = 1, Custom = 2): ", "The driver's gender that you have entered is not valid");
						break;
					default:
						break;
				}

				// Write the edited driver into file
				operation = writeFile(path_file_driver, &driver, sizeof(Driver_t), index_record, SEEK_SET);
			}
			else
			{
				// Force the operation to error bacause an error has occurred during the reading of the file
				operation = error_file;
			}
		}
		else
		{
			// The driver has non been found
			operation = error_file;
		}
	}
	else
	{
		// Get index of the travel that the user want to edit
		index_record = getIndexUser(path_file_driver, path_file_travel, "Enter the ID of the travel that you want to edit: ", "The ID of the travel that you want to edit is not valid", TRAVEL);

		if(index_record != INDEX_NOT_FOUND)
		{
			// Index has been found

			// Loads travel from file
			operation = readFile(path_file_travel, &travel, sizeof(Travel_t), index_record, SEEK_SET);
			if(operation == done)
			{
				showMemberTravel(); // Output of the member

				// Get the member of the travel that the user wants to edit
				setNumberInput((int *) &member_input_travel, departure_destination, additional_notes, "Enter the number of member that you want to edit: ", "The number of member that you have entered is not valid");

				switch(member_input_travel)
				{
					case departure_destination:
						setWord(travel.departure_destination, "travel's departure destination");
						capitalizeString(travel.departure_destination);
						break;
					case arrival_destination:
						setWord(travel.arrival_destination, "travel's arrival destination");
						capitalizeString(travel.arrival_destination);
						break;
					case departure_date:
						setDate(&travel.departure_date, MIN_YEAR_TRAVEL, MAX_YEAR_TRAVEL, "travel's departure date");
						break;
					case departure_time:
						setTime(&travel.departure_time, "travel's departure time");
						break;
					case total_seats:
						setNumberInput((int *) &travel.total_seats, MIN_NUMBER_TOTAL_SEATS, MAX_NUMBER_TOTAL_SEATS, "Enter the driver's veicle total number seats (the number should be between 2 and 9, and it must include the driver's seat): ", "The driver's veicle total number seats is not valid");
						break;
					case free_seats:
						do
						{
							setNumberInput((int *) &travel.free_seats, MIN_NUMBER_FREE_SEATS, MAX_NUMBER_FREE_SEATS, "Enter the number of free seats of the driver's veicle (the number should be between 1 and 8): ", "The number of free seats of the driver's veicle is not valid");

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
				operation = writeFile(path_file_travel, &travel, sizeof(Travel_t), index_record, SEEK_SET);
			}
			else
			{
				// Force the operation to error bacause an error has occurred during the reading of the file
				operation = error_file;
			}
		}
		else
		{
			// The travel has non been found
			operation = error_file;
		}
	}

	return operation;
}

File_status_t deleteStruct(const char path_file_driver[], const char path_file_travel[], bool select_struct)
{
	File_status_t operation = done;
	Driver_t driver;
	Travel_t travel;
	int id = -1;
	long int index_record = INDEX_NOT_FOUND; // Variable that will store the index of the record
	long int i = 0; // Used to search travel to delete after the delete of the driver

	resetDriver(&driver);
	resetTravel(&travel);

	if(select_struct)
	{

		// Get index of the driver that the user want to delete
		index_record = getIndexUser(path_file_driver, path_file_travel, "Enter the ID of the driver that you want to delete: ", "The ID of the driver that you want to delete is not valid", DRIVER);

		if(index_record != INDEX_NOT_FOUND)
		{
			// The driver has been found so the system will delete him
			operation = readFile(path_file_driver, &driver, sizeof(Driver_t), index_record, SEEK_SET);
			if(operation == done)
			{
				id = driver.id; // Get the ID in order to search the travel to delete
				driver.deleted = true;
				operation = writeFile(path_file_driver, &driver, sizeof(Driver_t), index_record, SEEK_SET);
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
			operation = error_file;
		}
	}
	else
	{
		// Get index of the driver that the user want to delete
		index_record = getIndexUser(path_file_driver, path_file_travel, "Enter the ID of the travel that you want to delete: ", "The ID of the driver that you want to delete is not valid", TRAVEL);

		if(index_record != INDEX_NOT_FOUND)
		{
			// The driver has been found so the system will delete him
			operation = readFile(path_file_travel, &travel, sizeof(Travel_t), index_record, SEEK_SET);
			if(operation == done)
			{
				travel.deleted = true;
				operation = writeFile(path_file_travel, &travel, sizeof(Travel_t), index_record, SEEK_SET);
			}
		}
		else
		{
			// The driver has non been found
			operation = error_file;
		}
	}

	return operation;
}

File_status_t showAllStructs(const char path_file_driver[], const char path_file_travel[], bool select_struct) // This function returns if it has read all records of the file
{
	File_status_t operation = error_file;
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
	File_status_t reading_operation = error_file;
	File_status_t writing_operation = error_file;
	Travel_t travel;
	Booking_travel_t booking_travel;


	int id_input_travel = -1; // This variable is used to take the input of the ID

	int id_travel = -1; // Used to check if the ID that the user has choosen is valid
	long int i = 0; // Index of the travel's file
	long int j = 0; // Index of the temporary file

	resetTravel(&travel);
	resetBookingTravel(&booking_travel);

	if(isValidFile(BOOK_TRAVEL_TEMP_FILE_PATH))
	{
		// Take input
		setWord(booking_travel.departure_destination, "travel's departure destination");
		capitalizeString(booking_travel.departure_destination);

		setWord(booking_travel.arrival_destination, "travel's arrival destination");
		capitalizeString(booking_travel.arrival_destination);

		setDate(&booking_travel.departure_date, MIN_YEAR_TRAVEL, MAX_YEAR_TRAVEL, "travel's departure date");
		setTime(&booking_travel.departure_time, "travel's departure time");

		setNumberInput((int *) &booking_travel.number_seats, MIN_NUMBER_FREE_SEATS + 1, MAX_NUMBER_FREE_SEATS, "Enter the number of seats that you need: ", "The number of seats that you have entered is not valid");

		i = 0;
		j = 0;

		// Save valid travel to temporary file
		do
		{
			reading_operation = readFile(path_file_travel, &travel, sizeof(Travel_t), i, SEEK_SET);
			if(reading_operation == done)
			{
				if(cmpString(booking_travel.departure_destination, travel.departure_destination) && cmpString(booking_travel.arrival_destination, travel.arrival_destination) && (cmpDate(&booking_travel.departure_date, &travel.departure_date) == equal) && (cmpTime(&booking_travel.departure_time, &travel.departure_time) <= equal) && (booking_travel.number_seats <= travel.free_seats))
				{
					writing_operation = writeFile(BOOK_TRAVEL_TEMP_FILE_PATH, &travel.id , sizeof(int), j, SEEK_SET);
					if(!writing_operation)
					{
						reading_operation = error_file;
						writing_operation = error_file;
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


			// Get the number of the ID of the travel that the user wants to book
			setNumberInput(&id_input_travel, INT_MIN, INT_MAX, "Enter the ID of the travel that you want to book: ", "The ID of the travel that you want to book is not valid");
			reading_operation = done;
			i = 0;
			travel_booked = false; // Used to check if the ID of the driver is a correct ID

			// Booking the travel with the ID specified by the user
			while(i < j && reading_operation == done)
			{
				reading_operation = readFile(BOOK_TRAVEL_TEMP_FILE_PATH, &id_travel, sizeof(int), i, SEEK_SET);
				if(id_input_travel == id_travel)
				{
					travel_booked = true;
					readFile(path_file_travel, &travel, sizeof(Travel_t), getIndex(path_file_travel, &id_travel, TRAVEL), SEEK_SET);
					travel.free_seats -= booking_travel.number_seats;
					writeFile(path_file_travel, &travel, sizeof(Travel_t), getIndex(path_file_travel, &id_travel, TRAVEL), SEEK_SET);
				}
				i++;
			}
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
	File_status_t operation = error_file;
	Driver_t driver;
	Rating_file_t rating;

	// Used to calculate the driving capacity
	int number_rating_driving_capacity = 0;
	int sum_rating_driving_capacity = 0;

	// Used to calculate the comfort capacity
	int number_rating_comfort_capacity = 0;
	int sum_rating_comfort_capacity = 0;

	// Used to calculate the average rating
	int number_total_rating = 0;
	int sum_total_rating = 0;

	long int i = 0; // Index of drivers
	long int j = 0; // Index of ratings

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

		// Get driver from file
		operation = readFile(path_file_driver, &driver, sizeof(Driver_t), i, SEEK_SET);
		while(operation == done)
		{
			// Searchin rating of the driver that has just been read from the file
			operation = readFile(path_file_rating, &rating, sizeof(Rating_file_t), j, SEEK_SET);
			if(isIdDriverEqual(&driver, &rating.id_driver))
			{
				// A rating of the travel has been found

				// Operations used to calculate the arithmetic mean of total rating
				number_total_rating++;
				sum_total_rating += rating.rating;

				if(rating.option_rating)
				{
					// Operations used to calculate the arithmetic mean of comfort capacity
					number_rating_comfort_capacity++;
					sum_rating_comfort_capacity += rating.rating;
				}
				else
				{
					// Operations used to calculate the arithmetic mean of driving capacity
					number_rating_driving_capacity++;
					sum_rating_driving_capacity += rating.rating;
				}
			}
			j++;
		}

		if(number_total_rating)
		{
			// Assigning the arithmetic mean to the driver

			driver.average_rating = sum_total_rating / number_total_rating; // Calculating arithmetic mean of total rating

			if(number_rating_comfort_capacity)
			{
				// Calculating arithmetic mean of comfort rating
				driver.comfort_capacity = sum_rating_comfort_capacity / number_rating_comfort_capacity;
			}

			if(number_rating_driving_capacity)
			{
				// Calculating arithmetic mean of driving rating
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
	File_status_t operation = error_file;
	Rating_file_t rating;
	Driver_t driver;
	bool id_driver_not_valid = true; // Used to understand if the user has entered a valid ID

	long int i = 0;

	resetDriver(&driver);

	showAllStructs(path_file_driver, NULL, DRIVER);

	// Get the id of the driver to evalutate
	setNumberInput(&rating.id_driver, INT_MIN, INT_MAX, "Enter the ID of the driver that you want to evaluate: ", "The ID that you have entered is not valid");

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
		operation = error_file;
	}
	else
	{
		// Get the kind of evalutating that the user wants to do
		setNumberInput((int *) &rating.option_rating, false, true, "Enter what you want to evaluate (Driving capacity = 0, Comfort capacity = 1): ", "The choice that you have entered is not valid");

		if(rating.option_rating)
		{
			// Entering the comfort rating
			setNumberInput((int *) &rating.rating,one_star, five_star, "Enter the driver's comfort capacity (It should be between 1 and 5): ", "The driver's driving capacity that you have entered is not valid");
		}
		else
		{
			// Entering the driving rating
			setNumberInput((int *) &rating.rating, one_star, five_star, "Enter the driver's driving capacity (It should be between 1 and 5): ", "The driver's driving capacity that you have entered is not valid");
		}

		// Writing the rating to the file
		operation = writeFile(path_file_rating, &rating, sizeof(Rating_file_t), 0, SEEK_END);

		if(operation)
		{
			// Adding the rating to the driver
			operation = manageRating(path_file_driver, path_file_rating);
		}
	}

	return operation;
}

File_status_t updateID(const char path_file[], const long int offset, int *id)
{
	File_status_t operation = error_file;

	(*id)++;
	operation = writeFile(path_file, id, sizeof(int), offset, SEEK_SET);

	return operation;
}

long int getIndexUser(const char path_file_driver[], const char path_file_travel[], const char printf_value_input[], const char printf_value_error[], bool select_struct)
{
	File_status_t operation = error_file;
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
				// Reading drivers
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
				// Reading travels
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

long int getIndex(const char path_file[], const int *id, bool select_struct)
{
	File_status_t operation = error_file;
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
			// Reading drivers
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
			// Reading travels
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

double setSort(const char path_file[], long int start, long int end, bool select_struct)
{
	double sorting_seconds = 0; // Returning value that shows how many seconds have the sorting alghoritm spent

	time_t sorting_start = 0;
	time_t sorting_end = 0;

	int sort_key_input = -1;

	if(select_struct)
	{
		showSortKeyDriver();
		setNumberInput(&sort_key_input, inc_id_driver, dec_average_rating, "Enter the number of sorting that you want to do on the drivers: ", "The number of sorting that you have entered is not valid");
		sorting_start = clock();
		mergeSort(path_file, start, end, select_struct, sort_key_input);
		sorting_end = clock();
	}
	else
	{
		showSortKeyTravel();
		setNumberInput(&sort_key_input, inc_id_travel, dec_free_seats, "Enter the number of sorting that you want to do on the travels: ", "The number of sorting that you have entered is not valid");
		sorting_start = clock();
		mergeSort(path_file, start, end, select_struct, sort_key_input);
		sorting_end = clock();
	}

	if(sorting_start != -1 && sorting_end != -1)
	{
		// The functions clock() have not failed
		sorting_seconds = getSecondSort(sorting_start, sorting_end);
	}

	return sorting_seconds;
}

void mergeSort(const char path_file[], long int start, long int end, bool select_struct, int key_sort)
{
	long int middle = 0;

	if(start < end)
	{
		middle = (start + end) / 2;
		mergeSort(path_file, start, middle, select_struct, key_sort);
		mergeSort(path_file, middle + 1, end, select_struct, key_sort);

		if(select_struct)
		{
			mergeDriver(path_file, start, middle, end, key_sort);
		}
		else
		{
			mergeTravel(path_file, start, middle, end, key_sort);
		}
	}
}

void mergeDriver(const char path_file[], long int start, long int middle, long int end, int key_sort)
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

			// Using the sorting key to make different kind of sorting
			switch(key_sort)
			{
				case inc_id_driver:
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
				case dec_id_driver:
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
				case inc_name:
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
				case dec_name:
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
				case inc_surname:
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
				case dec_surname:
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
				case inc_birthday:
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
				case dec_birthday:
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
				case inc_gender:
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
				case dec_gender:
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
				case inc_driving_capacity:
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
				case dec_driving_capacity:
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
				case inc_comfort_capacity:
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
				case dec_comfort_capacity:
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
				case inc_average_rating:
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
				case dec_average_rating:
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

void mergeTravel(const char path_file[], long int start, long int middle, long int end, int key_sort)
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

			// Using the sorting key to make different kind of sorting
			switch(key_sort)
			{
				case inc_id_travel:
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
				case dec_id_travel:
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
				case inc_departure_destination:
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
				case dec_departure_destination:
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
				case inc_arrival_destination:
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
				case dec_arrival_destination:
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
				case inc_departure_date:
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
				case dec_departure_date:
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
				case inc_price:
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
				case dec_price:
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
				case inc_total_seats:
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
				case dec_total_seats:
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
				case inc_free_seats:
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
				case dec_free_seats:
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
