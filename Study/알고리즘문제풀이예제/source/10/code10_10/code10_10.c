#include <stdio.h>

int gcd(int, int);

int gcd(int x, int y)
{
	static int ExecNum = 1;
	printf("%d회 실행한다\n", ExecNum++);

	if (y != 0) {
		printf("x : %d, y : %d\n", x, y);
		return gcd(y, x % y);
	}

	else
		return x;
}

void main()
{
	int result;
	int num1, num2;
	printf("최대공약수를 구하는 프로그램\n");
	printf("2개의 수를 입력하세요\n");
	printf("입력 => ");
	scanf("%d %d", &num1, &num2);

	result = gcd(num1, num2);
	printf("%d와 %d의 최대공약수는 : %d\n", num1, num2, result);
}