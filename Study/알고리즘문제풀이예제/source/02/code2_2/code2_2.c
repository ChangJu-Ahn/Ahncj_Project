#include <stdio.h>
#define MAX 5

void main()
{
	int Scores[MAX];
	double total, aver;
	int i;

	printf("5개의 점수를 입력해주세요.\n");

	for (i = 0; i < MAX; i++) {
		printf("점수 --> ");
		scanf("%d", &Scores[i]);
	}

	total = 0;

	for (i = 0; i < MAX; i++) {
		total += Scores[i];
	}

	aver = total / MAX;
	printf(" 총점 : %f 평균 : %.2f\n", total, aver);
}