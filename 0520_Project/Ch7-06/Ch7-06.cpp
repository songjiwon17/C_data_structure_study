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

    // 데이터 개수 입력
    printf("데이터의 개수를 입력하시오: ");
    scanf_s("%d", &n);

    // 노드 입력 및 리스트 구성
    for (i = 1; i <= n; i++) {
        printf("노드#%d의 데이터를 입력하시오: ", i);
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

    // 마지막 노드 찾기 위함
    DListNode* current;
    for (current = head; current && current->rlink != NULL; current = current->rlink);

    // 역순으로 출력
    printf("\n데이터를 역순으로 출력: ");
    for (; current != NULL; current = current->llink) {
        printf("%d ", current->data);
    }
    printf("\n");

    // 메모리 해제
    for (current = head; current != NULL; ) {
        DListNode* temp = current;
        current = current->rlink;
        free(temp);
    }

    return 0;
}