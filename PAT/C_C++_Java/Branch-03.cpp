#include <iostream>

int main()
{
	int days;

	std::cin >> days;
	std::cout << ((days - 1) % 5 > 2 ? "Drying" : "Fishing") << " in day " << days;

	return 0;
}