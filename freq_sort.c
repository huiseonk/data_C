#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int i, j, k, temp, tmp, count[26] = { 0 }, alphabet[26] = { 0 };
    char str;
    FILE* fp1 = fopen("file.txt", "r");  // file.txt ���� �б�
    FILE* fp2 = fopen("number.txt", "w");  // number.txt ���� ����
    FILE* fp3 = fopen("alphabet.txt", "w");  // alphabet.txt ���� ����

    while (feof(fp1) == 0) {  // eof(end of file), fp1 ������ ������ ��� �о� ���� ��
        str = fgetc(fp1);  // fp1���κ��� �ϳ��� ���ڸ� �о ���� str�� ����
        if (str >= 97 && str <= 122) {  // str�� ���� a���� z���� �϶�
            k = str - 97;  // k�� ���� str-97
            count[k] += 1;  // k�� �󵵼� �ϳ��� ����
        }
        else if (str >= 65 && str <= 90) {  // str�� ���� A���� Z���� �϶�
            k = str - 65;  // k�� ���� str-65
            count[k] += 1;  // k�� �󵵼� �ϳ��� ����
        }
    }
    fclose(fp1);  // fp1 ���� �ݱ�

    printf("���ĺ�\n");
    for (i = 0; i < 26; i++) {
        alphabet[i] = 'a' + i;
        printf("%c ", alphabet[i]);
    }
    printf("\n�󵵼�\n");
    for (i = 0; i < 26; i++) {
        printf("%d ", count[i]);
    }
    
    for (i = 0; i < 25; i++) {  // ����
        for (j = 0; j < 25; j++) {
            if (count[j]> count[j + 1]) {  // count[j]�� ���ؼ� ������ �� count[j]�� count[j+1]���� ũ��
                temp = count[j];  // temp�� count[j]�� ����
                count[j] = count[j + 1];  // count[j]�� count[j+1]�� ����
                count[j + 1] = temp;  // count[j+1]�� temp�� ����

                tmp = alphabet[j];  // tmp�� alphabet[j]�� ����
                alphabet[j] = alphabet[j + 1];  // alphabet[j]�� alphabet[j+1]�� ����
                alphabet[j + 1] = tmp;  // alphabet[j+1]�� tmp�� ����
            }
        }
    }

    printf("\n�󵵼� ����\n");
    for (i = 0; i < 26; i++) {
        printf("%d ", count[i]);  // ���� �� count[i]�� ��
        fprintf(fp2, "%d\n", count[i]);  // ���� �� count[i]�� �� fp2 ���Ͽ� ����
    }
    printf("�󵵼��� �����Ǵ� ���ĺ�\n");
    for (i = 0; i < 26; i++) {
        printf("%c ", alphabet[i]);  // ���� �� alphabet[i]�� ��
        fprintf(fp3, "%c\n", alphabet[i]);  // ���� �� alphabet[i]�� �� fp3 ���Ͽ� ����
    }
    fclose(fp2);  // fp2 ���� �ݱ�
    fclose(fp3);  // fp3 ���� �ݱ�
}