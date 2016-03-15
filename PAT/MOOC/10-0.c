#include <stdio.h>

void swap(int beg, int end, char * Array);

int main()
{
	char Array[80];
	char ch;
	int index = 0;
	int flag = 0;
	int beg = 0, end = 0, i = 0;

	scanf("%c", &ch);
	while(ch != '\n')
	{
		if(ch == ' ')
		{
			if(flag)
				Array[index++] = ch;
			flag = 0;
		}
		else
		{
			Array[index++] = ch;
			flag = 1;
		}
		scanf("%c", &ch);
	}
	Array[index] = '\0';

	while(1)
	{
		beg = end;
		while(Array[i++] != ' ' && i < index);
		if(i == index)
			break;
		end = i++;
		swap(beg, end - 1, Array);
	}
	swap(beg, index, Array);
	swap(0,index, Array);
	
	i = 0;
	while(Array[i] != '\0')
		printf("%c", Array[i++]);

	return 0;
}

void swap(int beg, int end, char * Array)
{
	int i,j;
	int tmp;

	for(i = beg, j = end -1; i < j; ++i, --j)
	{
		tmp = Array[i];
		Array[i] = Array[j];
		Array[j] = tmp;
	}
}