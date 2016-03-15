#include <iostream>
#include <vector>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;

bool isprime(int n);

int main()
{
  int n;
  cin >> n;
  vector<int> primes;
  for(int i = 2; i <= n; i++)
  {
    if(isprime(i))
    {
      primes.push_back(i);
    }
  }
  int count = 0;
  for(vector<int>::iterator iter = primes.begin(); iter != (primes.end()-1); iter++)
  {
    if((*(iter+1) - *iter) == 2)
    {
      count++;
    }
  }
  cout << count;

  return 0;
}

bool isprime(int n)   // choose a wise alorithm
{
  int sqr = sqrt(n);
  for(int i = 2; i <= sqr; i++)
  {
    if(n%i == 0)
      return false;
  }
  return true;
}
