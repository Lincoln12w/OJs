#include <cstdio>

int main()
{
	char ch;
	char charray[80];
	int i = 0;
	
	scanf("%c", &ch);

	while(ch != '\n')
	{
		charray[i++] = ch;
		scanf("%c", &ch);
	}
	scanf("%c", &ch);
	int j;
	for(j = 0; j < i; ++j)
	{
		if(charray[j] == ch)
			break;
	}
	if(j == i)
		printf("Not found");
	else
		for(int k = j; k < i; ++k)
			printf("%c",charray[k]);

	return 0;
}
