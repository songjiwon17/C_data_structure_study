#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//������ �̿��Ͽ� �̷�Ž�� ���α׷� �����
//����
//1. (1)�̷θ� �������� ����
//2. (1)Ż������� ��ġ�� ��θ� ���

#define MAX_STACK_SIZE 20
#define MAZE_SIZE 6 //�̷��� ũ�⸦ 6x6���� ����

//��� ���� ��� �ִ� ����ü�迭
//�� ����ü�� Ÿ���� elementŸ������ ������
typedef struct {
	short r; //��
	short c; //��
} element;

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
	return (s->top == -1);
}

//��ȭ ���� ���� �Լ�
int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

//�����Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ���¿���\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

//�����Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ���¿���\n");
		exit(1); //#include <stdlib.h> �߰�
	}
	else return s->data[(s->top)--];
}

element entry = { 1,0 }, here = { 1,0 };

//�̷θ� �����ϴ� �Լ�
void maze_generate(char maze[MAZE_SIZE][MAZE_SIZE]) {
	srand(time(NULL)); // ���� �ð��� ������� ���� �õ� ����, ������ ������ �ٸ� ����� ���� �� ���� //#include <time.h> �߰�

	for (int i = 0; i < MAZE_SIZE; i++) { // 6x6�� ����� ���� for��
		for (int j = 0; j < MAZE_SIZE; j++) { //�ܰ� ���� ����� ���� for�� 
			//��) 3x3�� ���� �� 
			// (0,0), (0,1) (0,2)�� �ܰ� ��
			// (2,0), (2,1), (2,2)�� �ܰ� ��
			// (0,0), (1,0), (2,0)�� �ܰ� ��
			// (0,2), (1,2), (2,2)�� �ܰ� ���� �Ǿ�� ��
			if (i == 0 || i == MAZE_SIZE - 1 || j == 0 || j == MAZE_SIZE - 1) {
				maze[i][j] = '1';
			}
			else maze[i][j] = (rand() % 3 == 0) ? '1' : '0'; //�� 3/1 Ȯ���� �����ϰ� �� ����
		}
	}
	maze[1][2] = 'e'; //���� ��ġ
	maze[MAZE_SIZE - 1][MAZE_SIZE - 2] = 'x'; //�ⱸ ��ġ
}

//������ �̷θ� ����ϴ� �Լ�
void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
	for (int i = 0; i < MAZE_SIZE; i++) {
		for (int j = 0; j < MAZE_SIZE; j++) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
}

//�ֺ� ��ġ�� �˻��ϰ� ���ÿ� �ִ� �Լ�
void push_loc(StackType* s, char maze[MAZE_SIZE][MAZE_SIZE], int r, int c) {
	if (r < 0 || r >= MAZE_SIZE || c < 0 || c >= MAZE_SIZE) return;
	if (maze[r][c] == '0' || maze[r][c] == 'x') {
		element tmp = { r,c };
		push(s, tmp);
	}
}

//���ÿ� ���� ���� ����ϴ� �Լ�
void stack_print(StackType* s) {
	printf("���� ���� ����:\n");
	for (int i = s->top; i >= 0; i--) {
		printf("(%d, %d)\n", s->data[i].r, s->data[i].c);
	}
	printf("\n");
}

//�̷θ� Ž���ϴ� �Լ�
int solve_maze(char maze[MAZE_SIZE][MAZE_SIZE]) {
	StackType s;
	init_stack(&s);
	element start = { 1,2 }; //���� ��ġ 'e'
	push(&s, start);

	while (!is_empty(&s)) {
		element pos = pop(&s); //��ġ�� ������ pos�� ����, ���� Ž�� ���� ��ġ�� ����
		int r = pos.r;
		int c = pos.c;

		printf("���� ��ġ: (%d, %d)\n", r, c); //Ž�� ��� ���

		if (maze[r][c] == 'x') { //���� ��ġ�� 'x'��� �̷� Ż�� ����
			printf("\n�̷� Ż�� ����!\n\n");
			return 1; //return 1�� �����̹Ƿ� ���α׷� ����
		}

		if (maze[r][c] != 'e') {
			maze[r][c] = '.'; //Ž���� ��� ǥ��
		}

		push_loc(&s, maze, r-1, c); //���� ��ġ�� �� Ȯ��
		push_loc(&s, maze, r + 1, c); //���� ��ġ�� �Ʒ� Ȯ��
		push_loc(&s, maze, r, c - 1); //���� ��ġ�� ���� Ȯ��
		push_loc(&s, maze, r, c + 1); //���� ��ġ�� ������ Ȯ��

		stack_print(&s);
	}
	printf("\nŻ�� �Ұ��� �̷�!\n\n");
	return 0;
}

int main() {
	char maze[MAZE_SIZE][MAZE_SIZE];
	printf("==������ �̷�==\n");
	maze_generate(maze);
	maze_print(maze);
	solve_maze(maze);
	printf("==Ž���� ���==\n");
	maze_print(maze);
}