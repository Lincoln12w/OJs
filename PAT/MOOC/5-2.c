#include <stdio.h>

int main()
{
	int number;
	int bit[10];
	int pos = 0,i;
	char sound[10][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	//void printbit(int bit);

	scanf("%d", &number);
	if(number == 0)
	{
		printf("ling");
		return 0;
	}

	if(number < 0)
	{
		printf("fu ");
		number = - number;
	}
	
	while(number)
	{
		bit[pos] = number % 10;
		number /= 10;
		++pos;
	}
	for(i = pos - 1; i >0; --i)
	{
		//printbit(bit[i]);
		printf("%s",sound[bit[i]]);
		printf(" ");
	}
	printf("%s",sound[bit[0]]);

	return 0;
}

void printbit(int bit)
{
	switch(bit)
	{
	case 0:
		printf("ling");
		break;
	case 1:
		printf("yi");
		break;
	case 2:
		printf("er");
		break;
	case 3:
		printf("san");
		break;
	case 4:
		printf("si");
		break;
	case 5:
		printf("wu");
		break;
	case 6:
		printf("liu");
		break;
	case 7:
		printf("qi");
		break;
	case 8:
		printf("ba");
		break;
	case 9:
		printf("jiu");
	}
}