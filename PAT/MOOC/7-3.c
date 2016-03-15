#include <stdio.h>
#include <math.h>

int main()
{
	int pm, pn;
	int i = 2;
	int cnt = 0;
	
	int isprime(int number);

	scanf("%d %d", &pm, &pn);

	while(cnt < pm)
	{
		while(isprime(i++) == 0);
		++cnt;
	}
	while(cnt < pn + 1)
	{
		printf("%d",i-1);
		while(isprime(i++) == 0);
		++cnt;
		if((cnt-pm)%10 == 0)
			printf("\n");
		else if(cnt != pn+1)
			printf(" ");
	}

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