#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100000

int sorted[MAX_SIZE];   // �߰� ������ �ʿ�

// �迭�� �պ����� �����ϴ� �Լ�
// i�� ���ĵ� ���� ����Ʈ�� ���� �ε���
// j�� ���ĵ� ������ ����Ʈ�� ���� �ε���
// k�� ���ĵ� ����Ʈ�� ���� �ε���
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left;  j = mid + 1;  k = left;

	// �� ���� ���ĵ� �κ� �迭�� �����ϴ� ����
	while (i <= mid && j <= right) {  // i�� mid���� �۰ų� ���� j�� right���� �۰ų� ���� ������ �ݺ�
		if (list[i] <= list[j]) {  // list[i]�� list[j]���� �۰ų� ���� ��
			sorted[k++] = list[i++];   // list[i]�� ���� sorted[k]�� �����ϰ� i�� k ����
		}
		else {  // �׷��� ������
			sorted[k++] = list[j++];  // list[j]�� ���� sorted[k]�� �����ϰ� j�� k ����
		}
	}
	if (i > mid) {  // i�� mid���� Ŭ ��
		for (l = j; l <= right; l++) {
			sorted[k++] = list[l];  // ������ �κ� �迭�� ��Ҹ� sorted�� ����
		}
	}
	else {  // �׷��� ���� ���
		for (l = i; l <= mid; l++) { 
			sorted[k++] = list[l];  // ���� �κ� �迭�� ��Ҹ� sorted�� ����
		}
	}

	for (l = left; l <= right; l++) {
		list[l] = sorted[l];  // �迭 sorted[]�� ��Ҹ� �迭 list[]�� �纹��
	}
}

// �պ����� �Լ�
void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right) {  // left�� right���� ���� ��
		mid = (left + right) / 2;  // ����Ʈ �յ��ϰ� ����
		merge_sort(list, left, mid);  // �κ� ����Ʈ ����
		merge_sort(list, mid + 1, right);  // �κ� ����Ʈ ����
		merge(list, left, mid, right);  // �պ�
	}
}

// �պ����� ����Լ�
void printData(int list[], int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", list[i]);
	printf("\n");
}

// ����ð� ���ϴ� �Լ�
float runTime(int n) {  // n�� �޾Ƽ� �迭 ũ�� ���Ѵ�.
	clock_t start, end;  // ������۽ð�, ��������ð� ���� ����(clock_t�� clock()�� ��ȯ ���� ������)
	int* list = (int*)malloc(n * sizeof(int));  // n�� ũ�� ���� �Ҵ�

	start = clock();  // ���� ���� �ð� ����
	merge_sort(list, 0, n - 1);
	end = clock();  // ���� ���� �ð� ����

	free(list);  // �޸� �Ҵ� ����

	return((float)(end - start)) / CLOCKS_PER_SEC;  // ��������ð� - ���Ľ��۽ð��� ����� ����ð��� ���Ѵ�. �� ������
}

int main(void) {
	int inputData1[1000];
	int inputData2[10000];
	int inputData3[100000];

	srand(time(NULL));  // �õ尪 ����
	for (int i = 0; i < 1000; i++)  // �Էµ�����1
		inputData1[i] = rand();  // �� �迭�� ������ �� �ֱ�
	for (int i = 0; i < 10000; i++)  // �Էµ�����2
		inputData2[i] = rand();  // �� �迭�� ������ �� �ֱ�
	for (int i = 0; i < 100000; i++)  // �Էµ�����3
		inputData3[i] = rand();  // �� �迭�� ������ �� �ֱ�

	int n1 = 1000;  // ũ��
	int n2 = 10000;
	int n3 = 100000;

	//printf("���� ��\n");
	//printData(inputData1, n1);

	// �� �迭�� �պ� ����
	merge_sort(inputData1, 0, n1 - 1);
	merge_sort(inputData2, 0, n2 - 1);
	merge_sort(inputData3, 0, n3 - 1);

	//printf("���� ��\n");
	//printf("�Է� ������ 1000��\n");
	//printData(inputData1, n1);
	//printf("�Է� ������ 10000��\n");
	//printData(inputData2, n2);
	//printf("�Է� ������ 100000��\n");
	//printData(inputData3, n3);

	float time1, time2, time3;
	// �Է� �����Ϳ� ���� �ð� ���
	printf("�Է� ������\t���� �ð�(sec)\n");
	time1 = runTime(n1);
	printf("%d\t\t%f\n", n1, time1);
	time2 = runTime(n2);
	printf("%d\t\t%f\n", n2, time2);
	time3 = runTime(n3);
	printf("%d\t\t%f\n", n3, time3);

	return 0;
}