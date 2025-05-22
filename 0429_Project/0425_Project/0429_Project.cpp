#include <stdio.h>
#include <stdlib.h>

// 단지 하나의 항(노드)를 나타내는 구조체 ListNode
typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode* link;
} ListNode;

// 다항식 전체를 나타내는 구조체 ListType
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
	//새로운 항을 담을 노드를 동적으로 할당하고 포인터 temp에 저장
	ListNode *temp = (ListNode*)malloc(sizeof(ListNode)); //ListNode의 땅 
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;

	if (plist->tail == NULL) {
		plist->head = temp; //첫번째 노드 가리킴
		plist->tail = temp;
	}
	else {
		plist->tail->link = temp; //현재 tail 노드 뒤에 새 노드를 연결하고, tail을 새 노드로 갱신
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
	//연결 리스트는 인덱스가 없기 때문에 link 포인터를 따라가야함
	for(; a!=NULL; a=a->link) //a=a->link의 의미: 지금 노드의 다음 노드로 가자.
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}

int main() {
	ListType* list1, *list2, *list3;
	list1 = create(); //주소값 100을 list1에 저장
	list2 = create();
	list3 = create();

	//insert_last()로 추가하는 각 항은 ListNode
	//이 노드들을 연결한 전체 다항식은 ListType
	insert_last(list1, 3,12); //계수3, 지수12를 넣는다. 
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);

	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

	poly_add(list1, list2, list3);
}