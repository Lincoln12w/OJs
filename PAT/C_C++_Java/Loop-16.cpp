#include <iostream>

int main()
{
	int m;
	int total = 1;

	std::cin >> m;
	while(--m)
	{
		total ++;
		total *= 2;
	}

	std::cout << total;

	return 0;
}