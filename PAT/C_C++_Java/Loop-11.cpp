#include <iostream>
#include <cmath>

int pow(int base, int exp);

int main()
{
	int n;

	std::cin >> n;
	for(int i = pow(10,n-1); i < pow(10, n); i++)
	{
		int number = 0;
		int tmp = i;
		while(tmp)
		{
			number += pow(tmp % 10,n);
			tmp /= 10;
		}
		if(number == i)
			std::cout << i << std::endl;
	}

	return 0;
}

int pow(int base, int exp)
{
	int i = 0, ans = 1;
	while(i++ < exp)
		ans *= base;

	return ans;
}