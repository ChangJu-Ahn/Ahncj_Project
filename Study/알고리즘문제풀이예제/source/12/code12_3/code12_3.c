#include <stdio.h>

int GCD(int, int);

// 유클리드 호제법을 이용한 최대공약수 구하기
int GCD(int p, int q)
{
	if (q == 0)
		return p;

	return GCD(q, p % q);
}

int main()
{
	int testCases, maxNumber, Solutions;
	int i, j, k;
	int flag = 0;

	freopen("input.txt", "r", stdin);

	// 총 테스트 개수를 입력받음
	scanf("%d", &testCases);

	for (i = 0; i < testCases; i++) {
		Solutions = 0;

		// 구하려는 기약 분수의 최댓값을 입력받음
		scanf("%d", &maxNumber);

		for (j = 1; j <= maxNumber; j++) {
			for (k = 2; k <= maxNumber; k++) {
				// 최대공약수가 1이면 기약 분수의 개수를 증가
				if (j < k && GCD(j, k) == 1) {
					if (flag == 0) {
						printf("찾은 기약 분수 : %d/%d\n", 0, 1); // 0/1 기약 분수 추가
						flag = 1;
					}

					printf("찾은 기약 분수 : %d/%d\n", j, k);
					Solutions++;
				}
			}
		}

		printf("찾은 기약 분수 : %d/%d\n", 1, 1); // 1/1 기약 분수 추가
		printf("찾은 기약 분수의 총 개수 : %d\n\n", Solutions + 2);
	}

	return 0;
}