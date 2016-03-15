#include <stdio.h>

int main()
{
	int n;
	int i, j;

	scanf("%d",&n);

	for(i = 1;i < n + 1; ++i)
	{
		for(j = 1; j < i + 1; ++j)
		{
			printf("%d*%d=%-4d",j,i,i*j);
		}
		printf("\n");
	}

	return 0;
}