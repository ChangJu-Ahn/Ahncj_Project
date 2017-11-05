#include <stdio.h>

void Square(int, int *); // 제곱근과 세제곱근을 구하는 함수

void Square(int lv, int *ret)
{
	if (lv == 2)
		*ret = *ret * *ret;

	else if (lv == 3)
		*ret = *ret * *ret * *ret;
}

void main()
{
	int number, level;
	printf("C 프로그래밍에서의 포인터 사용 예 - 두 번째 \n");

	level = 2;
	number = 3;
	Square(level, &number); // 3의 2승
	printf("Level : %d Return Value : %d\n", level, number);

	printf("\n");

	level = 3;
	number = 4;
	Square(level, &number); // 4의 3승

	printf("Level : %d Return Value : %d\n", level, number);
}