#include <stdio.h>
#define max(a, b) ((a > b) ? a : b)
#define MAX_VALUE 1000

int Solutions[MAX_VALUE][MAX_VALUE];

int main(void) {
	int tc, testCases, i, j;
	int sizeofTriangle;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	// 테스트 케이스를 입력받는다
	scanf("%d", &testCases);

	for (tc = 0; tc < testCases; tc++) {

		// 전체 크기(슬로프 길이)를 구한다
		scanf("%d", &sizeofTriangle);

		// 슬로프에 있는 깃발 정보를 입력받는다 
		for (i = 0; i < sizeofTriangle; i++) {
			for (j = 0; j <= i; j++) {
				scanf("%d", &Solutions[i][j]);
				printf("%3d", Solutions[i][j]);
			}

			printf("\n");
		}

		// 슬로프의 아래 부분부터 최댓값을 선택해 더한다
		// 이 과정을 슬로프 맨 위 꼭지점까지 반복한다
		for (i = sizeofTriangle - 1; i >= 0; i--) {
			for (j = 0; j <= i; j++) {
				Solutions[i][j] += max(Solutions[i + 1][j], Solutions[i + 1][j + 1]);
				printf("Solutions[%d][%d] : %d\n", i, j, Solutions[i][j]);
			}
		}

		printf("%d\n", Solutions[0][0]);
	}
	return 0;
}