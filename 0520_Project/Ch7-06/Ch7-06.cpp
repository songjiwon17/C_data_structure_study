#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct DListNode {
    int data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

int main() {
    int n, i, value;
    DListNode* head = NULL;

    // ������ ���� �Է�
    printf("�������� ������ �Է��Ͻÿ�: ");
    scanf_s("%d", &n);

    // ��� �Է� �� ����Ʈ ����
    for (i = 1; i <= n; i++) {
        printf("���#%d�� �����͸� �Է��Ͻÿ�: ", i);
        scanf_s("%d", &value);

        DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
        newNode->data = value;
        newNode->llink = NULL;
        newNode->rlink = NULL;

        if (head == NULL) {
            head = newNode;
        }
        else {
            DListNode* temp;
            for (temp = head; temp->rlink != NULL; temp = temp->rlink);
            temp->rlink = newNode;
            newNode->llink = temp;
        }
    }

    // ������ ��� ã�� ����
    DListNode* current;
    for (current = head; current && current->rlink != NULL; current = current->rlink);

    // �������� ���
    printf("\n�����͸� �������� ���: ");
    for (; current != NULL; current = current->llink) {
        printf("%d ", current->data);
    }
    printf("\n");

    // �޸� ����
    for (current = head; current != NULL; ) {
        DListNode* temp = current;
        current = current->rlink;
        free(temp);
    }

    return 0;
}