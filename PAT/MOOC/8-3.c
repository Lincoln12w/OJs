#include <stdio.h>
#include <malloc.h>

int main()
{
	int bit[10];
	int i;
	
	for(i = 0; i < 10; ++i)
		scanf("%d", &bit[i]);
	i = 0;
	while(bit[++i] == 0);
	printf("%d",i);
	bit[i]--;
	for(i = 0; i < 10; ++i)
	{
		while(bit[i]--)
			printf("%d", i);
	}
	return 0;
}
