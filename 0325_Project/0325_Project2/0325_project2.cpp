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
	s->data = (element *) malloc(sizeof(int)); // ���� 4����Ʈ �Ҵ� //�������� ������ �ּҴ�. ǥ���ϱ� ���� (element *) 
}

int is_full(StackType* s) {
	return s->top == s->capacity - 1;
}

void push(StackType* s, element item) {
	//overflow check
	if (is_full(s)) {
		//printf("overflow"); //�����޸� �Ҵ��� ��
		s->capacity *= 2; //capacity�� 2��� �ø���
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
		fprintf(stderr, "���� ���� ����\n"); //fprint�� printf�� ������ �˾ƺ���
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
	printf("pop value %d\n", pop(&s)); //���� ���� ����
}