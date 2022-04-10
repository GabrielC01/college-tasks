#include <stdio.h>
void main()
{
	unsigned short naturals[8], x, y;
	size_t lenNaturals = sizeof(naturals) / sizeof(naturals[0]);

	// Read in eight natural numbers to a set
	printf("Entre com oito numeros naturais:\n");
	for (unsigned short i = 0; i < lenNaturals; i++)
		scanf("%hu", &naturals[i]);

	// Read in two positions of the set
	do {
		printf("Entre com X (X >= 0 e X <= %hu):\n", lenNaturals-1);
		scanf("%hu", &x);
	} while (x > lenNaturals-1);

	do {
		printf("Entre com Y (Y >= 0 e Y <= %hu)\n", lenNaturals-1);
		scanf("%hu", &y);
	} while (x > lenNaturals-1);

	printf("Soma dos valores encontrados em X e Y: %hu.\n", naturals[x] + naturals[y]);	
}
