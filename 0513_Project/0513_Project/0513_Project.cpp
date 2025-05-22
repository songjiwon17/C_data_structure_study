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

//삽입함수
void enqueue(LinkedQueueType *q, element data) {
	QueueNode *temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;

	//비어있으면 
	if (is_empty(q)) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp;
		q->rear = temp; //삽입할 때는 front말고 rear값만 원형큐 참고 //그림으로 그려서 연습하기 기말고사
	}
}

//삭제 함수
element dequeue(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	element data = q->front->data;

	if (!is_empty(q)) {
		printf("큐 링크가 비어있음\n");
		exit(1); //리턴이 있는 함수를 종료할 때는 exit(1)
	}
	
	q->front = q->front->link;

	if (q->front == NULL) { //포인터 에러 방지 위해
		q->rear = NULL; 
	}

	free(temp);
	return data;
}

//출력 함수
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

	//삽입
	enqueue(&queue, 1);
	enqueue(&queue, 2);
	enqueue(&queue, 3);
	enqueue(&queue, 4);

	//삭제
	printf("출력데이터: %d->", dequeue(&queue));
	printf("출력데이터: %d->", dequeue(&queue));
}