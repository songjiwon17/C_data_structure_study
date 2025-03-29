#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 

typedef int element;
typedef struct
{
	element* data;
	int capacity;
	int top;

}StackType;

void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element *) malloc(sizeof(int)); // 정수 4바이트 할당 //정수값을 저장할 주소다. 표시하기 위해 (element *) 
}

int is_full(StackType* s) {
	return s->top == s->capacity - 1;
}

void push(StackType* s, element item) {
	//overflow check
	if (is_full(s)) {
		//printf("overflow"); //정적메모리 할당일 때
		s->capacity *= 2; //capacity를 2배로 늘리기
		s->data = (element*)realloc(s->data, s->capacity * sizeof(int));
	}
	s->data[++(s->top)] = item;
}

int is_empty(StackType* s) {
	return s->top == -1;
}

element pop(StackType* s) {
	//underflow check
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n"); //fprint와 printf의 차이점 알아보기
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}

int main() {
	StackType s;
	init_stack(&s);
	push(&s, 10); push(&s, 20);
	printf("pop value %d\n", pop(&s)); //20
	printf("pop value %d\n", pop(&s)); //10
	printf("pop value %d\n", pop(&s)); //스택 공백 에러
}