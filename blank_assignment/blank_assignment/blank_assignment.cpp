#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//�ϳ��� ���� ��Ÿ���� ����ü ListNode
typedef struct ListNode {
	int coef; //���
	int expon; //����
	struct ListNode* link;
} ListNode;

//���׽� ��ü�� ��Ÿ���� ����ü ListType
typedef struct ListType {
	int size; // ����� ����
	ListNode* head;
	ListNode* tail;
} ListType;

//���׽� ���� �Լ�
ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

//���׽� ������ �� �߰�
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

//���׽� ���� �Լ�
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

//���׽��� �Է¹޴� �Լ�
void poly_input(ListType* plist, char name) {
	int n, coef, expon;
	printf("\n");
	printf("���׽� %c�� ���� ���� �Է�: ", name);
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("���׽� %c�� %d��° ���� ����� ���� �Է�: ", name, i + 1);
		scanf_s("%d %d", &coef, &expon);
		insert_last(plist, coef, expon);
	}
}

//���׽Ŀ� x�� �����Ͽ� ����ϴ� �Լ�
double poly_eval(ListType* plist, double x) {
	double result = 0.0;
	ListNode* p = plist->head;
	while (p != NULL) {
		result += p->coef * pow(x, p->expon);
		p = p->link;
	}
	return result;
}

//���׽� ��� �Լ�
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
		printf("\n===== ���׽� ���α׷� �޴� =====\n");
		printf("1. ���׽� A, B �Է�\n");
		printf("2. C = A + B ��� ���׽� ���\n");
		printf("3. 3���� ���� x�� ���� 3���� ����� C�� ���\n");
		printf("4. ����\n\n");

		printf("�޴��� ������>> ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			polyA = create();
			polyB = create();

			poly_input(polyA, 'A');
			printf("�Է��� ���׽�A: ");
			poly_print(polyA);

			poly_input(polyB, 'B');
			printf("�Է��� ���׽�B: ");
			poly_print(polyB);

			break;
		case 2:
			if (polyA == NULL || polyB == NULL) {
				printf("���׽� A�� B�� �Է��ϼ���.\n");
			}
			else {
				polyC = create();
				poly_add(polyA, polyB, polyC);
				poly_print(polyC);
			}
			break;
		case 3:
			if (polyC == NULL) {
				printf("2���� ���� �������ּ���.\n");
			}
			else {
				srand((unsigned int)time(NULL)); //���� �õ� �ʱ�ȭ
				printf("x�� �����ϰ� 3���� ���Ƿ� �̽��ϴ�.\n");

				for (int i = 0; i < 3; i++) {
					double x = ((double)(rand() % 2001) - 1000) / 100.0;  // -10.00 ~ 10.00
					double result = poly_eval(polyC, x);
					printf("%d��° ����x�� x=%.2f�� ������ ���: C= %.2f\n", i + 1, x, result);
				}
			}
			break;
		case 4:
			printf("���׽� ��� ���α׷��� �����մϴ�.\n");
			exit(1);
		default:
			printf("�ٽ� �Է��ϼ���.");
			break;
			}
		}
	}