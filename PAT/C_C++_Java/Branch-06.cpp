#include <iostream>

int main()
{
	int score;
	char grades[6] = {'E','D','C','B','A','A'};

	std::cin >> score;

	score = score < 50 ? 0 : score / 10 - 5;
	
	std::cout << grades[score];

	return 0;
}