#include <stdio.h>
#include <math.h>

int main()
{
	int m,n;
	int guess;
	int cnt = 0;

	scanf("%d %d", &m, &n);

	scanf("%d", &guess);
	while(1)
	{
		++cnt;
		if(cnt > n || guess < 0)
		{
			printf("Game Over\n");
			return 0;
		}
		if(guess > m)
			printf("Too big\n");
		if(guess < m)
			printf("Too small\n");
		if(guess == m)
		{
			if(cnt == 1)
				printf("Bingo!\n");
			else if(cnt < 4)
				printf("Lucky You!\n");
			else
				printf("Good Guess!\n");
			return 0;
		}
		scanf("%d", &guess);
	}

	return 0;
}