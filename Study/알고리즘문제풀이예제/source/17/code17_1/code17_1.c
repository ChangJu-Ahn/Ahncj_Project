#include <stdio.h>
#define MAXIMUM 100000000
#define MAX_ELEMENTS 10000

int solutions[MAX_ELEMENTS + 1];
void initSolutions(void);

void initSolutions(void)
{
	int i;

	for (i = 0; i <= MAX_ELEMENTS; i++)
		solutions[i] = 0;
}

int main(int argc, char *argv[])
{
	int workingSet, T;
	int targetMoney, availableMoney;
	int i, j;

	freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	workingSet = 0;

	while (workingSet < T) {
		scanf("%d %d", &targetMoney, &availableMoney);

		initSolutions();
		solutions[0] = 1;

		for (i = 1; i <= availableMoney; i++)
			for (j = i; j <= targetMoney; j++) {
				solutions[j] = (solutions[j] + solutions[j - i]) % MAXIMUM;
				printf("solutions[%d]: %d\n", j, solutions[j]);
			}

		printf("%d\n", solutions[targetMoney]);
		workingSet++;
	}

	return 0;
}