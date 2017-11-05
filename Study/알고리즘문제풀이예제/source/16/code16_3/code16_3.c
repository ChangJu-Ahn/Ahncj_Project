#include <stdio.h>
#define UNCONNECTED 99999

int map[1001][1001];
int min_dist[1001];

int calculateMinCosts(int);

int calculateMinCosts(int num_Targets)
{
	int i, j, k;
	int min;
	int u;
	int visited[1001] = { 0 };

	for (i = 0; i < num_Targets; i++) {
		if (map[0][i] != UNCONNECTED && i != 0) {
			min_dist[i] = map[0][i];
		}

		else
			min_dist[i] = UNCONNECTED;
	}

	visited[0] = 1;

	for (i = 0; i < num_Targets; i++) {
		min = UNCONNECTED;

		for (j = 0; j < num_Targets; j++) {
			if (visited[j] == 0 && min_dist[j] < min) {
				min = min_dist[j];
				u = j;
			}
		}

		visited[u] = 1;

		for (k = 0; k < num_Targets; k++) {
			if (min_dist[k] == UNCONNECTED) {
				if (map[u][k] != UNCONNECTED && !visited[k]) {
					min_dist[k] = min_dist[u] + map[u][k];
					printf("%d를 거쳐 %d를 방문한다. 최소 비용 : %d\n", u, k, min_dist[k]);
				}
			}

			else {
				if (map[u][k] != UNCONNECTED && !visited[k] &&
					(map[u][k] + min_dist[u] < min_dist[k])) {
					min_dist[k] = min_dist[u] + map[u][k];
					printf("%d를 거쳐 %d를 방문하는 것이 더 효율적이다. 최소 비용 : %d\n", u, k, min_dist[k]);
				}
			}
		}
	}
}

int main(void)
{
	int tc, T;
	int num_Roads, num_Targets;
	int start, end, dist;
	int i, j;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (tc = 0; tc < T; tc++) {
		scanf("%d %d", &num_Roads, &num_Targets);

		for (i = 0; i < num_Targets; i++)
			for (j = 0; j < num_Targets; j++)
				map[i][j] = UNCONNECTED;

		for (i = 0; i < num_Roads; i++) {
			scanf("%d %d %d", &start, &end, &dist);
			if (dist < map[start - 1][end - 1]) {
				map[start - 1][end - 1] = dist;
				map[end - 1][start - 1] = dist;
			}
		}

		calculateMinCosts(num_Targets);
		printf("%d\n", min_dist[num_Targets - 1]);
	}

	return 0;
}