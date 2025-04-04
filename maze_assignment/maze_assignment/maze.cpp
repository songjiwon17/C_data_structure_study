#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//스택을 이용하여 미로탐색 프로그램 만들기
//조건
//(1)미로를 랜덤으로 생성
//(2)탈출과정의 위치와 경로를 출력

#define MAX_STACK_SIZE 20
#define MAZE_SIZE 6 //미로의 크기를 6x6으로 지정

//행과 열을 담고 있는 구조체배열
//그 구조체의 타입을 element타입으로 재정의
typedef struct {
	short r; //행
	short c; //열
} element;

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
	return (s->top == -1);
}

//포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

//삽입함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 상태에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

//삭제함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 상태에러\n");
		exit(1); //#include <stdlib.h> 추가
	}
	else return s->data[(s->top)--];
}

element entry = { 1,0 }, here = { 1,0 };

//미로를 생성하는 함수
void maze_generate(char maze[MAZE_SIZE][MAZE_SIZE]) {
	srand(time(NULL)); // 현재 시간을 기반으로 랜덤 시드 설정, 실행할 때마다 다른 결과를 얻을 수 있음 //#include <time.h> 추가

	for (int i = 0; i < MAZE_SIZE; i++) { // 6x6을 만들기 위한 for문
		for (int j = 0; j < MAZE_SIZE; j++) { //외곽 벽을 만들기 위한 for문 
			//예) 3x3을 만들 때 
			// (0,0), (0,1) (0,2)이 외곽 벽이어야하고
			// (2,0), (2,1), (2,2)이 외곽 벽
			// (0,0), (1,0), (2,0)이 외곽 벽
			// (0,2), (1,2), (2,2)이 외곽 벽이 되어야 함
			if (i == 0 || i == MAZE_SIZE - 1 || j == 0 || j == MAZE_SIZE - 1) {
				maze[i][j] = '1';
			}
			else maze[i][j] = (rand() % 3 == 0) ? '1' : '0'; //약 3/1 확률로 랜덤하게 벽 생성
		}
	}
	maze[1][2] = 'e'; //시작 위치
	maze[MAZE_SIZE - 1][MAZE_SIZE - 2] = 'x'; //출구 위치
}

//생성된 미로를 출력하는 함수
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
}

//
//void push_loc(StackType* s, int r, int c) {
//	if (r < 0 || c < 0) return;
//	if (maze[r][c] != '1' && maze[r][c] != '.') {
//		element tmp;
//		tmp.r = r;
//		tmp.c = c;
//		push(s, tmp);
//	}
//}

int main() {
	char maze[MAZE_SIZE][MAZE_SIZE];
	maze_generate(maze);
	maze_print(maze);
}