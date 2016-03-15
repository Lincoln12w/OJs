#include <iostream>

int main()
{
	int a,b,c;

	std::cin >> a >> b >> c;

	if(a > b && a > c)
	{
		if(b > c)
			std::cout << c << "->" << b << "->" << a;
		else
			std::cout << b << "->" << c << "->" << a;
	}
	if(b > a && b > c)
	{
		if(a > c)
			std::cout << c << "->" << a << "->" << b;
		else
			std::cout << a << "->" << c << "->" << b;
	}
	if(c > b && c > a)
	{
		if(b > a)
			std::cout << a << "->" << b << "->" << c;
		else
			std::cout << b << "->" << a << "->" << c;
	}
	if(a == b && a == c)
		std::cout << a << "->" << b << "->" << c;

	return 0;
}