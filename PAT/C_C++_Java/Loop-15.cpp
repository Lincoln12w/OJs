#include <iostream>
#include <cmath>

bool isPrime(int m);

int main()
{
	int m, n;
	int cnt = 0, sum = 0;

	std::cin >> m >> n;

	for(int i = m; i < n + 1; i++)
	{
		if(isPrime(i))
		{
			cnt ++;
			sum += i;
		}
	}
	std::cout << cnt << " " << sum;

	return 0;
}

bool isPrime(int m)
{
	if(m == 1)
		return false;
	if(m == 2)
		return true;
	int k = sqrt(m * 1.0);
	for(int j = 2; j < k + 1; j++)
	{
		if(m % j == 0)
			return false;
	}
	return true;
}