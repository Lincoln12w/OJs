#include <stdio.h>

int main()
{
	int speed;
	scanf("%d", &speed);
	printf("Speed: %d - ",speed);
	if(speed > 60)
		printf("Speeding");
	else
		printf("OK");

	return 0;
}