#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/**
 * main - main block
 * Description: prints all singe digit number of base 10
 * starting from 0, followed by new line.
 * Return: 0
 */
int main(void)
{
	char c = '0';
	
	while (c <= '9')
	{
		putchar(c);
		c++;
	}
	putchar('\n');
	return (0);
}
