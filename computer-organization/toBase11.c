/* Program to convert from base 10 to base 11 */
// Pass the number on CLI invokation
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char ** argv) {
	// End program case no argument passed
	if (argc < 2) return 0;
	
	// Convert argument to integer
	int num = atoi(argv[1]);
	
	if (num < 10) printf("%d\n", num);
	else if (num == 10) printf("A\n");
	else
	{
		// String for result
		char * result = malloc(sizeof(char));
		int i = 0;

		// Divide by 11, and save the remainders
		while (num >= 11)
		{
			if (num % 11 < 10)
				result[i] = num % 11 + '0';
			else if (num % 11 == 10)
				result[i] = 'A';

			num /= 11;
			i++;
			result = realloc(result, i * sizeof(char));
		}
		result[i] = num + '0';

		// Show result
		for (i; i >= 0; i--) printf("%c", result[i]);
		printf("\n");

		free(result);
	}
	return 0;
}
