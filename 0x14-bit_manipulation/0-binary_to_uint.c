#include <stdio.h>

/**
 * binary_to_uint - Convert a binary string to an unsigned integer.
 * @b: The binary string to convert.
 *
 * Return: The unsigned integer converted from the binary string.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int answer = 0;
	int counter = 0;

	if (b == NULL)
		return (0);

	while (b[counter] != '\0')
	{
		if (b[counter] == '0')
		{
			answer = answer * 2;
		}
		else if (b[counter] == '1')
		{
			answer = answer * 2 + 1;
		}
		else
		{
			return (0); /* Invalid character found */
		}
		counter++;
	}

	return (answer);
}
