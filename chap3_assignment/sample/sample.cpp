#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//복소수를 구조체로 정의하고 두 복소수에 대해 사칙연산을 수행하는 함수를 만드는 과제

//복소수 구조체 정의
typedef struct {
	double real;
	double imag;
} ComplexNumber;

//복소수 1.데이터 입력
void inputComplex(ComplexNumber* x, ComplexNumber* y) {
	printf("첫번째 복소수 중 실수부 입력: ");
	scanf_s("%lf", &x->real);

	printf("첫번째 복소수 중 허수부 입력(예: -i -> -1로 입력): ");
	scanf_s("%lf", &x->imag);

	printf("두번째 복소수 중 실수부 입력: ");
	scanf_s("%lf", &y->real);

	printf("두번째 복소수 중 허수부 입력(예: -i -> -1로 입력): ");
	scanf_s("%lf", &y->imag);
}

//복소수 덧셈
ComplexNumber add(ComplexNumber a, ComplexNumber b) {
	ComplexNumber result;
	result.real = a.real + b.real;
	result.imag = a.imag + b.imag;
	return result;
}

//복소수 뺄셈
ComplexNumber subtract(ComplexNumber a, ComplexNumber b) {
	ComplexNumber result;
	result.real = a.real - b.real;
	result.imag = a.imag - b.imag;
	return result;
}

//복소수 곱셈
ComplexNumber multiply(ComplexNumber a, ComplexNumber b) {
	ComplexNumber result;
	//복소수 곱셈 과정
	//(a + bi) * (c + di)
	//= (a * c) + (a * di) + (bi * c) + (bi * di)
	//= ac + adi + bci + bd * (i * i)
	result.real = (a.real * b.real) - (a.imag * b.imag); //i는 제곱하면 -1이 됨
	result.imag = (a.real * b.imag) + (a.imag * b.real);
	return result;
}

//복소수 나눗셈
ComplexNumber divide(ComplexNumber a, ComplexNumber b) {
	ComplexNumber result;
	//복소수 나눗셈 과정
	//분모에서 i를 없애기 위해 분자와 분모에 분모의 켤레 복소수 (c - di)를 곱함
	double denominator = (b.real * b.real) + (b.imag * b.imag); //분모(denominator)는 (c*c)+(d*d)이런 결과로 나옴
	if (denominator == 0) { //분모가 0일 경우
		printf("0으로 나눌 수 없습니다. \n");
		result.real = result.imag = 0;
	}
	else { //분모로 나누어 결과의 실수부와 허수부를 계산
		result.real = ((a.real * b.real) + (a.imag * b.imag)) / denominator;
		result.imag = ((a.imag * b.real) - (a.real * b.imag)) / denominator;
	}
	return result;
}

int main() {
	//ComplexNumber 멤버를 0으로 초기화
	ComplexNumber x = { 0,0 }, y = { 0,0 };
	ComplexNumber result;
	int choice;

	printf("***복소수 연산***\n");
	printf("1. 데이터입력\n");
	printf("2. 복소수 덧셈\n");
	printf("3. 복소수 뺄셈\n");
	printf("4. 복소수 곱셈\n");
	printf("5. 복소수 나눗셈\n");
	printf("6. 프로그램 종료\n");

	while (1) { //6을 입력하기 전까지 사용자가 계속해서 연산을 수행할 수 있어야 하기 때문에 while(1)문으로 무한루프
		printf("◆작업할 번호를 입력>> ");
		scanf_s("%d", &choice); //사용자로부터 메뉴에서 숫자를 입력을 받음

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
			//만약 허수부가 0일 때는 실수부만 출력되고 허수부가 0이 아닐 때는 부호와 함께 허수부를 표시
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
			//만약 허수부가 0일 때는 실수부만 출력되고 허수부가 0이 아닐 때는 부호와 함께 허수부를 표시
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
			//프로그램 종료
			printf("프로그램을 종료합니다.");
			return 0; //사용자가 6을 입력하면 return값을 0으로 하여 무한루프 종료
		}
	}
}
