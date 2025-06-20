#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode {
	struct TreeNode *left;
	int data;
	TreeNode* right;
} TreeNode;

//lrR 후위 순회
void postorder(TreeNode* root) {
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);
	}
}

//lRr 중위 순회
void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}

//RIr 전위 순회
void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int main() {
	TreeNode n1 = { NULL, 1, NULL };
	TreeNode n2 = { &n1, 4, NULL };
	TreeNode n3 = { NULL, 16, NULL };
	TreeNode n4 = { NULL, 25, NULL };
	TreeNode n5 = { &n3, 20, &n4 };
	TreeNode n6 = { &n2, 15, &n5 };

	TreeNode* root = &n6;

	printf("후위 순회 = ");
	postorder(root); // 1 4 16 25 20 15
	printf("\n");


	printf("중위 순회 = ");
	inorder(root); 
	printf("\n");


	printf("전위 순회 = ");
	preorder(root);
	printf("\n");
}