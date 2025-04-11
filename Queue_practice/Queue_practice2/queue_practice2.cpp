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
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

//is_full �Լ�
int is_full(QueueType *q) {
	return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

//is_empty �Լ�
int is_empty(QueueType *q) {
	return q->front == q->rear;
}

//������ ���� �Լ�
void enqueue(QueueType *q, element item) {
	if (is_full(q)) {
		printf("ť�� �� ������\n");
		return;
	}
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

//������ ���� �Լ�
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		printf("ť�� �������\n");
		exit(1);
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}

//ť ��� �Լ�
void print_queue(QueueType *q) {
	printf("\n���� ť ���� (front: %d, rear: %d):\n", q->front, q->rear);
	printf("+-------------------------+\n");
	printf("| ");
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("|\n+-------------------------+\n");
}

int main() {
	QueueType q;
	init_queue(&q);
	element item;

	printf("--����ť�� ������ �߰�--\n");
	while (!is_full(&q)) {
		printf("\n");
		printf("�߰��� ���� �Է�: ");
		scanf_s("%d", &item);

		enqueue(&q, item);
		print_queue(&q);
	}
	printf("ť�� ���� ��ȭ����!\n");
	printf("\n");

	printf("--����ť�� ������ ����--\n");
	while (!is_empty(&q)) {
		element item = dequeue(&q);
		printf("���� ���� %d\n", item);

		print_queue(&q);
	}
	printf("ť�� ���� �������!\n");
	printf("\n");
	return 0;
}