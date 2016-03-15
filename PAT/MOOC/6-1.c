#include <stdio.h>

int main()
{
	char op = '+',ch;
	int ans = 0, num = 0;

	scanf("%c", &ch);
	while(1)
	{
		if(ch > '0' - 1 && ch < '9' + 1)
		{
			num *= 10;
			num += ch - '0';
		}
		else
		{
			switch (op)
			{
			case '+':
				ans += num;
				break;
			case '-':
				ans -= num;
				break;
			case '*':
				ans *= num;
				break;
			case '/':
				if(num)
				{
					ans /= num;
					break;
				}
			default:
				printf("ERROR");
				return 0;
			}
			num = 0;
			op = ch;
			if(op == '=')
			{
				printf("%d",ans);
				return 0;
			}
		}
		scanf("%c", &ch);
	}
}