#include <stdio.h>

int extendPrime(int N);
int checkPrime(int num);
int prime[8][1000];

int extendPrime(int N)
{
	int i, j;
	int num;
	int k;
	int x;

	for (i = 0; i < N; i++) {
		if (i == 0) {
			if (prime[0][0] == 0) {
				prime[0][0] = 2;
				prime[0][1] = 3;
				prime[0][2] = 5;
				prime[0][3] = 7;
			}
		}

		else {
			x = 0;
			for (j = 0; prime[i - 1][j] > 0; j++) {
				for (k = 0; k < 5; k++) {
					num = prime[i - 1][j] * 10 + 2 * k + 1;
					printf("candidated num : %d\n", num);

					if ((prime[i][x] == 0) && (checkPrime(num))) {
						prime[i][x] = num;
						x++;
					}
				}
			}
		}
	}

	return 0;
}

int checkPrime(int num)
{
	int i;

	for (i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}

	return 1;
}

int main()
{
	int testCases, tc;
	int i;
	int baseNumber;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &testCases);

	for (tc = 0; tc < testCases; ++tc) {
		scanf("%d", &baseNumber);
		extendPrime(baseNumber);

		for (i = 0; prime[baseNumber - 1][i] > 0; i++) {
			printf("Prime number : %d\n", prime[baseNumber - 1][i]);
		}
		printf("\n");
	}

	return 0;
}