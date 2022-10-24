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

// Controlador.
int main() {
	return 0;
}
