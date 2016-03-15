#include <stdio.h>

int substr(char * str, char * substr);

int main()
{
	char Array[81];     // 81 留个空给'\0' 
	char subArray[81];
	char ch;
	int index = 0;
	int i = 0, j = 0;

	scanf("%c", &ch);
	while(ch != '\n')
	{
		Array[index++] = ch;
		scanf("%c", &ch);
	}
	Array[index] = '\0';
	scanf("%c", &ch);
	index = 0;
	while(ch != '\n')
	{
		subArray[index++] = ch;
		scanf("%c", &ch);
	}
	subArray[index] = '\0';
	while(substr(Array, subArray));
	i = 0;
	while(Array[i] != '\0')
		printf("%c",Array[i++]);

	return 0;
}

int substr(char * str, char * substr)
{
	int i = 0;
	int cur = 0;
	int j;
	int k;

	while(str[i] != '\0')
	{
		while(str[i] != substr[0] && str[i] != '\0')
			i++;
		if(str[i] == '\0')
			return 0;
		j = 0;
		cur = i;
		while(substr[j] != '\0')
		{
			if(str[i] == '\0')
				return 0;
			if(substr[j] != str[i])
				break;
			j++;
			i++;
		}
		if(substr[j] == '\0')
		{
			for(k = i; str[k] != '\0'; ++k)
				str[k - j] = str[k];
			str[k-j] = '\0';

			return 1;
		}
	}
	return 0;
}

/*
test case 0: 
test case 1: ans is ""
test case 3: format error
test case 4: wrong answer
*/