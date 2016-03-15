#include <stdio.h>

void swap(int beg, int end, char * str);

int main()
{
	char Array[80];
	char ch;
	int index = 0;
	int n;

	scanf("%c", &ch);
	while(ch != '\n')
	{
		Array[index++] = ch;
		scanf("%c", &ch);
	}
	Array[index] = '\0';
	scanf("%d", &n);
	n %= index;
	swap(0 ,n, Array);
	swap(n, index, Array);
	swap(0, index, Array);

	n = 0;
	while(Array[n] != '\0')
		printf("%c",Array[n++]);

	return 0;
}

void swap(int beg, int end, char * str)
{
	int i,j;
	char ch;

	for(i = beg, j = end - 1; i < j; ++i, --j)
	{
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
	}
}