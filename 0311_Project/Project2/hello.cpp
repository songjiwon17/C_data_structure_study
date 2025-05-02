#include <stdio.h>
int main() {
	printf("Hello World\n");
	//선언문- 메모리 요청 + 초기화
	int a = 10;
	printf("%d\n", a);

	printf("%p\n", &a); //16진수로 표현, 실제 주소값으로 표현하려면 &

	//배열 선언+초기화
	int ar[3] = { 1,2,3 };
	for (int i = 0; i < 3; i++ ) {
		printf("%2d", ar[i]);
	}
	printf("\n");
	//포인터 변수 pt의 선언과 초기화
	int* pt = ar; //배열은 &필요없음, 구조체는 &필요함
	// 예) int *spt = &sa;


	//배열의 이름은 배열의 시작주소
	printf("%p\n", ar);
	printf("%p\n", &ar[0]); //17번째 줄과 같아야 함
	printf("%p\n", pt);

	printf("%p\n", &ar[1]);
	printf("%p\n", ar + 1); //4바이트 증가
	printf("%p\n", pt + 1);

	printf("%p\n", &ar[2]);
	printf("%p\n", ar + 2);//데이터의 타입의 크기만큼 증가
	printf("%p\n", pt + 2);

	//구조체 정의 - 사용자 정의 자료형
	struct test
	{
		char ch;
		int k;
		double d;
	};

	//구조체 선언 - 메모리 할당
	struct test sa;

	//구조체 초기화
	sa.ch = 'a';
	sa.k = 1;
	sa.d = 1.1;
	printf("%c\n", sa.ch);
	printf("%d\n", sa.k);
	printf("%lf\n", sa.d);
	printf("%c %d %lf", sa.ch, sa.k, sa.d);
	printf("\n");

	//구조체 포인터 변수 spt 선언+초기화
	struct test* spt = &sa;
	printf("%c\n", spt->ch);
}

//0311 자료구조 수업
// 배열과 구조체
// 배열 : 똑같은 타입으로, 인덱스로 구별
//구조체: 다른 타입도 가능, 연속적으로 배열 할당, 이름으로 구별, 사용자 정의 struct 예) struct test 

//메모리 할당 : 선언해야 메모리가 생김 1. 사용자 정의 2. 선언 => 선언을 해야 메모리가 생기며 구조체가 됨
// struct test sa => 선언 
//예) sa.ch

//포인터변수 선언
// a = 10;
//int *pt = 1004; 1004번째 메모리