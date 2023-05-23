#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc(), free()�� ����ϱ� ���� ��ó����

typedef int element;
typedef struct ListNode {  // ��� Ÿ��
	element data;
	struct Listnode* link;
} ListNode;


void insert_set(struct ListNode*first, int data) {  // ������ �Ǵ� first ��� �ڿ� ���� ��带 �߰��ϴ� �Լ�
	struct ListNode* newNode = malloc(sizeof(struct ListNode));  // ���ο� ��� ����
	newNode->link = first->link;  // �� ��� ���� ��忡 ���� ����� ���� ��带 ����
	newNode->data = data;  // ������ ����

	first->link = newNode;  // ���� ����� ���� ��忡 �� ��带 ����
	printf("%d ", data);  // ������ ���
	free(newNode);
}

void hap_set(int x[], int y[], int hap[]) {  // ������ ����
	for (int i = 0; i < 5; i++) {  // �����տ� x�� ������ �� �ִ´�.
		hap[i] = x[i];
	}
	int cnt = 5;
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 5; i++) {
			if (y[j] == x[i])  // x�� ���հ� y�� ������ ���Ұ� ������
				break;  // �������´�.
			if (i == 4) {
				hap[cnt] = y[j];
				cnt++;
			}
		}
	}
	printf("������ : ");
	for (int i = 0; i < cnt; i++) {
		printf("%d ", hap[i]);
	}
	printf("\n");
}

void kyo_set(int x[], int y[], int kyo[]) {  // ������ ����
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (x[i] == y[j]) {  // x���հ� y������ ���Ұ� ������
				kyo[cnt] = x[i];  // y���հ� ������ x������ ���Ұ� ������ �迭�� ����ȴ�.
				cnt++;
			}
		}
	}
	printf("������ : ");
	for (int i = 0; i < cnt; i++) {
		printf("%d ", kyo[i]);
	}
	printf("\n");
}

void cha_set(int x[], int y[], int cha[]) {  // ������ ����
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (x[i] == y[j]) {  // 
				break;
			}
			if (j == 4) {
				cha[cnt] = x[i];  // x������ ����ǹǷ� x-y�� �������̴�.
				cnt++;
			}
		}
	}
	printf("������ : ");
	for (int i = 0; i < cnt; i++) {
		printf("%d ", cha[i]);
	}
}

int main(void) {
	int hap[10];
	int kyo[10];
	int cha[10];

	struct ListNode* head = malloc(sizeof(struct ListNode));  // ���� �޸𸮸� �Ҵ��Ѵ�. 

	printf("X�� ���� : ");
	insert_set(head, 3);  // ���Ҹ� �����Ѵ�.
	insert_set(head, 5);
	insert_set(head, 7);
	insert_set(head, 9);
	insert_set(head, 11);
	printf("\n");

	printf("Y�� ���� : ");
	insert_set(head, 4);  // ���Ҹ� �����Ѵ�.
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