#include <stdio.h>

int main()
{
	double d1, d2;
	int i;
	char c;

	scanf("%lf %d %c %lf", &d1, &i, &c, &d2);		// double must be %lf to input
	printf("%c %d %0.2f %0.2f", c, i, d1, d2);

	return 0;
}