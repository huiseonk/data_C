#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_XY 100  // 미로 행렬의 최대 크기

int x, y; // 행, 열
int maze[MAX_XY][MAX_XY];  // 미로의 행렬
int start_x, start_y, exit_x, exit_y;  // 출발하는 x,y 좌표, 도착하는 x,y 좌표

void coordinate() {  // 좌표 정하기
	printf("X좌표(열) : ");  // 열
	scanf("%d", &x);
	printf("Y좌표(행) : ");  // 행
	scanf("%d", &y);
	printf("출발점 좌표 : ");  // 미로 출발점 좌표
	scanf("%d %d", &start_x, &start_y);
	printf("도착점 좌표 : ");  // 미로 도착점 좌표
	scanf("%d %d", &exit_x, &exit_y);

	for (int i = 1; i <= y; i++) {
		scanf("%d", &maze[i][1]);  // 미로에 0과 1의 값을 설정. 다닐 수 있는 길은 0, 막혀있는 길은 1로 표현
	}
}

typedef struct {  // 큐의 구조체 타입
	int x, y, distance;  // 미로의 위치 x,y의 정보와 시작점으로부터의 거리를 잰다.
} QUEUE;

QUEUE queue[10000];  // 큐 넉넉하게 잡기
int front, rear;

// BFS 탐색을 위한 큐
void enqueue(int x, int y, int distance) {  // 큐 삽입
	if (maze[x][y] != 0) {  // 미로의 행렬 값이 0이 아니면
		return;  // return
	}
	queue[rear].x = x;  // x좌표의 큐 삽입
	queue[rear].y = y;  // y좌표의 큐 삽입
	queue[rear].distance = distance;  // 시작점으로부터의 거리
	rear++;
}

QUEUE dequeue(void) {  // 큐 삭제
	return queue[front++];
}

int is_empty(void) {  // 큐가 비어있는 상태
	return front == rear;
}

int confirmation(void) {
	front, rear == 0;  // 큐 상태 초기화
	int dx[4] = { 0,0,-1,1 };  // 상하좌우 확인
	int dy[4] = { -1,1,0,0 };  // 상하좌우 확인

	enqueue(start_x, start_y, 0);  // 시작 좌표에 큐 삽입

	while (is_empty) {  // 큐가 빌 때까지
		QUEUE current = dequeue();
		if (current.x == exit_x && current.y == exit_y) {  // 현재의 x,y 좌표 큐가 출구의 x,y 좌표와 같다면
			return current.distance;  // 현재까지의 거리를 return
		}
		for (int j = 0; j < 4; j++) {  // 상하좌우 4번에 대해 확인
			enqueue(current.x + dx[j], current.y + dy[j], current.distance + 1);
		}
	}
}

int main(void) {
	coordinate();  // 좌표 삽입
	int final = confirmation();  // 미로 빠져나가는 정보 확인
	printf("총 움직인 거리 : %d\n", final);  // 총 움직인 거리 출력

	return 0;
}