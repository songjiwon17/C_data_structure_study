#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode* link;
} ListNode;

typedef struct ListType {
	int size; //노드의 개수
	ListNode* head;
	ListNode* tail;
} ListType;

ListType* create() {
	ListType *plist = (ListType *)malloc(sizeof(ListType)); //포인터는 주소를 저장하는 메모리 //ListType의 땅
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist; //예) 주소값 100 들어감
}

void insert_last(ListType *plist, int coef, int expon) {
	ListNode *temp = (ListNode*)malloc(sizeof(ListNode)); //ListNode의 땅
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;

	if (plist->tail == NULL) {
		plist->head = temp; //첫번째 노드 가리킴
		plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;

	while (a != NULL && b != NULL) {
		int sum;

		if (a->expon == b->expon) {
			sum = a->coef + b->coef;
			insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link; //둘 다 전진
		}
		else if (a->expon > b->expon) {
			insert_last(plist3, a->coef, a->expon);
			a = a->link; //a만 전진
		}
		else {
			insert_last(plist3, b->coef, b->expon);
			b = b->link; //b만 전진
		}
	}
	//남은 다항식을 모두 이동
	for(; a!=NULL; a=a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

int main() {
	ListType* list1, *list2, *list3;
	list1 = create(); //주소값 100을 list1에 저장
	list2 = create();
	list3 = create();

	insert_last(list1, 3,12); //계수3, 지수12를 넣는다. 
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);

	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

	poly_add(list1, list2, list3);
}