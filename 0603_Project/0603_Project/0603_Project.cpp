#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* new_node(element item) {
	TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
	tmp->key = item;
	tmp->left = tmp->right = NULL;
	return tmp;
}

TreeNode* insert_node(TreeNode *node, element key) {
	if(node == NULL) return new_node(key);
	
	//Áß¿ä
	//if (node->key < key)
	//	node->right = insert_node(node->right, key);

	//else if (node->key > key)
	//	node->left = insert_node(node->left, key);

	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if(key > node->key)
		node->right = insert_node(node->right, key);

	return node;
}

int main() {
	TreeNode* root = NULL;

	root = insert_node(root, 7);
	root = insert_node(root, 17);
	root = insert_node(root, 10);
	root = insert_node(root, 3);
}