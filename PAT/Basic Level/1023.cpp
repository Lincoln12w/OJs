#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  int cnt;
  int num[10];
  for(int i = 0; i < 10; i++)
  {
    cin >> cnt;
    num[i] = cnt;
  }
  int i = 0;
  while(num[++i] == 0);
  cout << i;      // the smallest value that not zero
  num[i] --;
  for(int i = 0; i< 10; i++)
  {
      while(num[i]--)
	  {
		cout << i;
	  }
  }
}

