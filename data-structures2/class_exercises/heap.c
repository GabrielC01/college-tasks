/* Programa para implementar fila de prioridade. */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct List List;

struct Node {
	int data;
	Node *previous;
	Node *next;
};

struct List {
	Node *head;
	Node *priority_tail;
	Node *tail;
};

// Proc. inicializar lista
List* new_list() {
	List *list = (List*) malloc(sizeof(List));
	list->head = NULL;
	list->priority_tail = NULL;
	list->tail = NULL;
	return list;
}

// Proc. adicionar elemento à fila
void insert(List *list, int data) {
	// Cria novo nó
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	// Verifica a prioridade
	if (data >= 60) {
		if (list->head == NULL) {
			node->previous = NULL;
			list->head = node;
			list->tail = node;
			list->priority_tail = node;
		} else {
			if (list->head->data < 60) {
				node->previous = NULL;
				node->next = list->head;
				list->head->previous = node;
				list->head = node;
				list->priority_tail = node;
			} else {
				node->previous = list->priority_tail;
				node->next = list->priority_tail->next;
				list->priority_tail->next = node;
				list->priority_tail = node;
			}
		}
	} else {
		if (list->head == NULL) {
			list->head = node;
			list->tail = node;
		} else {
			node->previous = list->tail;
			list->tail->next = node;
			list->tail = node;
		}
	}
}

// Proc. imprimir lista
void print_list(List *list) {
	Node *curr = list->head;
	printf("[ ");
	while (curr != NULL) {
		printf("%d ", curr->data);
		curr = curr->next;
	}
	printf("]\n");
}

int main() {
	List *list = new_list();
	insert(list, 1);
	insert(list, 2);
	insert(list, 3);
	insert(list, 60);
	insert(list, 61);
	print_list(list);
	return 0;
}
