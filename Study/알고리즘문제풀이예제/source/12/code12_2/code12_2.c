#include <stdio.h>

int gcd(int, int);

int gcd(int p, int q)
{
	printf("p : %d, q : %d\n", p, q);

	if (q == 0)
		return p;

	return gcd(q, p % q);
}

int main()
{
	printf("120, 32 : %d\n", gcd(120, 32));

	return 0;
}