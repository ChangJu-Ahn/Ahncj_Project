#include <stdio.h>

typedef struct _NODE {
	int Number;
	char Name;
} NODE;

NODE Students[100];

void main()
{
	int i;

	for (i = 0; i < 100; i++) {
		if (i % 2 == 0) {
			Students[i].Number = 1000 + i;
			Students[i].Name = 'A' + i;
		}

		else
			continue;
	}

	printf("전체 데이터 크기와 저장된 데이터 크기 비교\n");
	printf("전체 데이터 크기 : %d bytes\n", sizeof(NODE) * 100);
	printf("저장된 데이터 크기 : %d bytes\n", sizeof(NODE) * 100 / 2);
}