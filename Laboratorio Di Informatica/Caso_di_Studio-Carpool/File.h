/*
	LABORATORIO DI INFORMATICA - Caso di Studio Carpooling
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

// -- Libraries --
#include <stdbool.h>
#include <stdio.h>
#include <errno.h> // This library was used to check if a directory exists
#include <direct.h> // This library was used to create directory

// -- Constant --
#define DIRECTORY_PATH "../Files"

#define NUMBER_MEMBER_FILE 1

// -- User-Defined types --


// -- Procedure & Functions Prototypes --
bool isValidFile(char path[]);
bool writeFile(char path[], void *pointer, size_t pointer_size);
bool readFile(char path[], void* pointer, size_t pointer_size, int offset);
