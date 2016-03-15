#include <iostream>

int main()
{
	int speed, limit;

	std::cin >> speed >> limit;

	double percent = (speed - limit) * 100.0 / limit;
	std::cout.precision(0);
	if(percent < 10)
		std::cout << "OK";
	else
		std::cout << "Exceed " << std::fixed << percent << "%. " << (percent < 50 ? "Ticket 200" : "License Revoked");

	return 0;
}