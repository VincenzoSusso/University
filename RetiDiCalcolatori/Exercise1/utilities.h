/**
 * @file serverClient.h
 * @author Vincenzo Susso
 */

// -- Libraries --
#ifndef utilities_h
	#define utilities_h

#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>


// -- Constants --
#define MAX_LENGTH_STRING 100
#define NULL_STRING "\0"

// -- Procedures & Functions Prototypes --
void clearBuffer(void);
void addNullCharacterString(char string[]);
void uppercaseString(char string[]);
void lowercaseString(char string[]);
void resetString(char string[]);
void pause(void);

#endif
