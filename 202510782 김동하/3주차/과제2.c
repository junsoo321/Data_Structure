#include <stdio.h>

int main(void) {
	int val[2][3][4] = { 0, };

	for (int a = 0; a < 2; a++) {
		for (int b = 0; b < 3; b++) {
			for (int c = 0; c < 4; c++) {
				scanf_s("%d", &val[a][b][c]);
			}
		}
	}

	for (int a = 0; a < 2; a++) {
		for (int b = 0; b < 3; b++) {
			for (int c; c < 4; c++) {
				printf("%d\n", val[a][b][c]);
			}
		}
	}



	return 0;
}