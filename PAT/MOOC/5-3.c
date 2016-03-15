#include <stdio.h>

int main()
{
	int m, n;
	int num = 0, sum = 0;

	scanf("%d %d", &m, &n);

	while(n--)
	{
		num *= 10;
		num += m;
		sum += num;
	}

	printf("%d", sum);

	return 0;
}