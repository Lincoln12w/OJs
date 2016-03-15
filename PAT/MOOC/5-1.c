#include <stdio.h>

int main()
{
	int up, down;
	int a,b,c;

	scanf("%d/%d", &up, &down);
	if(up > down)
	{
		a = up;
		b = down;
	}
	else
	{
		a = down;
		b = up;
	}
	while(c = a % b)
	{
		a = b;
		b = c;
	}


	printf("%d/%d",up/b, down/b);

	return 0;
}