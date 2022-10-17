/* Programa para realizar uma pesquisa binária. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Proc. para trocar valores de duas variáveis
void swap(int *a, int *b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *a;
}

// Proc. para preencher um vetor aleatoriamente
void fill_unsorted(int array[], size_t length) {
	srand(time(NULL));
	for (unsigned int i = 0; i < length; i++) {
		array[i] = rand() % 200;
	}
}

// Proc. ordenar vetor usando bubble sort
void sort(int array[], size_t length) {
	char is_sorted = 0;
	while (!is_sorted) {
		is_sorted = 1;
		for (unsigned int i = 0; i < length; i++) {
			if (array[i] > array[i+1]) {
				swap(&array[i], &array[i+1]);
				is_sorted = 0;
			}
		}
	}
}

// Func. encontrar elemento no vetor
int find(int array[], size_t length, int target) {
	int left = 0;
	int right = length;
	while (left != right) {
		int mid = (left + right) / 2;
		if (target == array[mid]) {
			return mid;
		}
		if (target < array[mid]) {
			right = mid - 1;
		}
		if (target > array[mid]) {
			left = mid + 1;
		}
	}
	return -1;
}

// Proc. imprimir vetor
void print_array(int array[], size_t length) {
	printf("[ ");
	for (size_t i = 0; i < length; i++) {
		printf("%d ", array[i]);
	}
	printf("]\n");
}

int main() {
	size_t length = 9000;
	int array[length];
	fill_unsorted(array, length);
	int i = find(array, length, 4);
	printf("%d\n", i);
	return 0;
}
