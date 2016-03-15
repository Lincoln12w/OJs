#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main()
{
  int number;
  cin >> number;
  vector<int> num;
  int temp = number;
  while(temp)
  {
    num.push_back(temp%10);
    temp = temp / 10;
  }
  if(num.size() == 3)
  {
    for(int i = 0; i < num[2]; i++)
    {
      cout << "B";
    }
  }
  if(num.size() >= 2)
  {
    for(int i = 0; i < num[1]; i++)
    {
      cout << "S";
    }
  }
  if(num.size())          // for n   print 123456...n
  {
    for(int i = 0; i < num[0]; i++)
    {
        cout << i+1;
    }
  }
  return 0;
}
