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
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>

// -- Constant --
#define NEWLINE_CHARACTER '\n' // This character is used in order to clear the buffer

// Those constants are used in order to check the email
#define PERIOD_CHARACTER '.'
#define AT_SIGN_CHARACTER '@'
#define NUMBER_DOT_DOMAIN 1 //This constant is used in order to check if the domain of the email has the right number of dots
#define AT_SIGN_STRING "@" // This character is used in order to check if the email has a @ character

// Those constants are used in order to check the number phone
#define PLUS_CHARACTER '+'
#define MAX_LENGHT_COUNTRY_CODE 4 // This constant was obtained by Plus character + country code lenght
#define MAX_LENGHT_SUBSCRIBER_NUMBER 12

// Those characters are used in order to check if the string is a void string
#define NEWLINE_STRING "\n"
#define SPACE_STRING " "
#define NULL_STRING "\0"

#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004 // This line is only for older versions of windows headers (pre Win 10)

// Those strings are used in order to make the procedure printfError()
#define RESET "\033[0m"
#define RED "\033[31m"
#define BOLDWHITE "\033[1m\033[37m"

// -- Procedure & Functions Prototypes --
int createRandomValue(int min, int max); // Return a random value between min and max
void clearBuffer(void);
void initializeCMD(void); // This function is used to enable ANSI escape sequences on CMD
void printfError(char string[]); // This function is used to make a printf() in red color
void addNullCharacterString(char string[]);
bool isIncluded(int min, int max, int number); // This function return true if the number is included between min and max
bool isLatinString(char string[]); // This function return true if each character of the string belongs to the Latin alphabet
bool isVoidString(char string[]);
bool isEmail(char email[]);
bool isNumberPhone(char phone_number[]);
