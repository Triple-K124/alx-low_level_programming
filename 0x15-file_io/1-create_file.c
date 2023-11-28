#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

/**
 * create_file - Creates a file.
 * @filename: The name of the file to create or truncate
 * @text_content: The text content to write into the file (can be NULL).
 *
 * Return: Return 1 on success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	size_t len_text = 0;
	ssize_t writer;
	int i;

	if (filename == NULL)
		return (-1);


	if (text_content != NULL)
	{
		for (i = 0; text_content[i] != '\0'; i++)
		{
			len_text++;
		}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC | 0600);

	if (fd == -1)
	{
		perror("open");
		exit(-1);
	}


		writer = write(fd, text_content, len_text);

		if (writer < 0)
		{
			perror("Write");
			close(fd);
			exit(-1);
		}
	}

	close(fd);

	return (1);
}
