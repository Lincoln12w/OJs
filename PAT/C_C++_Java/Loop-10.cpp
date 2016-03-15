#include <iostream>

int main()
{
	int n, i = 0;
	double up = 2, down = 1, ans = 0;

	std::cin >> n;
	while(i < n)
	{
		ans += up / down;
		double tmp = up;
		up += down;
		down = tmp;
		i++;
	}
	std::cout.precision(2);
	std::cout << std::fixed << ans;

	return 0;
}