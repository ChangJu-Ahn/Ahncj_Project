#include <stdio.h>
#define MAX 301

int makeReverseNumber(int, int);

int makeReverseNumber(int num_Origin, int b)
{
	int tmp, num_Reverse;
	tmp = num_Origin;
	num_Reverse = 0;

	while (tmp) {
		num_Reverse = (num_Reverse * b + (tmp % b));
		tmp = tmp / b;
	}

	if (num_Reverse == num_Origin)
		printf("num_Reverse : %d, num_Origin : %d\n", num_Reverse, num_Origin);

	return num_Reverse == num_Origin;
}

int main(void)
{
	int testCases, tc, baseNumber;
	int i;
	int Solution;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &testCases);

	for (tc = 0; tc < testCases; tc++) {
		Solution = 0;
		scanf("%d", &baseNumber);

		for (i = 1; i < MAX; i++) {
			Solution += makeReverseNumber(i * i, baseNumber);
		}

		printf("ÃÑ °³¼ö : %d\n", Solution);
	}

	return 0;
}