/* Implementação de uma tabela de dispersão usando endereçamento fechado, isto
 * é, encadeamento de colisões. */
#include <stdio.h>
#include <stdlib.h>


// Lista encadeada.
typedef struct ListNode ListNode;
typedef struct List List;

struct ListNode {
	unsigned int data;
	ListNode* next;
};

struct List {
	ListNode* first;
	ListNode* last;
};


// Criar nova lista.
List* newList() {
	List* list = (List*) malloc(sizeof(List));
	list->first = NULL;
	list->last = NULL;
}


// Adicionar à lista.
void addToList(List* list, unsigned int data) {
	ListNode* new_node = (ListNode*) malloc(sizeof(ListNode));
	new_node->data = data;
	new_node->next = NULL;
	list->last->next = new_node;
	list->last = new_node;
}


// Remover elemento da lista.
int rmFromList(List* list, unsigned int data) {
	ListNode* curr_node = (ListNode*) malloc(sizeof(ListNode));
	while (curr_node != NULL && curr_node->data != data) {
		curr_node = curr_node->next;
	}
	return curr_node->data == data ? data : -1;
}


// Função de dispersão.
size_t hash(size_t length_ht, unsigned int key) {
	return key % length_ht;
}


// Inserir elemento à tabela.
int addToHt(List* ht[], size_t length_ht, unsigned int key) {
	int i = (int) hash(length_ht, key);
	if (ht[i] == NULL) {
		ht[i] = newList();
	}
	addToList(ht[i], key);
}


// Remover elemento da tabela.
int rmFromHt(List* ht[], size_t length_ht, unsigned int key) {
	int i = (int) hash(length_ht, key);
	if (ht[i] != NULL) {
		i = rmFromList(ht[i], key);
	} else {
		i = -1;
	}
	return i;
}


// Imprimir tabela de dispersão.
void printHt(List* ht[], size_t length_ht) {
	for (size_t i = 0; i < length_ht; i++) {
		printf("%u ", ht[i]);
	}
	printf("\b");
}


// Controlador.
int main() {
	List* ht1[9] = { NULL };
	List* ht2[11] = { NULL };
	unsigned int test[] = { 5, 28, 19, 15, 20, 33, 12, 7, 10 };
	size_t length_ht1 = sizeof(ht1) / sizeof(ht1[0]);
	size_t length_ht2 = sizeof(ht2) / sizeof(ht2[0]);
	size_t length_test = sizeof(test) / sizeof(test[0]);

	/* Tabela de 9 posições. */
	for (size_t i = 0; i < length_test; i++) {
		addToHt(ht1, length_ht1, test[i]);
	}
	printHt(ht1, length_ht1);

	/* Tabela de 11 posições. */
	for (size_t i = 0; i < length_test; i++) {
		addToHt(ht2, length_ht2, test[i]);
	}
	printHt(ht2, length_ht2);

	return 0;
}
