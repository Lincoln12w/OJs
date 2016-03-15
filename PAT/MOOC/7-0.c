#include <stdio.h>

int main()
{
	char ch;
	int bit[3];
	char sound[10][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	int pos = 0;
	int sum = 0;
	int i = 0;

	scanf("%c", &ch);
	while(ch != '\n')
	{
		sum += ch - '0';
		scanf("%c", &ch);
	}

	while(sum)
	{
		bit[pos] = sum % 10;
		sum /= 10;
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