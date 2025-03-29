#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

//���� �ʱ�ȭ �Լ�
void init_stack(StackType *s) {
	s->top = -1;
}

//���� ���� ���� �Լ�
int is_empty(StackType* s) {
	return s->top == -1;
}

//��ȭ ���� ���� �Լ�
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

//���� �Լ� push
void push(StackType* s, element item) {
	if(is_full(s)){
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}

//���� �Լ� pop
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}



//����ǥ����� ����ǥ������� ��ȯ�ϴ� �Լ�
void postfix_to_infix() {

}


//����ǥ����� ����ǥ������� ��ȯ�ϴ� ���α׷�
int main() {
	const char* s = "23+4*9+";
	//postfix_to_infix();
}