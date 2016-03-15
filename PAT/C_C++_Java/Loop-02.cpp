#include<iostream>

int main()
{
	double limit;
	double up = 1, down = 3;
	double pi = 1;
	double i = 1;

	std::cin >> limit;
	
	while(up / down > limit)
	{
		pi += up / down;
		i++;
		up *= i;
		down *= (2 * i + 1);
	}
	pi += up / down;

	std::cout.precision(6);
	std::cout << std::fixed << 2 * pi; 
	
	return 0;
}
