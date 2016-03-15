#include <stdio.h>
int main()
{
	int n;
	int number, temp;
	int result = 0;
	int power(int base, int exp);
	scanf("%d",&n);
	for(number = power(10,n-1); number < power(10, n); ++number)
	{
		temp = number;
		result = 0;
		while(temp)
		{
			result += power(temp%10, n);
			temp /= 10;
		}
		if(result == number)
			printf("%d\n",number);
	}

	return 0;
}

int power(int base, int exp)
{
	int ans = 1;
	while(exp--)
	{
		ans *= base;
	}

	return ans;
}