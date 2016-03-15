#include <iostream>
#include <utility>
#include <map>

using std::cin;
using std::cout;
using std::map;
using std::ios;


int main()
{
  int K;
  cin >> K;
  map<int, double> poly;
  int n;
  double an;
  for(int i = 0; i < K; i++)
  {
    cin >> n >> an;
    poly[n] += an;
  }
  cin >> K;
  for(int i = 0; i < K; i++)
  {
    cin >> n >> an;
    poly[n] += an;
  }
  for(map<int,double>::iterator iter=poly.begin(); iter != poly.end(); iter++)
  {
    if(iter->second == 0)
      poly.erase(iter);          // for nonzero
  }
  if(poly.size() == 0)            // for 0
  {
    cout << 0;
    return 0;
  }
  cout << poly.size() << " ";
  for(map<int,double>::reverse_iterator rviter=poly.rbegin(); rviter != poly.rend(); rviter++)
  {
    if(rviter != poly.rbegin())         // poly.rend()-1 will cause compiler error
      cout << " ";
    cout.setf(ios::showpoint);        // 1位小数精度
    cout.precision(1);
    cout.setf(ios::fixed);
    cout << rviter->first << " " << rviter->second;
  }

  return 0;
}
