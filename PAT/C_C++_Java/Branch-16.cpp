#include <iostream>
#include <cmath>

int main()
{
	double x;

	std::cin >> x;

	std::cout.precision(2);
	std::cout << std::fixed << "f(" << x << ") = " << ((x < 0) ? (x + 1) * (x + 1) + 2 * x + 1 / x : sqrt(x));

	return 0;
}
