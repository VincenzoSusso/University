/*
	LABORATORIO DI INFORMATICA - Caso di Studio Carpooling
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
   This library was created in order to provide some utility procedure and functions
*/

// -- Libraries --
#ifndef Utilities_h
    #define Utilities_h

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <windows.h>

// -- Constant --
#define NEWLINE_CHARACTER '\n' // This character is used in order to clear the buffer

// Those characters are used in order to check if the string is a void string
#define NEWLINE_STRING "\n"
#define SPACE_STRING " "
#define NULL_STRING "\0"
#define SPACE_CHARACTER ' ' // Used to check the password
#define PERIOD_STRING "." // Used to check the decimal number

// Those constants are used in order to check the email
#define PERIOD_CHARACTER '.'
#define AT_SIGN_CHARACTER '@'
#define NUMBER_DOT_DOMAIN 1 //This constant is used in order to check if the domain of the email has the right number of dots
#define AT_SIGN_STRING "@" // This character is used in order to check if the email has a @ character

// Those constants are used in order to check the number phone
#define PLUS_CHARACTER '+'
#define MAX_LENGHT_COUNTRY_CODE 4 // This constant was obtained by Plus character + country code lenght
#define MAX_LENGHT_SUBSCRIBER_NUMBER 12

// Those constants are used in order to check the password
#define MIN_UPPERCASE_CHARACTERS 1
#define MIN_NUMBER_CHARACTERS 1

#define BASE_STRTOL 10 // Used to convert a string to long

#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004 // This line is only for older versions of windows headers (pre Win 10)

// Those strings are used in order to make the procedure printfError()
#define RESET "\033[0m"
#define RED "\033[31m"
#define BOLDWHITE "\033[1m\033[37m"

// -- Procedure & Functions Prototypes --
int createRandomValue(const int min, const int max); // Return a random value between min and max
void clearBuffer(void);
void swap(void *first_pointer, void *second_pointer, size_t size_pointer); // The pointer must be of the same type
void initializeCMD(void); // This function is used to enable ANSI escape sequences on CMD
void printfError(const char string[]); // This function is used to make a printf() in red color
void addNullCharacterString(char string[]);
void capitalizeString(char string[]); // This procedure converts the first letter of the string to uppercase and the other ones to lowercase
bool isIncluded(const int min, const int max, const int number); // This function return true if the number is included between min and max
bool isNumberString(const char string[]); // This function return true if each character of the string is a digit
bool isLatinString(const char string[]); // This function return true if each character of the string belongs to the Latin alphabet
bool isVoidString(const char string[]);
bool isEmail(const char email[]);
bool isPassword(const char password[]);
bool isNumberPhone(const char phone_number[]);
bool isDecimalNumber(const char decimal_number[]);

double getSecondSort(const time_t start, const time_t end); //Used to calculate the number of second that the sort has spent
#endif
