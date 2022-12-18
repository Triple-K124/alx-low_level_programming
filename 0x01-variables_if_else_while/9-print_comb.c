#include <stdio.h>
#include <stdlib.h>
/**
 * main - main block
 * Description: prints all single number of base 10
 * starting from 0, followed by a new line
 * Return: 0
 */
int main(void)
{
	int c;

	for (c = 0; c <= 9; c++)
	{
		if (c == 9)
		putchar('\n');
		else
		putchar(c + 48);
		putchar(',');
		putchar(' ');
		
	}

	return (0);
}
