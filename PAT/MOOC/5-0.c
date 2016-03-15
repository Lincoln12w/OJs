#include <stdio.h>

int main()
{
	int n;
	double up = 2, down = 1;
	int tmp;
	double ans = 0;

	scanf("%d", &n);

	while(n--)
	{
		ans += up /down;
		tmp = up + down;
		down = up;
		up = tmp;
	}

	printf("%.2f",ans);

	return 0;
}