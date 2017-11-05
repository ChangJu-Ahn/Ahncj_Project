#include <stdio.h>
#define MAX 1000

typedef struct __POINT {
	int x;
	int y;
} POINT;

int N;
POINT data[MAX];
double Solution;
POINT data_Vertex[MAX];
int num_realData;

int areaTriangle(const POINT A, const POINT B, const POINT C)
{
	return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

double distance(const POINT A, const POINT B)
{
	return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

double polygon_area(const int n, POINT p[])
{
	double area = 0.0;
	int i;
	POINT temp = p[1];

	for (i = 2; i < n; ++i) {
		area += areaTriangle(temp, p[i], p[i + 1]);
	}

	area = area / 2.0;
	return area > 0 ? area : -area;
}

int main(void)
{
	int tc, testCases, i, j;
	int num_Points;

	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	scanf("%d", &testCases);

	for (tc = 0; tc < testCases; tc++) {
		scanf("%d", &num_Points);

		for (i = 1; i <= num_Points; i++)
			scanf("%d%d", &data[i].x, &data[i].y);

		Solution = 0.0;

		int temp = 1;

		for (i = 2; i <= num_Points; i++)
			if (data[temp].y - data[i].y > 0 || (data[temp].y - data[i].y == 0 &&
				data[temp].x > data[i].x))
				temp = i;

		POINT tempPOINT = data[temp];
		data[temp] = data[1];
		data[1] = tempPOINT;
		printf("tempPoint.x : %d, tempPoint.y : %d\n", tempPOINT.x, tempPOINT.y);

		for (i = 2; i < num_Points; i++) {
			temp = i;

			for (j = temp + 1; j <= N; j++) {
				if ((areaTriangle(data[1], data[j], data[temp]) > 0) || (areaTriangle(data[1],
					data[j], data[temp]) == 0 && distance(data[1], data[j]) >
					distance(data[1], data[temp]))) {
					temp = j;
				}
			}

			tempPOINT = data[temp];
			data[temp] = data[i];
			data[i] = tempPOINT;
		}

		printf("tempPoint.x : %d, tempPoint.y : %d\n", tempPOINT.x, tempPOINT.y);

		data_Vertex[1] = data[1];
		data_Vertex[2] = data[2];
		data_Vertex[3] = data[3];
		num_realData = 3;

		for (i = 4; i < num_Points + 1; i++) {
			while (areaTriangle(data_Vertex[num_realData - 1],
				data_Vertex[num_realData], data[i]) <= 0) {
				num_realData--;
			}

			data_Vertex[++num_realData] = data[i];
		}

		Solution = polygon_area(num_realData, data_Vertex);
		printf("num_realData: %d\n", num_realData);

		for (i = 0; i < num_realData; i++)
			printf("data_Vertex[%d].x : %d, data_Vertex[%d].y: %d \n", i,
			data_Vertex[i].x, i, data_Vertex[i].y);

		printf("다각형의 면적은 %f\n\n", Solution);
	}

	return 0;
}