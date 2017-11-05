#include <stdio.h>

void main()
{
	char key;
	int data;

	printf("10진수->16진수 변환 프로그램이다\n");
	printf("10진수를 16진수로 바꾸려면 [A] 키를 누르고,\n");
	printf("16진수를 10진수로 바꾸려면 [B] 키를 누르세요.\n");
	printf("a나 b를 누르세요 : ");

	scanf("%c", &key);
	printf("변환할 숫자를 입력하세요 : ");

	if (key == 'a') {
		scanf("%d", &data);
		printf("10진수 값 : %d --> 16진수 값 : %x\n", data, data);
	}

	else if (key == 'b') {
		scanf("%x", &data);
		printf("16진수 값 : %x --> 10진수 값 : %d\n", data, data);
	}

	else
		printf("[A]와 [B] 키만을 사용해야 한다");
}