#include <stdio.h>

int m, n;

int a[21][301];
int t[21][301] = { 0 };
int Benefit[21][301];

void input()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &m);  // 투자할 금액을 입력받는다
	scanf("%d", &n);  // 투자할 기업의 수를 입력받는다
	int z;

	for (int i = 1; i <= m; i++) {  // 1부터 투자할 금액 m까지 읽어온다
		scanf("%d", &z);  // 투자 금액을 z에 읽어온다

		for (int j = 0; j < n; j++)
			// 1부터 j 번째 기업까지 z 금액을 투자했을 때
			// 이익을 배열 a[j][z]에 저장한다
			scanf("%d", &a[j][z]);
	}
}

void process()
{
	int i, j, k;

	for (i = 1; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			for (k = 0; k <= j; k++) {
				// a[i][k]의 이익을 추가한 이익이 원래 이익 t[i][j]보다 큰 경우
				if (t[i - 1][j - k] + a[i][k] > t[i][j]) {
					t[i][j] = t[i - 1][j - k] + a[i][k];
					Benefit[i][j] = k;
				}
			}
		}
	}
}

void output()
{
	int g[21];
	int i, j;

	j = m;

	for (i = n; i >= 0; i--) {
		g[i] = Benefit[i][j];
		j -= g[i];
	}

	for (i = 0; i < n; i++)
		printf("%d ", g[i]);

	printf("\n");
	printf("%d\n", t[n][m]);
}

void main()
{
	input();
	process();
	output();
}