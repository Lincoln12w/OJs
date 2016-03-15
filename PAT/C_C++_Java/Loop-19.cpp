#include <iostream>

int main()
{
	int number;
	char num[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	char ccc[8] = {'S', 'B', 'Q', 'W', 'S', 'B', 'Q', 'Y'};
	int flag = 100000000;
	int cnt = 9;
	int ok = 0;
	int zero = 0;
	int y = 0;

	std::cin >> number;

	if(number == 0)
	{
		std::cout << 'a';
		return 0;
	}

	while(number)
	{
		int a = number / flag;
		number %= flag;
		flag /= 10;
		if(a)
		{
			std::cout << num[a];
			if(cnt != 1)
				std::cout << ccc[cnt -2];
			ok = 1;
			zero = 0;
		}
		else
		{
			if(cnt == 5 && ok)
				std::cout << 'W';
			else if((cnt == 2 && number) || (ok && (cnt > 5) && (number / 10000) && !zero))
				std::cout << 'a';
			zero = 1;
		}
		cnt--;
	}

	return 0;
}