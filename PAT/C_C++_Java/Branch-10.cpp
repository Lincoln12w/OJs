#include <iostream>

int main()
{
	int income;

	std::cin >> income;
	std::cout.precision(2);
	double tax = 0;

	if(income > 1600)
		tax = (income - 1600) * 0.05;
	if(income > 2500)
		tax = (income - 1600) * 0.10;
	if(income > 3500)
		tax = (income - 1600) * 0.15;
	if(income > 4500)
		tax = (income - 1600) * 0.20;

	std::cout << std::fixed <<  tax;

	return 0;
}