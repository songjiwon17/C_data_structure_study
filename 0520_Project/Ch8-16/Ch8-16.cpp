#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

int count_single_child_nodes(TreeNode* root) {
    if (root == NULL)
        return 0;

    int count = 0;

    // 자식이 하나만 있는 경우 (왼쪽만 또는 오른쪽만)
    if ((root->left == NULL && root->right != NULL) ||
        (root->left != NULL && root->right == NULL)) {
        count = 1;
    }

    // 왼쪽과 오른쪽 서브트리에서 재귀적으로 개수 구함
    return count + count_single_child_nodes(root->left) + count_single_child_nodes(root->right);
}

TreeNode* create_node(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main() {
    // 예시 트리 구성
    TreeNode* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4); 
    root->right->right = create_node(5); 

    int result = count_single_child_nodes(root);
    printf("자식이 하나만 있는 노드의 개수: %d\n", result); 

    return 0;
}