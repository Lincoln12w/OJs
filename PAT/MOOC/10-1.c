#include <stdio.h>

int main()
{
	char Array[80];
	int index = 0;
	int i = 0;
	char ch;

	scanf("%c",&ch);
	while(ch != '\n')
	{
		Array[index++] = ch;
		scanf("%c",&ch);
	}
	Array[index] = '\0';
	scanf("%c",&ch);
	while(Array[i] != ch && i != index )
		i++;
	if(i == index)
		printf("Not found");
	else
		while(Array[i] != '\0')
		{
			printf("%c", Array[i]);
			i++;
		}

	return 0;
}