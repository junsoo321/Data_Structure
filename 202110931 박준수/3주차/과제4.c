#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fact(int a) {
	if (!a)
		return 1;
	printf("fact(%d) 함수 호출!\n", a);
	int k = a * fact(a - 1);
	
	printf("fact(%d) 값 %d 반환!\n", a, k);
	return k;
}

int main() {
	int i;
	printf("정수를 입력하세요 : ");
	scanf("%d", &i);
	printf("\n");
	int res = fact(i);
	printf("\n%d의 팩토리얼 값은 %d입니다.", i, res);
	return 0;
}
