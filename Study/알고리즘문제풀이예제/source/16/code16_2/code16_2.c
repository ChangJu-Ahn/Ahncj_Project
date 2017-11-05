#include <stdio.h>

int map[27][27] = { 0 };
int Solution;
int N;

void checkHousing(int, int);

void checkHousing(int x, int y)
{
	map[x][y] = 0;

	if (map[x - 1][y])
		checkHousing(x - 1, y);

	if (map[x][y - 1])
		checkHousing(x, y - 1);

	if (map[x + 1][y])
		checkHousing(x + 1, y);

	if (map[x][y + 1])
		checkHousing(x, y + 1);
}

int main(void)
{
	int tc, T;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (tc = 0; tc < T; tc++) {
		int i, j;
		scanf("%d", &N);
		Solution = 0;

		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				scanf("%d", &map[i][j]);

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (map[i][j]) {
					Solution++;
					checkHousing(i, j);
				}
			}
		}

		printf("%d\n", Solution);
	}

	return 0;
}