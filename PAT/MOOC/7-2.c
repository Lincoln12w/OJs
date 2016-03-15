#include <stdio.h>

int main()
{
	int n;
	int a,b,c;
	int i = 0;

	scanf("%d", &n);
	while(i < n)
	{
		++i;
		scanf("%d %d %d", &a, &b, &c);
		printf("Case #%d: ", i);
		if(a == b)
		{
			if( a > 1073741823)
			{
				printf("true\n");
				continue;
			}
			else if( a < -1073741824)
			{
				printf("false\n");
				continue;
			}
		}
		if(a < b)
		{
			a ^= b; b ^= a; a ^= b;
		}
		if((a == 2147483647 && b > 0) || (a > 0 && b > 2147483647 - a))
		{
			printf("true\n");
			continue;
		}
		if((a == -2147483648 && b < 0) ||(a < 0 && b < -2147483648 - a))
		{
			printf("false\n");
			continue;
		}
		if(a + b > c)
			printf("true\n");
		else
			printf("false\n");
	}

	return 0;
}