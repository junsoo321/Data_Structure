#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int array[2][3][4];
	int val = 1;
	for (int i = 0;i <= 1;i++)
		for (int j = 0;j <= 2;j++)
			for (int k = 0;k <= 3;k++)
				array[i][j][k] = val++;
	return 0;
}
