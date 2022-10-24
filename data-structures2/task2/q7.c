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
	return (2 * key + 5) % length_ht;
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


// Pesquisa sequencial.
int searchSeq(List* ht[], size_t length_ht, unsigned int key) {
	unsigned int num_cmps = 0;
	int result = 0;
	for (size_t i = 0; i < length_ht && result == 0; i++) {
		if (ht[i] != NULL) {
			ListNode* curr_node = ht[i]->first;
			while (curr_node != NULL && curr_node->data != key) {
				num_cmps++; // Considerando apenas a segunda comparação na condição
							// do while.
				curr_node = curr_node->next;
			}
			num_cmps++;
			if (curr_node != NULL) {
				if (curr_node->data == key) {
					result = i;
				}
			}
		}
	}
	return result != 0 ? result : -1;
}


// // Pesquisa binária. (Não é eficiente)
// unsigned int searchBin(List* ht, size_t length_ht, unsigned int key) {
// 	unsigned int num_cmps = 0;
// 	unsigned int result = NULL;
// 	size_t left = 0;
// 	size_t right = length_ht - 1;
// 	while (left != right) {
// 		size_t mid = (left + right) / 2;
// 		ListNode* curr_node = ht[mid];
// 		while (curr_node != NULL && curr_node->data != key) {
// 			num_cmps++;
// 			curr_node = curr_node->next;
// 		}
// 		if (curr_node->data != key) {
// 		}
// 	}
// }


// Controlador.
int main() {
	List* ht2[11] = { NULL };
	unsigned int test[] = { 12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5 };
	size_t length_ht2 = sizeof(ht2) / sizeof(ht2[0]);
	size_t length_test = sizeof(test) / sizeof(test[0]);

	printf("M = 11\n");
	for (size_t i = 0; i < length_test; i++) {
		addToHt(ht2, length_ht2, test[i]);
	}
	printf("%d\n", searchSeq(ht2, length_ht2, 23));

	return 0;
}
