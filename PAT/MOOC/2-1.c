#include <stdio.h>

int main()
{
	int cm;
    scanf("%d", &cm);
    cm = (cm / 30.48 *12 );
    printf("%d %d", cm/12, cm%12);

	return 0;
}