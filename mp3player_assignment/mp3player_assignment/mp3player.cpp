#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 음악 재생을 위한 Windows API 헤더
#include <windows.h>
#include <mmsystem.h>
#include <wchar.h>  // wchar_t 타입 사용을 위함
#include <locale.h> // setlocale 사용을 위함
#pragma comment(lib, "winmm.lib")  // winmm 라이브러리 링크

//곡 정보 구조체
typedef struct {
	char songTitle[100];
	char path[300];
} element;

typedef struct DListNode {
	struct DListNode* llink;
	element data;
	struct DListNode* rlink;
} DListNode;

//현재 재생 중인 노드를 가리키는 포인터
DListNode* current;

//리스트 초기화 함수
void init(DListNode *pHead) {
	pHead->llink = pHead;
	pHead->rlink = pHead;
}

//노드 추가, 곡 추가 함수
void dInsert(DListNode* before, element data) {
	DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));

	if (newNode == NULL) {
		fprintf(stderr, "메모리 할당 실패\n");
		exit(1);
	}

	//곡 정보 복사
	strcpy(newNode->data.songTitle, data.songTitle);
	strcpy(newNode->data.path, data.path);

	newNode->llink = before;
	newNode->rlink = before->rlink;
	before->rlink->llink = newNode;
	before->rlink = newNode;

	//리스트가 비어있을 경우 current 초기화
	if (current == before && current->rlink == before) {
		current = newNode;
	}
}

//노드 삭제, 현재 곡 삭제 함수
void dDelete(DListNode *head) {

	if (current == head) {
		printf("삭제할 곡이 없습니다!\n");
		return;
	}

	DListNode* remove = current;

	//current를 다음 노드로 이동
	current = current->rlink;

	remove->llink->rlink = remove->rlink;
	remove->rlink->llink = remove->llink;

	printf("[%s]가 삭제되었습니다.\n", remove->data.songTitle);
	free(remove);

	// 리스트가 비었다면 current = head
	if (head->rlink == head) {
		current = head;
	}
	// 삭제 후 current가 head라면 다음 노드로 이동
	else if (current == head) {
		current = head->rlink;
	}
}

//곡 리스트 출력 함수
void printfDList(DListNode* head) {
	DListNode* p = head->rlink;

	if (p == head) {
		printf("[곡이 없습니다.]\n");
		return;
	}

	while (p != head) {
		if (p == current) {
			printf("[ %s (현재 재생중)] ", p->data.songTitle);
		}
		else {
			printf("[ %s ] ", p->data.songTitle);
		}
		p = p->rlink;

		if (p != head) printf(" -> ");
	}
	printf("\n");
}

// 음악 재생 함수 (파일 경로를 wchar_t로 변환 후 재생)
void playMusic(const char* filepath) {
	wchar_t wPath[300];
	mbstowcs(wPath, filepath, 300); // 문자열 변환 (멀티바이트 -> 와이드)
	PlaySoundW(wPath, NULL, SND_FILENAME | SND_ASYNC); // 비동기 재생
}

// < 를 선택했을 때 이전 곡 재생 함수
void movePrev(DListNode* head) {
	current = current->llink;
	if (current == head) current = current->llink;
}

// > 를 선택했을 때 다음 곡 재생 함수
void moveNext(DListNode* head) {
	current = current->rlink;
	if (current == head) current = current->rlink;
}

int main() {
	// 한글 경로를 위한 로케일 설정
	setlocale(LC_ALL, "");

	int menu;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	current = head;

	while (1) {
		printf("\n===== MP3 플레이어 메뉴 =====\n");
		printf("1. 곡 삽입\n");
		printf("2. 곡 삭제\n");
		printf("3. 플레이리스트 보기\n");
		printf("4. 플레이리스트 재생하기\n");
		printf("5. 종료\n");
		printf(">> 메뉴 선택: ");
		scanf_s("%d", &menu);
		while (getchar() != '\n'); //입력 버퍼 지우기

		switch(menu) {
			printf("\n");
		//곡 삽입
		case 1:
			element newSong;
			printf("어떤 곡을 추가할까요?: ");
			fgets(newSong.songTitle, sizeof(newSong.songTitle), stdin);
			newSong.songTitle[strcspn(newSong.songTitle, "\n")] = '\0';

			printf("곡 파일 경로를 입력하세요 (예: C:\\music\\hello.wav): ");
			fgets(newSong.path, sizeof(newSong.path), stdin);
			newSong.path[strcspn(newSong.path, "\n")] = '\0';

			dInsert(head, newSong);

			// 삽입 후 current가 초기 상태라면 첫 곡으로 지정
			if (current == head)
				current = head->rlink;
			break;
		//곡 삭제
		case 2:
			dDelete(head);
			break;
		//플레이리스트 출력
		case 3:
			printf("나의 플레이리스트\n");
			printfDList(head);
			break;
		//플레이리스트 재생
		case 4: {
			char ch;

			//플레이리스트에 곡이 없을 때
			if (head->rlink == head) {
				printf("플레이리스트에 곡이 없습니다!\n");
				break;
			}

			// 처음 재생 시 current가 head라면 이전 곡으로 이동
			if (current == head) {
				current = head->rlink;
			}

			printf("현재 나의 플레이리스트\n");
			printfDList(head);
			playMusic(current->data.path);

			while (1) {
				printf("명령을 입력하세요[<, >, q]: ");
				ch = getchar();
				while (getchar() != '\n');

				if (ch == '<') {
					movePrev(head);
					printfDList(head);
					playMusic(current->data.path);
				}
				else if (ch == '>') {
					moveNext(head);
					printfDList(head);
					playMusic(current->data.path);
				}
				else if (ch == 'q') {
					PlaySound(NULL, 0, 0);  // 재생 중지
					break;
				}
				else {
					printf("<, >, q 중 하나를 입력하세요.\n");
				}
			}
			break;
		}
		//프로그램 종료
		case 5:
			printf("프로그램을 종료합니다.\n");
			return 0;

		default:
			printf("잘못된 입력입니다.\n");
		}
	}
}