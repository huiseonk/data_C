#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_XY 100  // �̷� ����� �ִ� ũ��

int x, y; // ��, ��
int maze[MAX_XY][MAX_XY];  // �̷��� ���
int start_x, start_y, exit_x, exit_y;  // ����ϴ� x,y ��ǥ, �����ϴ� x,y ��ǥ

void coordinate() {  // ��ǥ ���ϱ�
	printf("X��ǥ(��) : ");  // ��
	scanf("%d", &x);
	printf("Y��ǥ(��) : ");  // ��
	scanf("%d", &y);
	printf("����� ��ǥ : ");  // �̷� ����� ��ǥ
	scanf("%d %d", &start_x, &start_y);
	printf("������ ��ǥ : ");  // �̷� ������ ��ǥ
	scanf("%d %d", &exit_x, &exit_y);

	for (int i = 1; i <= y; i++) {
		scanf("%d", &maze[i][1]);  // �̷ο� 0�� 1�� ���� ����. �ٴ� �� �ִ� ���� 0, �����ִ� ���� 1�� ǥ��
	}
}

typedef struct {  // ť�� ����ü Ÿ��
	int x, y, distance;  // �̷��� ��ġ x,y�� ������ ���������κ����� �Ÿ��� ���.
} QUEUE;

QUEUE queue[10000];  // ť �˳��ϰ� ���
int front, rear;

// BFS Ž���� ���� ť
void enqueue(int x, int y, int distance) {  // ť ����
	if (maze[x][y] != 0) {  // �̷��� ��� ���� 0�� �ƴϸ�
		return;  // return
	}
	queue[rear].x = x;  // x��ǥ�� ť ����
	queue[rear].y = y;  // y��ǥ�� ť ����
	queue[rear].distance = distance;  // ���������κ����� �Ÿ�
	rear++;
}

QUEUE dequeue(void) {  // ť ����
	return queue[front++];
}

int is_empty(void) {  // ť�� ����ִ� ����
	return front == rear;
}

int confirmation(void) {
	front, rear == 0;  // ť ���� �ʱ�ȭ
	int dx[4] = { 0,0,-1,1 };  // �����¿� Ȯ��
	int dy[4] = { -1,1,0,0 };  // �����¿� Ȯ��

	enqueue(start_x, start_y, 0);  // ���� ��ǥ�� ť ����

	while (is_empty) {  // ť�� �� ������
		QUEUE current = dequeue();
		if (current.x == exit_x && current.y == exit_y) {  // ������ x,y ��ǥ ť�� �ⱸ�� x,y ��ǥ�� ���ٸ�
			return current.distance;  // ��������� �Ÿ��� return
		}
		for (int j = 0; j < 4; j++) {  // �����¿� 4���� ���� Ȯ��
			enqueue(current.x + dx[j], current.y + dy[j], current.distance + 1);
		}
	}
}

int main(void) {
	coordinate();  // ��ǥ ����
	int final = confirmation();  // �̷� ���������� ���� Ȯ��
	printf("�� ������ �Ÿ� : %d\n", final);  // �� ������ �Ÿ� ���

	return 0;
}