#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	int value;
	int cnt[10] = {0,0,0,0,0,0,0,0,0,0};
	int max = 0, i;

	scanf("%d", &n);

	while(n--)
	{
		scanf("%d", &value);
		while(value)
		{
			if(++cnt[value%10] >max)
				max = cnt[value%10];
			value /= 10;

		}
	}
	printf("%d:", max);
	for(i = 0; i < 10; ++i)
	{
		if(cnt[i] == max)
			printf(" %d",i);
	}

	return 0;
}
