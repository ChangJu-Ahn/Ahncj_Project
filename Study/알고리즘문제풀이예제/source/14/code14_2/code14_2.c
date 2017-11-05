#include <stdio.h>

int widthFrame, maxNumber;
int Solutions;

int main(void) {
	int tc;
	int tesetCases;
	int i;
	int localSum_1, localSum_2, localSum_3;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	// 테스트 케이스를 입력받는다
	scanf("%d", &tesetCases);

	for (tc = 0; tc < tesetCases; tc++) {
		// 타일링할 총 가로 길이를 입력받는다
		scanf("%d", &widthFrame);

		// 나눌 숫자를 입력받는다
		scanf("%d", &maxNumber);

		// 총 가로 길이가 1인 경우
		if (widthFrame == 1)
			Solutions = 2 % maxNumber;

		// 총 가로 길이가 2인 경우
		else if (widthFrame == 2)
			Solutions = 3 % maxNumber;

		// 총 가로 길이가 3 이상인 경우
		else {
			localSum_1 = 1;
			localSum_2 = 3;

			for (i = 2; i < widthFrame; i++) {
				localSum_3 = (localSum_2 + 2 * localSum_1) % maxNumber;
				localSum_1 = localSum_2;
				localSum_2 = localSum_3;
				printf("localSum_1 : %d, localSum_2 : %d, localSum_3 : %d\n",
					localSum_1, localSum_2, localSum_3);
			}

			Solutions = localSum_3;
		}

		printf("%d\n", Solutions);
	}

	return 0;
}