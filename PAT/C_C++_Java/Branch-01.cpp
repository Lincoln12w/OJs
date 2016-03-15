#include <iostream>

int main()
{
	int speed;
	
	std::cin >> speed;
	std::cout << "Speed: " << speed << " - " << (speed > 60 ? "Speeding" : "OK");

	return 0;
}