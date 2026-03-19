#include <stdio.h>

int main() {
	char data[2][3][30];
	char list[3][10] = { "이름", "학과", "학번" };

	for (int a = 0; a < 2; a++) {
		for (int b = 0; b < 3; b++) {
			printf("학생%d의 %s: ", a + 1, list[b]);
			int c = 0;
			char ch;
			while (1) {
				scanf_s("%c", &ch);
				if (ch == '\n') break;
				data[a][b][c++] = ch;
			}
			data[a][b][c] = '\0';
		}
	}

	for (int a = 0; a < 2; a++) {
		printf("학생 %d\n", a + 1);
		for (int b = 0; b < 3; b++) {
			printf("\t%s: ", list[b]);
			for (int c = 0; data[a][b][c] != '\0'; c++) {
				printf("%c", data[a][b][c]);
			}
			printf("\n");
		}
	}

	return 0;
}