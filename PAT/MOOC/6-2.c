#include <stdio.h>

int main()
{
	char ch;

	scanf("%c", &ch);
	while(ch != '#')
	{
		if(ch > 'a' - 1 && ch < 'z' + 1)
			printf("%c", ch + 'A' - 'a');
		else if(ch > 'A' - 1 && ch < 'Z' + 1)
			printf("%c", ch + 'a' - 'A');
		else
			printf("%c",ch);
		scanf("%c", &ch)
;	}

	return 0;
}