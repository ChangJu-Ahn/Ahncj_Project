#include <stdio.h>
#include <stdlib.h>
#define MAX_DAY 10
#define MAX_PAYDAY 10000

int daypay[MAX_DAY];
int OptimalPay[MAX_PAYDAY];

int main(int argc, char *argv[]) {
	int T, Period;
	int i, j, workingSet;

	freopen("input.txt", "r", stdin);

	// 전체 테스트 케이스 수
	scanf("%d", &T);

	workingSet = 0;

	while (workingSet < T) {

		// 각 기간별 요금을 입력받음(예: 1일권, 2일권, ...... , 10일권)
		for (i = 0; i < MAX_DAY; i++)
			scanf("%d", &daypay[i]);

		// 사용자가 원하는 기간
		scanf("%d", &Period);

		// 사용자가 원하는 기간만큼 1일권을 구매한 것을 최소 비용으로 가정
		for (i = 0; i < Period; i++)
			OptimalPay[i] = (i + 1) * daypay[0];

		// 2일권부터 최대 10일권까지 반복해 사용자가 원하는 기간 동안의
		// 리프트권을 구매했을 때 최소 비용을 구함
		for (i = 1; i < MAX_DAY; i++) {
			int fixedDaypay = daypay[i];
			if (OptimalPay[i] > fixedDaypay)
				OptimalPay[i] = fixedDaypay;

			for (j = i + 1; j < Period; j++) {
				if (OptimalPay[j] >(fixedDaypay + OptimalPay[j - i - 1]))
					OptimalPay[j] = (fixedDaypay + OptimalPay[j - i - 1]);
			}
		}
		printf("%d", ++workingSet);
		printf("번째 최소 비용 : ");
		printf("%d\n", OptimalPay[Period - 1]);
	}
	return 0;
}