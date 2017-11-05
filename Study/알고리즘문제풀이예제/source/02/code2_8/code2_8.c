#include <stdio.h>

void main()
{
	int data = 10;
	int *ptr;
	// ptr = &data;
	*ptr = data;

	printf("ptr : 0x%p, *ptr : %d\n", ptr, *ptr);
}