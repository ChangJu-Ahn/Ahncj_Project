#include <stdio.h>

int main(int argc, char *argv[])
{
	int i, input;
	int data[1000];
	int min = 0;
	int max = 1000;

	for (i = 0; i < 1000; i++)
		data[i] = i + 1;

	printf("찾을 값을 입력하세요 => ");
	scanf("%d", &input);

	i = (max + min) / 2;
	while (min <= max) {
		if (input == data[i]) {
			printf("찾으려고 하는 값은 배열 data의 %d번째에 있군요.\n", i + 1);
			break;
		}

		else if (input < data[i])
			max = (max + min) / 2 - 1;

		else
			min = (max + min) / 2 + 1;

		i = (max + min) / 2;
	}

	return 0;
}