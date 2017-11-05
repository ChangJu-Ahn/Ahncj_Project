#include <stdio.h>
#include <string.h>

#define MAX 5

int main(int argc, char *argv[]) {
	int i;
	int testArray_1[MAX] = { -1 };

	for (i = 0; i < MAX; i++)
		printf("testArray_1[%d] : %d\n", i, testArray_1[i]);

	printf("\n");
	int testArray_2[MAX] = { -1, };

	for (i = 0; i < MAX; i++)
		printf("testArray_2[%d] : %d\n", i, testArray_2[i]);

	printf("\n");
	int testArray_3[MAX];
	memset(testArray_3, (int)-1, sizeof(testArray_3));

	for (i = 0; i < MAX; i++)
		printf("testArray_3[%d] : %d\n", i, testArray_3[i]);

	printf("\n");

	return 0;
}