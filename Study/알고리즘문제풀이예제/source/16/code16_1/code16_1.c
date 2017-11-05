#include <stdio.h>

void displayTable(void);

int map[102][102] = { 0 };
int Solution, N, M;
int sx, sy;

void displayTable(void)
{
	int i, j;

	for (i = 1; i < N; i++) {
		for (j = 1; j < M; j++)
			printf("%3d ", map[i][j]);

		printf("\n");
	}
}

int main(void)
{
	int tc, T;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (tc = 0; tc < T; tc++) {
		int i, j, flag;
		scanf("%d %d", &M, &N);

		for (i = 0; i <= N + 1; i++)
			for (j = 0; j <= M + 1; j++)
				map[i][j] = 0;

		for (i = 1; i <= N; i++)
			for (j = 1; j <= M; j++)
				scanf("%d", &map[i][j]);

		scanf("%d %d", &sy, &sx);
		map[sx][sy] = 2;
		Solution = 2;

		printf("초기 맵\n");

		for (i = 1; i <= N; i++) {
			for (j = 1; j <= M; j++)
				printf("%3d ", map[i][j]);

			printf("\n");
		}

		while (1) {
			flag = 1;
			for (i = 1; i <= N; i++) {
				for (j = 1; j <= M; j++) {
					if (map[i][j] == Solution) {
						if ((map[i - 1][j] == 1) || (map[i][j - 1] == 1) ||
							(map[i + 1][j] == 1) || (map[i][j + 1] == 1))
							flag = 0;

						if (map[i - 1][j] == 1)
							map[i - 1][j] = Solution + 1;

						if (map[i][j - 1] == 1)
							map[i][j - 1] = Solution + 1;

						if (map[i + 1][j] == 1)
							map[i + 1][j] = Solution + 1;

						if (map[i][j + 1] == 1)
							map[i][j + 1] = Solution + 1;
					}
				}
			}

			if (flag)
				break;

			else
				Solution++;
		}

		printf("바이러스가 퍼진 이후 맵\n");
		displayTable();
		printf("총 걸린 시간 : %d초\n\n", Solution - 1);
	}

	return 0;
}