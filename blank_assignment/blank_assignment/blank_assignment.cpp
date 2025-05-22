#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//하나의 항을 나타내는 구조체 ListNode
typedef struct ListNode {
	int coef; //계수
	int expon; //지수
	struct ListNode* link;
} ListNode;

//다항식 전체를 나타내는 구조체 ListType
typedef struct ListType {
	int size; // 노드의 개수
	ListNode* head;
	ListNode* tail;
} ListType;

//다항식 생성 함수
ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

//다항식 마지막 항 추가
void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;

	if (plist->tail == NULL) {
		plist->head = temp;
		plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
}

//다항식 덧셈 함수
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* A = plist1->head;
	ListNode* B = plist2->head;

	while (A != NULL && B != NULL) {
		int sum;

		if (A->expon == B->expon) {
			sum = A->coef + B->coef;
			insert_last(plist3, sum, A->expon);
			A = A->link; B = B->link;
		}
		else if (A->expon > B->expon) {
			insert_last(plist3, A->coef, A->expon);
			A = A->link;
		}
		else {
			insert_last(plist3, B->coef, B->expon);
			B = B->link;
		}
	}
	for (; A != NULL; A = A->link) {
		insert_last(plist3, A->coef, A->expon);
	}
	for (; B != NULL; B = B->link) {
		insert_last(plist3, B->coef, B->expon);
	}
}

//다항식을 입력받는 함수
void poly_input(ListType* plist, char name) {
	int n, coef, expon;
	printf("\n");
	printf("다항식 %c의 항의 개수 입력: ", name);
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("다항식 %c의 %d번째 항의 계수와 지수 입력: ", name, i + 1);
		scanf_s("%d %d", &coef, &expon);
		insert_last(plist, coef, expon);
	}
}

//다항식에 x를 대입하여 계산하는 함수
double poly_eval(ListType* plist, double x) {
	double result = 0.0;
	ListNode* p = plist->head;
	while (p != NULL) {
		result += p->coef * pow(x, p->expon);
		p = p->link;
	}
	return result;
}

//다항식 출력 함수
void poly_print(ListType* plist) {
	ListNode* p = plist->head;
	printf("C = ");
	for (; p; p = p->link) {
		printf("%dX^%d", p->coef, p->expon);
		if (p->link != NULL) {
			printf(" + ");
		}
	}
	printf("\n");
}

int main() {
	int choice;
	ListType* polyA = NULL;
	ListType* polyB = NULL;
	ListType* polyC = NULL;

	while (1) {
		printf("\n===== 다항식 프로그램 메뉴 =====\n");
		printf("1. 다항식 A, B 입력\n");
		printf("2. C = A + B 결과 다항식 출력\n");
		printf("3. 3개의 랜덤 x에 대해 3개의 결과값 C를 출력\n");
		printf("4. 종료\n\n");

		printf("메뉴를 고르세요>> ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			polyA = create();
			polyB = create();

			poly_input(polyA, 'A');
			printf("입력한 다항식A: ");
			poly_print(polyA);

			poly_input(polyB, 'B');
			printf("입력한 다항식B: ");
			poly_print(polyB);

			break;
		case 2:
			if (polyA == NULL || polyB == NULL) {
				printf("다항식 A와 B를 입력하세요.\n");
			}
			else {
				polyC = create();
				poly_add(polyA, polyB, polyC);
				poly_print(polyC);
			}
			break;
		case 3:
			if (polyC == NULL) {
				printf("2번을 먼저 실행해주세요.\n");
			}
			else {
				srand((unsigned int)time(NULL)); //랜덤 시드 초기화
				printf("x는 랜덤하게 3개를 임의로 뽑습니다.\n");

				for (int i = 0; i < 3; i++) {
					double x = ((double)(rand() % 2001) - 1000) / 100.0;  // -10.00 ~ 10.00
					double result = poly_eval(polyC, x);
					printf("%d번째 랜덤x인 x=%.2f를 대입한 결과: C= %.2f\n", i + 1, x, result);
				}
			}
			break;
		case 4:
			printf("다항식 계산 프로그램을 종료합니다.\n");
			exit(1);
		default:
			printf("다시 입력하세요.");
			break;
			}
		}
	}