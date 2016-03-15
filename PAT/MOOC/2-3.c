#include <stdio.h>

int main()
{
	int number, ans = 0;
	scanf("%d", &number);
	while(number)
	{
		ans *= 10;
		ans += number %10;
		number /= 10;
	}
	printf("%d",ans);

	return 0;
}