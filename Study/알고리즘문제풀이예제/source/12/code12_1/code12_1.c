#include <stdio.h>

int Cnt;

void hanoi(int n, int a, int b)
{
	int temp;

	if (n == 1) {
		printf("원판 %d를 %d에서 %d로 이동한다\n", n, a, b);
	}
	else {
		temp = 6 - a - b;
		hanoi(n - 1, a, temp);
		printf("원판 %d를 %d에서 %d로 이동한다\n", n, a, b);
		hanoi(n - 1, temp, b);
	}

	Cnt++;
}

int main()
{
	int n;
	printf("이동할 원판 수를 입력하세요: ");
	scanf("%d", &n);

	hanoi(n, 1, 2);
	printf("원판의 총 이동 횟수 : %d회\n", Cnt);
	return 0;
}