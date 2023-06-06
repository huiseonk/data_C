#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100000

int sorted[MAX_SIZE];   // 추가 공간이 필요

// 배열의 합병과정 수행하는 함수
// i는 정렬된 왼쪽 리스트에 대한 인덱스
// j는 정렬된 오른쪽 리스트에 대한 인덱스
// k는 정렬될 리스트에 대한 인덱스
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;  j = mid + 1;  k = left;

	// 두 개의 정렬된 부분 배열을 병합하는 과정
	while (i <= mid && j <= right) {  // i가 mid보다 작거나 같고 j가 right보다 작거나 같을 때까지 반복
		if (list[i] <= list[j]) {  // list[i]가 list[j]보다 작거나 같을 때
			sorted[k++] = list[i++];   // list[i]의 값을 sorted[k]에 저장하고 i와 k 증가
		}
		else {  // 그렇지 않으면
			sorted[k++] = list[j++];  // list[j]의 값을 sorted[k]에 저장하고 j와 k 증가
		}
	}
	if (i > mid) {  // i가 mid보다 클 때
		for (l = j; l <= right; l++) {
			sorted[k++] = list[l];  // 오른쪽 부분 배열의 요소를 sorted에 복사
		}
	}
	else {  // 그렇지 않은 경우
		for (l = i; l <= mid; l++) { 
			sorted[k++] = list[l];  // 왼쪽 부분 배열의 요소를 sorted에 복사
		}
	}

	for (l = left; l <= right; l++) {
		list[l] = sorted[l];  // 배열 sorted[]의 요소를 배열 list[]로 재복사
	}
}

// 합병정렬 함수
void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right) {  // left가 right보다 작을 때
		mid = (left + right) / 2;  // 리스트 균등하게 분할
		merge_sort(list, left, mid);  // 부분 리스트 정렬
		merge_sort(list, mid + 1, right);  // 부분 리스트 정렬
		merge(list, left, mid, right);  // 합병
	}
}

// 합병정렬 출력함수
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
	merge_sort(list, 0, n - 1);
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

	int n1 = 1000;  // 크기
	int n2 = 10000;
	int n3 = 100000;

	//printf("정렬 전\n");
	//printData(inputData1, n1);

	// 각 배열을 합병 정렬
	merge_sort(inputData1, 0, n1 - 1);
	merge_sort(inputData2, 0, n2 - 1);
	merge_sort(inputData3, 0, n3 - 1);

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