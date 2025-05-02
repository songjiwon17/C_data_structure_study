#include <stdio.h>
#include <stdlib.h> //malloc함수 사용하기 위함

//동적할당을 하기 때문에 크기를 지정할 필요가 없다.
//아래 코드 잘 이해하기

typedef int element;
//자기 참조 구조체
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode * insert_first(ListNode *head, element value) {
	//종적 생성 
	ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //주소값
	p->data = value;
	p->link = head; //현재 head값 200 => 리스트 연결 위함
	head = p; //head가 300이 됨 -> main head값이 300이 됨
	return head;
}

int main() {
	ListNode* head = NULL;

	head = insert_first(head, 10); //Head값 100
	head = insert_first(head, 20); //head값 200
	head = insert_first(head, 30); //head값 300
	//리스트가 거꾸로 연결됨(효율적) -> 출력하려면 바꾸어서 출력해야 함
}