#include <iostream>

int main()
{
	double kms;
	int times;
	double money = 10;

	std::cin >> kms >> times;
	if(kms > 3)
		money += 2 * (kms - 3);
	if(kms > 10)
		money += 1 * (kms - 10);

	money +=  2 * (times / 5);

	std::cout.precision(0);
	std::cout << std::fixed << money;

	return 0;
}