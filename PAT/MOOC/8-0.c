#include <stdio.h>
#include <math.h>

int main()
{
	int n, num;
	int value, i = 0;

	scanf("%d %d", &n, &num);

	while(n--)
	{
		scanf("%d", &value);
		if(value == num)
		{
			printf("%d", i);
			return 0;
		}
		++i;
	}
	printf("Not Found");

	return 0;
}
