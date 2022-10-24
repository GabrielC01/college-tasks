/* Implementação de uma tabela de dispersão usando endereçamento fechado, isto
 * é, encadeamento de colisões. */
#include <stdio.h>
#include <stdlib.h>


// Lista encadeada.
typedef struct ListNode ListNode; typedef struct List List;

struct ListNode {
	unsigned int data;
	ListNode* previous;
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
	return list;
}


// Adicionar à lista.
void addToList(List* list, unsigned int data) {
	ListNode* new_node = (ListNode*) malloc(sizeof(ListNode));
	new_node->data = data;
	new_node->next = NULL;
	if (list->last != NULL) {
		list->last->next = new_node;
	}
	if (list->first == NULL) {
		list->first = new_node;
	}
	new_node->previous = list->last;
	list->last = new_node;
}


// Remover elemento da lista.
int rmFromList(List* list, unsigned int data) {
	ListNode* curr_node = (ListNode*) malloc(sizeof(ListNode));
	while (curr_node != NULL && curr_node->data != data) {
		curr_node = curr_node->next;
	}
	unsigned int value;
	if (curr_node->data == data) {
		value = curr_node->data;
		curr_node->previous->next = curr_node->next;
	} else {
		value = -1;
	}
	return value;
}


// Imprimir lista.
void printList(List* list) {
	ListNode* curr_node = list->first;
	while (curr_node != NULL) {
		printf("%u ", curr_node->data);
		curr_node = curr_node->next;
	}
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
		if (ht[i] != NULL) {
			printList(ht[i]);
			printf("\n");
		}
	}
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
	printf("M = 9\n");
	for (size_t i = 0; i < length_test; i++) {
		addToHt(ht1, length_ht1, test[i]);
	}
	printHt(ht1, length_ht1);
	printf("\n\n");

	/* Tabela de 11 posições. */
	printf("M = 11\n");
	for (size_t i = 0; i < length_test; i++) {
		addToHt(ht2, length_ht2, test[i]);
	}
	printHt(ht2, length_ht2);
	printf("\n");

	return 0;
}
