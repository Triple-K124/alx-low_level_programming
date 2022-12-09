#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0 for success
 */
int main(void)
{
	int n;
	int last;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	last = n % 10;
	if (last > 5)
		printf("Last digit of %i is %i greater than 5\n", n, last);
	else if (last == 0)
		printf("Last digit of %i is %i 0\n", n, last);
	else if (n < 6)
		printf("Last digit of %i is %i less than 6 and not 0\n", n, last);
	return (0);

}
