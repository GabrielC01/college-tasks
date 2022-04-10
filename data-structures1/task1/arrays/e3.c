#include <stdio.h>
#include <math.h>
void main()
{
	// Declare two sets and the length of both
	float set1[10], set2[10];
	size_t lenSets = sizeof(set1) / sizeof(set1[0]);

	// Initialize the first from stdin and the second
	// receives the square of each item from the first
	printf("Entre com dez numeros reais:\n");
	for (unsigned short i = 0; i < lenSets; i++)
	{
		scanf("%f", &set1[i]);
		set2[i] = pow(set1[i], 2); 
	}

	// Print set 1
	printf("A = [ ");
	for (unsigned short i = 0; i < lenSets; i++)
		printf("%.2f ", set1[i]);	
	printf("]\n");

	// Print set 2
	printf("B = [ ");
	for (unsigned short i = 0; i < lenSets; i++)
		printf("%.2f ", set2[i]);	
	printf("]\n");
}
