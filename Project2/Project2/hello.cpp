#include <stdio.h>
int main() {
	printf("Hello World\n");
	//����- �޸� ��û + �ʱ�ȭ
	int a = 10;
	printf("%d\n", a);

	printf("%p\n", &a); //16������ ǥ��, ���� �ּҰ����� ǥ���Ϸ��� &

	//�迭 ����+�ʱ�ȭ
	int ar[3] = { 1,2,3 };
	for (int i = 0; i < 3; i++ ) {
		printf("%2d", ar[i]);
	}
	printf("\n");
	//������ ���� pt�� ����� �ʱ�ȭ
	int* pt = ar; //�迭�� &�ʿ����, ����ü�� &�ʿ���
	// ��) int *spt = &sa;


	//�迭�� �̸��� �迭�� �����ּ�
	printf("%p\n", ar);
	printf("%p\n", &ar[0]); //17��° �ٰ� ���ƾ� ��
	printf("%p\n", pt);

	printf("%p\n", &ar[1]);
	printf("%p\n", ar + 1); //4����Ʈ ����
	printf("%p\n", pt + 1);

	printf("%p\n", &ar[2]);
	printf("%p\n", ar + 2);//�������� Ÿ���� ũ�⸸ŭ ����
	printf("%p\n", pt + 2);

	//����ü ���� - ����� ���� �ڷ���
	struct test
	{
		char ch;
		int k;
		double d;
	};

	//����ü ���� - �޸� �Ҵ�
	struct test sa;

	//����ü �ʱ�ȭ
	sa.ch = 'a';
	sa.k = 1;
	sa.d = 1.1;
	printf("%c\n", sa.ch);
	printf("%d\n", sa.k);
	printf("%lf\n", sa.d);
	printf("%c %d %lf", sa.ch, sa.k, sa.d);
	printf("\n");

	//����ü ������ ���� spt ����+�ʱ�ȭ
	struct test* spt = &sa;
	printf("%c\n", spt->ch);
}

//0311 �ڷᱸ�� ����
// �迭�� ����ü
// �迭 : �Ȱ��� Ÿ������, �ε����� ����
//����ü: �ٸ� Ÿ�Ե� ����, ���������� �迭 �Ҵ�, �̸����� ����, ����� ���� struct ��) struct test 

//�޸� �Ҵ� : �����ؾ� �޸𸮰� ���� 1. ����� ���� 2. ���� => ������ �ؾ� �޸𸮰� ����� ����ü�� ��
// struct test sa => ���� 
//��) sa.ch

//�����ͺ��� ����
// a = 10;
//int *pt = 1004; 1004��° �޸�