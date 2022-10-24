/* Implementação de uma tabela de dispersão usando endereçamento fechado, isto
 * é, encadeamento de colisões. */
#include <stdio.h>
#include <stdlib.h>


// Pilha (lista simplesmente encadeada).
typedef struct StackNode StackNode;

struct StackNode {
	unsigned int data;
	StackNode* next;
};


// Inicializar nova pilha.
StackNode* newStack() {
	return (StackNode*) malloc(sizeof(StackNode));
}


// Inserir elemento à pilha.
void addToStack(StackNode* top, unsigned int data) {
	StackNode* new_node = (StackNode*) malloc(sizeof(StackNode));
	new_node->data = data;
	new_node->next = NULL;
	top->next = new_node;
}


// Remover topo da pilha.
void pop(StackNode* top) {
	top = NULL;
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

// Controlador.
int main() {
	return 0;
}
