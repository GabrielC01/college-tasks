/* Implementação de uma árvore binária. */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	char data;
	Node *left, *right;
};

Node* newNode(char data) {
	Node* node = (Node*) calloc(1, sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void traversePreOrder(Node* node) {
	if (node == NULL) {
		return;
	}

	printf("%c ", node->data);
	traversePreOrder(node->left);
	traversePreOrder(node->right);
}

int main() {
	Node *root = newNode('M');
	root->left = newNode('H');
	root->right = newNode('R');
	root->left->left = newNode('D');
	root->left->right = newNode('J');
	root->right->left = newNode('E');
	root->right->right = newNode('T');

	traversePreOrder(root);

	return 0;
}

