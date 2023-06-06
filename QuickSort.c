#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )  // 배열 요소를 교환

// 분할 함수
int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;  // low는 작은 값
	high = right + 1;  // high는 큰 값
	pivot = list[left];
	do {
		do
			low++;  // low 증가
		while (list[low] < pivot);  // list[low]가 pivot보다 작을 때까지
		do
			high--;  // high 감소
		while (list[high] > pivot);  // list[high]가 pivot보다 클 때까지
		if (low < high) {  // low가 high보다 작다면 
			SWAP(list[low], list[high], temp); // 작은 값과 큰 값을 교환
		}
	} while (low < high);  // low가 high보다 작을 때까지 계속 반복

	SWAP(list[left], list[high], temp);
	return high;
}

// 퀵정렬 함수
void quick_sort(int list[], int left, int right)
{
	if (left < right) {  // left가 right보다 작을 때
		int q = partition(list, left, right);  // 분할 진행
		quick_sort(list, left, q - 1);  // 왼쪽 부분 배열 퀵정렬
		quick_sort(list, q + 1, right);  // 오른쪽 부분 배열 퀵정렬
	}
}

// 퀵정렬 출력 함수
void printData(int list[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", list[i]);
	printf("\n");
}

// 실행시간 구하는 함수
float runTime(int n) {  // n을 받아서 배열 크기 정한다.
	clock_t start, end;  // 실행시작시간, 실행종료시간 변수 선언(clock_t는 clock()의 반환 값을 저장함)
	int* list = (int*)malloc(n * sizeof(int));  // n의 크기 동적 할당

	start = clock();  // 정렬 시작 시간 저장
	quick_sort(list, 0, n - 1);
	end = clock();  // 정렬 종료 시간 저장

	free(list);  // 메모리 할당 해제

	return((float)(end - start)) / CLOCKS_PER_SEC;  // 정렬종료시간 - 정렬시작시간을 계산해 실행시간을 구한다. 초 단위로
}

int main(void) {
	int inputData1[1000];
	int inputData2[10000];
	int inputData3[100000];

	srand(time(NULL));  // 시드값 생성
	for (int i = 0; i < 1000; i++)  // 입력데이터1
		inputData1[i] = rand();  // 각 배열에 랜덤한 값 넣기
	for (int i = 0; i < 10000; i++)  // 입력데이터2
		inputData2[i] = rand();  // 각 배열에 랜덤한 값 넣기
	for (int i = 0; i < 100000; i++)  // 입력데이터3
		inputData3[i] = rand();  // 각 배열에 랜덤한 값 넣기

	int n1 = 1000;
	int n2 = 10000;
	int n3 = 100000;

	//printf("정렬 전\n");
	//printData(inputData1, n1);

	// 각 배열을 퀵 정렬
	quick_sort(inputData1, 0, n1 - 1);
	quick_sort(inputData2, 0, n2 - 1);
	quick_sort(inputData3, 0, n3 - 1);

	//printf("정렬 후\n");
	//printf("입력 데이터 1000개\n");
	//printData(inputData1, n1);
	//printf("입력 데이터 10000개\n");
	//printData(inputData2, n2);
	//printf("입력 데이터 100000개\n");
	//printData(inputData3, n3);

	float time1, time2, time3;
	// 입력 데이터와 실행 시간 출력
	printf("입력 데이터\t실행 시간(sec)\n");
	time1 = runTime(n1);
	printf("%d\t\t%f\n", n1, time1);
	time2 = runTime(n2);
	printf("%d\t\t%f\n", n2, time2);
	time3 = runTime(n3);
	printf("%d\t\t%f\n", n3, time3);

	return 0;
}