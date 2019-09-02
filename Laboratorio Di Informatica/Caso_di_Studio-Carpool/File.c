// -- Libraries --
#include "File.h"

// -- Procedure & Functions --
File_status_t isValidFile(const char path_file[])
{
	File_status_t valid_file = done;
	FILE *file = NULL;

	errno = 0; // Reset the value of errno which may have been modified by others errors
	if(mkdir(DIRECTORY_PATH)) // Create a directory named "Files" if it doesn't exsist
	{
		/*
		 	 When mkdir fails, it returns -1 so it executes the if-then statement; when an error occurs, errno is set on a value based on kind of error
		 	 that has been verified, so if mkdir has failed because the directory esist, errno will be set to EEXIST
		 */
		if(errno != EEXIST)
		{
			valid_file = error;
		}
	}
	errno = 0;

	// Create a file named with the path if it doesn't exsist
	file = fopen(path_file, "ab");
	if(!file)
	{
		valid_file = error;
	}
	fclose(file);

	return valid_file;
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
			file_written = error;
		}
	}
	else
	{
		// The file cannot be opened
		file_written = error;
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
				file_read = error;
			}
		}
	}
	else
	{
		// The file cannot be opened
		file_read = error;
	}

	fclose(file);

	return file_read;
}
