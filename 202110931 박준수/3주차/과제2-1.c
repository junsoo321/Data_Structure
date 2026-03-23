#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* str;
	str = (char*)malloc(sizeof(char)*100);
	printf("문자열을 입력하세요 : ");
	scanf("%s", str);

	printf("\n\n입력된 문자열은\n\"%s\"\n입니다.\n",str);
	printf("\n입력된 문자열의 길이 = %d", strlen(str));
	return 0;
}
