#include <stdio.h>

char tmpChar[2];
char initMatrix[128];

int main(void)
{
	int tc;
	int i, j;
	int testCases;
	int num_Matrix;

	freopen("input.txt", "r", stdin);

	// 테스트 케이스를 입력받는다
	scanf("%d", &testCases);

	for (tc = 0; tc < testCases; tc++) {
		// 행렬 크기를 입력받는다. 대칭 행렬은 정사각행렬이다
		scanf("%d", &num_Matrix);

		// 행렬 데이터를 입력받는다
		for (i = 0; i < num_Matrix; i++)
			scanf("%s", &initMatrix[i]);

		for (i = 0; i < num_Matrix; i++) {
			for (j = 0; j < num_Matrix; j++) {
				char c = initMatrix[i ^ j];
				if (j == num_Matrix - 1)
					printf("%c\n", c);

				else
					printf("%c ", c);
			}
		}

		printf("\n");
	}

	return 0;
}