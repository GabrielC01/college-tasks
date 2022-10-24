/* Implementação de uma tabela de dispersão usando endereçamento aberto,
 * especificamente a sondagem linear. O registro nulo é o 0. */
#include <stdio.h>

// Função de dispersão.
size_t hash(size_t ht_length, unsigned int key) {
	return key % ht_length;
}


// Função de endereçamento aberto para encontrar registro.
size_t rehashFilled(unsigned int ht[], size_t ht_length, size_t hv, unsigned int key) {
	size_t j = (hv + 1) % ht_length;
	while (j != hv && ht[j] != key) {
		j = (j + 1) % ht_length;
	}
	return j == hv ? -1 : j;
}


// Função de endereçamento aberto para encontrar célula vazia.
size_t rehashInsertion(unsigned int ht[], size_t ht_length, size_t hv, unsigned int key) {
	size_t j = (hv + 1) % ht_length;
	while (j != hv && ht[j] != 0) {
		j = (j + 1) % ht_length;
	}
	return j == hv ? -1 : j;
}


// Inserir registro na tabela.
int insert(unsigned int ht[], size_t ht_length, unsigned int key) {
	int i = (int) hash(ht_length, key);
	if (key != 0) {
		if (ht[i] == 0) {
			ht[i] = key;
		} else if (ht[i] != key) {
			i = rehashInsertion(ht, ht_length, i, key);
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
			i = rehashFilled(ht, ht_length, i, key);
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


// Controlador.
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
	insert(ht, ht_length, 40);
	insert(ht, ht_length, 3);
	printf("c) ");
	printHt(ht, ht_length);
	printf("\n");

	return 0;
}
