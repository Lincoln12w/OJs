#include <iostream>
#include <vector>


using std::cin;
using std::cout;
using std::endl;
using std::vector;

void display(int num);

int main()
{
  int a,b;
  cin >> a >> b;
  int c = a+b;
  if(c < 1000 && c > -1000)
  {
    cout << c;
    return 0;
  }
  if(c < 0)
  {
    cout << "-";
    c = -c;
  }
  vector<int> out;
  while(c/1000)
  {
    out.push_back(c%1000);
    c = c/1000;
  }
  if(c)
    cout << c << ",";
  for(vector<int>::reverse_iterator vrite=out.rbegin(); vrite != out.rend(); vrite++)
  {
    display(*vrite);
    if(vrite!=out.rend()-1)
      cout << ",";
  }

  return 0;
}

void display(int num)
{
  if(num < 10)
    cout << "00" << num;
  else if(num < 100)
    cout << "0" << num;
  else
    cout << num;
}
