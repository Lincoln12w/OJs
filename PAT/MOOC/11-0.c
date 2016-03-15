#include <stdio.h>

int main()
{
	double x1, y1, x2, y2;
	double sumx, sumy;

	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	sumx = x1 + x2;
	sumy = y1 + y2;
	if(sumx < 0 && sumx > -0.05)
		sumx = 0;
	if(sumy < 0 && sumy > -0.05)
		sumy = 0;
	printf("(%.1f, %.1f)", sumx, sumy);
}


/* test case:  -0.31 -0.26 0.30 0.20 */