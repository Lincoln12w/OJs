#include <iostream>

int main()
{
	int n, i;

	std::cin >> n;
	int y, f;
	for(i = 1; i < 100; i++)
	{
		if((98 * i - n) % 199 == 0)
			break;
	}
	if(i == 100)
		std::cout << "No Solution";
	else
		std::cout << (n + 98 * i) / 199 << "." << i;

	return 0;
}