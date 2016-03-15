#include<iostream>

int main()
{
	int number;

	std::cin >> number;
	int n1 = 1, n2 = 0, n3 = 0;
	int months = 1;

	while(n1 + n2 + n3 < number)
	{
		int tmp = n3;
		n3 += n2;
		n2 = n1;
		n1 = tmp;
		months ++;
	}

	std::cout << months;
	
	return 0;
}
