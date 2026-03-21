#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char* arr[4];
	for (int i = 0; i < 4; i++) {
		arr[i] = (char*)malloc(20 * sizeof(char));
		scanf_s("%s", arr[i]);
	}

	printf("\n\n");

	for (int i = 0; i < 4; i++) {
		printf("%s \n", arr[i]);
	}

	return 0;
}
