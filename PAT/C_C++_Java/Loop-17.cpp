#include <iostream>
#include <cctype>

int main()
{
	double num = 0;
	char ch, op = '+';
	double ans = 0;

	while(1)
	{
		std::cin >> ch;
		if(isdigit(ch))
		{
			num *= 10;
			num += ch - '0';
		}
		else
		{
			switch(op)
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
				std::cout << "ERROR";
				return 0;
			}
			op = ch;
			if(op == '=')
				break;
			num = 0;
		}
	}

	std::cout << ans;

	return 0;
}