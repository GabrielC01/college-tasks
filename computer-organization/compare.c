/* Program to compare two integers
 * using only logical operators */

// Pass two  numbers, separated by space
// on CLI invokation.

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char ** argv)
{
	// End program case no argument passed
	if (argc < 2) return 0;

	// Convert the arguments to integer
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);

	/* To compare different numbers I decremented
	 * them, so they get to zero at different time. */

	unsigned int i = a, j = b;
	while (1) {
		// Equality //
		if (!i)
			if (!j)
			{
				printf("%d = %d.\n", a, b);
				return 0;
			}

		// Larger than
		if (i)
			if (!j)
			{
				printf("%d > %d.\n", a, b);
				return 0;
			}
		
		// Less than
		if (!i)
			if (j)
			{
				printf("%d < %d.\n", a, b);
				return 0;
			}

		i--;
		j--;
	}
	return 0;
}
