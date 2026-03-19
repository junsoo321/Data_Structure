#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	char list[3][10] = { "이름","학과","학번" };
	char* arr[2][3];
	for (int k = 0;k < 2;k++) {
		for (int i = 0;i <= 1;i++) {
			if (k) printf("학생 %d\n", i + 1);
			for (int j = 0;j <= 2;j++) {
				if(k) printf("\t%s\n", arr[i][j]);
				else {
					printf("학생 %d의 %s : ", i + 1, list[j]);
					arr[i][j] = (char*)malloc(30 * sizeof(char));
					scanf("%s", arr[i][j]);
				}
			}
			printf("\n");
		}
	}

	return 0;
}
