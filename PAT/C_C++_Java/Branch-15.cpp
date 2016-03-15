#include <iostream>

int main()
{
	double Open,High,Low,Close;

	std::cin >> Open >> High >> Low >> Close;

	if(Open > Close)
		std::cout << "BW-Solid";
	else
		std::cout << (Open < Close ? "R-Hollow" : "R-Cross");
	if(Low < Open && Low < Close)
	{
		std::cout << " with Lower Shadow";
		if(High > Open && High > Close)
			std::cout << " and Upper Shadow";
	}
	else
		if(High > Open && High > Close)
			std::cout << " with Upper Shadow";

	return 0;
}