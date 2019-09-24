// -- Libraries --
#include "File.h"

/**
 * @file File.c
 * @author Vincenzo Susso
 * @date 2019 Sep 10
 * @version 1.0
 * @brief This file is the implementation file of File.h
 */

// -- Procedure & Functions --
File_status_t isValidFile(const char path_file[])
{
	File_status_t valid_file = done;
	FILE *file = NULL;

	errno = 0; // Reset the value of errno which may have been modified by others errors
	if(mkdir(DIRECTORY_PATH)) // Create a directory named "Files" if it doesn't exsist
	{
		/*
		 	 When mkdir fails, it returns -1 so it executes the if-then statement; when an error occurs, errno is set on
		 	 a value based on kind of error that has been verified, so if mkdir has failed because the directory esist,
		 	 errno will be set to EEXIST
		 */
		if(errno != EEXIST)
		{
			valid_file = error_file;
		}
	}
	errno = 0;

	// Create a file named with the path if it doesn't exsist
	file = fopen(path_file, "ab");
	if(!file)
	{
		valid_file = error_file;
	}
	fclose(file);

	return valid_file;
}

File_status_t deleteFile(const char path_file[])
{
	File_status_t deleted_file = error_file;

	if(!remove(path_file))
	{
		deleted_file = done;
	}

	return deleted_file;
}

File_status_t writeFile(const char path_file[], void* pointer, size_t pointer_size, long int offset, int whence)
{
	File_status_t file_written = done;
	FILE *file = NULL;
	int number_member_written = 0;

	file = fopen(path_file, "rb+");
	if(file)
	{
		fseek(file, (offset * (long int) pointer_size), whence);
		number_member_written = fwrite(pointer, pointer_size, NUMBER_MEMBER_FILE, file);

		if(number_member_written < NUMBER_MEMBER_FILE)
		{
			// The writing of the file has failed
			file_written = error_file;
		}
	}
	else
	{
		// The file cannot be opened
		file_written = error_file;
	}

	fclose(file);

	return file_written;
}

File_status_t readFile(const char path_file[], void* pointer, size_t pointer_size, long int offset, int whence)
{
	File_status_t file_read = done;
	FILE *file = NULL;
	int number_member_read = 0;

	file = fopen(path_file, "rb");

	if(file)
	{
 		fseek(file, (offset * (long int) pointer_size), whence);

		number_member_read = fread(pointer, pointer_size, NUMBER_MEMBER_FILE, file);

		if(number_member_read < NUMBER_MEMBER_FILE)
		{
			if(feof(file))
			{
				// The file is finished
				file_read = fail;
			}
			else
			{
				// An error has occurred during the reading of the file
				file_read = error_file;
			}
		}
	}
	else
	{
		// The file cannot be opened
		file_read = error_file;
	}

	fclose(file);

	return file_read;
}

long int getLastIndex(const char path_file[])
{
	FILE *file = NULL;
	long int index = INDEX_NOT_FOUND;


	file = fopen(path_file, "rb");

	if(file)
	{
 		fseek(file, 0, SEEK_END);
 		index = ftell(file);
	}

	fclose(file);

	return index;
}

int getNumberRecord(const char path_file[], size_t size_record)
{
	int number_record = 0;
	if(getLastIndex(path_file) != INDEX_NOT_FOUND)
	{
		number_record = getLastIndex(path_file) / size_record;
	}

	return number_record;
}
