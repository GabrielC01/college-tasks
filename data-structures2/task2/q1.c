/* Implementação de uma tabela de dispersão usando endereçamento aberto,
 * especificamente a sondagem linear. O registro nulo é o 0. */
#include <stdio.h>

// Função de dispersão.
size_t hash(size_t ht_length, unsigned int key) {
	return key % ht_length;
}

// Inserir registro na tabela.
int insert(unsigned int ht[], size_t ht_length, unsigned int key) {
	int i = (int) hash(ht_length, key);
	if (key != 0) {
		if (ht[i] == 0) {
			ht[i] = key;
		} else if (ht[i] != key) {
			size_t j = (i + 1) % ht_length;
			while (j != i && ht[j] != 0) {
				j = (j + 1) % ht_length;
			}
			if (j == i) {
				i = -1;
			} else {
				i = j;
				ht[j] = key;
			}
		}
	} else {
		i = -1;
	}
	return i;
}

// Remover registro da tabela.
int rm(unsigned int ht[], size_t ht_length, unsigned int key) {
	int i = (int) hash(ht_length, key);
	if (key != 0) {
		if (ht[i] == key) {
			ht[i] = 0;
		} else {
			size_t j = (i + 1) % ht_length;
			while (j != i && ht[j] != 0) {
				j = (j + 1) % ht_length;
			}
			if (j == i || ht[j] == 0) {
				i = -1;
			} else {
				i = j;
				ht[j] = 0;
			}
			i = -1;
		}
	} else {
		i = -1;
	}
	return i;
}

// Imprimir tabela.
void printHt(unsigned int ht[], size_t ht_length) {
	for (size_t i = 0; i < ht_length; i++) {
		printf("%u ", ht[i]);
	}
	printf("\b");
}

int main() {
	unsigned int ht[11] = { 0 }; // Necessário para inicializar com zeros.
	size_t ht_length = sizeof(ht) / sizeof(ht[0]);

	// a) Inserção dos registros 4, 17, 13, 35, 25, 11, 2, 10, 32.
	unsigned int test[] = { 4, 17, 13, 35, 25, 11, 2, 10, 32 };
	size_t length_test = sizeof(test) / sizeof(test[0]);
	printf("a) ");
	for (size_t i = 0; i < length_test; i++) {
		insert(ht, ht_length, test[i]);
	}
	printHt(ht, ht_length);
	printf("\n");
	
	// b) Remoção dos registros 25 e 11.
	rm(ht, ht_length, 25);
	rm(ht, ht_length, 11);
	printf("b) ");
	printHt(ht, ht_length);
	printf("\n");
	
	// c) Inserção dos registros 40 e 3.
	// insert(ht, ht_length, 40); insert(ht, ht_length, 3);

	return 0;
}
