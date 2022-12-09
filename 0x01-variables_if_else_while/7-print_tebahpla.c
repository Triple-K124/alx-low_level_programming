#include <stdio.h>
/**
 * main - main block
 * Description: prints all single digit number of base 10
 * starting from, followed by new line.
 * Return: 0
 */
int main(void)
{
	char c = 'a';

	while (c <= 'z')
	{
		putchar(c);
		c--;
	}

	putchar('\n');
	return (0);
}
