#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//스택을 이용하여 미로탐색 프로그램 만들기
//조건
//1. (1)미로를 랜덤으로 생성
//2. (1)탈출과정의 위치와 경로를 출력

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
			// (0,0), (0,1) (0,2)이 외곽 벽
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

//주변 위치를 검사하고 스택에 넣는 함수
void push_loc(StackType* s, char maze[MAZE_SIZE][MAZE_SIZE], int r, int c) {
	if (r < 0 || r >= MAZE_SIZE || c < 0 || c >= MAZE_SIZE) return;
	if (maze[r][c] == '0' || maze[r][c] == 'x') {
		element tmp = { r,c };
		push(s, tmp);
	}
}

//스택에 쌓인 값들 출력하는 함수
void stack_print(StackType* s) {
	printf("현재 스택 상태:\n");
	for (int i = s->top; i >= 0; i--) {
		printf("(%d, %d)\n", s->data[i].r, s->data[i].c);
	}
	printf("\n");
}

//미로를 탐색하는 함수
int solve_maze(char maze[MAZE_SIZE][MAZE_SIZE]) {
	StackType s;
	init_stack(&s);
	element start = { 1,2 }; //시작 위치 'e'
	push(&s, start);

	while (!is_empty(&s)) {
		element pos = pop(&s); //위치를 꺼내서 pos에 저장, 지금 탐색 중인 위치를 꺼냄
		int r = pos.r;
		int c = pos.c;

		printf("현재 위치: (%d, %d)\n", r, c); //탐색 경로 출력

		if (maze[r][c] == 'x') { //현재 위치가 'x'라면 미로 탈출 성공
			printf("\n미로 탈출 성공!\n\n");
			return 1; //return 1로 성공이므로 프로그램 종료
		}

		if (maze[r][c] != 'e') {
			maze[r][c] = '.'; //탐색한 경로 표시
		}

		push_loc(&s, maze, r-1, c); //현재 위치의 위 확인
		push_loc(&s, maze, r + 1, c); //현재 위치의 아래 확인
		push_loc(&s, maze, r, c - 1); //현재 위치의 왼쪽 확인
		push_loc(&s, maze, r, c + 1); //현재 위치의 오른쪽 확인

		stack_print(&s);
	}
	printf("\n탈출 불가능 미로!\n\n");
	return 0;
}

int main() {
	char maze[MAZE_SIZE][MAZE_SIZE];
	printf("==생성된 미로==\n");
	maze_generate(maze);
	maze_print(maze);
	solve_maze(maze);
	printf("==탐색한 경로==\n");
	maze_print(maze);
}