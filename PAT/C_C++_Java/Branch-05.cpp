#include <iostream>

int main()
{
	int a,b,c;

	std::cin >> a >> b >> c;

	if(a == b)
		std::cout << "C";
	else
		std::cout << (b == c ? "A" : "B");

	return 0;
}