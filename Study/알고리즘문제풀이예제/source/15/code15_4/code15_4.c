#include<stdio.h>
#include<string.h>

int main()
{
	int num_Scores[30001];
	int i, j, testCases, rank;
	int num_Employee, max;
	int tc;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &testCases);

	for (tc = 0; tc < testCases; tc++) {
		int num_Grades[32001] = { 0 };
		rank = 1;
		max = 0;
		scanf("%d", &num_Employee);

		for (i = 0; i < num_Employee; i++) {
			scanf("%d", &num_Scores[i]);
			num_Grades[num_Scores[i]]++;

			if (max < num_Scores[i])
				max = num_Scores[i];
		}

		printf("max : %d\n", max);

		for (i = max; i >= 0; i--) {
			if (num_Grades[i]) {
				j = num_Grades[i];
				num_Grades[i] = rank;
				printf("j : %d, rank : %d\n", j, rank);
				rank += j;
			}
		}

		for (i = 0; i < num_Employee; i++)
			printf("%d ", num_Grades[num_Scores[i]]);
		
		printf("\n");
	}

	return 0;
}