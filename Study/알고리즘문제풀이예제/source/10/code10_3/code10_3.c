#include <stdio.h>

void main()
{
	int data;
	int i;
	printf("약수를 구할 정숫값을 입력하세요\n");
	printf("입력 : ");
	scanf("%d", &data);

	for (i = 1; i <= data; i++) {
		if ((data % i) == 0)
			printf("%4d", i);
	}
}