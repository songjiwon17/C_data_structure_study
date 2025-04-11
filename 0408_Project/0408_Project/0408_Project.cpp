#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

//큐
//FIFO 선입선출
//front가 0이면 데이터가 없음

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

//초기화 함수
void init_queue(QueueType *q) {
	/*q->front = -1;*/ // 선형 큐
	/*q->rear = -1;*/ // 선형 큐
	q->front = q->rear = 0; //원형 큐

}

int is_full(QueueType *q) { //q의 주소값 1000
	return /*q->rear == MAX_QUEUE_SIZE -1;*/ //선형 큐
		(q->rear + 1) % MAX_QUEUE_SIZE == q->front; // 원형 큐
}

int is_empty(QueueType* q) {
	return q->rear == q->front;
}

//삽입 함수
void enqueue(QueueType *q, element item) { //q의 주소값 1000
	//overflow check
	if (is_full(q)) {
		fprintf(stderr, "스택오버플로우");
		return;
	}
	else /*q->data[++(q->rear)] = item;*/ //선형 큐
	q->data[(++(q->rear)) % MAX_QUEUE_SIZE] = item; //원형 큐
}

element dequeue(QueueType* q) {
	//underflow check
	if (is_empty(q)) {
		printf("큐가 비었음\n");
		exit(1);
	}else /*return q->data[++(q->front)];*/ //선형 큐
	return q->data[(++(q->front)) % MAX_QUEUE_SIZE]; //원형 큐
}

int main() {
	QueueType q; // 메모리 생성, 메모리의 이름 q
	init_queue(&q);
	enqueue(&q, 10); enqueue(&q, 20); enqueue(&q, 30);

	element item = dequeue(&q);

	//큐 값 프린트
	for (int i = q.front; i <= q.rear; i++) {
		printf("%3d\n", q.data[i]);
	}
}