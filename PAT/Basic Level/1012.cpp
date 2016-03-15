#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ios;

int main()
{
  int n;
  vector<int> vnum;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    int number;
    cin >> number;
    vnum.push_back(number);
  }
  vector<int> A1,A2,A3,A4,A5;
  for(vector<int>::iterator iiter = vnum.begin(); iiter != vnum.end(); iiter++) // differ
  {
    if((*iiter % 5 == 0) && (*iiter % 2 == 0))
      A1.push_back(*iiter);
    if(*iiter % 5 == 1)
      A2.push_back(*iiter);
    if(*iiter % 5 == 2)
      A3.push_back(*iiter);
    if(*iiter % 5 == 3)
      A4.push_back(*iiter);
    if(*iiter % 5 == 4)
      A5.push_back(*iiter);
  }
  if(A1.size())
  {
    int sum = 0;
    for(vector<int>::iterator iter = A1.begin(); iter != A1.end(); iter++)
    {
      sum += *iter;
    }
    cout << sum << " ";
  }
  else
    cout << "N ";
  if(A2.size())
  {
    int sum = 0;
    int flag = -1;
    for(vector<int>::iterator iter = A2.begin(); iter != A2.end(); iter++)
    {
      flag = -flag;
      sum += *iter * flag;
    }
    cout << sum << " ";
  }
  else
    cout << "N ";
  if(A3.size())
  {
    cout << A3.size() << " ";
  }
  else
    cout << "N ";
  if(A4.size())
  {
    double sum = 0;
    for(vector<int>::iterator iter = A4.begin(); iter != A4.end(); iter++)
    {
      sum += *iter;
    }
    sum /= A4.size();
    cout.setf(ios::showpoint);
    cout.precision(1);
    cout.setf(ios::fixed);
    cout << sum << " ";
  }
  else
    cout << "N ";
  if(A5.size())
  {
    int max = A5[0];
    for(vector<int>::iterator iter = A5.begin(); iter != A5.end(); iter++)
    {
      if(max < *iter)
        max = *iter;
    }
    cout << max;
  }
  else
    cout << "N";

  return 0;
}
