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
size_t hash(size_t ht_length, unsigned int key) {
	return key % ht_length;
}


// Inserir elemento à tabela.
int addToHt(unsigned int ht, size_t ht_length, unsigned int key) {
	int i = (int) hash(ht_length, key);
	if (ht[i] == NULL) {
		ht[i] = newList();
	}
	addToList(ht[i], key);
}


// Remover elemento da tabela.
int rmFromHt(unsigned int ht, size_t ht_length, unsigned int key) {
	int i = (int) hash(ht_length, key);
}


// Controlador.
int main() {
	return 0;
}
