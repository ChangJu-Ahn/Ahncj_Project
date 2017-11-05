#include <stdio.h>

void main()
{
	int i, num, count = 0;
	long sum = 0;

	printf("1부터 1000 사이에서 선택한 수의 배수가 몇 개고, 배수의 합은 얼마인가?\n");
	printf("1부터 1000 사이의 수 중에서 하나를 입력하세요 ==> ");
	scanf("%d", &num);

	for (i = 1; i <= 1000; i++) {
		if (i % num == 0) {
			sum += i;
			count++;
		}
	}

	printf("1부터 1000 사이 %d의 배수의 개수 : %d, 배수의 합 : %ld\n", num, count, sum);
}