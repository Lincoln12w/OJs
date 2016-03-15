#include <iostream>
#include <cmath>

int main()
{
	int m, n;
	int big, litle;

	std::cin >> m >> n;
	int a;
	int tmp = m * n;

	while((a = m % n) != 0)
	{
		m = n;
		n = a;
	}

	std::cout << n << " " << tmp / n;

	return 0;
}