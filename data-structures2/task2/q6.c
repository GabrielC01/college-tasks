/* Implementação de uma tabela de dispersão usando endereçamento fechado, isto
 * é, encadeamento de colisões. */
#include <stdio.h>
#include <stdlib.h>


// Lista encadeada.
typedef struct ListNode ListNode;
typedef struct List List;

struct ListNode {
	unsigned int data;
	ListNode* previous;
	ListNode* next;
	
};

struct List {
	ListNode* first;
	ListNode* last;
};


// Inicializar nova list.
List* newList() {
	List* list = (List*) malloc(sizeof(List));
	list->first = NULL;
	list->last = NULL;
	return list;
}


// Inserir elemento à list'.
void addToList(List* list, unsigned int data) {
	ListNode* node = (ListNode*) malloc(sizeof(ListNode));
	node->previous = NULL;
	node->next = NULL;
	if (list->first == NULL) {
		list->first = node;
	}
	if (list->last != NULL) {
		list->last->next = node;
	}
	list->last = node;
}


// Remover da fila.
void dequeue(List* list) {
	list->first = list->first->previous;
}


// Função de dispersão.
size_t hash(size_t ht_length, unsigned int key) {
	return key % ht_length;
}


// Inserir elemento à tabela.
int addToHt(unsigned int ht, size_t ht_length, unsigned int key) {
	int i = (int) hash(ht_length, key);
	if (ht[i] == NULL) {
		ht[i] = newStack();
	}
	addToStack(ht[i], key);
}


// Remover elemento da tabela.
int rmFromHt(unsigned int ht, size_t ht_length, unsigned int key) {
	int i = (int) hash(ht_length, key);
	
	if (ht[i] != NULL) {
		StackNode* curr_node = ht[i];
	}
}


// Controlador.
int main() {
	return 0;
}
