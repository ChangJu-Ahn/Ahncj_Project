#include <stdio.h>
#include <string.h>
#define MAX_CITY 50000

int num_Cities;

int main(void)
{
	int tc, testCases;
	int Solutions;
	int i, j, currentLocation, prevLocation, number;
	int sum;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &testCases);

	for (tc = 0; tc < testCases; tc++) {
		// 도시 위치 정보 초기화
		int locations[MAX_CITY] = { 0 };

		Solutions = 0;
		sum = 0;

		// 전체 도시 수를 입력받음
		scanf("%d", &num_Cities);

		// 도시 위치를 입력받음
		for (i = 0; i < num_Cities; i++) {
			scanf("%d", &currentLocation);
			locations[currentLocation]++;
		}

		number = 0;
		prevLocation = 0;

		for (currentLocation = 0; currentLocation < MAX_CITY; currentLocation++) {
			if (locations[currentLocation]) {
				sum = sum + number * (currentLocation - prevLocation);
				Solutions = Solutions + sum;

				printf("locations[%d:%d] -> sum : %d, Solutions : %d, number : %d\n", currentLocation, prevLocation, sum, Solutions, number);
				prevLocation = currentLocation;
				number++;

				if (number == num_Cities)
					break;
			}
		}

		printf("%d\n", 2 * Solutions);
	}

	return 0;
}