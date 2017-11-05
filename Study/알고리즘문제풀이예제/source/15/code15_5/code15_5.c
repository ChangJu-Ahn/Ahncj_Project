#include<stdio.h>
#define MAX 10001

int countString(char[]);

int countString(char str[])
{
	int i;
	int counter = 0;

	printf("origin str : %s\n", str);
	for (i = 0; i < MAX; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			counter++;

		else
			break;
	}

	return counter;
}

int main()
{
	int i, j, k, length;
	int tc, flag;
	char passwd_str[MAX];

	freopen("input.txt", "r", stdin);
	scanf("%d", &tc);

	while (tc--) {
		length = 0;
		scanf("%s", &passwd_str);
		length = countString(passwd_str);
		printf("str length : %d\n", length);

		for (i = 1; i < length; i++) {
			for (j = 0; i + j < length; j++) {
				k = i;
				while (k--) {
					if (passwd_str[j] == passwd_str[i + j])
						flag = 1;

					else {
						flag = 0;
						break;
					}

					j++;
				}

				if (flag == 1)
					break;
			}

			if (flag == 1)
				break;
		}

		if (flag == 1)
			printf("Rejected\n");

		else
			printf("Accepted\n");

		printf("\n");
	}

	return 0;
}