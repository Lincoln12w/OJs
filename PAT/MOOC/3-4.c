#include <stdio.h>

int main()
{
	int grade;
	scanf("%d",&grade);

	if(grade < 60)
		printf("E");
	else if(grade < 70)
		printf("D");
	else if(grade < 80)
		printf("C");
	else if(grade < 90)
		printf("B");
	else
		printf("A");

	return 0;
}