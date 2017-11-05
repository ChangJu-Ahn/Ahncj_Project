#include<stdio.h>

#define MAX_POCKETS 32000

int eachPocket[MAX_POCKETS];
int num_Moves, num_Pockets;

int main()
{
	int testCases, p, totalBeans, averBeans;
	int i, j;

	freopen("input.txt", "r", stdin);
	scanf("%d", &testCases);

	for (i = 0; i < testCases; i++) {
		num_Moves = 0;
		totalBeans = 0;

		// 주머니 개수를 입력받는다 
		scanf("%d", &num_Pockets);

		// 각 주머니에 들어 있는 동전 개수를 입력받고 전체 동전 개수를 구한다
		for (j = 0; j < num_Pockets; j++) {
			scanf("%d", &eachPocket[j]);
			totalBeans = totalBeans + eachPocket[j];
		}

		// 주머니 개수와 전체 동전 개수가 1개만 차이나는 경우
		if ((totalBeans % num_Pockets) > num_Pockets) {
			num_Moves = -1;
		}

		else {
			// 각 주머니의 평균 동전 개수를 구한다 
			averBeans = totalBeans / num_Pockets;

			// 각 주머니와 평균 동전 개수의 차이를 구한다
			for (j = 0; j < num_Pockets; j++) {
				if (eachPocket[j] < averBeans) {
					num_Moves = num_Moves + (averBeans - eachPocket[j]);
					printf("eachPocket[%d]의 이동 횟수 : %d\n", j, (averBeans - eachPocket[j]));
				}
			}
		}

		printf("누적 이동 횟수 : %d\n", num_Moves);
	}

	return 0;
}