#include<cstdio>
 
int main()
{
  int beg, end;
  int sum = 0;
  
  scanf("%d %d", &beg, &end);
  for(int i = beg; i < end + 1; ++i)
  {
    printf("%5d", i);
    sum += i;
    if((i - beg) % 5 == 4)
      printf("\n");
  }
  if((end - beg) % 5 != 4)
    printf("\n");
  printf("Sum = %d", sum);
  return 0;
}