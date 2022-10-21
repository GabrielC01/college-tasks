#include <stdio.h>

// Proc. troca valores de variáveis
void swap(short *a, short *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Proc. empilhar do menor ao maior (min. heap)
void min_heapify(short array[], size_t length) {
	for (unsigned short i = 0; i < length; i++) {
		short left = 2 * i + 1;
		short right = 2 * i + 2;
		if (left < length && array[left] < array[i]) {
			swap(&array[i], &array[left]);
		}
		if (right < length && array[right] < array[i]) {
			swap(&array[i], &array[right]);
		}
	}
}

// Proc. empilhar do maior ao menor (max. heap)
void max_heapify(short array[], size_t length) {
	char heap_property = 0;
	while (!heap_property) {
		heap_property = 1;
		for (unsigned short i = 0; i < length; i++) {
			short left = 2 * i + 1;
			short right = 2 * i + 2;
			if (left < length && array[left] > array[i]) {
				swap(&array[i], &array[left]);
				heap_property = 0;
			}
			if (right < length && array[right] > array[i]) {
				swap(&array[i], &array[right]);
				heap_property = 0;
			}
		}
	}
}

// Proc. imprimir vetor
void print_array(short array[], size_t length) {
	printf("[ ");
	for (unsigned short i = 0; i < length; i++)
		printf("%d ", array[i]);
	printf("]\n");
}

// Proc. controlador
int main() {
	// Questão 1:
	short array1[] = { 19, 1, 8, 22, 87, 4, 3, 2, 15, 44, 55, 56, 74 };
	size_t length1 = sizeof(array1) / sizeof(array1[0]);

	printf("Min-heap: ");
	min_heapify(array1, length1);
	print_array(array1, length1);

	printf("Max-heap: ");
	max_heapify(array1, length1);
	print_array(array1, length1);

	printf("\n");

	// Questão 2:
	short array2[] = { 16, 4, 10, 14, 7, 9, 3, 3, 8, 1, 35, 56, 12, 11, 70, 42 };
	size_t length2 = sizeof(array2) / sizeof(array2[0]);

	printf("Min-heap: ");
	min_heapify(array2, length2);
	print_array(array2, length2);

	printf("Max-heap: ");
	max_heapify(array2, length2);
	print_array(array2, length2);

	return 0;
}
