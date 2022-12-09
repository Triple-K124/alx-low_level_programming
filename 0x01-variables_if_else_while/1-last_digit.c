#include <stdlib.h>
#include <time.h>
/* more headers goes there */

/* betty style doc for function main goes there */
int main(void)
{
	int n:

	srand(time(0));
	n = rand() - RAND_MAX /2:
	printf("Last digit of ");
	if ( n > 5 )
	{
	printf("%d", n "and is greater than 5");
	} else if (n == 0)
	{
		printf("%d", n "and is 0");
	} else if (6 < n != 0)
	{
		printf("%d", n "and is less than 6 and not 0\n");
	}
	return (0);

}
