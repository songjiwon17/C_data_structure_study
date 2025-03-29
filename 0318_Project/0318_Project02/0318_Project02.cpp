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
//함수에서 사용된 s들은 메모리 할당들이 다르기 때문에 다른 것
//포인터들이 메모리를 공유하고 있다.

int is_empty(StackType* s) {
	return s->top == -1;
}

void push(StackType* s, element item) {
	//overflow check!! 5번까지는 push가 가능하다! 다음 6번째는 오류
	if (is_full(s)) {
		printf("Stack Overflow Error\n");
		return;
	}
	else {
		//s->top = s->top + 1;
		++(s->top); //15줄과 같음
		s->data[s->top] = item;
		//s->data[++(s->top)] = item; //한 줄로 가능
	}
}

element pop(StackType* s) {
	//underflow check!!
	if (is_empty(s)) {
		printf("Stack underflow Error\n");
		exit(1);
	}
	else {
		//int v;
		//v = s->data[s->top];
		//s->top s->top - 1;
		//return v;
		return s->data[(s->top)--];
	}
}

int check_matching(const char* in) {
	//p[0]이나 in[0]이나 똑같다.
	StackType s;
	char ch, open_ch;

	init_stack(&s);
	int n = strlen(in);

	for (int i = 0; i < n; i++) {
		ch = in[i]; //{를 읽어옴
		switch (ch) {
		case '{':
		case '[':
		case '(':
			push(&s, ch);
			break;
		case '}':
		case ']':
		case ')':
			if (is_empty(&s)) return 0;
			open_ch = pop(&s);
			if ((open_ch == '(' && ch != ')') ||
				(open_ch == '[' && ch != ']') ||
				(open_ch == '{' && ch != '}'))
				return 0;
			break;
		} //end swith
	} //end for
	return is_empty(&s);
}

int main() {

	//괄호검사
	const char* p = "{[A(i+1))]=1;}";

	if (check_matching(p)) {
		printf("%s 괄호 검사 성공!\n", p);
	}
	else {
		printf("%s 괄호 검사 실패!\n", p);
	}
}