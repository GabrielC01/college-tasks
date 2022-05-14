#include <stdio.h>
#include <stdbool.h>

int sort(int * array, int size) {
	bool all_sorted = false;	
	int num_probes = 0;
	while (!all_sorted) {
		all_sorted = true;
		for (int i = 0; i < size-1; i++) {
			if (array[i] > array[i+1]) {
				int aux = array[i];
				array[i] = array[i+1];
				array[i+1] = aux;
				all_sorted = false;
			}
		}
		num_probes++;
	}

	return num_probes;
}

void main() {
	int array[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5, 33, 42};
	size_t size = sizeof(array) / sizeof(array[0]);

	int num_probes = sort(array, size);

	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n%d\n", num_probes);
}
