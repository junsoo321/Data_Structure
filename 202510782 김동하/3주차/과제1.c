#include <stdio.h>
#include <stdlib.h>

int main() {
	char* ptr[4];

	for (int i = 0; i < 4; i++) {
		ptr[i] = (char*)calloc(20, sizeof(char));
		scanf_s("%19s", ptr[i]);
	}

	for (int i = 0;i < 4;i++)
		printf("%s\n", ptr[i]);

	return 0;
}