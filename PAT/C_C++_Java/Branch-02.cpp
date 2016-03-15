#include <iostream>
#include <cmath>

int main()
{
	double x1,y1,x2,y2,x3,y3;

	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	double s = ((x3 - x2) * y1 + (x1 - x3) * y2 + (x2 - x1) * y3)/2;
	double l = sqrt((x1 - x2)*(x1- x2) + (y1 - y2) * (y1 - y2)) + sqrt((x2 - x3)*(x2- x3) + (y2 - y3) * (y2 - y3)) + sqrt((x3 - x1)*(x3- x1) + (y3 - y1) * (y3 - y1));

	if(s == 0)
	{
		std::cout << "Impossible";
	}
	else
	{
		std::cout.precision(2);
		std::cout << std::fixed << "L = " << l << ", A = " << (s > 0 ? s : -s);
	}

	return 0;
}

/*
test case 2: Impossible
*/