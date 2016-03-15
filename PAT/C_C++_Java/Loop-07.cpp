#include <iostream>

int main()
{
	int n, u, d;
	int minutes = 1;
	
	std::cin >> n >> u >> d;
	int cur = u;

	if(n < u)
	{
		std::cout << 1;
		return 0;
	}
	
	while(cur < n)
	{
		minutes += 2;
		cur += u - d;
	}
	
	std::cout << minutes;

	return 0;
}

