#include <stdio.h>
#include <malloc.h>

int main()
{
	int m,n;
	int * mat, number;
	int i,j, index, flag = 1;

	scanf("%d %d", &m, &n);
	mat = (int *)malloc(m * n * sizeof(int));

	for(i = 0; i < m; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			scanf("%d", &mat[i*n+j]);
		}
	}
	for(i = 1; i < m - 1; ++i)
	{
		for(j = 1; j < n - 1; ++j)
		{
			index = i * n + j;
			number = mat[index];
			if(number > mat[index + 1] && number > mat[index - 1] && number > mat[index - n] && number > mat[index + n])
			{
				flag = 0;
				printf("%d %d %d\n", number, i+1, j+1);
			}
		}
	}
	if(flag)
		printf("None %d %d", m, n);

	return 0;
}
