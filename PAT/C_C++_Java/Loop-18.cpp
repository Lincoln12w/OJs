#include <iostream>

int main()
{
	int minutes;
	int turtles = 0, rabbit = 0;

	std::cin >> minutes;
	if(minutes < 10)
	{
		std::cout << "^_^ " << minutes * 9;
		return 0;
	}
	while(minutes)
	{
		if(turtles > rabbit)
		{
			if(minutes < 10)
			{
				turtles += 3 * minutes;
				rabbit += 9 * minutes;
				break;
			}
			turtles += 30;
			rabbit += 90;
			minutes -= 10;
		}
		else
		{
			if(minutes < 30)
			{
				turtles += minutes * 3;
				break;
			}
			turtles += 90;
			minutes -= 30;
		}
	}

	if(turtles > rabbit)
		std::cout << "@_@ " << turtles;
	else if(turtles < rabbit)
		std::cout << "^_^ " << rabbit;
	else
		std::cout << "-_- " << rabbit;

	return 0;
}