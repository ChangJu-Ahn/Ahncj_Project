#include <stdio.h>
#define MAX 10000

int M, N, C;
int cowHouse[MAX];
int diff[MAX];
int Solution;

void SortingData(int data[], int n);

void SortingData(int data[], int n)
{
	long i, j, t;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (data[j] > data[j + 1]) {
				t = data[j];
				data[j] = data[j + 1];
				data[j + 1] = t;
			}
		}
	}
}

int main(void)
{
	int tc, i, T;
	int max_length;
	int sum;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (tc = 0; tc < T; tc++) {
		sum = 0;
		scanf("%d %d %d", &M, &N, &C);

		for (i = 0; i < C; i++) {
			scanf("%d", &cowHouse[i]);
		}

		SortingData(&cowHouse[0], C);

		for (i = 0; i < C; i++) {
			diff[i] = (cowHouse[i + 1] - cowHouse[i] - 1);
		}

		SortingData(&diff[0], C - 1);

		for (i = 0; i < M; i++) {
			if (i >= C)
				break;

			sum += diff[C - i - 2];
			printf("판자를 사용할 필요가 없는 길이 : %d\n", sum);
		}

		max_length = cowHouse[C - 1] - cowHouse[0] + 1;
		Solution = max_length - sum;

		printf("판자로 막아야 할 외양간들의 총 길이 : %d\n", max_length);
		printf("사용한 판자의 총 길이 : %d\n\n", Solution);
	}

	return 0;
}