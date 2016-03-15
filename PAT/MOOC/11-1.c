#include <stdio.h>

typedef struct _note
{
	char name[11];
	char date[11];
	char sex;
	char fixPhone[17];
	char cellPhone[17];
}note;

int main()
{
	int n, k, no;
	int i, j;
	char ch;
	note phonenode[10];

	scanf("%d", &n);
	getchar();
	for(i = 0; i < n; i++)
	{
		scanf("%c", &ch);
		j = 0;
		while(ch != ' ')
		{
			phonenode[i].name[j++] = ch;
			scanf("%c", &ch);
		}
		phonenode[i].name[j] = '\0';

		scanf("%c", &ch);
		j = 0;
		while(ch != ' ')
		{
			phonenode[i].date[j++] = ch;
			scanf("%c", &ch);
		}
		phonenode[i].date[j] = '\0';

		scanf("%c", &ch);
		phonenode[i].sex = ch;
		scanf("%c", &ch);

		scanf("%c", &ch);
		j = 0;
		while(ch != ' ')
		{
			phonenode[i].fixPhone[j++] = ch;
			scanf("%c", &ch);
		}
		phonenode[i].fixPhone[j] = '\0';

		scanf("%c", &ch);
		j = 0;
		while(ch != '\n')
		{
			phonenode[i].cellPhone[j++] = ch;
			scanf("%c", &ch);
		}
		phonenode[i].cellPhone[j] = '\0';
	}

	scanf("%d", &k);
	for(j = 0; j < k; j++)
	{
		scanf("%d", &no);
		if(no > -1 && no < n)
			printf("%s %s %s %c %s\n", phonenode[no].name, phonenode[no].fixPhone, 
				phonenode[no].cellPhone, phonenode[no].sex, phonenode[no].date);
		else
			printf("Not Found\n");
	}

	return 0;
}