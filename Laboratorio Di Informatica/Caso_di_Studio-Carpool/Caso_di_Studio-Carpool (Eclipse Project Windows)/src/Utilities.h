/*
	LABORATORIO DI INFORMATICA - Caso di Studio Carpooling
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
   This library was created in order to provide some utility procedure and functions
*/

/**
 * @file Utilities.h
 * @author Vincenzo Susso
 * @date 2019 Sep 09
 * @version 1.0
 * @brief This library was created in order to provide some utility procedures and functions.
 *
 * This library provide several utility, for example, the procedure cleanBuffer() can clear the buffer after an input,
 * some function are used in order to check the correct insertion of a string and some function are used to operate
 * on strings.
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
#include <math.h>
#include <windows.h>

// -- Constant --
/**
 * @def NEWLINE_CHARACTER
 * This character is used in order to clean the buffer after an input.
 * */
#define NEWLINE_CHARACTER '\n'


// Those constant are used to check void strings
/**
 * @def NEWLINE_STRING
 * This character is used in order to check if the input string is a void string.
 */
#define NEWLINE_STRING "\n"


/**
 * @def SPACE_STRING
 * This character is used in order to check if the input string is a void string.
 */
#define SPACE_STRING " "


/**
 * @def NULL_STRING
 * This character is used in order to check if the input string is a void string.
 */
#define NULL_STRING "\0"


// Those constant are used to check the email
/**
 * @def PERIOD_CHARACTER
 * This character is used in order to check if the email has a valid domain.
 */
#define PERIOD_CHARACTER '.'


/**
 * @def AT_SIGN_STRING
 * This string is used in order to check if the email has an at sign character "@".
 */
#define AT_SIGN_STRING "@"


/**
 * @def NUMBER_DOT_DOMAIN
 * This integer is used in order to check if the domain of the email has the right number of dots.
 */
#define NUMBER_DOT_DOMAIN 1


// Those constants are used in order to check the number phone
/**
 * @def PLUS_CHARACTER
 * This character is used in order to check if the number has a valid country code.
 */
#define PLUS_CHARACTER '+'


/**
 * @def MAX_LENGHT_COUNTRY_CODE
 * This integer is used to check the correct number of characters that made the country code,
 * this integer is obtained by: Plus character "+" + Country code lenght (3).
 */
#define MAX_LENGHT_COUNTRY_CODE 4


/**
 * @def MAX_LENGHT_SUBSCRIBER_NUMBER
 * This integer is used to check the correct number of characters that made the subscriber number.
 */
#define MAX_LENGHT_SUBSCRIBER_NUMBER 12


// Those constants are used in order to check the password
/**
 * @def MIN_UPPERCASE_CHARACTERS
 * This integer is used to check if the password has the minimum number of uppercase characters.
 */
#define MIN_UPPERCASE_CHARACTERS 1


/**
 * @def MIN_NUMBER_CHARACTERS
 * This integer is used to check if the password has the minimum number of digits.
 */
#define MIN_NUMBER_CHARACTERS 1


/**
 * @def SPACE_CHARACTER
 * This character is used to check if the password doesn't have a space.
 */
#define SPACE_CHARACTER ' '


/**
 * @def BASE_STRTOL
 * This integer is used as base during the convertion of a string to long.
 */
#define BASE_STRTOL 10


/**
 * @def PERIOD_STRING
 * This string is used to check if a decimal number has a period.
 */
#define PERIOD_STRING "."


/**
 * @def MATCHING_PERCENT
 * This integer is used when comparing two strings to indicate the percentage needed.
 */
#define MATCHING_PERCENT 70


/**
 * @def FLOOR_ROUNDING
 * This float is used to approximate a decimal number correctly.
 * The function floor(double x) return the number x rounded dows, so, because of this i need this const.
 * E.g:
 * floor(3.1) = 3
 * floor(3.8) = 3
 * floor(4.2) = 4
 * Using const:
 * floor(3.1 + FLOOR_ROUNDING) = 3
 * floor(3.8 + FLOOR_ROUNDING) = 4
 */
#define FLOOR_ROUNDING 0.5

/**
 * @def ENABLE_VIRTUAL_TERMINAL_PROCESSING
 * This hexadecimal is used in order to enable ANSI escape sequences on CMD (pre Windows 10).
 */
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004


// Those strings are used in order to make the procedure printfError()
/**
 * @def RESET
 * This escape sequence resets the color of the text.
 */
#define RESET "\033[0m"


/**
 * @def RED
 * This escape sequence makes the text red.
 */
#define RED "\033[31m"

// -- Procedure & Functions Prototypes --
/**
 * @fn clearBuffer(void)
 * This procedure is used to clear the buffer after an input, this procedure delete the '\\n' character that usually
 * remains into the buffer after a scanf().
 */
void clearBuffer(void);

/**
 * @fn initializeCMD(void)
 * This procedure is used to enable ANSI escape sequences on CMD.
 */
void initializeCMD(void);

/**
 * @fn printfError(const char string[])
 * This procedure printf the string in red.
 * @param string is printed in red.
 */
void printfError(const char string[]);

/**
 * @fn addNullCharacterString(char string[])
 * The procedure adds the null character to the string in order to indicates the end of the string.
 * @param string null character is added.
 */
void addNullCharacterString(char string[]);


/**
 * @fn capitalizeString(char string[])
 * This procedure converts the first letter of the string to uppercase and the other ones to lowercase.
 * @param string is converted in a string with the first character in uppercase and the other ones to lowercase.
 */
void capitalizeString(char string[]);


/**
 * @fn isIncluded(const int min, const int max, const int number)
 * This function checks if the number is included between min and max.
 * @param min is the minimum valid value.
 * @param max is the maximum valid value.
 * @param number is what the user wants to test.
 * @return true if number is included between min and max, otherwise It will return false.
 */
bool isIncluded(const int min, const int max, const int number);


/**
 * @fn isNumberString(const char string[])
 * This function checks if each character of the string is a digit.
 * @param string is checked in order to see if each character of the string is a digit.
 * @return true if each character of the string is a digit, otherwise It will return false.
 */
bool isNumberString(const char string[]);


/**
 * @fn isLatinString(const char string[])
 * This function checks if each character of the string belongs to the Latin alphabet.
 * @param string is checked in order to see if each character of the string belongs to the Latin alphabet.
 * @return true if each character of the string belongs to the Lating alphabet, otherwise It will return false.
 */
bool isLatinString(const char string[]);


/**
 * @fn isVoidString(const char string[])
 * This function checks if the string is void.
 * @param string is checked in order to see if the string is void.
 * @return true if the string is void, otherwise It will return false.
 */
bool isVoidString(const char string[]);


/**
 * @fn isEmail(const char email[])
 * This function checks if email is valid. The email should be of the format \"localname\@domain\".
 * @param email is checked in order to see if It is valid.
 * @return true if the email is valid, otherwise It will return false.
 */
bool isEmail(const char email[]);


/**
 * @fn isPassword(const char password[])
 * This function checks if the password is valid. The password should have at least one character uppercase and
 * one digit.
 * @param password is checked in order to see if It is valid.
 * @return true if the password is valid, otherwise It will return false.
 */
bool isPassword(const char password[]);


/**
 * @fn isPhoneNumber(const char phone_number[])
 * This function checks if the phone number is valid. The phone number should be of the format \"+xxx xxxxxxxxxxxx\"
 * @param phone_number is checked in order to see if It is valid.
 * @return true if the phone number is valid, otherwise It will return false.
 */
bool isPhoneNumber(const char phone_number[]);


/**
 * @fn isDecimalNumber(const char decimal_number[])
 * This function checks if the decimal number is valid.
 * @param decimal_number is checked in order to see if It is valid.
 * @return true if the decimal number is valid, otherwise It will return false.
 */
bool isDecimalNumber(const char decimal_number[]);


/**
 * @fn cmpString(char first_string[], char second_string[])
 * This function is used to compare two strings. If the matching of the strings is equal or above the 70%, the string
 * will return true.
 * @param first_string is the first member to compare.
 * @param second_string is the second member to compare.
 * @return true if the matching of the strings is equal or abouve the 70%, otherwise this funtion will return false.
 */
bool cmpString(char first_string[], char second_string[]);


/**
 * @fn getSecondSort(const time_t start, const time_t end)
 * This function is used to calculate the number of second that the sort has spent.
 * @param start indicates when the sorting starts.
 * @param end indicates when the sorting ends.
 * @return the seconds that the sorting algorithms has spent.
 */
double getSecondSort(const time_t start, const time_t end);

#endif
