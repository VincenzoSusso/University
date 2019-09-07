// -- Libraries --
#include "Utilities.h"

// -- Procedure & Functions --
void clearBuffer(void)
{
    while(getchar() != NEWLINE_CHARACTER){};
}

void initializeCMD(void) // This function is used to enable ANSI escape sequences on CMD
{
	// For more information, please visit here: https://stackoverflow.com/questions/47157714/escape-character-doesnt-work

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD consoleMode;
	GetConsoleMode(console, &consoleMode);
	consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(console, consoleMode);
}

void printfError(const char string[]) // This function is used to make a printf() in red color
{
	printf("%s%s%s", RED, string, RESET);
}

void addNullCharacterString(char string[])
{
	strcat(string, NULL_STRING);
}

void capitalizeString(char string[]) // This procedure converts the first letter of the string to uppercase and the other ones to lowercase
{
	unsigned short i = 0;

	string[i] = toupper(string[i]);

	for(i = 1; i < strlen(string); i++)
	{
		string[i] = tolower(string[i]);
	}

}

bool isIncluded(const int min, const int max, const int number) // This function return true if the number is included between min and max
{
	bool included_number = false;

	if(number >= min && number <= max)
	{
		included_number = true;
	}

	return included_number;
}

bool isLatinString(const char string[]) // This function return true if each character of the string belongs to the Latin alphabet
{
	bool latin_string = false;
	unsigned short i = 0;

	for(i = 0; i < strlen(string); i++)
	{
		if(isalpha(string[i]))
		{
			latin_string = true;
		}
		else
		{
			latin_string = false;
			i = strlen(string);
		}
	}

	return latin_string;
}

bool isNumberString(const char string[]) // This function return true if each character of the string is a digit
{
	bool number = false;
	unsigned short i = 0;

	for(i = 0; i < strlen(string); i++)
	{
		if(isdigit(string[i]))
		{
			number = true;
		}
		else
		{
			number = false;
			i = strlen(string);
		}
	}

	return number;
}

bool isVoidString(const char string[])
{
    bool void_string = false;

    if(!strcmp(string, SPACE_STRING) || !strcmp(string, NEWLINE_STRING) || !strcmp(string, NULL_STRING))
    {
    	void_string = true;
    }

    return void_string;
}

bool isEmail(const char email[])
{
	/*
		The format of email addresses is local-part@domain.

		The local-part of the email address may use any of these ASCII characters:
		- Uppercase and lowercase Latin letters A to Z and a to z;
		- Digits 0 to 9;
		- Dot ., provided that it is not the first or last character, and provided also that it does not appear consecutively;

		The domain name part of an email address has to conform to strict guidelines:
		- Uppercase and lowercase Latin letters A to Z and a to z;
		- Digits 0 to 9, provided that top-level domain names are not all-numeric;

		For more informations, please visit here: https://en.wikipedia.org/wiki/Email_address
	*/

	bool valid_email = true;
	unsigned short number_dot_domain = 0; // Used to verify if the domain of the email has one dot
	unsigned short i = 0;
	char *copied_email = NULL;
	char *local_part = NULL; // Used to point to the email address' local-part
	char *domain = NULL; // Used to point to the email-address' domain

	// The + 1 was added in order to allow the dynamic array to store the null character
	copied_email = malloc(sizeof(char) * (strlen(email) + 1));

	if(copied_email)
	{
		strcpy(copied_email, email); // The use of the function strtok() modify the original string so I use a copied string to check the email
		local_part = strtok(copied_email, AT_SIGN_STRING); // The function strtok() replaces the @ with a null character and splits the string
		domain = strtok(NULL, NULL_STRING); // The function strtok() takes a pointer NULL in order to re-start from the null character previously inserted
	}
	else
	{
		valid_email = false;
	}

	// It means that the email has the @
	if(domain && valid_email)
	{
		// It means that the local-part of the email starts or ends with a period
		if(*local_part == PERIOD_CHARACTER || *(local_part + (int) (strlen(local_part) - 1)) == PERIOD_CHARACTER)
		{
			valid_email = false;
		}

		while(valid_email && i < (int) strlen(local_part))
		{
			// It means that the local part of the email has a special character which is not allowed
			if(!isalnum(*(local_part + i)) && *(local_part + i) != PERIOD_CHARACTER)
			{
				valid_email = false;
			}

			// It means that the local part of the email constains two dots that appear consecutively
			if(i < (int) (strlen(local_part) - 1) && *(local_part + i) == PERIOD_CHARACTER && *(local_part + i + 1) == PERIOD_CHARACTER)
			{
				valid_email = false;
			}

			i++;
		}

		i = 0;
		while(valid_email && i < (int) strlen(domain))
		{
			// It means that the domain of the email has a character which is not allowed
			if(!isalnum(*(domain + i)) && *(domain + i) != PERIOD_CHARACTER)
			{
				valid_email = false;
			}

			if(*(domain + i) == PERIOD_CHARACTER)
			{
				if(number_dot_domain > NUMBER_DOT_DOMAIN)
				{
					// It means that domain has a number of dots that is not allowed
					valid_email = false;
				}
				else
				{
					number_dot_domain++;
				}
			}

			i++;
		}
	}
	else
	{
		valid_email = false;
	}

	free(copied_email);

	return valid_email && (number_dot_domain == NUMBER_DOT_DOMAIN);
}

bool isPassword(const char password[])
{
	bool valid_password = false;
	bool space = false; // This varible is used to check if the string has a space
	unsigned short i = 0;
	unsigned short uppercase_characters = 0;
	unsigned short number_characters = 0;

	for(i = 0; i < strlen(password); i++)
	{
		if(isupper(password[i]))
		{
			uppercase_characters++;
		}

		if(isdigit(password[i]))
		{
			number_characters++;
		}

		if(password[i] == SPACE_CHARACTER)
		{
			// The password is not valid
			space = true;
			i = strlen(password);
		}

		if(uppercase_characters >= MIN_UPPERCASE_CHARACTERS && number_characters >= MIN_NUMBER_CHARACTERS)
		{
			// The password is valid - Get out from the loop
			i = strlen(password);
		}
	}

	if((uppercase_characters >= MIN_UPPERCASE_CHARACTERS) && (number_characters >= MIN_NUMBER_CHARACTERS) && (!space))
	{
		// The password is valid
		valid_password = true;
	}

	return valid_password;
}

bool isNumberPhone(const char phone_number[])
{
	bool valid_phone_number = true;
	char *copied_number_phone = NULL;
	char *country_code = NULL; // Used to point to the country code of the number phone
	char *subscriber_number = NULL; // Used to point to the number path of the number phone

	// The + 1 was added in order to allow the dynamic array to store the null character
	copied_number_phone = malloc(sizeof(char) * (strlen(phone_number) + 1));

	if(copied_number_phone)
	{
		strcpy(copied_number_phone, phone_number); // The use of the function strtok() modify the original string so I use a copied string to check the phone number
		country_code = strtok(copied_number_phone, SPACE_STRING); // The function strtok() replaces the space with a null character and splits the string
		subscriber_number = strtok(NULL, NULL_STRING); // The function strtok() takes a pointer NULL in order to re-start from the null character previously inserted
	}
	else
	{
		valid_phone_number = false;
	}

	if(subscriber_number && valid_phone_number)
	{
		if(strlen(country_code) > MAX_LENGHT_COUNTRY_CODE || strlen(subscriber_number) > MAX_LENGHT_SUBSCRIBER_NUMBER)
		{
			//The phone number has too many digits
			valid_phone_number = false;
		}

		if(*country_code != PLUS_CHARACTER)
		{
			// The country code doesn't start with + character
			valid_phone_number = false;
		}

		valid_phone_number = isNumberString(country_code + 1) && valid_phone_number;

		valid_phone_number = isNumberString(subscriber_number) && valid_phone_number;
	}
	else
	{
		valid_phone_number = false;
	}

	free(copied_number_phone);

	return valid_phone_number;
}

bool isDecimalNumber(const char decimal_number[])
{
	bool valid_number = true;
	char *copied_decimal_number = NULL;
	char *integer_part = NULL;
	char *decimal_portion = NULL;

	// The + 1 was added in order to allow the dynamic array to store the null character
	copied_decimal_number = malloc(sizeof(char) * (strlen(decimal_number) + 1));

	if(copied_decimal_number)
	{
		strcpy(copied_decimal_number, decimal_number); // The use of the function strtok() modify the original string so I use a copied string to check the decimal number
		integer_part = strtok(copied_decimal_number, PERIOD_STRING); // The function strtok() replaces the space with a null character and splits the string
		decimal_portion = strtok(NULL, NULL_STRING); // The function strtok() takes a pointer NULL in order to re-start from the null character previously inserted
	}
	else
	{
		valid_number = false;
	}

	if(integer_part && valid_number)
	{
		valid_number = isNumberString(integer_part);
	}

	if(decimal_portion && valid_number)
	{
		valid_number = isNumberString(decimal_portion);
	}

	return valid_number;
}

double getSecondSort(const time_t start, const time_t end) //Used to calculate the number of second that the sort has spend
{
     return  ((double) (end - start)) / CLOCKS_PER_SEC;
}
