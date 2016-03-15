#include <cstdio>

int main()
{
	int time1, time2;

	scanf("%d %d", &time1, &time2);
	
	int minutes = time2 % 100 - time1 % 100;
	int hours = time2 / 100 - time1 / 100;
	if(minutes < 0)
	{
		-- hours;
		minutes += 60;
	}

	printf("%02d:%02d", hours, minutes);
	//std::cout << std::setw(2) << std::setfill('0') << hours << ":" << std::setw(2) << std::setfill('0') << minutes;

	return 0;
}