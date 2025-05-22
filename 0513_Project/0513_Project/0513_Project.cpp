#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct QueueNode {
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct {
	QueueNode* front;
	QueueNode* rear;
} LinkedQueueType;

void init(LinkedQueueType*q) {
	q->front = NULL;
	q->rear = NULL;
}

int is_empty(LinkedQueueType* q) {
	return (q->front == NULL);
}

//�����Լ�
void enqueue(LinkedQueueType *q, element data) {
	QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;

	//��������� 
	if (is_empty(q)) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp;
		q->rear = temp; //������ ���� front���� rear���� ����ť ���� //�׸����� �׷��� �����ϱ� �⸻���
	}
}

//���� �Լ�
element dequeue(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	element data = q->front->data;

	if (!is_empty(q)) {
		printf("ť ��ũ�� �������\n");
		exit(1); //������ �ִ� �Լ��� ������ ���� exit(1)
	}
	
	q->front = q->front->link;

	if (q->front == NULL) { //������ ���� ���� ����
		q->rear = NULL; 
	}

	free(temp);
	return data;
}

//��� �Լ�
void print_queue(LinkedQueueType* q) {
	QueueNode* p;
	for (p = q->front; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL\n");
}

int main() {
	LinkedQueueType queue;
	init(&queue);

	//����
	enqueue(&queue, 1);
	enqueue(&queue, 2);
	enqueue(&queue, 3);
	enqueue(&queue, 4);

	//����
	printf("��µ�����: %d->", dequeue(&queue));
	printf("��µ�����: %d->", dequeue(&queue));
}