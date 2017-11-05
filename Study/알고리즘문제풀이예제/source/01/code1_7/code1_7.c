#include <stdio.h>

int Add(void);
int Subtract(void);

// 지역 변수로 사용할 변수를 전역 변수로 선언했다
int Num_A, Num_B;

int ret;

int Add()
{
	// 전역 변수를 사용하여 메모리가 낭비된다
	return Num_A + Num_B;
}

int Subtract()
{
	// 전역 변수를 사용하여 메모리가 낭비된다
	return Num_A - Num_B;
}

int main(int argc, char *argv[])
{
	Num_A = 100;
	Num_B = 90;

	ret = Add();

	// ... 중간 생략 ...
	ret = Subtract();
	// ... 중간 생략 ...
}