#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

//ť
//FIFO ���Լ���
//front�� 0�̸� �����Ͱ� ����

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

//�ʱ�ȭ �Լ�
void init_queue(QueueType *q) {
	/*q->front = -1;*/ // ���� ť
	/*q->rear = -1;*/ // ���� ť
	q->front = q->rear = 0; //���� ť

}

int is_full(QueueType *q) { //q�� �ּҰ� 1000
	return /*q->rear == MAX_QUEUE_SIZE -1;*/ //���� ť
		(q->rear + 1) % MAX_QUEUE_SIZE == q->front; // ���� ť
}

int is_empty(QueueType* q) {
	return q->rear == q->front;
}

//���� �Լ�
void enqueue(QueueType *q, element item) { //q�� �ּҰ� 1000
	//overflow check
	if (is_full(q)) {
		fprintf(stderr, "���ÿ����÷ο�");
		return;
	}
	else /*q->data[++(q->rear)] = item;*/ //���� ť
	q->data[(++(q->rear)) % MAX_QUEUE_SIZE] = item; //���� ť
}

element dequeue(QueueType* q) {
	//underflow check
	if (is_empty(q)) {
		printf("ť�� �����\n");
		exit(1);
	}else /*return q->data[++(q->front)];*/ //���� ť
	return q->data[(++(q->front)) % MAX_QUEUE_SIZE]; //���� ť
}

int main() {
	QueueType q; // �޸� ����, �޸��� �̸� q
	init_queue(&q);
	enqueue(&q, 10); enqueue(&q, 20); enqueue(&q, 30);

	element item = dequeue(&q);

	//ť �� ����Ʈ
	for (int i = q.front; i <= q.rear; i++) {
		printf("%3d\n", q.data[i]);
	}
}