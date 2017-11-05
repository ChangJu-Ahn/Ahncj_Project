#include <stdio.h>
#define MAX (99999)

void getHeight(int, int);
int data[25000];

void getHeight(int n, int m)
{
	int min, j;
	min = MAX;

	for (j = n - 1; j < m; j++){
		if (min > data[j])
			min = data[j];
	}

	printf("%d\n", min);
}

int main()
{
	int T, num_Gates, num_Questions;
	int n, m, i, j, k;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%d %d", &num_Gates, &num_Questions);

		for (j = 0; j < num_Gates; j++) {
			scanf("%d", &data[j]);
			printf("data[%d] : %d\n", j, data[j]);
		}

		for (k = 0; k < num_Questions; k++) {
			scanf("%d %d", &n, &m);
			printf("num_Questions : %d, n : %d, m : %d\n", num_Questions, n, m);
			getHeight(n, m);
		}

		printf("\n");
	}

	return 0;
}