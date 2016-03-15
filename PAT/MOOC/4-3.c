#include <stdio.h>
#include <math.h>

int main()
{
	int m,n;
	int i;
	int cnt = 0, sum = 0;

	int isprime(int number);

	scanf("%d %d", &m, &n);

	for(i =m; i < n + 1; i++)
	{
		if(isprime(i))
		{
			++cnt;
			sum += i;
		}
	}

	printf("%d %d",cnt,sum);

	return 0;
}

int isprime(int number)
{
	int i = 2;
	if(number == 2)
		return 1;
	if(number == 1)
		return 0;
	for(;i < sqrt(number*1.0) + 1; ++i)
	{
		if(number % i == 0)
			return 0;
	}
	return 1;
}