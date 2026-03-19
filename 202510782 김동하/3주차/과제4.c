#include <stdio.h>

int fact(int n) {
	if (n <= 1) {
		return (1);
	}
	else {
		return (n * fact(n - 1));
	}
}

int main() {
	int num = 0;
	int result = 0;
	printf("정수를 입력하세요: ");
	scanf_s("%d", &num);

	result = fact(num);

	printf("%d의 팩토리얼 값은 %d입니다.\n", num, result);

	return 0;
}