#include <iostream>

#define F(a3, a2, a1, a0, x) (a3 * x * x * x + a2 * x * x + a1 * x + a0)
int main()
{
	double a3, a2, a1, a0;
	double a, b;
	double mid = 0;
	
	std::cin >> a3 >> a2 >> a1 >> a0 >> a >> b;
	if(F(a3,a2,a1,a0, a) == 0)
		mid = a;
	else if(F(a3,a2,a1,a0, b) == 0)
		mid = b;
	else
		while(b - a > 0.02)
		{
			mid = (b + a) / 2;
			double fmid = F(a3,a2,a1,a0,mid);
			if(fmid == 0)
				break;
			if(F(a3,a2,a1,a0, a) * fmid > 0)
				a = mid;
			else
				b = mid;
		}
	std::cout.precision(2);
	std::cout << std::fixed << mid;

	return 0;
}

