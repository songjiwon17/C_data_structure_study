#include <stdio.h>
#include <stdlib.h> //malloc�Լ� ����ϱ� ����

//�����Ҵ��� �ϱ� ������ ũ�⸦ ������ �ʿ䰡 ����.
//�Ʒ� �ڵ� �� �����ϱ�

typedef int element;
//�ڱ� ���� ����ü
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode * insert_first(ListNode *head, element value) {
	//���� ���� 
	ListNode *p = (ListNode *)malloc(sizeof(ListNode)); //�ּҰ�
	p->data = value;
	p->link = head; //���� head�� 200 => ����Ʈ ���� ����
	head = p; //head�� 300�� �� -> main head���� 300�� ��
	return head;
}

int main() {
	ListNode* head = NULL;

	head = insert_first(head, 10); //Head�� 100
	head = insert_first(head, 20); //head�� 200
	head = insert_first(head, 30); //head�� 300
	//����Ʈ�� �Ųٷ� �����(ȿ����) -> ����Ϸ��� �ٲپ ����ؾ� ��
}