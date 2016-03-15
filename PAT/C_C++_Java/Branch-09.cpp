#include <iostream>

int main()
{
	double cost;

	std::cin >> cost;
	std::cout.precision(2);
	std::cout << std::fixed << (cost > 15 ? cost * 2.5 - 17.5 : 4 * cost / 3);

	return 0;
}