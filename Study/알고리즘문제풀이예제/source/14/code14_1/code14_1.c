#include<stdio.h>
#define MAX_STEPS 3012

int value_Steps[MAX_STEPS];
int Solutions[MAX_STEPS];

int main() {
	int i, j;
	int oneJumpSteps, noJumpSteps;
	int num_Steps;
	int testCases;

	freopen("input.txt", "r", stdin);

	// 총 테스트 개수를 입력받는다
	scanf("%d", &testCases);

	for (i = 0; i < testCases; i++) {

		// 계단 개수를 입력받는다
		scanf("%d", &num_Steps);

		// 각 계단의 값을 입력받는다
		for (j = 1; j <= num_Steps; j++) {
			scanf("%d", &value_Steps[j]);
		}

		// 처음부터 두 번째 계단까지 값을 구함
		Solutions[0] = 0;
		Solutions[1] = value_Steps[1];
		Solutions[2] = value_Steps[1] + value_Steps[2];

		// 세 번째 계단부터 누적값을 계산함
		for (j = 3; j <= num_Steps; j++) {
			noJumpSteps = value_Steps[j] + value_Steps[j - 1] + Solutions[j - 3];
			oneJumpSteps = value_Steps[j] + Solutions[j - 2];

			// 두 가지 경우 중에서 큰 값을 선택
			if (noJumpSteps > oneJumpSteps)
				Solutions[j] = noJumpSteps;

			else
				Solutions[j] = oneJumpSteps;

			printf("Solutions[%d] : %d\n", j, Solutions[j]);
		}

		printf("%d\n", Solutions[num_Steps]);
	}

	return 0;
}