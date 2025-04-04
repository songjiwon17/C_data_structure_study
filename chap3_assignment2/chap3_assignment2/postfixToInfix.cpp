#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

typedef char element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

//스택 초기화 함수
void init_stack(StackType *s) {
	s->top = -1;
}

//공백 상태 검출 함수
int is_empty(StackType* s) {
	return s->top == -1;
}

//포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

//삽입 함수 push
void push(StackType* s, element item) {
	if(is_full(s)){
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		s->data[++(s->top)] = item;
	}
}

//삭제 함수 pop
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}



//후위표기식을 중위표기식으로 변환하는 함수
void postfix_to_infix() {

}


//후위표기식을 중위표기식으로 변환하는 프로그램
int main() {
	const char* s = "23+4*9+";
	//postfix_to_infix();
}