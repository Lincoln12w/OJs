#include <stdio.h>

int main()
{
	char ch;
	int cnt = 0, flag;

	scanf("%c", &ch);
	if(ch == '.')
		return 0;
	while(ch != '.')
	{
		if(ch == ' ')
		{
			flag = 0;
			if(cnt)
			{
				printf("%d", cnt);
				flag = 1;
			}
			cnt = 0;
			while(ch == ' ')
				scanf("%c", &ch);
			if(ch == '.')
			{
				return 0;
			}
			if(flag)
				printf(" ");
		}
		++cnt;
		scanf("%c", &ch);
	}
	printf("%d",cnt);					/* Input case:   "   my name is      lincoln   ." */

	return 0;
}