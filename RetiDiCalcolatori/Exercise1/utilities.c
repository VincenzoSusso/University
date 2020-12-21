/**
 * @file utilities.c
 * @author Vincenzo Susso
 */

// -- Libraries --
#include "utilities.h"

// -- Procedures & Functions Prototypes --
void clearBuffer(void) {
    while(getchar() != '\n'){};
}
void addNullCharacterString(char string[]) {
	strcat(string, NULL_STRING);
}

void uppercaseString(char string[]) {
	if(strlen(string) > 0) {
		for(unsigned short i = 0; i < strlen(string); i++) {
			string[i] = toupper(string[i]);
		}
	}
}

void lowercaseString(char string[]) {
	if(strlen(string) > 0) {
		for(unsigned short i = 0; i < strlen(string); i++) {
			string[i] = tolower(string[i]);
		}
	}
}

void resetString(char string[]) {
	strcpy(string, NULL_STRING); // Reset word
}

void pause(void) {
	printf("\n\nPress Any Key to Continue\n");
	getch();
}
