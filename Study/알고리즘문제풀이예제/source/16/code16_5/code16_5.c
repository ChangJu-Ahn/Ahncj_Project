#include <stdio.h>
#define MAX 999999

int Solution;

int main(void)
{
	int tc, T;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (tc = 0; tc < T; tc++) {
		int num, map[101][101] = { 0 };
		int i, j;
		int temp = MAX, n = 1, m;
		Solution = 0;
		scanf("%d", &num);

		for (i = 1; i <= num; i++) {
			for (j = 1; j <= num; j++) {
				scanf("%d", &map[i][j]);
			}

			map[0][i] = 1;
		}

		map[1][0] = 1;
		map[0][1] = 0;

		printf("initial map\n");

		for (i = 0; i <= num; i++) {
			for (j = 0; j <= num; j++) {
				printf("%3d", map[i][j]);
			}

			printf("\n");
		}

		printf("\n");

		while (n < num) {
			for (i = 1; i <= num; i++) {
				if (map[i][0] == 1) {
					for (j = 1; j <= num; j++) {
						if (map[0][j] == 1) {
							if ((map[i][j] <temp) && (map[i][j] != 0)) {
								temp = map[i][j];
								m = j;
							}
						}
					}
				}
			}

			Solution = Solution + temp;
			temp = MAX;
			map[0][m] = 0;
			map[m][0] = 1;
			n++;
		}

		printf("최소 파이프 길이를 구한 이후의 맵\n");

		for (i = 1; i <= num; i++) {
			for (j = 1; j <= num; j++) {
				printf("%3d", map[i][j]);
			}
			printf("\n");
		}

		printf("최소 파이프 길이 : %d\n", Solution);
	}

	return 0;
}