#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

//head: 현재 연결 리스트의 첫 번째 노드를 가리키는 포인터
//value: 로 추가할 노드에 저장할 데이터
ListNode* insert_first(ListNode* head, element value) {
	//ListNode 구조체 크기만큼의 메모리를 동적할당
	//p는 새로 생성된 노드를 가리키는 포인터
	ListNode* p = (ListNode *)malloc(sizeof(ListNode)); //형 변환(ListNode*)을 해줌
	p->data = value;
	p->link = head; //기존의 첫 번째 노드가 새 노드의 다음 노드가
	head = p; //head 포인터를 새 노드를 가리키도록 변경, 새 노드가 리스트의 가장 앞에 위치
	return head; //새로 삽입된 노드를 첫 번째로 하는 리스트의 새 head를 반환
}

void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) {
		printf("%d ->", p->data);
	}
	printf("NULL\n");
}

ListNode* reverse(ListNode* head) {
	ListNode* p, * q, * r;

	p = head;
	q = NULL;
	while (p != NULL) {
		r = q; //r은 역순으로 만들 리스트, r은 q
		q = p; //p는 q를 차례대로 따라감
		p = p->link;
		q->link = r; //q의 링크 방향을 바꿈
	}
	return q; //새롭게 만들어진 역순 리스트의 시작 주소
}

int main() {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	head1 = insert_first(head1, 10);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 30);
	print_list(head1);

	head2 = reverse(head1);
	print_list(head2);
	return 0;
}