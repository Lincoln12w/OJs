#include <stdio.h>

int main()
{
	int days;
	scanf("%d",&days);
	if((days - 1)%5 > 2)
		printf("Drying");
	else
		printf("Fishing");
	printf(" in day %d", days);

	return 0;
}