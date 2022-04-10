#include <stdio.h>
void main()
{
	unsigned short naturals[10], largest, smallest;
	size_t lenNaturals = sizeof(naturals) / sizeof(naturals[0]);

	// Read in the 10 elements of array
	printf("Entre com 10 numeros naturais:\n");
	for (unsigned short i = 0; i < lenNaturals; i++)
	{
		scanf("%hu", &naturals[i]);

		// Check for the largest and smallest number
		if (i == 0)
		{
			largest = naturals[i];
			smallest = naturals[i]; // :)
		}
		else
		{
			if (naturals[i] > largest) largest = naturals[i];
			if (naturals[i] < smallest) smallest = naturals[i];
		}
	}

	// Print the largest and smallest number
	printf("Maior: %hu.\nMenor: %hu.\n", largest, smallest);
}
