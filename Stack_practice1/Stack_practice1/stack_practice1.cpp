#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5

//구조체 정의 및 선언하기
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
}
int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}
int is_empty(StackType* s) {
	return s->top == -1;
}
void push(StackType* s, element item) {
	if (is_full(s)) {
		printf("stack overflow\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}
element pop(StackType* s) {
	if (is_empty(s)) {
		printf("stack underflow\n");
		exit(1); //stdlib.h
	}
	else return s->data[(s->top)--];
}

int main() {
	StackType s; //구조체 변수 s

	init_stack(&s);
	push(&s, 10); push(&s, 20); push(&s, 30);

	int res = pop(&s);
	printf("pop value => %d\n", res); //30 top은 1
	printf("pop value => %d\n", pop(&s)); //20 top은 0
}