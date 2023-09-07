#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
 * append_text_to_file - Appends a text to the file
 * @filename: Name of file we want to append text to
 * @text_content: The text we want to append to the file
 *
 * Return: return 1 is successful and -1 if unsuccessful
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t writer;
	ssize_t len_text;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);

	if (fd == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		len_text = strlen(text_content);

		writer = write(fd, text_content, len_text);

		if (writer == -1)
		{
			perror("write");
			exit(EXIT_FAILURE);
		}
	close(fd);
	return (1);
	}

	return (1);
}
