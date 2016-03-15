#include <stdio.h>

int main()
{
	int n;
	int i,j,k;
	int cnt = 0;
	scanf("%d",&n);
	for(i = 0; i < 4; ++i)
	{
		for(j = 0; j < 4; ++j)
		{
			if(i == j)
				continue;
			for(k = 0; k < 4; ++k)
			{
				if(j == k || i == k)
					continue;
				printf("%d%d%d", i+n, j+n, k+n);
				if(cnt % 6 == 5)
					printf("\n");
				else
					printf(" ");
				++cnt;
			}
		} 
	}

	return 0;
}