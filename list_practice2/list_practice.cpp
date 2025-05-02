#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

//head: ���� ���� ����Ʈ�� ù ��° ��带 ����Ű�� ������
//value: �� �߰��� ��忡 ������ ������
ListNode* insert_first(ListNode* head, element value) {
	//ListNode ����ü ũ�⸸ŭ�� �޸𸮸� �����Ҵ�
	//p�� ���� ������ ��带 ����Ű�� ������
	ListNode* p = (ListNode *)malloc(sizeof(ListNode)); //�� ��ȯ(ListNode*)�� ����
	p->data = value;
	p->link = head; //������ ù ��° ��尡 �� ����� ���� ��尡
	head = p; //head �����͸� �� ��带 ����Ű���� ����, �� ��尡 ����Ʈ�� ���� �տ� ��ġ
	return head; //���� ���Ե� ��带 ù ��°�� �ϴ� ����Ʈ�� �� head�� ��ȯ
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
		r = q; //r�� �������� ���� ����Ʈ, r�� q
		q = p; //p�� q�� ���ʴ�� ����
		p = p->link;
		q->link = r; //q�� ��ũ ������ �ٲ�
	}
	return q; //���Ӱ� ������� ���� ����Ʈ�� ���� �ּ�
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