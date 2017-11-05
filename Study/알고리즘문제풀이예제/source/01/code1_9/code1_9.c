#include <stdio.h>

int main(int argc, char *argv[])
{
	int Sum = 0;
	int i;

	for (i = 1; i <= 100; i++) {
		Sum = Sum + i;
	}

	printf("1부터 100까지의 합 : %d\n", Sum);

	return 0;
}