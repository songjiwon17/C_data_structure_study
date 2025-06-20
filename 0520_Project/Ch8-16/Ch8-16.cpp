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

    // �ڽ��� �ϳ��� �ִ� ��� (���ʸ� �Ǵ� �����ʸ�)
    if ((root->left == NULL && root->right != NULL) ||
        (root->left != NULL && root->right == NULL)) {
        count = 1;
    }

    // ���ʰ� ������ ����Ʈ������ ��������� ���� ����
    return count + count_single_child_nodes(root->left) + count_single_child_nodes(root->right);
}

TreeNode* create_node(int data) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main() {
    // ���� Ʈ�� ����
    TreeNode* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4); 
    root->right->right = create_node(5); 

    int result = count_single_child_nodes(root);
    printf("�ڽ��� �ϳ��� �ִ� ����� ����: %d\n", result); 

    return 0;
}