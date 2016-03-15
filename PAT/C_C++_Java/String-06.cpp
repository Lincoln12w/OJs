#include <iostream>
 
int main()
{
  int i, j;
  char bit;
  int number[4]= {0,0,0,0};
  
  for(i = 0; i < 4; ++i)
  {
     for(j = 0; j < 8; ++j)
     {
       std::cin >> bit;
       number[i] *= 2;
       number[i] += bit - '0';
     }
  }
  for(i = 0; i < 3; ++i)
  {
    std::cout << number[i] << ".";
  }
  std::cout << number[3];
  
  return 0;
}