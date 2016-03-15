#include <stdio.h>

int main()
{
	int num;
	int t;

	scanf("%d",&num);

	if(t = num /100)
	{
		while(t--)
		{
			printf("B");
		}
		num %= 100;
	}
	if(t = num/10)
	{
		while(t--)
		{
			printf("S");
		}
		num %= 10;
	}
	if(num)
	{
		t = 1;
		while(num--)
		{
			printf("%d",t);
			++t;
		}
	}

	return 0;
}