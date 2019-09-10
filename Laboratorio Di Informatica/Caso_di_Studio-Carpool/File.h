/*
	LABORATORIO DI INFORMATICA - Caso di Studio Carpooling
	-----------------------------
	Name: Vincenzo
	Surname: Susso
	Freshman: 697538
   ------------------------------
   This library was developed in order to manage files.
*/

/**
 * @file File.h
 * @author Vincenzo Susso
 * @date 2019 Sep 10
 * @version 1.0
 * @brief This library was created in order to provide some procedures and functions that are used to files.
 *
 * This library can check if a file exits and can create new files, furthermore this library can read and write a file.
 * This library can get the number of records that have been saved into a file.
 */

// -- Libraries --
#ifndef File_h
	#define File_h

#include <stdbool.h>
#include <stdio.h>
#include <errno.h> // This library was used to check if a directory exists
#include <direct.h> // This library was used to create directory

// -- Constant --
/**
 * @def DIRECTORY_PATH
 * This string is used to indicates the relative path of the directory that will store all the files.
 */
#define DIRECTORY_PATH "../Files"


/**
 * @def NUMBER_MEMBER_FILE
 * This integer indicates the number of member that the file can read/write.
 * This integer can be used to check if the file has been read or written correctly.
 */
#define NUMBER_MEMBER_FILE 1


/**
 * @def INDEX_NOT_FOUND
 * This integer is used to indicates that the index of a record has not been found.
 */
#define INDEX_NOT_FOUND -1

// -- User-Defined types --
/**
 * @enum File_status_t
 * This user-defined type is used to manage the operation with files.
 */
typedef enum {error_file = 0, /**< This value is returned when a fatal error has occurred*/
			 fail, /**< This value is returned when a minor error has occurred so the program can continue to run*/
			 done /**< This value is returned when error has not occurred */
} File_status_t;

// -- Procedure & Functions Prototypes --
/**
 * @fn isValidFile(const char path_file[])
 * This function checks if the directory and the file specified in the path_file exist, otherwise this function will
 * create the directory and the file.
 * @param path_file is the path of the file to check or create.
 * @return 2 if the directory and the file exist or if they have been created, otherwise It will return 0.
 */
File_status_t isValidFile(const char path_file[]);


/**
 * @fn deleteFile(const char path_file[])
 * This function will delete the file specified in the path_file.
 * @param path_file is the path of the file to delete.
 * @return 2 if the file has been deleted, otherwise this function will return 0.
 */
File_status_t deleteFile(const char path_file[]);


/**
 * @fn writeFile(const char path_file[], void* pointer, size_t pointer_size, long int offset, int whence)
 * This function will write the file specified by the path passed by pointer whence the offset is specified.
 * @param path_file is the path of the file to write
 * @param pointer will point the element that will be written to the file
 * @param pointer_size is the size of the pointer that will be written to the file
 * @param offset is where the file will be written
 * @param whence is where the file will start to count the offset
 * @return 2 if the file has been written, otherwise this function will return 0
 */
File_status_t writeFile(const char path_file[], void* pointer, size_t pointer_size, long int offset, int whence);


/**
 *
 * @fn readFile(const char path_file[], void* pointer, size_t pointer_size, long int offset, int whence)
 * This function will read the file specified by the path passed by pointer whence the offset is specified.
 * @param path_file is the path of the file to read
 * @param pointer will point the element that will be read to the file
 * @param pointer_size is the size of the pointer that will be read to the file
 * @param offset is where the file will be read
 * @param whence is where the file will start to count the offset
 * @return 2 if the file has been read, 1 if the file has reached EOF, otherwise this function will return 0
 */
File_status_t readFile(const char path_file[], void* pointer, size_t pointer_size, long int offset, int whence);


/**
 * @fn getLastIndex(const char path_file[])
 * This function will return the last index of the file specified by the path passed by pointer
 * @param path_file is the path of the file that will be read to get the last index of the file
 * @return the index of the file if it has been found, otherwise It will return -1
 */
long int getLastIndex(const char path_file[]);


/**
 * @fn getNumberRecord(const char path_file[], size_t size_record)
 * This function will return the number of records that have been saved into the file specified by the path
 * passed by pointer
 * @param path_file is the path of the file that will be read to get the number of records that have been saved into the file
 * @param size_record is the size of records that have been saved into the file
 * @return the number of records that have been saved into the file, otherwise It will return 0
 */
int getNumberRecord(const char path_file[], size_t size_record);

#endif
