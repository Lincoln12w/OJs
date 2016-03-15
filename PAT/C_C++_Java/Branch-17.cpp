#include <iostream>
#include <cmath>

int main()
{
	int n;
	int grade[5] = {0,0,0,0,0};
	int score;

	std::cin >> n;
	while(n--)
	{
		std::cin >> score;
		if(score == 100)
			score =99;
		score = score < 50 ? 0 : score / 10 - 5;
		grade[score]++;
	}
	for(int i = 4; i > 0; --i)
		std::cout << grade[i] << " ";
	std::cout << grade[0];

	return 0;
}
