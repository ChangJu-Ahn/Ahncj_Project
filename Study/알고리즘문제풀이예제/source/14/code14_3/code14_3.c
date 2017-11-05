#include <stdio.h>
#define INIT_MAX_RATIO (-1000000)

int main(void) {
	int tc, testCases;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	// 테스트 케이스를 입력 받는다.
	scanf("%d", &testCases);

	for (tc = 0; tc < testCases; tc++) {
		float xpos[500], heights[500];
		int numofStake, i, j, pos, Solutions;
		float ratio, maxRatio;

		// 말뚝 개수를 입력 받음 
		scanf("%d", &numofStake);

		// 각 말뚝의 x 위치와 해당 말뚝의 높이를 입력받음
		for (i = 0; i < numofStake; i++) {
			scanf("%f", &xpos[i]);
			scanf("%f", &heights[i]);
		}

		i = 1;
		printf("%d ", i);

		while (i < numofStake) {
			maxRatio = INIT_MAX_RATIO;

			for (j = i + 1; j <= numofStake; j++) {
				// i 번째 말뚝과 j 번째 말뚝을 연결했을 때 비율을 구함
				ratio = (heights[j - 1] - heights[i - 1]) / (xpos[j - 1] - xpos[i - 1]);

				if (ratio > maxRatio) {
					maxRatio = ratio;
					Solutions = j;
					printf("maxRatio : %f, Solutions : %d\n", maxRatio, Solutions);
				}
			}

			i = Solutions;
			printf("%d ", Solutions);

			if (i == numofStake)
				break;
		}

		printf("\n");
	}

	return 0;
}