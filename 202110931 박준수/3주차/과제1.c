#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	char* ptr[4];
	for (int i = 0;i < 4;i++) {
		ptr[i] = (char*)calloc('\0', 20 * sizeof(char));
		scanf("%s", ptr[i]);
	}
	printf("\n\n");
	for (int i = 0;i < 4;i++)
		printf("%s\n", ptr[i]);
	return 0;
}
