// Program do invert an array and
// sum its even index elements.

#include <stdio.h>

int main()
{
	unsigned short int array[] = { 1, 2, 3, 4, 5, 6, 7 };
	unsigned short int sum = 0, aux;
	size_t lastIndex = sizeof( array ) / sizeof( array[0] ) - 1;

	for (unsigned short int i = lastIndex, j = 0; i >= lastIndex / 2; i--, j++)
	{
		aux = array[i];
		array[i] = array[j];
		array[j] = aux;
	}

	for (unsigned short int i = 0; i <= lastIndex; i++)
		sum += (i % 2 == 0) ? array[i] : 0;

	printf("Vetor invertido: [ ");
	for (unsigned short int i = 0; i <= lastIndex; i++)
		printf("%hd ", array[i]);
	printf("]\nSoma dos elementos de índice par: %d.\n", sum);
	return 0;
}
