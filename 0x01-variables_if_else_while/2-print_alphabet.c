#include <stdio.h>
#include <stdlib.h>
/**
 * main - Entry block
 * Description: Print characters in lower case
 */
int main(void)
{
	char c = 'a';

	while (c <= 'z')
	{
		putchar(c);
		c++;
	}

	putchar('\n');
	return (0);
}
