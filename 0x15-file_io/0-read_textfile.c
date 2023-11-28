#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: The name of the file to read.
 * @letters: The number of letters it should read and print.
 *
 * Return: The actual number of letters it could read and print.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	FILE *file;
	char *buffer;
	ssize_t reader, writer;

	if (filename == NULL)
		return (0);

	file = fopen(filename, "r");
	if (file == NULL)
	{
		return (0);
	}
	buffer = (char *)malloc(letters + 1);
	if (buffer == NULL)
	{
		fclose(file);
		return (0);
	}
	reader = fread(buffer, 1, letters, file);
	if (reader < 0)
	{
		free(buffer);
		fclose(file);
		return (0);
	}

	buffer[reader] = '\0';

	writer = write(STDOUT_FILENO, buffer, reader);
	if (writer < 0 || (size_t)writer != (size_t)reader)
	{
		free(buffer);
		fclose(file);
		return (0);
	}

	free(buffer);
	fclose(file);

	return (reader);
}
