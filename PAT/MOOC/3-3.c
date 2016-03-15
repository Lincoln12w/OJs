#include <stdio.h>

int main()
{
	int hours, minutes;
	scanf("%d:%d",&hours, &minutes);
	if(hours == 12)
		printf("%d:%d PM", hours, minutes);
	else
	{
		printf("%d:%d ",hours%12,minutes);
		if(hours > 12)
			printf("PM");
		else
			printf("AM");
	}

	return 0;
}