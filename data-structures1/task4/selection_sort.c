/* Programa para ordenar um vetor e informar o número de operações críticas
 * realizadas. */
#include <stdio.h>

void sort( int *array, int size ) {
	for ( int i = 0; i < size; i++ ) {
		int smPos = i;
		for ( int j = i+1; j < size; j++ ) {
			if ( array[j] < array[smPos] ) {
				smPos = j;
			}
		}
		if ( array[i] > array[smPos] ) {
			int temp = array[i];
			array[i] = array[smPos];
			array[smPos] = temp;
		}
	}
}

int main() {
	int array[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5, 33, 42};
	int size = sizeof( array ) / sizeof( array[0] );
	sort( array, size );
	printf("[ ");
	for ( int i = 0; i < size; i++ ) {
		printf("%d ", array[i]);
	}
	printf("]\n");
	return 0;
}

