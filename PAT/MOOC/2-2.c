#include <stdio.h>

int main()
{
	int beg, interval;
	int minite;
	scanf("%d %d", &beg, &interval);
	minite = beg/100 * 60 + beg%100 + interval;
	printf("%d%02d", minite/60,minite%60);

	return 0;
}