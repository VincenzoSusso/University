// -- Libraries --
#include "File.h"

// -- Procedure & Functions --
bool isValidFile(char path[])
{
	bool valid_file = true;
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
			valid_file = false;
		}
	}
	errno = 0;

	// Create a file named with the path if it doesn't exsist
	file = fopen(path, "ab");
	if(!file)
	{
		valid_file = false;
	}
	fclose(file);

	return valid_file;
}

bool writeFile(char path[], void *pointer, size_t pointer_size)
{
	bool file_written = true;
	FILE *file = NULL;
	int number_member_written = 0;

	file = fopen(path, "ab");
	if(!file)
	{
		file_written = false;
	}

	number_member_written = fwrite(pointer, pointer_size, NUMBER_MEMBER_FILE, file);

	if(number_member_written < NUMBER_MEMBER_FILE)
	{
		// The writing of the file has failed
		file_written = false;
	}

	fclose(file);

	return file_written;
}

bool readDriversFile(char path[], void* pointer, size_t pointer_size)
{
	bool file_read = true;
	bool flag = true;

	int number_member_read = 0;
	FILE *file = NULL;

	file = fopen(path, "rb");

	if(!file)
	{
		file_read = false;
	}

	while(flag && file_read)
	{
		number_member_read = fread(pointer, pointer_size, NUMBER_MEMBER_FILE, file);
		if(number_member_read < NUMBER_MEMBER_FILE)
		{
			if(feof(file))
			{
				flag = false;
			}
			else
			{
				file_read = false;
			}
		}
	}


	fclose(file);

	return file_read;
}
