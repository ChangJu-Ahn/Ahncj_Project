#include <stdio.h>

int N;
int cost_Maps[13][13];
int visited[13];
int fare, finalfare, traverseCounter;

void traverse(int);

void traverse(int src)
{
	int i, j;
	visited[src] = 1;
	traverseCounter++;

	if (traverseCounter == N && cost_Maps[src][1] != 0) {
		if (finalfare > fare + cost_Maps[src][1])
			finalfare = fare + cost_Maps[src][1];

		traverseCounter--;
		visited[src] = 0;

		return;
	}

	for (i = 0; i < N; i++) {
		if (cost_Maps[src][i] != 0 && !visited[i]) {
			if (finalfare < fare + cost_Maps[src][i])
				continue;

			fare = fare + cost_Maps[src][i];
			traverse(i);
			fare = fare - cost_Maps[src][i];
		}
	}

	visited[src] = 0;
	traverseCounter--;

	return;
}

int main(void)
{
	int tc, T;
	int i, j;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (tc = 0; tc < T; tc++) {
		scanf("%d", &N);

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				scanf("%d", &cost_Maps[i][j]);
			}
		}

		for (i = 0; i < N; i++) {
			visited[i] = 0;
		}

		fare = 0;
		finalfare = 99999;
		traverseCounter = 0;

		traverse(1);

		printf("%d\n", finalfare);
	}

	return 0;
}