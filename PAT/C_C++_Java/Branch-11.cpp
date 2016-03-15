#include <iostream>

int main()
{
	int years, hours;
	int base;

	std::cin >> years >> hours;
	base = years < 5 ? 30 : 50;
	
	std::cout.precision(2);
	std::cout << std::fixed << (hours > 40 ? 40 * base + (hours - 40) * base * 1.5 : hours * base);

	return 0;
}