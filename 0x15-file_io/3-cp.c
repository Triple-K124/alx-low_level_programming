#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024
/**
* print_error - Prints the error to standard output
* @code: The error code
* @message: The error message to be displayed
* @arg: Points to the string
* return: Return nothing
*/

void print_error(int code, const char *message, const char *arg)
{
	dprintf(STDERR_FILENO, message, arg);
	exit(code);
}

/**
* main - Entry point of the code
* @argc: The argument count of the function
* @argv: The arguments
*
* Return: Return 1 if successsful
*/
int main(int argc, char *argv[])
{
	const char *file_from = argv[1], *file_to = argv[2];
	int fd_from, fd_to;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	if (argc != 3)
	{
		print_error(97, "Usage: %s file_from file_to\n", argv[0]);
	}
	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		print_error(98, "Error: Can't read from file %s\n", file_from);
	}
	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		print_error(99, "Error: Can't write to %s\n", file_to);
	}
	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			print_error(99, "Error: Can't write to %s\n", file_to);
		}
	}
	if (bytes_read == -1)
	{
		print_error(98, "Error: Can't read from file %s\n", file_from);
	}
	if (close(fd_from) == -1)
	{
		print_error(100, "Error: Can't close fd %d\n", argv[1]);
	}
	if (close(fd_to) == -1)
	{
		print_error(100, "Error: Can't close fd %d\n", argv[2]);
	}
	return (0);
}
