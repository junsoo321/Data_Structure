#include <stdio.h>

int main(void) {
	char str[20];
	int len = 0;
	printf("문자열을 입력하세요: ");
	scanf_s("%s", str, 20);
	printf("\n입력된 문자열은 \n");
	printf("\"%s\"", str);
	printf("\n입니다.\n");

	while (str[len] != '\0') {
		len++;
	}

	printf("\n입력된 문자열의 길이 = %d", len);
	return 0;
}