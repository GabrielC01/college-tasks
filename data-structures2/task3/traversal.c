/* Programa para percorrer árvore binária em ordem prefixada. */
/* Baseado no código desta página web:
 * 		https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
 * */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
	int data;
	Node *left, *right;
};

Node* newNode(short data) {
	Node* node = (Node*) malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

void traversePreOrder(Node* node) {
	if (node == NULL) {
		return;
	}

	printf("%d ", node->data);
	traversePreOrder(node->left);
	traversePreOrder(node->right);
}

void traverseInOrder(Node* node) {
	if (node == NULL) {
		return;
	}

	traverseInOrder(node->left);
	printf("%d ", node->data);
	traverseInOrder(node->right);
}

void traversePostOrder(Node* node) {
	if (node == NULL) {
		return;
	}

	printf("%d ", node->data);

	traversePostOrder(node->left);
	traversePostOrder(node->right);
}

int main() {
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left->left = newNode(8);
	root->left->right->right = newNode(9);

	traversePreOrder(root);
	printf("\n");
	traverseInOrder(root);

	return 0;
}

