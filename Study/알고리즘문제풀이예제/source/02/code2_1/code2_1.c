#include <stdio.h>

void main()
{
	int i = 0;
	char buf[11];

	printf("소문자 11개를 입력해봅시다.\n");
	printf("입력 : ");

	while (i < 11) {
		scanf("%c", &buf[i]); // Visual C++ 컴파일러에서는 scanf_s() 함수를 사용하면 좋다
		i++;
	}

	printf("문자를 입력하셨군요. 대문자로 변환합니다.\n");

	for (i = 0; i < 11; i++)
		printf("%c", buf[i] - ('a' - 'A'));
}