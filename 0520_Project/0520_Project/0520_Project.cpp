#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[50];
typedef struct DListNode {
	struct DListNode* llink;
	element data;
	struct DListNode* rlink;
} DListNode;

//전역변수
DListNode* current;

void init(DListNode* pHead) {
	pHead->llink = pHead;
	pHead->rlink = pHead;
}

void dInsert(DListNode* before, const element data) { //문자열이 직접적으로 쓰기 위해 const
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
	strcpy(newNode->data, data);
	newNode->llink = before; //(1)
	newNode->rlink = before->rlink; //(2)
	before->rlink->llink = newNode; //(3)
	before->rlink = newNode; //(4)
}

void print_dlist(DListNode* pHead) {
	DListNode* p = pHead;
	for (p = p->rlink; p != pHead; p = p->rlink) {
		if(p == current)
			printf("[<- #%s# ->]", p->data);
		else 
			printf("[<- %s ->]", p->data);
	}
	printf("\n");
}

int main() {
	char ch;
	DListNode* head = (DListNode *)malloc(sizeof(DListNode));
	init(head);

	dInsert(head, "Mammamia");
	dInsert(head, "Dancing");
	dInsert(head, "Fernando");

	current = head->rlink;
	print_dlist(head);

	do {
		printf("명령을 입력하세요[<, >, q]: ");
		ch = getchar();

		if (ch == '<') {
			current = current->llink;
			if (current == head)
				current = current->llink;
			print_dlist(head);
		}
		else if (ch == '>') {
			current = current->rlink;
			if (current == head)
				current = current->rlink;
			print_dlist(head);
		}
		getchar();
	} while (ch != 'q');
}