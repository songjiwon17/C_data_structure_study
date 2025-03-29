#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//���Ҽ��� ����ü�� �����ϰ� �� ���Ҽ��� ���� ��Ģ������ �����ϴ� �Լ��� ����� ����

//���Ҽ� ����ü ����
typedef struct {
	double real;
	double imag;
} ComplexNumber;

//���Ҽ� 1.������ �Է�
void inputComplex(ComplexNumber* x, ComplexNumber* y) {
	printf("ù��° ���Ҽ� �� �Ǽ��� �Է�: ");
	scanf_s("%lf", &x->real);

	printf("ù��° ���Ҽ� �� ����� �Է�(��: -i -> -1�� �Է�): ");
	scanf_s("%lf", &x->imag);

	printf("�ι�° ���Ҽ� �� �Ǽ��� �Է�: ");
	scanf_s("%lf", &y->real);

	printf("�ι�° ���Ҽ� �� ����� �Է�(��: -i -> -1�� �Է�): ");
	scanf_s("%lf", &y->imag);
}

//���Ҽ� ����
ComplexNumber add(ComplexNumber a, ComplexNumber b) {
	ComplexNumber result;
	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return result;
}

//���Ҽ� ����
ComplexNumber subtract(ComplexNumber a, ComplexNumber b) {
	ComplexNumber result;
	result.real = a.real - b.real;
	result.imag = a.imag - b.imag;
	return result;
}

//���Ҽ� ����
ComplexNumber multiply(ComplexNumber a, ComplexNumber b) {
	ComplexNumber result;
	//���Ҽ� ���� ����
	//(a + bi) * (c + di)
	//= (a * c) + (a * di) + (bi * c) + (bi * di)
	//= ac + adi + bci + bd * (i * i)
	result.real = (a.real * b.real) - (a.imag * b.imag); //i�� �����ϸ� -1�� ��
	result.imag = (a.real * b.imag) + (a.imag * b.real);
	return result;
}

//���Ҽ� ������
ComplexNumber divide(ComplexNumber a, ComplexNumber b) {
	ComplexNumber result;
	//���Ҽ� ������ ����
	//�и𿡼� i�� ���ֱ� ���� ���ڿ� �и� �и��� �ӷ� ���Ҽ� (c - di)�� ����
	double denominator = (b.real * b.real) + (b.imag * b.imag); //�и�(denominator)�� (c*c)+(d*d)�̷� ����� ����
	if (denominator == 0) { //�и� 0�� ���
		printf("0���� ���� �� �����ϴ�. \n");
		result.real = result.imag = 0;
	}
	else { //�и�� ������ ����� �Ǽ��ο� ����θ� ���
		result.real = ((a.real * b.real) + (a.imag * b.imag)) / denominator;
		result.imag = ((a.imag * b.real) - (a.real * b.imag)) / denominator;
	}
	return result;
}

int main() {
	//ComplexNumber ����� 0���� �ʱ�ȭ
	ComplexNumber x = { 0,0 }, y = { 0,0 };
	ComplexNumber result;
	int choice;

	printf("***���Ҽ� ����***\n");
	printf("1. �������Է�\n");
	printf("2. ���Ҽ� ����\n");
	printf("3. ���Ҽ� ����\n");
	printf("4. ���Ҽ� ����\n");
	printf("5. ���Ҽ� ������\n");
	printf("6. ���α׷� ����\n");

	while (1) { //6�� �Է��ϱ� ������ ����ڰ� ����ؼ� ������ ������ �� �־�� �ϱ� ������ while(1)������ ���ѷ���
		printf("���۾��� ��ȣ�� �Է�>> ");
		scanf_s("%d", &choice); //����ڷκ��� �޴����� ���ڸ� �Է��� ����

		switch (choice) {
		case 1:
			inputComplex(&x, &y);
			break;
		case 2:
			result = add(x, y);
			printf("%.2lf + %.2lfi\n", result.real, result.imag);
			printf("\n");
			break;
		case 3:
			result = subtract(x, y);
			printf("%.2lf + %.2lfi\n", result.real, result.imag);
			printf("\n");
			break;
		case 4:
			result = multiply(x, y);
			printf("%.2lf", result.real);
			//���� ����ΰ� 0�� ���� �Ǽ��θ� ��µǰ� ����ΰ� 0�� �ƴ� ���� ��ȣ�� �Բ� ����θ� ǥ��
			if (result.imag > 0) {
				printf(" + %.2lfi\n", result.imag);
			}
			else if (result.imag < 0) {
				printf(" - %.2lfi\n", -result.imag);
			}
			else {
				printf("\n");
			}
			break;
		case 5:
			result = divide(x, y);
			printf("%.2lf", result.real);
			//���� ����ΰ� 0�� ���� �Ǽ��θ� ��µǰ� ����ΰ� 0�� �ƴ� ���� ��ȣ�� �Բ� ����θ� ǥ��
			if (result.imag > 0) {
				printf(" + %.2lfi\n", result.imag);
			}
			else if (result.imag < 0) {
				printf(" - %.2lfi\n", -result.imag);
			}
			else {
				printf("\n");
			}
			break;
		case 6:
			//���α׷� ����
			printf("���α׷��� �����մϴ�.");
			return 0; //����ڰ� 6�� �Է��ϸ� return���� 0���� �Ͽ� ���ѷ��� ����
		}
	}
}
