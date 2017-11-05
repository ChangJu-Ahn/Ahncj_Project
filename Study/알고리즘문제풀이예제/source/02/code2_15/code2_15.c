#include <stdio.h>

void main()
{
	char buf[6] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	char *ptr = buf;
	int i = 0;
	printf("ptr을 1씩 증가시켜보자.\n");

	for (i = 0; i < 6; i++) {
		printf("ptr : 0x%p, *ptr : %c\n", ptr, *ptr);
		ptr++;
	}

	printf("\n다시 ptr이 buf를 가리키게 하자.\n");
	ptr = buf;

	printf("*ptr++의 결과\n");
	printf("ptr : 0x%p, *ptr : %c\n", ptr, *ptr++);

	printf("*(ptr++)의 결과\n");
	printf("ptr : 0x%p, *ptr : %c\n", ptr, *(ptr++));

	printf("--ptr을 한 후 *(ptr++)의 결과\n");
	--ptr;
	printf("ptr : 0x%p, *ptr : %c\n", ptr, *(ptr++));

	printf("(*ptr)++의 결과\n");
	(*ptr)++;
	printf("ptr : 0x%p, *ptr : %c\n", ptr, *ptr);

	printf("ptr += 1을 한 후 *ptr의 결과\n");
	ptr += 1;
	printf("ptr : 0x%p, *ptr : %c\n", ptr, *ptr);

	printf("ptr -= 2를 한 후 *ptr의 결과\n");
	ptr -= 2;
	printf("ptr : 0x%p, *ptr : %c\n", ptr, *ptr);
}