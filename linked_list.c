#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc(), free()를 사용하기 위한 전처리기

typedef int element;
typedef struct ListNode {  // 노드 타입
	element data;
	struct Listnode* link;
} ListNode;


void insert_set(struct ListNode*first, int data) {  // 기준이 되는 first 노드 뒤에 다음 노드를 추가하는 함수
	struct ListNode* newNode = malloc(sizeof(struct ListNode));  // 새로운 노드 생성
	newNode->link = first->link;  // 새 노드 다음 노드에 기준 노드의 다음 노드를 저장
	newNode->data = data;  // 데이터 저장

	first->link = newNode;  // 기준 노드의 다음 노드에 새 노드를 지정
	printf("%d ", data);  // 데이터 출력
	free(newNode);
}

void hap_set(int x[], int y[], int hap[]) {  // 합집합 연산
	for (int i = 0; i < 5; i++) {  // 합집합에 x의 집합을 다 넣는다.
		hap[i] = x[i];
	}
	int cnt = 5;
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			if (y[j] == x[i])  // x의 집합과 y의 집합의 원소가 같으면
				break;  // 빠져나온다.
			if (i == 4) {
				hap[cnt] = y[j];
				cnt++;
			}
		}
	}
	printf("합집합 : ");
	for (int i = 0; i < cnt; i++) {
		printf("%d ", hap[i]);
	}
	printf("\n");
}

void kyo_set(int x[], int y[], int kyo[]) {  // 교집합 연산
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (x[i] == y[j]) {  // x집합과 y집합의 원소가 같으면
				kyo[cnt] = x[i];  // y집합과 동일한 x집합의 원소가 교집합 배열에 저장된다.
				cnt++;
			}
		}
	}
	printf("교집합 : ");
	for (int i = 0; i < cnt; i++) {
		printf("%d ", kyo[i]);
	}
	printf("\n");
}

void cha_set(int x[], int y[], int cha[]) {  // 차집합 연산
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (x[i] == y[j]) {  // 
				break;
			}
			if (j == 4) {
				cha[cnt] = x[i];  // x집합이 저장되므로 x-y의 차집합이다.
				cnt++;
			}
		}
	}
	printf("차집합 : ");
	for (int i = 0; i < cnt; i++) {
		printf("%d ", cha[i]);
	}
}

int main(void) {
	int hap[10];
	int kyo[10];
	int cha[10];

	struct ListNode* head = malloc(sizeof(struct ListNode));  // 동적 메모리를 할당한다. 

	printf("X의 집합 : ");
	insert_set(head, 3);  // 원소를 삽입한다.
	insert_set(head, 5);
	insert_set(head, 7);
	insert_set(head, 9);
	insert_set(head, 11);
	printf("\n");

	printf("Y의 집합 : ");
	insert_set(head, 4);  // 원소를 삽입한다.
	insert_set(head, 5);
	insert_set(head, 7);
	insert_set(head, 13);
	insert_set(head, 15);
	printf("\n");

	int x[5] = { 3,5,7,9,11 };
	int y[5] = { 4,5,7,13,15 };

	hap_set(x, y, hap);
	kyo_set(x, y, kyo);
	cha_set(x, y, cha);
	return 0;
}