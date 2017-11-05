#include <stdio.h>
#define MIN (-99999)

int N;
int data[10001];
int Solution;

int main(void)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++) {
		int i;
		int sum = 0;

		scanf("%d", &N);

		for (i = 0; i < N; i++) {
			scanf("%d", &data[i]);
		}

		Solution = MIN;

		for (i = 0; i < N; i++) {
			sum = sum + data[i];

			if (Solution < sum) {
				Solution = sum;
				printf("Solution이 새로운 값 %d로 업데이트됐습니다\n", Solution);
			}

			if (sum < 0) {
				sum = 0;
			}
		}

		printf("%d\n", Solution);
	}

	return 0;
}