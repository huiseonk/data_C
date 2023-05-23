#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>  // malloc(), free()�� ����ϱ� ���� ��ó����
#include <math.h>  // sqrt�� ����ϱ� ���� ��ó����

struct studentData {  // studentData��� �±׷� ����ü�� �����Ѵ�.
	int id;  // �й�
	char name[10];  // �̸�
	int middle;  // �߰���� ����
	int final;  // �⸻��� ����
	float sum;
	float average;
};

int main(void) {
	struct studentData* s;  // ����ü ������ �����Ѵ�.
	int i = 0;
	int n;
	float all_sum = 0;
	float all_avg = 0;
	float bunsan = 0;

	FILE* fp1 = fopen("student.txt", "r");  // �л��� ������ ����ִ� ������ �б���� �ҷ��´�.

	printf("�л��� �� : ");
	scanf_s("%d", &n);  // �л� ���� �ִ� 40������ �ʿ��� ����ŭ �޸𸮸� �Ҵ�ޱ� ���� �л��� ���� �Է¹޴´�.
	printf("�й�\t�̸�\t�߰�\t�⸻\t���\n");

	s = (struct studentData*)malloc(n * sizeof(struct studentData));  // ���� �޸𸮸� �Ҵ��Ѵ�. 

	for (i = 0; i < n; i++) {  // �л��� ����ŭ
		fscanf(fp1, "%d %s %d %d", &s[i].id, &s[i].name, &s[i].middle, &s[i].final);  // student.txt���� �л��� ������ �о �� ����ü ����� �迭�� �����Ѵ�.
		s[i].sum = s[i].middle + s[i].final;  // �� �л� �� �߰����� �⸻��� ������ ������ ���Ѵ�.
		s[i].average = s[i].sum / 2;  // �� �л� �� �߰����� �⸻����� ����� ���Ѵ�.
		printf("%d\t%s\t%d\t%d\t%f\n", s[i].id, s[i].name, s[i].middle, s[i].final, s[i].average);  // �о�� �л��� ������ ����Ѵ�.
	}

	printf("--------------��ü �л��� ���----------------\n");
	for (i = 0; i < n; i++) {
		s[i].sum = s[i].middle + s[i].final;  // �� �л� �� �߰����� �⸻��� ������ ������ ���Ѵ�.
		all_sum = all_sum + s[i].sum;  // ��ü �л��� ������ ���Ѵ�.
		all_avg = all_sum / (n * 2);  // ��ü �л��� ����� ���Ѵ�.
	}
	printf("��ü ��� = %f\n", all_avg);

	printf("--------------ǥ������----------------\n");
	for (i = 0; i < n; i++) {
		bunsan = (bunsan + ((s[i].middle - all_avg) * (s[i].middle - all_avg) + (s[i].final - all_avg) * (s[i].final - all_avg))) / n - 1;
		// ǥ�������� ���ϱ� ���� �л��� ���� ���Ѵ�.
	}
	printf("ǥ������ = %f\n", sqrt(bunsan));  // ��Ʈ �л��� ǥ�������� ���ϱ� ���� ����

	fclose(fp1);  // fp1 ���� �ݱ�
	free(s);  // ���� �Ҵ�޾Ҵ� �޸𸮸� �ݳ��Ѵ�.
	
	return 0;
}