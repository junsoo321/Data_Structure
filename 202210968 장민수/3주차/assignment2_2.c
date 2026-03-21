#include <stdio.h>

int main(void) {
	int array[2][3][4];
	printf("===============입력시작==================\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 4; k++) {
				printf("array[%d][%d][%d] =", i, j, k);
				scanf_s("%d", &array[i][j][k]);
			}
		}
	}

	printf("\n===============출력시작==================\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 4; k++) {
				printf("array[%d][%d][%d] = %d\n", i, j, k, array[i][j][k]);
			}
		}
	}
	return 0;
}