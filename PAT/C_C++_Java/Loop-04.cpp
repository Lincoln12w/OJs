#include<iostream>
#include<cmath>

bool ifPrime(int n);

int main()
{
	int number;

	std::cin >> number;

	for(int i = 2; i < (number / 2) + 1; i++)
	{
		if(ifPrime(i) && ifPrime(number - i))
		{
			std::cout << number << " = " << i << " + " << number - i;
			return 0;
		}
	}
	
	return 0;
}

bool ifPrime(int n)
{
	if(n == 2)
		return true;
	if(n == 1)
		return false;
	for(int i = 2; i < sqrt(n*1.0) + 1; ++i)
	{
		if(n % i == 0)
			return false;
	}

	return true;
}