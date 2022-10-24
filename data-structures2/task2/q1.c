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
	if (ht[i] == 0) {
		ht[i] = key;
	} else if (ht[i] != key) {
		size_t j = (i + 1) % ht_length;
		while (j != i && ht[j] != 0) {
			j = (i + 1) % ht_length;
		}
		j == i ? i = -1 : i = j;
	}
	return i;
}

// Remover registro da tabela.
int remove(unsigned int ht[], size_t ht_length, unsigned int key) {
	if (key == 0) return -1; // Registro vazio.
							 //
	int i = (int) hash(ht_length, key);
	if (ht[i] == key) {
		ht[i] = 0;
	} else {
		i = -1;
	}
	return i;
}

int main() {
	return 0;
}
