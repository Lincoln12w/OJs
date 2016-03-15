#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
  int n;
  long int a,b,c;
  int flaga = 0, flagb = 0, flagc = 0;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    if(i)
      cout << endl;
    cin >> a;
    if(!cin.good())
    {
      cin.clear();
      flaga = 1;
    }
    cin >> b;
    if(!cin.good())
    {
      cin.clear();
      flagb = 1;
    }
    cin >> c;
    if(!cin.good())
    {
      cin.clear();
      flagc = 1;
    }
    cout << "Case #" << i+1 << ": ";
    if(flaga && flagb)
    {
      cout << "true";
      continue;
    }
    if(flaga && !flagb && !flagc)
    {
      if(b >= 0)
      {
        cout << "true";
        continue;
      }
      if(b < 0)
      {
        if(((2147483647+b)+1) > c)
          cout << "true";
        else
          cout << "false";
        continue;
      }
    }
    if(!flaga && flagb && !flagc)
    {
      if(a >= 0)
      {
        cout << "true";
        continue;
      }
      if(a < 0)
      {
        if(((2147483647+a)+1) > c)
          cout << "true";
        else
          cout << "false";
        continue;
      }
    }
    if(flaga && flagc)
    {
      if(b>0)
        cout << "true";
      else
        cout << "false";
      continue;
    }
    if(flagb && flagc)
    {
      if(a > 0)
        cout << "true";
      else
        cout << "false";
      continue;
    }
    if(flagc)
    {
      if(a > 0 && b > 0 && (a+b) < 0)
        cout << "true";
      else
        cout << "false";
      continue;
    }
    if(a > 0 && b > 0 && (a+b) < 0)
    {
      cout << "true";
      continue;
    }
    #if 0
    if(a < 0 && (b < (-2147483647 - 1 -a)))     // 常量用 -2147483647-1 来代替-2147483648 防止溢出
    {
      cout << "flase";
      continue;
    }
    #else
    if(a < 0 && b < 0 && (a+b) > 0)
    {
        cout << "flase";
        continue;
    }
    #endif
    if((a+b) > c)
      cout << "true";
    else
      cout << "false";
  }

  return 0;
}
