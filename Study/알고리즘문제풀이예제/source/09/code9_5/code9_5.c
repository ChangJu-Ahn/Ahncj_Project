#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define TRUE 1
#define FALSE 0
#define OVERFLOW 3

typedef struct _NODE {
	int Key[3];
	int Counter;
} NODE;

void Initialize(void);
void MakeRandomNumber(void);
void DisplayBuffer(void);
void DisplayHitBuffer(void);
void DisplayHitCounter(void);
int IsNumberExit(int);

int Buf[MAX];
NODE Hit[50];

// 정렬할 데이터 초기화
void Initialize(void)
{
	int i, j;
	for (i = 0; i < MAX; i++) {
		Buf[i] = -1;
	}

	for (i = 0; i < 20; i++) {
		for (j = 0; j < 3; j++)
			Hit[i].Key[j] = -1;

		Hit[i].Counter = 0;
	}
}

void MakeRandomNumber(void)
{
	int i, Num, index;
	i = 0;
	srand((unsigned)time(NULL));

	while (i < 50) {
		Num = rand() % 100;

		if (!IsNumberExit(Num)) {
			Buf[Num] = Num;
			index = Num % 50;

			if (Hit[index].Counter > 2)
				printf("\n OverFlow\n");

			else
				Hit[index].Key[Hit[index].Counter++] = Num;

			i++;
		}
	}
}

void DisplayBuffer(void)
{
	int i;

	for (i = 0; i < MAX; i++) {
		if ((i % 10) == 0)
			printf("\n");

		printf("%4d ", Buf[i]);
	}

	printf("\n");
}

void DisplayHitBuffer(void)
{
	int i;
	printf("====> Hit key Data <===== \n");

	for (i = 0; i < 50; i++) {
		if ((i % 5) == 0)
			printf("\n");

		switch (Hit[i].Counter) {
		case 0:

		case 1:
			printf("%2d", Hit[i].Key[0]);
			break;

		case 2:
			printf("%2d/%2d", Hit[i].Key[0], Hit[i].Key[1]);
			break;

		case 3:
			printf("%2d/%2d/%2d", Hit[i].Key[0], Hit[i].Key[1], Hit[i].Key[2]);
			break;

		default:
			printf("**");
		}

		printf("\t");
	}

	printf("\n\n");
}

void DisplayHitCounter(void)
{
	int i;
	printf("====> Hit Counter Data <===== \n");

	for (i = 0; i < 50; i++) {
		if ((i % 5) == 0)
			printf("\n");

		printf("%4d ", Hit[i].Counter);
	}

	printf("\n");
}

int IsNumberExit(int number)
{
	int i;

	for (i = 0; i < MAX; i++) {
		if (Buf[i] == number)
			return TRUE;
	}

	return FALSE;
}

void main()
{
	Initialize();

	MakeRandomNumber();
	printf("키-매핑으로 생성된 데이터\n");

	DisplayBuffer();
	printf("\n");

	DisplayHitBuffer();
	DisplayHitCounter();
}