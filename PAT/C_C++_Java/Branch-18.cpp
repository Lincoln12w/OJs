#include <iostream>
#include <cmath>


int main()
{
	double a, b, c;

	std::cin >> a >> b >> c;

	if(a == 0 && b == 0)
	{
		std::cout << (c ? "Not An Equation" : "Zero Equation");
		return 0;
	}
	std::cout.precision(2);
	double ans = -(b / (2 * a));
	double delta = b * b - 4 * a * c;

	if(a == 0)
	{
		std::cout << std::fixed << ((c / b) ? -(c / b) : 0);
		return 0;
	}

	if(delta > 0)
	{
		double temp = sqrt(delta) / (2 * a);
		std::cout << std::fixed << ans + temp << '\n' << ans - temp;
	}
	else if(delta < 0)
	{
		double temp = sqrt(-delta) / (2 * a);
		if(ans)
			std::cout << std::fixed << ans << '+' << temp << "i\n" << ans << '-' << temp << 'i';
		else
			std::cout << std::fixed << '+' << temp << "i\n" << '-' << temp << "i";
	}
	else
		std::cout << std::fixed << (ans ? ans : 0);

	return 0;
}

/*
test case 0: a + b / a - b		delta > 0	include c = 0
test case 1: a + bi / a - bi	delta < 0	include b = 0
test case 2: bx + c = 0			a = 0		include a = c = 0
test case 3: "Zero Equation"	a = b = c = 0
test case 4: "Not An Equation"	a = b = 0
test case 5: a					delta = 0	include b = c = 0
test case 6: 
*/