#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int desend(int n);
int acsend(int n);
void coutt(int d);

int main()
{
  int number;
  cin >> number;
  if(acsend(number) == desend(number))
  {
    cout << number << " - " << number << " = 0000";
    return 0;
  }
  if(number == 6174)        // 不要漏了这种特殊情况
  {
    cout << "7641 - 1467 = 6174";
    return 0;
  }
  while(number != 6174)
  {
    int a = acsend(number);
    int d = desend(number);
    number = a - d;
    cout << a << " - ";
    coutt(d);
    cout << " = ";
    coutt(number);
    if(number != 6174)
      cout << endl;
  }

  return 0;
}

int acsend(int n)       // 排序
{
  int num[4];
  int number = 0;
  for(int i = 0;i < 4; i++)
  {
    num[i] = n%10;
    n = n/10;
  }
  for(int i = 0; i < 4; i++)
  {
    for(int j = i+1; j < 4; j++)
    {
      if(num[i] < num[j])
      {
        int temp = num[j];
        num[j] = num[i];
        num[i] = temp;
      }
    }
  }
  number = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];

  return number;
}

int desend(int n)
{
  int num[4];
  int number = 0;
  for(int i = 0;i < 4; i++)
  {
    num[i] = n%10;
    n = n/10;
  }
  for(int i = 0; i < 4; i++)
  {
    for(int j = i+1; j < 4; j++)
    {
      if(num[j] < num[i])
      {
        int temp = num[j];
        num[j] = num[i];
        num[i] = temp;
      }
    }
  }
  number = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];

  return number;
}

void coutt(int d)       // 为了4位数输出
{
  if(d < 10)
    cout << "000" << d;
  else if(d < 100)
    cout << "00" << d;
  else if(d < 1000)
    cout << "0" << d;
  else
    cout << d;
}
