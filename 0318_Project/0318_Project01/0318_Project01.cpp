#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
}
int is_full(StackType* s) {
	return s->top == MAX_STACK_SIZE - 1;
}
//�Լ����� ���� s���� �޸� �Ҵ���� �ٸ��� ������ �ٸ� ��
//�����͵��� �޸𸮸� �����ϰ� �ִ�.

int is_empty(StackType* s) {
	return s->top == -1;
}

void push(StackType* s, element item) {
	//overflow check!! 5�������� push�� �����ϴ�! ���� 6��°�� ����
	if (is_full(s)) {
		printf("Stack Overflow Error\n");
		return;
	}
	else {
		//s->top = s->top + 1;
		++(s->top); //15�ٰ� ����
		s->data[s->top] = item;
		//s->data[++(s->top)] = item; //�� �ٷ� ����
	}
}

element pop(StackType* s) {
	//underflow check!!
	if (is_empty(s)) {
		printf("Stack underflow Error\n");
		exit(1);
	}
	else {
		int v;
		//v = s->data[s->top];
		//s->top s->top - 1;
		//return v;
		return s->data[(s->top)--];
	}
}

int main() {
	StackType s;

	init_stack(&s);
	push(&s, 10); push(&s, 20); push(&s, 30);

	//push�� �迭���� ����ϱ�
	int res;
	res = pop(&s);
	printf("pop value => %d\n", res); //30
	
	printf("pop value => %d\n", pop(&s)); //20

}