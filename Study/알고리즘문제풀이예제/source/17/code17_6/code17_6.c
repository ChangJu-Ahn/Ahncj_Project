#include <stdio.h>
#include <memory.h>
#define SIZE 256

typedef struct {
	int num_Researchers;
	int num_Cannibals;
	int boat;
	int counter;
} NODE;

int N, M, Solution;
NODE Queue[SIZE];
int flag[11][11][2];

int front, rear;

void initQueue();
int fullQueue();
int emptyQueue();
void enQueue(NODE node);
NODE deQueue();
int checkStatus(NODE n);

void initQueue()
{
	front = 0;
	rear = 0;
}

int fullQueue()
{
	if (front == (rear + 1) % SIZE)
		return 1;

	else
		return 0;
}

int emptyQueue()
{
	if (front == rear)
		return 1;

	else
		return 0;
}

void enQueue(NODE node)
{
	if (fullQueue())
		return;

	printf("node.counter : %d\n", node.counter);
	Queue[rear] = node;
	rear = (rear + 1) % SIZE;
}

NODE deQueue()
{
	if (!emptyQueue()) {
		NODE n = Queue[front];
		front = (front + 1) % SIZE;
		return n;
	}
}

int checkStatus(NODE node)
{
	int num_Researchers = node.num_Researchers;
	int num_Cannibals = node.num_Cannibals;
	int boat = node.boat;

	if (num_Researchers != 0 && num_Researchers < num_Cannibals)
		return 0;

	if (N - num_Researchers != 0 && N - num_Researchers < N - num_Cannibals)
		return 0;

	if (num_Researchers < 0 || num_Cannibals < 0)
		return 0;

	if (num_Researchers > N || num_Cannibals > N)
		return 0;

	if (num_Researchers == N && num_Cannibals == N && boat == 0)
		return 0;

	if (num_Researchers == 0 && num_Cannibals == 0 && boat == 1)
		return 0;

	return 1;
}

int main(void)
{
	int testCases, tc;

	setbuf(stdout, NULL);
	freopen("input.txt", "r", stdin);
	scanf("%d", &testCases);

	for (tc = 0; tc < testCases; tc++) {
		int finishStatus;
		NODE node;
		scanf("%d %d", &N, &M);

		Solution = -1;
		memset(flag, 0, sizeof(flag));
		initQueue();

		node.num_Researchers = N;
		node.num_Cannibals = N;
		node.boat = 1;
		node.counter = 0;
		enQueue(node);
		finishStatus = 0;
		flag[node.num_Researchers][node.num_Cannibals][node.boat] = 1;

		while (!emptyQueue()) {
			NODE tmp = deQueue();
			NODE currentStatusNode;
			int s = 0, c = 1;

			// printf("%d %d %d\n", tmp.num_Researchers, tmp.num_Cannibals, tmp.boat);

			for (s = 0; s <= M; s++) {
				if (s == 0)
					c = 1;

				else
					c = 0;

				while ((s == 0 && s + c <= M) || (s != 0 && s + c <= M && c <= s)) {
					// printf("연구원 :  %d 식인종 :  %d\n", s, c);

					if (tmp.boat == 1) {
						currentStatusNode.num_Researchers = tmp.num_Researchers - s;
						currentStatusNode.num_Cannibals = tmp.num_Cannibals - c;
						currentStatusNode.boat = 1 - tmp.boat;
						currentStatusNode.counter = tmp.counter + 1;

						// printf("[->]%d명 연구원, %d명 식인종 %d번 이동\n", tmp.num_Researchers,
						// tmp.num_Cannibals, tmp.counter);
					}

					else {
						currentStatusNode.num_Researchers = tmp.num_Researchers + s;
						currentStatusNode.num_Cannibals = tmp.num_Cannibals + c;
						currentStatusNode.boat = 1 - tmp.boat;
						currentStatusNode.counter = tmp.counter + 1;

						// printf("[<-]%d명 연구원, %d명 식인종 %d번 이동\n", tmp.num_Researchers,
						// tmp.num_Cannibals, tmp.counter);
					}

					if (currentStatusNode.num_Researchers == 0 &&
						currentStatusNode.num_Cannibals == 0 &&
						currentStatusNode.boat == 0) {
						// printf("s %d c %d\n", s, c);
						finishStatus = 1;
						Solution = currentStatusNode.counter;

						break;
					}

					if (checkStatus(currentStatusNode)) {
						if (flag[currentStatusNode.num_Researchers][currentStatusNode.num_Cannibals]
							[currentStatusNode.boat] == 1) {
							c++;

							continue;
						}

						else
							flag[currentStatusNode.num_Researchers][currentStatusNode.num_Cannibals]
							[currentStatusNode.boat] = 1;

						printf("연구원 : %d 식인종 : %d 보트 방향 : %d\n",
							currentStatusNode.num_Researchers, currentStatusNode.num_Cannibals,
							currentStatusNode.boat);
						enQueue(currentStatusNode);
					}

					c++;
				}

				if (finishStatus == 1)
					break;
			}

			if (finishStatus == 1)
				break;
		}

		if (Solution == -1)
			printf("impossible\n\n");

		else
			printf("총 %d회 이동\n\n", Solution);
	}

	return 0;
}