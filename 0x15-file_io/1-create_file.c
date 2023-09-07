#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
/**
 * create_file - A function that creates a file
 * @filename - The file that is being created
 * @text_content - Text that will be written into the file
 *
 * Return - Return 1 on success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	size_t len_text;
	ssize_t writer;

	if (filename == NULL)
		return -1;
	fd = open(filename, O_CREAT | O_TRUNC | S_IRUSR | S_IWUSR);

	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}

	if (chmod(filename, S_IRUSR | S_IWUSR) == -1)
	{
		perror("chmod");
		exit(EXIT_FAILURE);
	}

	if (text_content != NULL)
	{
		len_text = strlen(text_content);

		writer = write(fd, text_content, len_text);

		if (writer == -1)
		{
			perror("Write");
			exit(EXIT_FAILURE);
		}
	}

		close(fd);

		return (1);
	
}
