#include <iostream>

int main()
{
	int a;
	char c;
	double b, d;

	std::cin >> b >> a >> c >> d;

	std::cout << c << " " << a << " ";
	std::cout.precision(2);
	std::cout << std::fixed << b << " " << d;

	return 0;
}