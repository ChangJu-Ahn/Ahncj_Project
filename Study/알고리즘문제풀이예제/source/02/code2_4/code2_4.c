#include <stdio.h>

void DisplayTable(void);

int Grade[5][2];

void main(void)
{
	int i;

	printf("각 학생의 영어 점수와 수학 점수를 입력하세요.\n");

	for (i = 0; i < 5; i++) {
		printf("%d번 학생의 영어 점수 : ", i + 1);
		scanf("%d", &Grade[i][0]);

		printf("%d번 학생의 수학 점수 : ", i + 1);
		scanf("%d", &Grade[i][1]);
	}

	printf("입력을 종료합니다.\n\n");
	DisplayTable();
}

void DisplayTable(void)
{
	int i;
	int Total[2] = { 0, 0 };

	printf("학생 번호\t영어 점수\t수학 점수\n");

	// 각 학생별로 영어 점수와 수학 점수를 출력한다
	for (i = 0; i < 5; i++) {
		printf("\t%d\t\t%d\t\t%d\n", i + 1, Grade[i][0], Grade[i][1]);
		Total[0] += Grade[i][0];  // 영어 총점을 계산한다
		Total[1] += Grade[i][1];  // 수학 총점을 계산한다
	}

	printf("===================================================\n");
	printf("총 점\t\t\t%d\t\t%d\n", Total[0], Total[1]);  // 총점 출력
	printf("평 균\t\t\t%d\t\t%d\n", Total[0] / 5, Total[1] / 5);  // 평균 출력
}