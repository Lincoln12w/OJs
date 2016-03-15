#include<iostream>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
  int A, B, D;
  cin >> A >> B >> D;
  int sum = A + B;
  if(sum == 0)      //边界检测
  {
    cout << 0;
    return 0;
  }
  vector<int> Dd;
  while(sum)
  {
    Dd.push_back(sum%D);
    sum = sum/D;
  }
  for(vector<int>::reverse_iterator riter = Dd.rbegin(); riter != Dd.rend(); riter++)
  {
    cout << *riter;
  }
  return 0;
}
