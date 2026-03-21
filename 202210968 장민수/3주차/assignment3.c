#include <stdio.h>

int main(void) {
	char data[2][3][30];
	const char *options[3] = {"이름", "학과", "학번"};
	char inputs[30];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("학생 %d의 %s : ", i + 1, options[j]);
			scanf_s("%[^\n]", inputs, 30); 
			getchar();

			for (int k = 0; k < 30; k++) {
				data[i][j][k] = inputs[k];
				inputs[k] = '\0';
			}
		}
	}

	for (int i = 0; i < 2; i++) {
		printf("학생 %d\n", i + 1);
		for (int j = 0; j < 3; j++) {
			printf("\t");
			for (int k = 0; data[i][j][k] != '\0'; k++) {
				printf("%c", data[i][j][k]);
			}
			printf("\n");
		}
	}

	return 0;
}