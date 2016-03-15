#include <iostream>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;


bool isprime(int n);

int main()
{
  int m,n;
  cin >> m >> n;
  int count = 0;
  int number = 2;
  while(count < n)
  {
    if(isprime(number))
    {
      ++count;
      if(count >= m)      // Pm - Pn
      {
        cout << number;
        if(count != n)
        {
          if((count + 1 - m)%10)    // every 10 numbers a line
            cout << " ";
          else
            cout << "\n";
        }
      }
    }
    ++number;
  }
}

bool isprime(int n)
{
  int sqr = sqrt(n);
  for(int i = 2; i <= sqr; i++)
  {
    if(n%i == 0)
      return false;
  }
  return true;
}
