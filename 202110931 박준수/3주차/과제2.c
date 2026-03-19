#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int array[2][3][4];
	for (int i = 0;i <= 1;i++)
		for (int j = 0;j <= 2;j++)
			for (int k = 0;k <= 3;k++)
				scanf("%d",&array[i][j][k]);

	for (int i = 0;i <= 1;i++)
		for (int j = 0;j <= 2;j++)
			for (int k = 0;k <= 3;k++)
				printf("array[%d][%d][%d]=%d\n", i, j, k, array[i][j][k]);
	return 0;
}
