#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//선형큐

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

//초기화 함수
void init_queue(QueueType *q) {
	q->front = -1;
	q->rear = -1;
}

//is_full 함수
int is_full(QueueType *q) {
	return q->rear == MAX_QUEUE_SIZE - 1;
}

//is_empty 함수
int is_empty(QueueType* q) {
	return q->front == q->rear;
}

//데이터 삽입 함수
void enqueue(QueueType *q, element item) {
	if (is_full(q)) {
		fprintf(stderr, "스택오버플로우\n");
		return;
	}
	else q->data[++(q->rear)] = item;
}

//데이터 삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		printf("큐가 비었음!\n");
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
	printf("삭제 item 출력\n");

	element item = dequeue(&q);
	printf("%d\n", item);
	item = dequeue(&q);
	printf("%d\n", item);
	item = dequeue(&q);
	printf("%d\n", item);
}