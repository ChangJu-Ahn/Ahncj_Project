#include <stdio.h>
#define NUM_MOVES 8

int move_X[NUM_MOVES] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int move_Y[NUM_MOVES] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int map[101][101];

typedef struct {
	int x, y;
	int counter;
} POINT;

POINT position_Queue[10005];

int main(void)
{
	int tc, T;
	int i, j;
	int N, M, x_Attacker, y_Attacker, x_Victim, y_Victim, x, y;
	POINT start;
	POINT out, in;
	int top, bottom;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (tc = 0; tc < T; tc++) {
		for (i = 0; i < 101; i++)
			for (j = 0; j < 101; j++)
				map[i][j] = 0;

			scanf("%d", &N);
			scanf("%d", &M);

			scanf("%d", &x_Attacker);
			scanf("%d", &y_Attacker);
			scanf("%d", &x_Victim);
			scanf("%d", &y_Victim);

			start.x = x_Attacker;
			start.y = y_Attacker;
			start.counter = 0;
			top = bottom = 0;

			position_Queue[top++] = start;

			while (top != bottom) {
				out = position_Queue[bottom++];
				for (i = 0; i < NUM_MOVES; i++) {
					x = out.x + move_X[i];
					y = out.y + move_Y[i];

					if ((x >= 1 && x <= N) && (y >= 1 && y <= M) && map[x][y] == 0) {
						in.x = x;
						in.y = y;
						in.counter = out.counter + 1;
						position_Queue[top++] = in;
						map[x][y] = 1;
						printf("Queue에 새로운 위치 (%d, %d)를 저장한다\n", x, y);
					}
				}

				if (map[x_Victim][y_Victim] == 1) {
					printf("KILLED VICTIM!!!\n");
					break;
				}
			}

			if (map[x_Victim][y_Victim] == 1)
				printf("총 %d회 이동으로 victim을 잡았다\n\n", in.counter);

			else
				printf("-1\n");

	}

	return 0;
}