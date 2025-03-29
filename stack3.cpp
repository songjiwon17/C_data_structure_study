#include <stdio.h>
#include <stdlib.h>
#include <string.h> //식별자 strlen을 사용하기 위함

#define MAX_STACK_SIZE 10

//중위표기식을 후위표기식으로 바꾸기

typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item; //s->top에 먼저 1을 증가 후 사용
}
// 삭제함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--]; //s->top을 먼저 사용하고 1을 감소
}
//peek stack의 top에 있는 연산자를 return
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)];
}
//연산자의 우선순위를 결정하기위한 함수
int prec(char op) {
	switch (op)
	{
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}
// 중위표기식을 후위표기식으로 변환하는 함수
void infix_to_postfix(const char exp[]) {
	char ch, top_op; //ch: 내가 push하려고 하는 연산자, top_op: 스택에서 꺼낸 연산자
	int len = strlen(exp);

	StackType s;
	init_stack(&s);

	for (int i = 0; i < len; i++) {
		ch = exp[i]; //내가 push하려고하는 연산자
		switch (ch)
		{
			case '+': case '-': case '*': case '/':
				//우선순위를 판단해서 push
				while (!is_empty(&s) && prec(ch) <=prec(peek(&s))) {
					printf("%c", pop(&s));
				}
				push(&s, ch);
				break;
			case '(':
				push(&s, ch);
				break;
			case ')':
				top_op = pop(&s);
				while (top_op != '(') {
					printf("%c", top_op);
					top_op = pop(&s);
				}
				break;
			default: //피연산자
				printf("%c", ch);
				break;
		}
	} // end for
	while (!is_empty(&s)) {
		printf("%c", pop(&s));
	}
}
int main() {
	const char* s = "(2+3)*4+9"; //문자열을 변경할 필요가 없기 때문에 const 사용
	infix_to_postfix(s);
}