/*
	LABORATORIO DI INFORMATICA - Caso di Studio Carpooling
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
*/

// -- Libraries --
#ifndef File_h
	#define File_h

#include <stdbool.h>
#include <stdio.h>
#include <errno.h> // This library was used to check if a directory exists
#include <direct.h> // This library was used to create directory

// -- Constant --
#define DIRECTORY_PATH "../Files"

#define NUMBER_MEMBER_FILE 1

#define INDEX_NOT_FOUND -1 // This constant is used to check if the index has been found
#define NUMBER_RECORD_ERROR -1 // This constant is used to check if an error has occurred

// -- User-Defined types --

/* 	Used to get the status of the operations with files:
  	- error: this value is returned when a fatal error has occurred
    - fail: this value is returned when a minor error has occurred
   	- done: this value is returned when error has not occurred
*/
typedef enum {error = 0, fail, done} File_status_t;

// -- Procedure & Functions Prototypes --
File_status_t isValidFile(const char path_file[]);
File_status_t deleteFile(const char path_file[]);
File_status_t writeFile(const char path_file[], void* pointer, size_t pointer_size, long int offset, int whence);
File_status_t readFile(const char path_file[], void* pointer, size_t pointer_size, long int offset, int whence);

long int getLastIndex(const char path_file[]);
int getNumberRecord(const char path_file[], size_t size_record);
#endif
