#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//원형큐
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

//초기화 함수
void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

//is_full 함수
int is_full(QueueType *q) {
	return q->front == (q->rear + 1) % MAX_QUEUE_SIZE;
}

//is_empty 함수
int is_empty(QueueType *q) {
	return q->front == q->rear;
}

//데이터 삽입 함수
void enqueue(QueueType *q, element item) {
	if (is_full(q)) {
		printf("큐가 꽉 차있음\n");
		return;
	}
	else {
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
		q->data[q->rear] = item;
	}
}

//데이터 삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		printf("큐가 비어있음\n");
		exit(1);
	}
	else {
		q->front = (q->front + 1) % MAX_QUEUE_SIZE;
		return q->data[q->front];
	}
}

//큐 출력 함수
void print_queue(QueueType *q) {
	printf("\n현재 큐 상태 (front: %d, rear: %d):\n", q->front, q->rear);
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

	printf("--원형큐에 데이터 추가--\n");
	while (!is_full(&q)) {
		printf("\n");
		printf("추가할 정수 입력: ");
		scanf_s("%d", &item);

		enqueue(&q, item);
		print_queue(&q);
	}
	printf("큐는 현재 포화상태!\n");
	printf("\n");

	printf("--원형큐에 데이터 삭제--\n");
	while (!is_empty(&q)) {
		element item = dequeue(&q);
		printf("꺼낸 정수 %d\n", item);

		print_queue(&q);
	}
	printf("큐는 현재 공백상태!\n");
	printf("\n");
	return 0;
}