#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//������ �̿��Ͽ� �̷�Ž�� ���α׷� �����
//����
//(1)�̷θ� �������� ����
//(2)Ż������� ��ġ�� ��θ� ���

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
			// (0,0), (0,1) (0,2)�� �ܰ� ���̾���ϰ�
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