#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int i, j, k, temp, tmp, count[26] = { 0 }, alphabet[26] = { 0 };
    char str;
    FILE* fp1 = fopen("file.txt", "r");  // file.txt 파일 읽기
    FILE* fp2 = fopen("number.txt", "w");  // number.txt 파일 쓰기
    FILE* fp3 = fopen("alphabet.txt", "w");  // alphabet.txt 파일 쓰기

    while (feof(fp1) == 0) {  // eof(end of file), fp1 파일을 끝까지 모두 읽어 들일 때
        str = fgetc(fp1);  // fp1으로부터 하나씩 문자를 읽어서 변수 str에 저장
        if (str >= 97 && str <= 122) {  // str의 값이 a에서 z까지 일때
            k = str - 97;  // k의 값은 str-97
            count[k] += 1;  // k의 빈도수 하나씩 증가
        }
        else if (str >= 65 && str <= 90) {  // str의 값이 A에서 Z까지 일때
            k = str - 65;  // k의 값은 str-65
            count[k] += 1;  // k의 빈도수 하나씩 증가
        }
    }
    fclose(fp1);  // fp1 파일 닫기

    printf("알파벳\n");
    for (i = 0; i < 26; i++) {
        alphabet[i] = 'a' + i;
        printf("%c ", alphabet[i]);
    }
    printf("\n빈도수\n");
    for (i = 0; i < 26; i++) {
        printf("%d ", count[i]);
    }
    
    for (i = 0; i < 25; i++) {  // 정렬
        for (j = 0; j < 25; j++) {
            if (count[j]> count[j + 1]) {  // count[j]에 대해서 정렬할 때 count[j]가 count[j+1]보다 크면
                temp = count[j];  // temp에 count[j]값 저장
                count[j] = count[j + 1];  // count[j]에 count[j+1]값 저장
                count[j + 1] = temp;  // count[j+1]에 temp값 저장

                tmp = alphabet[j];  // tmp에 alphabet[j]값 저장
                alphabet[j] = alphabet[j + 1];  // alphabet[j]에 alphabet[j+1]값 저장
                alphabet[j + 1] = tmp;  // alphabet[j+1]에 tmp값 저장
            }
        }
    }

    printf("\n빈도수 정렬\n");
    for (i = 0; i < 26; i++) {
        printf("%d ", count[i]);  // 정렬 후 count[i]의 값
        fprintf(fp2, "%d\n", count[i]);  // 정렬 후 count[i]의 값 fp2 파일에 쓰기
    }
    printf("빈도수에 대응되는 알파벳\n");
    for (i = 0; i < 26; i++) {
        printf("%c ", alphabet[i]);  // 정렬 후 alphabet[i]의 값
        fprintf(fp3, "%c\n", alphabet[i]);  // 정렬 후 alphabet[i]의 값 fp3 파일에 쓰기
    }
    fclose(fp2);  // fp2 파일 닫기
    fclose(fp3);  // fp3 파일 닫기
}