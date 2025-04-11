#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//����ť

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

//�ʱ�ȭ �Լ�
void init_queue(QueueType *q) {
	q->front = -1;
	q->rear = -1;
}

//is_full �Լ�
int is_full(QueueType *q) {
	return q->rear == MAX_QUEUE_SIZE - 1;
}

//is_empty �Լ�
int is_empty(QueueType* q) {
	return q->front == q->rear;
}

//������ ���� �Լ�
void enqueue(QueueType *q, element item) {
	if (is_full(q)) {
		fprintf(stderr, "���ÿ����÷ο�\n");
		return;
	}
	else q->data[++(q->rear)] = item;
}

//������ ���� �Լ�
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		printf("ť�� �����!\n");
		exit(1);
	}
	else return q->data[++(q->front)];
}


int main() {
	QueueType q;
	init_queue(&q);
	enqueue(&q, 10); enqueue(&q, 20); enqueue(&q, 30);

	for (int i = 0; i <= q.rear; i++) {
		printf("%d\n", q.data[i]);
	}
	printf("\n");
	printf("���� item ���\n");

	element item = dequeue(&q);
	printf("%d\n", item);
	item = dequeue(&q);
	printf("%d\n", item);
	item = dequeue(&q);
	printf("%d\n", item);
}