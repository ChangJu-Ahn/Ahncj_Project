#include <stdio.h>

void main(void)
{
	int data = 10;    // int 자료형 변수 data의 선언과 초기화
	int *ptr;         // int 자료형 포인터 변수 ptr 선언

	// 변수 data의 메모리 주소 값과 실제 값 출력
	printf("data의 주소 : 0x%p, data의 값 : %d \n", &data, data);
	ptr = &data;

	// 포인터 변수 ptr의 메모리 주소 값과 실제 값 출력
	printf("ptr의 주소 : 0x%p, ptr의 값 : 0x%p \n", &ptr, ptr);
}