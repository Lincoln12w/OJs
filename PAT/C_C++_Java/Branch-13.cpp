#include <cstdio>

int main()
{
	int year,month,day;
	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d/%d/%d",&year, &month, &day);
	int days = day;
	for(int i = 1; i < month; ++i)
		days += months[i-1];
	if(((year % 4 == 0 && year % 100) || year % 400 == 0) && month > 2)
		++days;

	printf("%d", days);

	return 0;
}