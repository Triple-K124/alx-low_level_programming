#include <stdlib.h>

#include <time.h>

/* more headers goes there */



/* betty style doc for function main goes there */

int main(void)

{

		int n;



			srand(time(0));

				n = rand() - RAND_MAX / 2;

					/* your code goes there */

			if (0 < n)
			{
			printf("%d", n " is positive\n");
			} else if(0 == n)
			{
			printf("%d", n " is zero\n")
			} else if(0 > n)
			{
			printf("%d", n " is negative\n")
			}
				
				return (0);

}
