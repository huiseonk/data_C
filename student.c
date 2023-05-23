#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc(), free()를 사용하기 위한 전처리기
#include <math.h>  // sqrt를 사용하기 위한 전처리기

struct studentData {  // studentData라는 태그로 구조체를 정의한다.
	int id;  // 학번
	char name[10];  // 이름
	int middle;  // 중간고사 점수
	int final;  // 기말고사 점수
	float sum;
	float average;
};

int main(void) {
	struct studentData* s;  // 구조체 변수를 정의한다.
	int i = 0;
	int n;
	float all_sum = 0;
	float all_avg = 0;
	float bunsan = 0;

	FILE* fp1 = fopen("student.txt", "r");  // 학생의 정보가 담겨있는 파일을 읽기모드로 불러온다.

	printf("학생의 수 : ");
	scanf_s("%d", &n);  // 학생 수는 최대 40명으로 필요한 수만큼 메모리를 할당받기 위해 학생의 수를 입력받는다.
	printf("학번\t이름\t중간\t기말\t평균\n");

	s = (struct studentData*)malloc(n * sizeof(struct studentData));  // 동적 메모리를 할당한다. 

	for (i = 0; i < n; i++) {  // 학생의 수만큼
		fscanf(fp1, "%d %s %d %d", &s[i].id, &s[i].name, &s[i].middle, &s[i].final);  // student.txt에서 학생의 정보를 읽어서 각 구조체 멤버의 배열에 저장한다.
		s[i].sum = s[i].middle + s[i].final;  // 각 학생 별 중간고사와 기말고사 점수의 총점을 구한다.
		s[i].average = s[i].sum / 2;  // 각 학생 별 중간고사와 기말고사의 평균을 구한다.
		printf("%d\t%s\t%d\t%d\t%f\n", s[i].id, s[i].name, s[i].middle, s[i].final, s[i].average);  // 읽어온 학생의 정보를 출력한다.
	}

	printf("--------------전체 학생의 평균----------------\n");
	for (i = 0; i < n; i++) {
		s[i].sum = s[i].middle + s[i].final;  // 각 학생 별 중간고사와 기말고사 점수의 총점을 구한다.
		all_sum = all_sum + s[i].sum;  // 전체 학생의 총점을 구한다.
		all_avg = all_sum / (n * 2);  // 전체 학생의 평균을 구한다.
	}
	printf("전체 평균 = %f\n", all_avg);

	printf("--------------표준편차----------------\n");
	for (i = 0; i < n; i++) {
		bunsan = (bunsan + ((s[i].middle - all_avg) * (s[i].middle - all_avg) + (s[i].final - all_avg) * (s[i].final - all_avg))) / n - 1;
		// 표준편차를 구하기 위해 분산을 먼저 구한다.
	}
	printf("표준편차 = %f\n", sqrt(bunsan));  // 루트 분산은 표준편차를 구하기 위한 공식

	fclose(fp1);  // fp1 파일 닫기
	free(s);  // 동적 할당받았던 메모리를 반납한다.
	
	return 0;
}