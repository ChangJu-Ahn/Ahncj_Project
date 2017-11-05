#include <stdio.h>

void main()
{
	int data1, data2;
	int i, num;
	printf("공약수를 구할 두 정숫값을 입력하세요\n");

	printf("입력1 : ");
	scanf("%d", &data1);

	printf("입력2 : ");
	scanf("%d", &data2);

	if (data1 > data2)
		num = data1;

	else
		num = data2;

	for (i = 1; i <= num; i++) {
		if (((data1 % i) == 0) && ((data2 % i) == 0))
			printf("%4d", i);

		if ((i == data1) || (i == data2))
			break;
	}
}