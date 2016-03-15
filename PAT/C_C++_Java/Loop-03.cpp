#include<iostream>

int main()
{
	int a;

	std::cin >> a;

	int cnt = 0;
	int i,j,k;

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++)
		{
			if(i == j)
				continue;
			for(k = 0; k < 4; k++)
			{
				if(k == i || k == j)
					continue;
				std::cout << a+i << a+j << a+k;
				cnt++;
				if(cnt % 6 == 0)
					std::cout << '\n';
				else
					std::cout << ' ';
			}
		}
	}
	
	return 0;
}
