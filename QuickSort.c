#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )  // �迭 ��Ҹ� ��ȯ

// ���� �Լ�
int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;  // low�� ���� ��
	high = right + 1;  // high�� ū ��
	pivot = list[left];
	do {
		do
			low++;  // low ����
		while (list[low] < pivot);  // list[low]�� pivot���� ���� ������
		do
			high--;  // high ����
		while (list[high] > pivot);  // list[high]�� pivot���� Ŭ ������
		if (low < high) {  // low�� high���� �۴ٸ� 
			SWAP(list[low], list[high], temp); // ���� ���� ū ���� ��ȯ
		}
	} while (low < high);  // low�� high���� ���� ������ ��� �ݺ�

	SWAP(list[left], list[high], temp);
	return high;
}

// ������ �Լ�
void quick_sort(int list[], int left, int right)
{
	if (left < right) {  // left�� right���� ���� ��
		int q = partition(list, left, right);  // ���� ����
		quick_sort(list, left, q - 1);  // ���� �κ� �迭 ������
		quick_sort(list, q + 1, right);  // ������ �κ� �迭 ������
	}
}

// ������ ��� �Լ�
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
	quick_sort(list, 0, n - 1);
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

	int n1 = 1000;
	int n2 = 10000;
	int n3 = 100000;

	//printf("���� ��\n");
	//printData(inputData1, n1);

	// �� �迭�� �� ����
	quick_sort(inputData1, 0, n1 - 1);
	quick_sort(inputData2, 0, n2 - 1);
	quick_sort(inputData3, 0, n3 - 1);

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